#pragma once

class mersenneHash{
public:

  template<class REALTYPE, int NB>
  static bool hashBool(const vr_packArg<REALTYPE,NB>& pack,
		       uint64_t seed,
		       uint32_t hashOp){
    tinymt64_t localGen;
    mersenneHash::setGen(localGen, pack, seed^ hashOp);
    uint32_t res=tinymt64_generate_uint64(&localGen);
    return (res>>31);
  };

  template<class REALTYPE, int NB>
  static double hashRatio(const vr_packArg<REALTYPE,NB>& pack,
			  uint64_t seed,
			  uint32_t hashOp){
    tinymt64_t localGen;
    mersenneHash::setGen(localGen, pack, seed^hashOp);
    return tinymt64_generate_doubleOO(&localGen);
  };

private:
  template<class REALTYPE>
  static void setGen(tinymt64_t& gen,
		     const vr_packArg<REALTYPE,1>& pack,
		     uint64_t seed){
    const uint64_t keys[2]={seed,
			    realToUint64_reinterpret_cast<REALTYPE>(pack.arg1)
    };
    tinymt64_init_by_array(&gen, keys, 2);
  };


  static void setGen(tinymt64_t& gen,
		     const vr_packArg<double,2>& pack,
		     uint64_t seed){
    const uint64_t keys[3]={seed,
			    realToUint64_reinterpret_cast<double>(pack.arg1),
			    realToUint64_reinterpret_cast<double>(pack.arg2)
    };
    tinymt64_init_by_array(&gen, keys, 3);
  };

  static void setGen(tinymt64_t& gen,
		     const vr_packArg<float,2>& pack,
		     uint64_t seed){

    uint32_t arg1=realToUint32_reinterpret_cast(pack.arg1);
    uint32_t arg2=realToUint32_reinterpret_cast(pack.arg2);
    uint64_t arg=arg1;
    arg=(arg<<32)+arg2;

    const uint64_t keys[2]={seed,arg};
    tinymt64_init_by_array(&gen, keys, 2);
  };

  static void setGen(tinymt64_t& gen,
		     const vr_packArg<double,3>& pack,
		     uint64_t seed){

    uint64_t arg1=realToUint64_reinterpret_cast<double>(pack.arg1);
    uint64_t arg2=realToUint64_reinterpret_cast<double>(pack.arg2);
    uint64_t arg3=realToUint64_reinterpret_cast<double>(pack.arg2);
    const uint64_t keys[4]={seed,arg1, arg2,arg3};
    tinymt64_init_by_array(&gen, keys, 4);
  };

  static void setGen(tinymt64_t& gen,
		     const vr_packArg<float,3>& pack,
		     uint64_t seed){

    uint32_t arg1=realToUint32_reinterpret_cast(pack.arg1);
    uint32_t arg2=realToUint32_reinterpret_cast(pack.arg2);
    uint64_t arg3=realToUint64_reinterpret_cast<double>(pack.arg3);
    uint64_t arg=arg1;
    arg=(arg<<32)+arg2;
    const uint64_t keys[3]={seed,arg,arg3};
    tinymt64_init_by_array(&gen, keys, 3);
  };

};
