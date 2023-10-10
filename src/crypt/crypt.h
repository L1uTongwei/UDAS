#pragma once
// CH(x, y, z) = (x & y) ^ (!x & z)
#define CH \
"and r9, r8\n\t" \
"not r8\n\t" \
"and r8, r10\n\t" \
"xor r8, r9\n\t"
// MAJ(x, y, z) = (x & y) ^ (x & z) ^ (y & z)
#define MAJ \
"mov r11, r9\n\t" \
"and r11, r8\n\t" \
"and r8, r10\n\t" \
"xor r8, r11\n\t" \
"and r9, r10\n\t" \
"xor r8, r9\n\t"
// BSIG0(x) = _rotr(x, 28) ^ _rotr(x, 34) ^ _rotr(x, 39)
#define BSIG0 \
"mov r9, r8\n\t" \
"mov r10, r8\n\t" \
"ror r9, 28\n\t" \
"ror r10, 34\n\t" \
"xor r9, r10\n\t" \
"ror r8, 39\n\t" \
"xor r8, r9\n\t"
// BSIG1(x) = _rotr(x, 14) ^ _rotr(x, 18) ^ _rotr(x, 41)
#define BSIG1 \
"mov r9, r8\n\t" \
"mov r10, r8\n\t" \
"ror r9, 14\n\t" \
"ror r10, 18\n\t" \
"xor r9, r10\n\t" \
"ror r8, 41\n\t" \
"xor r8, r9\n\t"
// SSIG0(x) = _rotr(x, 1) ^ _rotr(x, 8) ^ _shr(x, 7)
#define SSIG0 \
"mov r9, r8\n\t" \
"mov r10, r8\n\t" \
"ror r9, 1\n\t" \
"ror r10, 8\n\t" \
"xor r9, r10\n\t" \
"shr r8, 7\n\t" \
"xor r8, r9\n\t"
// SSIG1(x) = _rotr(x, 19) ^ _rotr(x, 61) ^ _shr(x, 6)
#define SSIG1 \
"mov r9, r8\n\t" \
"mov r10, r8\n\t" \
"ror r9, 19\n\t" \
"ror r10, 61\n\t" \
"xor r9, r10\n\t" \
"shr r8, 6\n\t" \
"xor r8, r9\n\t"

const unsigned long long SHA_K[80] ={
    0x428a2f98d728ae22ull, 0x7137449123ef65cdull, 0xb5c0fbcfec4d3b2full, 0xe9b5dba58189dbbcull,
    0x3956c25bf348b538ull, 0x59f111f1b605d019ull, 0x923f82a4af194f9bull, 0xab1c5ed5da6d8118ull,
    0xd807aa98a3030242ull, 0x12835b0145706fbeull, 0x243185be4ee4b28cull, 0x550c7dc3d5ffb4e2ull,
    0x72be5d74f27b896full, 0x80deb1fe3b1696b1ull, 0x9bdc06a725c71235ull, 0xc19bf174cf692694ull,
    0xe49b69c19ef14ad2ull, 0xefbe4786384f25e3ull, 0x0fc19dc68b8cd5b5ull, 0x240ca1cc77ac9c65ull,
    0x2de92c6f592b0275ull, 0x4a7484aa6ea6e483ull, 0x5cb0a9dcbd41fbd4ull, 0x76f988da831153b5ull,
    0x983e5152ee66dfabull, 0xa831c66d2db43210ull, 0xb00327c898fb213full, 0xbf597fc7beef0ee4ull,
    0xc6e00bf33da88fc2ull, 0xd5a79147930aa725ull, 0x06ca6351e003826full, 0x142929670a0e6e70ull,
    0x27b70a8546d22ffcull, 0x2e1b21385c26c926ull, 0x4d2c6dfc5ac42aedull, 0x53380d139d95b3dfull,
    0x650a73548baf63deull, 0x766a0abb3c77b2a8ull, 0x81c2c92e47edaee6ull, 0x92722c851482353bull,
    0xa2bfe8a14cf10364ull, 0xa81a664bbc423001ull, 0xc24b8b70d0f89791ull, 0xc76c51a30654be30ull,
    0xd192e819d6ef5218ull, 0xd69906245565a910ull, 0xf40e35855771202aull, 0x106aa07032bbd1b8ull,
    0x19a4c116b8d2d0c8ull, 0x1e376c085141ab53ull, 0x2748774cdf8eeb99ull, 0x34b0bcb5e19b48a8ull,
    0x391c0cb3c5c95a63ull, 0x4ed8aa4ae3418acbull, 0x5b9cca4f7763e373ull, 0x682e6ff3d6b2b8a3ull,
    0x748f82ee5defb2fcull, 0x78a5636f43172f60ull, 0x84c87814a1f0ab72ull, 0x8cc702081a6439ecull,
    0x90befffa23631e28ull, 0xa4506cebde82bde9ull, 0xbef9a3f7b2c67915ull, 0xc67178f2e372532bull,
    0xca273eceea26619cull, 0xd186b8c721c0c207ull, 0xeada7dd6cde0eb1eull, 0xf57d4f7fee6ed178ull,
    0x06f067aa72176fbaull, 0x0a637dc5a2c898a6ull, 0x113f9804bef90daeull, 0x1b710b35131c471bull,
    0x28db77f523047d84ull, 0x32caab7b40c72493ull, 0x3c9ebe0a15c9bebcull, 0x431d67c49c100d4cull,
    0x4cc5d4becb3e42b6ull, 0x597f299cfc657e2aull, 0x5fcb6fab3ad6faecull, 0x6c44198c4a475817ull
};

inline void SHA_512(unsigned long long buffer[8], char contents[48]) __attribute((always_inline));