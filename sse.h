#include <xmmintrin.h>
#include <mmintrin.h>
#include <smmintrin.h>

#define BLEND(a,b,c,d) d<<3|c<<2|b<<1|a
#define SHUFFLE(a,b,c,d) d<<6|c<<4|b<<2|a

#define min _mm_min_ps
#define max _mm_max_ps
#define shuffle _mm_shuffle_ps
#define blend _mm_blend_ps
#define load _mm_load_ps
#define store _mm_store_ps
#define unpacklo _mm_unpacklo_ps
#define unpackhi _mm_unpackhi_ps
#define movelh _mm_movelh_ps
#define movehl _mm_movehl_ps
#define lessthan _mm_comilt_ss
#define transpose _MM_TRANSPOSE4_PS
