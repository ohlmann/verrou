#!/usr/bin/env python3

import sys
import re



def generateNargs(fileOut, fileNameTemplate, listOfBackend, listOfOp, nargs):

    templateStr=open(fileNameTemplate, "r").readlines()

    FctNameRegExp=re.compile("(.*)FCTNAME\(([^,]*),([^)]*)\)(.*)")
    BckNameRegExp=re.compile("(.*)BACKENDFUNC\(([^)]*)\)(.*)")

    
    for backend in listOfBackend:
        for op in listOfOp:
            if nargs in [1,2]:
                applyTemplate(fileOut, templateStr, FctNameRegExp, BckNameRegExp, backend,op)
            if nargs==3:
                sign=""
                if "msub" in op:
                    sign="-"
                applyTemplate(fileOut, templateStr,FctNameRegExp,BckNameRegExp, backend, op, sign)
                
            
    
def applyTemplate(fileOut, templateStr, FctRegExp, BckRegExp, backend, op ,sign=None):
    fileOut.write("// generation of operation %s backend %s \n"%(op,backend))
    def fctName(typeVal,opt):
        return "vr_"+backend+op+typeVal+opt
    def bckName(typeVal):
        if sign!="-":
            return "interflop_"+backend+"_"+op+"_"+typeVal
        else:
            return "interflop_"+backend+"_"+op.replace("sub","add")+"_"+typeVal
    contextName="backend_"+backend+"_context"
    
    for line in templateStr:
        if "CONTEXT" in line:
            line=line.replace("CONTEXT", contextName)
        if "SIGN" in line:
            if sign!=None:
                line=line.replace("SIGN", sign)
            else:
                print("Generation failed")
                sys.exit()
        result=FctRegExp.match(line)
        if result!=None:
            res=result.group(1) + fctName(result.group(2), result.group(3)) + result.group(4)
            fileOut.write(res+"\n")
            continue
        result=BckRegExp.match(line)
        if result!=None:
            res=result.group(1) + bckName(result.group(2)) + result.group(3)
            fileOut.write(res+"\n")
            continue

        fileOut.write(line)
        
        
        


if __name__=="__main__":
    listOfBackend=["verrou","mcaquad"]

    fileNameOutput="vr_generated_from_templates.h"
    fileOut=open(fileNameOutput,"w")
    fileOut.write("//Generated by %s\n"%(str(sys.argv)[1:-1]))

    
    template1Args="vr_interp_operator_template_cast.h"
    listOfOp1Args=["cast"]
    generateNargs(fileOut,template1Args, listOfBackend, listOfOp1Args, 1)
    
    template2Args="vr_interp_operator_template_2args.h"
    listOfOp2Args=["add","sub","mul","div"]
    generateNargs(fileOut,template2Args, listOfBackend, listOfOp2Args, 2)
    

    template3Args="vr_interp_operator_template_3args.h"
    listOfOp3Args=["madd","msub"]
    generateNargs(fileOut,template3Args, listOfBackend, listOfOp3Args, 3)

    
    







    fileOut.close()






