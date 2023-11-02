//generated by ['./genXoshiro.py']
//generated from ['org/xoshiro128plus.c', 'org/xoshiro128plusplus.c', 'org/xoshiro128starstar.c', 'org/xoroshiro128plus.c', 'org/xoroshiro128plusplus.c', 'org/xoroshiro128starstar.c', 'org/xoshiro256plus.c', 'org/xoshiro256plusplus.c', 'org/xoshiro256starstar.c', 'splitmix64']
// cf. copyright

#include<stdint.h>
#include<cfloat>

typedef uint32_t xoshiro128_state_t[4];
typedef uint64_t xoshiro256_state_t[4];
typedef uint64_t xoroshiro128_state_t[2];

static inline uint32_t xoshiro128plus_rotl(const uint32_t x, int k) {
	return (x << k) | (x >> (32 - k));
}

inline uint32_t xoshiro128plus_next(xoshiro128_state_t& s) {
	const uint32_t result = s[0] + s[3];

	const uint32_t t = s[1] << 9;

	s[2] ^= s[0];
	s[3] ^= s[1];
	s[1] ^= s[2];
	s[0] ^= s[3];

	s[2] ^= t;

	s[3] = xoshiro128plus_rotl(s[3], 11);

	return result;
}
static inline uint32_t xoshiro128plusplus_rotl(const uint32_t x, int k) {
	return (x << k) | (x >> (32 - k));
}

inline uint32_t xoshiro128plusplus_next(xoshiro128_state_t& s) {
	const uint32_t result = xoshiro128plusplus_rotl(s[0] + s[3], 7) + s[0];

	const uint32_t t = s[1] << 9;

	s[2] ^= s[0];
	s[3] ^= s[1];
	s[1] ^= s[2];
	s[0] ^= s[3];

	s[2] ^= t;

	s[3] = xoshiro128plusplus_rotl(s[3], 11);

	return result;
}
static inline uint32_t xoshiro128starstar_rotl(const uint32_t x, int k) {
	return (x << k) | (x >> (32 - k));
}

inline uint32_t xoshiro128starstar_next(xoshiro128_state_t& s) {
	const uint32_t result = xoshiro128starstar_rotl(s[1] * 5, 7) * 9;

	const uint32_t t = s[1] << 9;

	s[2] ^= s[0];
	s[3] ^= s[1];
	s[1] ^= s[2];
	s[0] ^= s[3];

	s[2] ^= t;

	s[3] = xoshiro128starstar_rotl(s[3], 11);

	return result;
}
static inline uint64_t xoroshiro128plus_rotl(const uint64_t x, int k) {
	return (x << k) | (x >> (64 - k));
}

inline uint64_t xoroshiro128plus_next(xoroshiro128_state_t& s) {
	const uint64_t s0 = s[0];
	uint64_t s1 = s[1];
	const uint64_t result = s0 + s1;

	s1 ^= s0;
	s[0] = xoroshiro128plus_rotl(s0, 24) ^ s1 ^ (s1 << 16); // a, b
	s[1] = xoroshiro128plus_rotl(s1, 37); // c

	return result;
}
static inline uint64_t xoroshiro128plusplus_rotl(const uint64_t x, int k) {
	return (x << k) | (x >> (64 - k));
}

inline uint64_t xoroshiro128plusplus_next(xoroshiro128_state_t& s) {
	const uint64_t s0 = s[0];
	uint64_t s1 = s[1];
	const uint64_t result = xoroshiro128plusplus_rotl(s0 + s1, 17) + s0;

	s1 ^= s0;
	s[0] = xoroshiro128plusplus_rotl(s0, 49) ^ s1 ^ (s1 << 21); // a, b
	s[1] = xoroshiro128plusplus_rotl(s1, 28); // c

	return result;
}
static inline uint64_t xoroshiro128starstar_rotl(const uint64_t x, int k) {
	return (x << k) | (x >> (64 - k));
}

inline uint64_t xoroshiro128starstar_next(xoroshiro128_state_t& s) {
	const uint64_t s0 = s[0];
	uint64_t s1 = s[1];
	const uint64_t result = xoroshiro128starstar_rotl(s0 * 5, 7) * 9;

	s1 ^= s0;
	s[0] = xoroshiro128starstar_rotl(s0, 24) ^ s1 ^ (s1 << 16); // a, b
	s[1] = xoroshiro128starstar_rotl(s1, 37); // c

	return result;
}
static inline uint64_t xoshiro256plus_rotl(const uint64_t x, int k) {
	return (x << k) | (x >> (64 - k));
}

inline uint64_t xoshiro256plus_next(xoshiro256_state_t& s) {
	const uint64_t result = s[0] + s[3];

	const uint64_t t = s[1] << 17;

	s[2] ^= s[0];
	s[3] ^= s[1];
	s[1] ^= s[2];
	s[0] ^= s[3];

	s[2] ^= t;

	s[3] = xoshiro256plus_rotl(s[3], 45);

	return result;
}
static inline uint64_t xoshiro256plusplus_rotl(const uint64_t x, int k) {
	return (x << k) | (x >> (64 - k));
}

inline uint64_t xoshiro256plusplus_next(xoshiro256_state_t& s) {
	const uint64_t result = xoshiro256plusplus_rotl(s[0] + s[3], 23) + s[0];

	const uint64_t t = s[1] << 17;

	s[2] ^= s[0];
	s[3] ^= s[1];
	s[1] ^= s[2];
	s[0] ^= s[3];

	s[2] ^= t;

	s[3] = xoshiro256plusplus_rotl(s[3], 45);

	return result;
}
static inline uint64_t xoshiro256starstar_rotl(const uint64_t x, int k) {
	return (x << k) | (x >> (64 - k));
}

inline uint64_t xoshiro256starstar_next(xoshiro256_state_t& s) {
	const uint64_t result = xoshiro256starstar_rotl(s[1] * 5, 7) * 9;

	const uint64_t t = s[1] << 17;

	s[2] ^= s[0];
	s[3] ^= s[1];
	s[1] ^= s[2];
	s[0] ^= s[3];

	s[2] ^= t;

	s[3] = xoshiro256starstar_rotl(s[3], 45);

	return result;
}

inline uint64_t splitmix64_next(uint64_t & x) {
	uint64_t z = (x += 0x9e3779b97f4a7c15);
	z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;
	z = (z ^ (z >> 27)) * 0x94d049bb133111eb;
	return z ^ (z >> 31);
}

inline void init_xoshiro256_state(xoshiro256_state_t& state, uint64_t seed){
  uint64_t splitMixState=seed;
  state[0]= splitmix64_next(splitMixState);
  state[1]= splitmix64_next(splitMixState);
  state[2]= splitmix64_next(splitMixState);
  state[3]= splitmix64_next(splitMixState);
}

inline void init_xoroshiro128_state(xoroshiro128_state_t& state,uint64_t seed){
  uint64_t splitMixState=seed;
  state[0]= splitmix64_next(splitMixState);
  state[1]= splitmix64_next(splitMixState);
}

inline void init_xoshiro128_state(xoshiro128_state_t& state,uint64_t seed){
  uint64_t splitMixState=seed;
  uint64_t state01=splitmix64_next(splitMixState);
  uint64_t state23=splitmix64_next(splitMixState);
  state[0]= (uint32_t)state01;
  state[1]= (uint32_t)(state01 << 32);
  state[2]= (uint32_t)state23;
  state[3]= (uint32_t)(state23 << 32);
}


inline float xoshiro_uint32_to_float(const uint32_t i){
    constexpr float factor(0.5*FLT_EPSILON);//0x1.0p-24
    return (i >> 8) * factor;
};

inline double xoshiro_uint64_to_double(const uint64_t i){
   constexpr double factor(0.5*DBL_EPSILON);//0x1.0p-53
    return (i >> 11) * factor;
};

