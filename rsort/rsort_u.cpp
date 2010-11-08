// Copyright 2007, Tim Furtak
// Distributed under the GNU Lesser General Public License

#include "rsort_u.h"

void rsort_u_1 (float* first) {

__m128 xmm0 = _mm_loadu_ps(first + 0 * 4);
__m128 xmm1;
__m128 xmm2;
__m128 xmm3;
   	xmm1 = _mm_movelh_ps(xmm1, xmm0);
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm0);
  xmm0 = _mm_max_ps(xmm0, t);
};
   	xmm0 = _mm_movehl_ps(xmm0, xmm1);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm0, 136);
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm0);
  xmm0 = _mm_max_ps(xmm0, t);
};
   	xmm2 = _mm_movelh_ps(xmm2, xmm0);
   	xmm3 = _mm_unpackhi_ps(xmm3, xmm1);
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm1 = _mm_shuffle_ps(xmm1, xmm2, 49);
   	xmm0 = _mm_movehl_ps(xmm0, xmm3);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm0, 216);
   _mm_storeu_ps(first + 0 * 4, xmm1);
}

void rsort_u_2 (float* first) {

__m128 xmm0 = _mm_loadu_ps(first + 0 * 4);
__m128 xmm1 = _mm_loadu_ps(first + 1 * 4);
__m128 xmm2;
__m128 xmm3;
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm1);
  xmm1 = _mm_max_ps(xmm1, t);
};
   	xmm2 = _mm_movelh_ps(xmm2, xmm0);
   	xmm0 = _mm_movehl_ps(xmm0, xmm1);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm2, 228);
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm0);
  xmm0 = _mm_max_ps(xmm0, t);
};
   	xmm2 = _mm_movehl_ps(xmm2, xmm0);
   	xmm3 = xmm1;
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm1 = _mm_shuffle_ps(xmm1, xmm3, 27);
   	xmm0 = _mm_movelh_ps(xmm0, xmm2);
   	xmm2 = _mm_movelh_ps(xmm2, xmm0);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm1, 39);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm1, 120);
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm0);
  xmm0 = _mm_max_ps(xmm0, t);
};
   	xmm1 = xmm0;
   	xmm0 = _mm_shuffle_ps(xmm0, xmm2, 54);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm2, 129);
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   	xmm2 = _mm_shuffle_ps(xmm2, xmm0, 51);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm0, 3);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm1, 9);
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm1, 38);
   	xmm1 = _mm_movelh_ps(xmm1, xmm2);
   	xmm2 = _mm_movehl_ps(xmm2, xmm0);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm0, 22);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm2, 72);
   _mm_storeu_ps(first + 0 * 4, xmm0);
   	xmm2 = _mm_movehl_ps(xmm2, xmm1);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm2, 150);
   _mm_storeu_ps(first + 1 * 4, xmm1);
}

void rsort_u_3 (float* first) {

__m128 xmm0 = _mm_loadu_ps(first + 0 * 4);
__m128 xmm2 = _mm_loadu_ps(first + 2 * 4);
__m128 xmm1 = _mm_loadu_ps(first + 1 * 4);
__m128 xmm3;
__m128 xmm4;
__m128 xmm5;
__m128 xmm6;
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm1);
  xmm1 = _mm_max_ps(xmm1, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   	xmm3 = _mm_movelh_ps(xmm3, xmm0);
   	xmm0 = _mm_movehl_ps(xmm0, xmm1);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm3, 228);
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm0);
  xmm0 = _mm_max_ps(xmm0, t);
};
   	xmm3 = _mm_movelh_ps(xmm3, xmm2);
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   	xmm4 = xmm0;
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm3 = _mm_shuffle_ps(xmm3, xmm1, 27);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm4, 177);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm1 = _mm_movehl_ps(xmm1, xmm3);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm0, 123);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm1, 50);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm1, 96);
   	xmm1 = _mm_movehl_ps(xmm1, xmm2);
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm0);
  xmm0 = _mm_max_ps(xmm0, t);
};
   	xmm2 = _mm_movelh_ps(xmm2, xmm3);
   	xmm3 = _mm_movelh_ps(xmm3, xmm2);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm2, 51);
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   	xmm4 = xmm0;
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm3 = _mm_shuffle_ps(xmm3, xmm1, 114);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm4, 39);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm1 = _mm_shuffle_ps(xmm1, xmm3, 98);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm1, 147);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm4 = _mm_movehl_ps(xmm4, xmm1);
   	xmm5 = _mm_unpackhi_ps(xmm5, xmm2);
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   	xmm1 = _mm_shuffle_ps(xmm1, xmm0, 32);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm3, 39);
   	xmm6 = xmm0;
   	xmm0 = _mm_movehl_ps(xmm0, xmm1);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm6, 40);
   _mm_storeu_ps(first + 0 * 4, xmm1);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm3, 49);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm6, 114);
   _mm_storeu_ps(first + 1 * 4, xmm0);
   	xmm3 = _mm_movelh_ps(xmm3, xmm5);
   	xmm2 = _mm_movelh_ps(xmm2, xmm4);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm2, 61);
   _mm_storeu_ps(first + 2 * 4, xmm3);
}

void rsort_u_4 (float* first) {

__m128 xmm0 = _mm_loadu_ps(first + 0 * 4);
__m128 xmm2 = _mm_loadu_ps(first + 2 * 4);
__m128 xmm1 = _mm_loadu_ps(first + 1 * 4);
__m128 xmm3 = _mm_loadu_ps(first + 3 * 4);
__m128 xmm4;
__m128 xmm5;
__m128 xmm6;
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm1);
  xmm1 = _mm_max_ps(xmm1, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   	xmm4 = _mm_movelh_ps(xmm4, xmm0);
   	xmm0 = _mm_movehl_ps(xmm0, xmm1);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm4, 228);
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm0);
  xmm0 = _mm_max_ps(xmm0, t);
};
   	xmm4 = _mm_movelh_ps(xmm4, xmm2);
   	xmm2 = _mm_movehl_ps(xmm2, xmm3);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm4, 228);
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm4 = _mm_movelh_ps(xmm4, xmm1);
   	xmm4 = _mm_movehl_ps(xmm4, xmm3);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   	xmm5 = _mm_movehl_ps(xmm5, xmm2);
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm1 = _mm_movehl_ps(xmm1, xmm4);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm0, 33);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm1, 119);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm1, 32);
   	xmm1 = _mm_movehl_ps(xmm1, xmm2);
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm0);
  xmm0 = _mm_max_ps(xmm0, t);
};
   	xmm4 = _mm_movelh_ps(xmm4, xmm5);
   	xmm2 = _mm_movelh_ps(xmm2, xmm3);
   	xmm3 = _mm_movelh_ps(xmm3, xmm2);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm4, 115);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm4, 44);
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm0, 135);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm4 = _mm_movelh_ps(xmm4, xmm3);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm1, 219);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm5 = _mm_shuffle_ps(xmm5, xmm2, 176);
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   	xmm1 = _mm_shuffle_ps(xmm1, xmm3, 114);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm1, 98);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm4 = _mm_movehl_ps(xmm4, xmm1);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm5, 49);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm2, 104);
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   	xmm1 = _mm_shuffle_ps(xmm1, xmm0, 48);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm3, 54);
   	xmm6 = xmm0;
   	xmm0 = _mm_movehl_ps(xmm0, xmm1);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm6, 40);
   _mm_storeu_ps(first + 0 * 4, xmm1);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm3, 33);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm6, 114);
   _mm_storeu_ps(first + 1 * 4, xmm0);
   	xmm3 = _mm_movelh_ps(xmm3, xmm5);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm4, 176);
   	xmm4 = _mm_shuffle_ps(xmm4, xmm5, 33);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm4, 141);
   _mm_storeu_ps(first + 2 * 4, xmm3);
   	xmm5 = _mm_movehl_ps(xmm5, xmm2);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm2, 45);
   _mm_storeu_ps(first + 3 * 4, xmm5);
}

void rsort_u_5 (float* first) {

__m128 xmm0 = _mm_loadu_ps(first + 0 * 4);
__m128 xmm4 = _mm_loadu_ps(first + 4 * 4);
__m128 xmm2 = _mm_loadu_ps(first + 2 * 4);
__m128 xmm3 = _mm_loadu_ps(first + 3 * 4);
__m128 xmm1 = _mm_loadu_ps(first + 1 * 4);
__m128 xmm5;
__m128 xmm6;
__m128 xmm7;
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm1);
  xmm1 = _mm_max_ps(xmm1, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   	xmm5 = _mm_movelh_ps(xmm5, xmm0);
   	xmm0 = _mm_movehl_ps(xmm0, xmm1);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm5, 228);
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm0);
  xmm0 = _mm_max_ps(xmm0, t);
};
   	xmm5 = _mm_movelh_ps(xmm5, xmm2);
   	xmm2 = _mm_movehl_ps(xmm2, xmm3);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm5, 228);
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   	xmm5 = _mm_movelh_ps(xmm5, xmm4);
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   	xmm6 = xmm0;
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm6, 228);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm6 = xmm2;
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   	xmm2 = _mm_movelh_ps(xmm2, xmm3);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm1, 78);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm5 = _mm_movehl_ps(xmm5, xmm2);
   	xmm6 = _mm_shuffle_ps(xmm6, xmm2, 78);
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   	xmm1 = _mm_movehl_ps(xmm1, xmm3);
   	xmm2 = xmm0;
   	xmm0 = _mm_shuffle_ps(xmm0, xmm1, 119);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm1, 34);
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm0);
  xmm0 = _mm_max_ps(xmm0, t);
};
   	xmm3 = _mm_movelh_ps(xmm3, xmm6);
   	xmm6 = _mm_shuffle_ps(xmm6, xmm5, 27);
   	xmm1 = xmm3;
   	xmm1 = _mm_shuffle_ps(xmm1, xmm6, 39);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm6, 114);
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm1);
  xmm1 = _mm_max_ps(xmm1, t);
};
   	xmm4 = _mm_movehl_ps(xmm4, xmm5);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm4, 136);
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm0, 27);
   	xmm6 = xmm0;
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   	xmm6 = _mm_shuffle_ps(xmm6, xmm0, 135);
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm0 = _mm_movelh_ps(xmm0, xmm1);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm0, 140);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm2, 39);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm3, 29);
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   	xmm1 = _mm_shuffle_ps(xmm1, xmm0, 27);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm3, 231);
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   	xmm0 = _mm_movehl_ps(xmm0, xmm2);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm0, 49);
   	xmm6 = _mm_shuffle_ps(xmm6, xmm6, 216);
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm5, 38);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm0, 157);
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   	xmm3 = _mm_movehl_ps(xmm3, xmm0);
   	xmm7 = xmm4;
   
{ __m128 t = xmm7;
  xmm7 = _mm_min_ps(xmm7, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm6, 32);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm6, 113);
   	xmm6 = _mm_shuffle_ps(xmm6, xmm2, 32);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm6, 40);
   _mm_storeu_ps(first + 0 * 4, xmm0);
   	xmm6 = _mm_movehl_ps(xmm6, xmm3);
   	xmm0 = _mm_movelh_ps(xmm0, xmm2);
   	xmm0 = _mm_movehl_ps(xmm0, xmm3);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm0, 54);
   _mm_storeu_ps(first + 1 * 4, xmm0);
   	xmm2 = _mm_movehl_ps(xmm2, xmm1);
   	xmm0 = _mm_movelh_ps(xmm0, xmm1);
   	xmm1 = _mm_movehl_ps(xmm1, xmm5);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm1, 195);
   _mm_storeu_ps(first + 2 * 4, xmm2);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm5, 123);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm0, 114);
   _mm_storeu_ps(first + 3 * 4, xmm0);
   	xmm5 = _mm_movelh_ps(xmm5, xmm7);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm4, 48);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm3, 140);
   _mm_storeu_ps(first + 4 * 4, xmm5);
}

void rsort_u_6 (float* first) {

__m128 xmm0 = _mm_loadu_ps(first + 0 * 4);
__m128 xmm4 = _mm_loadu_ps(first + 4 * 4);
__m128 xmm1 = _mm_loadu_ps(first + 1 * 4);
__m128 xmm5 = _mm_loadu_ps(first + 5 * 4);
__m128 xmm2 = _mm_loadu_ps(first + 2 * 4);
__m128 xmm3 = _mm_loadu_ps(first + 3 * 4);
__m128 xmm6;
__m128 xmm7;
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm1);
  xmm1 = _mm_max_ps(xmm1, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   	xmm6 = _mm_movelh_ps(xmm6, xmm0);
   	xmm0 = _mm_movehl_ps(xmm0, xmm1);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm6, 228);
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm0);
  xmm0 = _mm_max_ps(xmm0, t);
};
   	xmm6 = _mm_movelh_ps(xmm6, xmm2);
   	xmm2 = _mm_movehl_ps(xmm2, xmm3);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm6, 228);
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   	xmm6 = _mm_movelh_ps(xmm6, xmm4);
   	xmm4 = _mm_movehl_ps(xmm4, xmm5);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm6, 228);
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   	xmm6 = _mm_movelh_ps(xmm6, xmm1);
   	xmm6 = _mm_movehl_ps(xmm6, xmm3);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   	xmm3 = _mm_shuffle_ps(xmm3, xmm5, 177);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm2, 27);
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm7 = _mm_movehl_ps(xmm7, xmm4);
   
{ __m128 t = xmm7;
  xmm7 = _mm_min_ps(xmm7, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   	xmm1 = _mm_movehl_ps(xmm1, xmm6);
   	xmm4 = _mm_shuffle_ps(xmm4, xmm0, 33);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm1, 119);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm1, 32);
   	xmm1 = _mm_movehl_ps(xmm1, xmm4);
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm0);
  xmm0 = _mm_max_ps(xmm0, t);
};
   	xmm6 = _mm_movelh_ps(xmm6, xmm3);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm2, 123);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm6, 98);
   	xmm4 = _mm_movelh_ps(xmm4, xmm3);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm6, 62);
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   	xmm5 = _mm_movelh_ps(xmm5, xmm7);
   	xmm6 = xmm4;
   	xmm4 = _mm_shuffle_ps(xmm4, xmm5, 115);
   	xmm6 = _mm_shuffle_ps(xmm6, xmm5, 38);
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm0, 198);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm0, 57);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm2 = _mm_shuffle_ps(xmm2, xmm2, 147);
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   	xmm5 = _mm_movelh_ps(xmm5, xmm0);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm3, 123);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm1, 33);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm3, 119);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm0, 27);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm5, 114);
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm1);
  xmm1 = _mm_max_ps(xmm1, t);
};
   	xmm3 = _mm_shuffle_ps(xmm3, xmm6, 34);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm2, 216);
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm4, 43);
   	xmm7 = _mm_unpackhi_ps(xmm7, xmm0);
   
{ __m128 t = xmm7;
  xmm7 = _mm_min_ps(xmm7, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm1, 49);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm0, 118);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm5, 27);
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm1);
  xmm1 = _mm_max_ps(xmm1, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm3, 34);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm0, 55);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm2, 30);
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm6 = _mm_shuffle_ps(xmm6, xmm0, 39);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm4, 55);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm7, 9);
   
{ __m128 t = xmm7;
  xmm7 = _mm_min_ps(xmm7, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm5, 49);
   	xmm4 = _mm_movelh_ps(xmm4, xmm5);
   	xmm5 = _mm_movehl_ps(xmm5, xmm1);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm5, 152);
   _mm_storeu_ps(first + 0 * 4, xmm0);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm4, 48);
   	xmm0 = _mm_movelh_ps(xmm0, xmm1);
   	xmm0 = _mm_movehl_ps(xmm0, xmm4);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm0, 56);
   _mm_storeu_ps(first + 1 * 4, xmm5);
   	xmm0 = _mm_movehl_ps(xmm0, xmm2);
   	xmm1 = _mm_movelh_ps(xmm1, xmm0);
   	xmm1 = _mm_movehl_ps(xmm1, xmm3);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm1, 150);
   _mm_storeu_ps(first + 2 * 4, xmm0);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm3, 97);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm2, 114);
   _mm_storeu_ps(first + 3 * 4, xmm2);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm7, 32);
   	xmm4 = _mm_movelh_ps(xmm4, xmm6);
   	xmm6 = _mm_movehl_ps(xmm6, xmm3);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm6, 104);
   _mm_storeu_ps(first + 4 * 4, xmm3);
   	xmm7 = _mm_unpacklo_ps(xmm7, xmm4);
   	xmm4 = _mm_unpackhi_ps(xmm4, xmm7);
   _mm_storeu_ps(first + 5 * 4, xmm4);
}

void rsort_u_7 (float* first) {

__m128 xmm0 = _mm_loadu_ps(first + 0 * 4);
__m128 xmm4 = _mm_loadu_ps(first + 4 * 4);
__m128 xmm1 = _mm_loadu_ps(first + 1 * 4);
__m128 xmm5 = _mm_loadu_ps(first + 5 * 4);
__m128 xmm2 = _mm_loadu_ps(first + 2 * 4);
__m128 xmm6 = _mm_loadu_ps(first + 6 * 4);
__m128 xmm3 = _mm_loadu_ps(first + 3 * 4);
__m128 xmm7;
__m128 xmm8;
__m128 xmm9;
__m128 xmm10;
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm1);
  xmm1 = _mm_max_ps(xmm1, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   	xmm7 = _mm_movelh_ps(xmm7, xmm0);
   	xmm0 = _mm_movehl_ps(xmm0, xmm1);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm7, 228);
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm0);
  xmm0 = _mm_max_ps(xmm0, t);
};
   	xmm7 = _mm_movelh_ps(xmm7, xmm2);
   	xmm2 = _mm_movehl_ps(xmm2, xmm3);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm7, 228);
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   	xmm7 = _mm_movelh_ps(xmm7, xmm4);
   	xmm4 = _mm_movehl_ps(xmm4, xmm5);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm7, 228);
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   	xmm7 = _mm_movelh_ps(xmm7, xmm6);
   
{ __m128 t = xmm7;
  xmm7 = _mm_min_ps(xmm7, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   	xmm8 = xmm2;
   
{ __m128 t = xmm8;
  xmm8 = _mm_min_ps(xmm8, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm2 = _mm_shuffle_ps(xmm2, xmm8, 228);
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   	xmm8 = xmm4;
   
{ __m128 t = xmm8;
  xmm8 = _mm_min_ps(xmm8, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   	xmm4 = _mm_movelh_ps(xmm4, xmm3);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm1, 78);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm1 = _mm_shuffle_ps(xmm1, xmm4, 27);
   	xmm4 = _mm_movehl_ps(xmm4, xmm5);
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   	xmm5 = _mm_shuffle_ps(xmm5, xmm7, 177);
   	xmm8 = _mm_shuffle_ps(xmm8, xmm1, 235);
   
{ __m128 t = xmm8;
  xmm8 = _mm_min_ps(xmm8, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   	xmm1 = _mm_shuffle_ps(xmm1, xmm3, 49);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm0, 38);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm1, 103);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm3, 19);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm1, 126);
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm0);
  xmm0 = _mm_max_ps(xmm0, t);
};
   	xmm1 = _mm_shuffle_ps(xmm1, xmm4, 50);
   	xmm4 = _mm_shuffle_ps(xmm4, xmm1, 118);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm2, 114);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm4, 50);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm2, 75);
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm1);
  xmm1 = _mm_max_ps(xmm1, t);
};
   	xmm4 = _mm_shuffle_ps(xmm4, xmm5, 22);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm4, 123);
   	xmm4 = _mm_shuffle_ps(xmm4, xmm8, 114);
   	xmm6 = _mm_shuffle_ps(xmm6, xmm5, 27);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm8, 46);
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   	xmm7 = _mm_movelh_ps(xmm7, xmm6);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm6, 51);
   
{ __m128 t = xmm7;
  xmm7 = _mm_min_ps(xmm7, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm0, 30);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   	xmm1 = _mm_shuffle_ps(xmm1, xmm1, 30);
   	xmm8 = xmm1;
   
{ __m128 t = xmm8;
  xmm8 = _mm_min_ps(xmm8, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm0, 180);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   	xmm1 = _mm_shuffle_ps(xmm1, xmm8, 39);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm1, 216);
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   	xmm5 = _mm_shuffle_ps(xmm5, xmm5, 27);
   	xmm8 = xmm5;
   
{ __m128 t = xmm8;
  xmm8 = _mm_min_ps(xmm8, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   	xmm5 = _mm_shuffle_ps(xmm5, xmm2, 55);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm3, 102);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm0, 147);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   	xmm3 = _mm_shuffle_ps(xmm3, xmm4, 35);
   	xmm4 = _mm_shuffle_ps(xmm4, xmm5, 183);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm1, 210);
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   	xmm7 = _mm_shuffle_ps(xmm7, xmm3, 178);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm8, 36);
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   	xmm3 = _mm_shuffle_ps(xmm3, xmm2, 33);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm3, 141);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   	xmm3 = _mm_shuffle_ps(xmm3, xmm4, 39);
   	xmm4 = _mm_shuffle_ps(xmm4, xmm3, 141);
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   	xmm3 = _mm_shuffle_ps(xmm3, xmm7, 103);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm3, 131);
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   	xmm8 = _mm_movehl_ps(xmm8, xmm3);
   	xmm9 = _mm_unpackhi_ps(xmm9, xmm6);
   
{ __m128 t = xmm9;
  xmm9 = _mm_min_ps(xmm9, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   	xmm3 = _mm_shuffle_ps(xmm3, xmm0, 33);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm2, 39);
   	xmm10 = xmm0;
   	xmm0 = _mm_movehl_ps(xmm0, xmm3);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm10, 40);
   _mm_storeu_ps(first + 0 * 4, xmm3);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm10, 23);
   	xmm0 = _mm_movelh_ps(xmm0, xmm2);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm0, 120);
   _mm_storeu_ps(first + 1 * 4, xmm2);
   	xmm10 = _mm_movehl_ps(xmm10, xmm1);
   	xmm0 = _mm_movelh_ps(xmm0, xmm1);
   	xmm1 = _mm_movehl_ps(xmm1, xmm4);
   	xmm10 = _mm_shuffle_ps(xmm10, xmm1, 195);
   _mm_storeu_ps(first + 2 * 4, xmm10);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm4, 123);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm0, 114);
   _mm_storeu_ps(first + 3 * 4, xmm0);
   	xmm4 = _mm_shuffle_ps(xmm4, xmm5, 32);
   	xmm6 = _mm_movelh_ps(xmm6, xmm5);
   	xmm5 = _mm_movehl_ps(xmm5, xmm7);
   	xmm4 = _mm_shuffle_ps(xmm4, xmm5, 200);
   _mm_storeu_ps(first + 4 * 4, xmm4);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm7, 48);
   	xmm0 = _mm_unpackhi_ps(xmm0, xmm6);
   _mm_storeu_ps(first + 5 * 4, xmm0);
   	xmm7 = _mm_movelh_ps(xmm7, xmm9);
   	xmm6 = _mm_movelh_ps(xmm6, xmm8);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm6, 61);
   _mm_storeu_ps(first + 6 * 4, xmm7);
}

void rsort_u_8 (float* first) {

__m128 xmm0 = _mm_loadu_ps(first + 0 * 4);
__m128 xmm4 = _mm_loadu_ps(first + 4 * 4);
__m128 xmm1 = _mm_loadu_ps(first + 1 * 4);
__m128 xmm5 = _mm_loadu_ps(first + 5 * 4);
__m128 xmm2 = _mm_loadu_ps(first + 2 * 4);
__m128 xmm6 = _mm_loadu_ps(first + 6 * 4);
__m128 xmm3 = _mm_loadu_ps(first + 3 * 4);
__m128 xmm7 = _mm_loadu_ps(first + 7 * 4);
__m128 xmm8;
__m128 xmm9;
__m128 xmm10;
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm1);
  xmm1 = _mm_max_ps(xmm1, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   	xmm8 = _mm_movelh_ps(xmm8, xmm0);
   	xmm0 = _mm_movehl_ps(xmm0, xmm1);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm8, 228);
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm0);
  xmm0 = _mm_max_ps(xmm0, t);
};
   	xmm8 = _mm_movelh_ps(xmm8, xmm2);
   	xmm2 = _mm_movehl_ps(xmm2, xmm3);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm8, 228);
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   	xmm8 = _mm_movelh_ps(xmm8, xmm4);
   	xmm4 = _mm_movehl_ps(xmm4, xmm5);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm8, 228);
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   	xmm8 = _mm_movelh_ps(xmm8, xmm6);
   	xmm6 = _mm_movehl_ps(xmm6, xmm7);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm8, 228);
   
{ __m128 t = xmm7;
  xmm7 = _mm_min_ps(xmm7, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   	xmm8 = _mm_movelh_ps(xmm8, xmm1);
   	xmm8 = _mm_movehl_ps(xmm8, xmm3);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   	xmm3 = _mm_shuffle_ps(xmm3, xmm5, 177);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm2, 27);
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm5 = _mm_shuffle_ps(xmm5, xmm7, 177);
   	xmm4 = _mm_shuffle_ps(xmm4, xmm4, 27);
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   	xmm9 = _mm_movehl_ps(xmm9, xmm6);
   
{ __m128 t = xmm9;
  xmm9 = _mm_min_ps(xmm9, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   	xmm1 = _mm_movehl_ps(xmm1, xmm8);
   	xmm6 = _mm_shuffle_ps(xmm6, xmm0, 33);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm1, 119);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm1, 32);
   	xmm1 = _mm_movehl_ps(xmm1, xmm6);
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm0);
  xmm0 = _mm_max_ps(xmm0, t);
};
   	xmm8 = _mm_movelh_ps(xmm8, xmm3);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm2, 123);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm8, 98);
   	xmm6 = _mm_movelh_ps(xmm6, xmm3);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm8, 62);
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   	xmm7 = _mm_shuffle_ps(xmm7, xmm5, 177);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm6, 49);
   	xmm6 = _mm_shuffle_ps(xmm6, xmm4, 118);
   	xmm4 = _mm_shuffle_ps(xmm4, xmm5, 98);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm6, 19);
   	xmm6 = _mm_shuffle_ps(xmm6, xmm5, 126);
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   	xmm9 = _mm_shuffle_ps(xmm9, xmm7, 49);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm7, 2);
   	xmm5 = _mm_movelh_ps(xmm5, xmm9);
   	xmm9 = _mm_shuffle_ps(xmm9, xmm5, 107);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm5, 57);
   
{ __m128 t = xmm7;
  xmm7 = _mm_min_ps(xmm7, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm0, 225);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   	xmm2 = _mm_shuffle_ps(xmm2, xmm2, 30);
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm0, 180);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm2 = _mm_shuffle_ps(xmm2, xmm2, 27);
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   	xmm4 = _mm_shuffle_ps(xmm4, xmm4, 27);
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   	xmm5 = _mm_movelh_ps(xmm5, xmm0);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm3, 123);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm1, 33);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm3, 119);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm0, 27);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm5, 114);
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm1);
  xmm1 = _mm_max_ps(xmm1, t);
};
   	xmm3 = _mm_shuffle_ps(xmm3, xmm6, 98);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm2, 54);
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm6 = _mm_shuffle_ps(xmm6, xmm7, 99);
   	xmm4 = _mm_shuffle_ps(xmm4, xmm4, 57);
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm9, 59);
   	xmm9 = _mm_shuffle_ps(xmm9, xmm9, 129);
   
{ __m128 t = xmm9;
  xmm9 = _mm_min_ps(xmm9, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   	xmm8 = _mm_movelh_ps(xmm8, xmm0);
   	xmm8 = _mm_movehl_ps(xmm8, xmm1);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm8, 33);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm5, 198);
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm1);
  xmm1 = _mm_max_ps(xmm1, t);
};
   	xmm8 = _mm_movelh_ps(xmm8, xmm3);
   	xmm8 = _mm_shuffle_ps(xmm8, xmm3, 153);
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   	xmm3 = _mm_shuffle_ps(xmm3, xmm6, 3);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm6, 120);
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm6 = _mm_shuffle_ps(xmm6, xmm7, 2);
   
{ __m128 t = xmm9;
  xmm9 = _mm_min_ps(xmm9, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   	xmm10 = _mm_unpackhi_ps(xmm10, xmm0);
   
{ __m128 t = xmm10;
  xmm10 = _mm_min_ps(xmm10, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm5, 38);
   	xmm6 = _mm_shuffle_ps(xmm6, xmm5, 51);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm1, 33);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm0, 7);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm5, 41);
   _mm_storeu_ps(first + 0 * 4, xmm0);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm1, 23);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm6, 18);
   	xmm6 = _mm_shuffle_ps(xmm6, xmm5, 2);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm6, 38);
   _mm_storeu_ps(first + 1 * 4, xmm5);
   	xmm0 = _mm_movelh_ps(xmm0, xmm1);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm2, 3);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm2, 178);
   	xmm2 = _mm_movelh_ps(xmm2, xmm8);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm2, 104);
   _mm_storeu_ps(first + 2 * 4, xmm0);
   	xmm2 = _mm_movehl_ps(xmm2, xmm1);
   	xmm0 = _mm_movelh_ps(xmm0, xmm1);
   	xmm1 = _mm_movehl_ps(xmm1, xmm8);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm1, 135);
   _mm_storeu_ps(first + 3 * 4, xmm2);
   	xmm1 = _mm_movelh_ps(xmm1, xmm4);
   	xmm0 = _mm_movehl_ps(xmm0, xmm4);
   	xmm4 = _mm_movelh_ps(xmm4, xmm3);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm4, 105);
   _mm_storeu_ps(first + 4 * 4, xmm1);
   	xmm4 = _mm_shuffle_ps(xmm4, xmm0, 19);
   	xmm0 = _mm_movehl_ps(xmm0, xmm3);
   	xmm3 = _mm_movehl_ps(xmm3, xmm4);
   	xmm4 = _mm_shuffle_ps(xmm4, xmm3, 120);
   _mm_storeu_ps(first + 5 * 4, xmm4);
   	xmm9 = _mm_shuffle_ps(xmm9, xmm0, 35);
   	xmm9 = _mm_shuffle_ps(xmm9, xmm9, 39);
   _mm_storeu_ps(first + 6 * 4, xmm9);
   	xmm6 = _mm_shuffle_ps(xmm6, xmm10, 49);
   	xmm0 = _mm_movehl_ps(xmm0, xmm7);
   	xmm6 = _mm_shuffle_ps(xmm6, xmm0, 216);
   _mm_storeu_ps(first + 7 * 4, xmm6);
}

void rsort_u_9 (float* first) {

__m128 xmm0 = _mm_loadu_ps(first + 0 * 4);
__m128 xmm8 = _mm_loadu_ps(first + 8 * 4);
__m128 xmm4 = _mm_loadu_ps(first + 4 * 4);
__m128 xmm5 = _mm_loadu_ps(first + 5 * 4);
__m128 xmm1 = _mm_loadu_ps(first + 1 * 4);
__m128 xmm6 = _mm_loadu_ps(first + 6 * 4);
__m128 xmm2 = _mm_loadu_ps(first + 2 * 4);
__m128 xmm7 = _mm_loadu_ps(first + 7 * 4);
__m128 xmm3 = _mm_loadu_ps(first + 3 * 4);
__m128 xmm9;
__m128 xmm10;
__m128 xmm11;
__m128 xmm12;
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm1);
  xmm1 = _mm_max_ps(xmm1, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   
{ __m128 t = xmm7;
  xmm7 = _mm_min_ps(xmm7, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   	xmm9 = _mm_movelh_ps(xmm9, xmm0);
   	xmm0 = _mm_movehl_ps(xmm0, xmm1);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm9, 228);
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm0);
  xmm0 = _mm_max_ps(xmm0, t);
};
   	xmm9 = _mm_movelh_ps(xmm9, xmm2);
   	xmm2 = _mm_movehl_ps(xmm2, xmm3);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm9, 228);
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   	xmm9 = _mm_movelh_ps(xmm9, xmm4);
   	xmm4 = _mm_movehl_ps(xmm4, xmm5);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm9, 228);
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   	xmm9 = _mm_movelh_ps(xmm9, xmm6);
   	xmm6 = _mm_movehl_ps(xmm6, xmm7);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm9, 228);
   
{ __m128 t = xmm7;
  xmm7 = _mm_min_ps(xmm7, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   	xmm9 = _mm_movelh_ps(xmm9, xmm8);
   
{ __m128 t = xmm9;
  xmm9 = _mm_min_ps(xmm9, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   	xmm10 = xmm0;
   
{ __m128 t = xmm10;
  xmm10 = _mm_min_ps(xmm10, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm10, 228);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   	xmm10 = xmm4;
   
{ __m128 t = xmm10;
  xmm10 = _mm_min_ps(xmm10, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   	xmm4 = _mm_shuffle_ps(xmm4, xmm10, 228);
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   	xmm10 = xmm6;
   
{ __m128 t = xmm10;
  xmm10 = _mm_min_ps(xmm10, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   	xmm6 = _mm_movelh_ps(xmm6, xmm3);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm1, 78);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm1 = _mm_shuffle_ps(xmm1, xmm5, 27);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm6, 238);
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   	xmm6 = _mm_movelh_ps(xmm6, xmm7);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm1, 190);
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   	xmm9 = _mm_movehl_ps(xmm9, xmm6);
   	xmm10 = _mm_shuffle_ps(xmm10, xmm6, 78);
   
{ __m128 t = xmm10;
  xmm10 = _mm_min_ps(xmm10, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   	xmm1 = _mm_shuffle_ps(xmm1, xmm3, 49);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm0, 38);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm1, 103);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm3, 19);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm1, 126);
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm0);
  xmm0 = _mm_max_ps(xmm0, t);
};
   	xmm1 = _mm_shuffle_ps(xmm1, xmm5, 50);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm1, 118);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm2, 114);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm5, 50);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm2, 75);
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm1);
  xmm1 = _mm_max_ps(xmm1, t);
};
   	xmm5 = _mm_shuffle_ps(xmm5, xmm7, 54);
   	xmm6 = xmm4;
   	xmm4 = _mm_shuffle_ps(xmm4, xmm5, 103);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm7, 32);
   	xmm6 = _mm_shuffle_ps(xmm6, xmm5, 34);
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   	xmm7 = _mm_movelh_ps(xmm7, xmm9);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm10, 119);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm9, 3);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm10, 34);
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   	xmm8 = _mm_movehl_ps(xmm8, xmm9);
   	xmm9 = _mm_shuffle_ps(xmm9, xmm8, 136);
   
{ __m128 t = xmm9;
  xmm9 = _mm_min_ps(xmm9, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm0, 30);
   	xmm10 = xmm0;
   
{ __m128 t = xmm10;
  xmm10 = _mm_min_ps(xmm10, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm10, 114);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm0, 210);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   	xmm1 = _mm_shuffle_ps(xmm1, xmm1, 180);
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   	xmm4 = _mm_shuffle_ps(xmm4, xmm4, 30);
   	xmm10 = xmm4;
   
{ __m128 t = xmm10;
  xmm10 = _mm_min_ps(xmm10, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm0, 78);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   	xmm1 = _mm_shuffle_ps(xmm1, xmm1, 75);
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   	xmm4 = _mm_shuffle_ps(xmm4, xmm10, 114);
   	xmm4 = _mm_shuffle_ps(xmm4, xmm4, 141);
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   	xmm10 = xmm7;
   
{ __m128 t = xmm10;
  xmm10 = _mm_min_ps(xmm10, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   	xmm7 = _mm_shuffle_ps(xmm7, xmm2, 50);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm3, 102);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm0, 147);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   	xmm3 = _mm_shuffle_ps(xmm3, xmm6, 99);
   	xmm6 = _mm_shuffle_ps(xmm6, xmm7, 179);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm1, 54);
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   	xmm11 = _mm_shuffle_ps(xmm11, xmm5, 208);
   	xmm11 = _mm_unpackhi_ps(xmm11, xmm3);
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm11);
  xmm11 = _mm_max_ps(xmm11, t);
};
   	xmm5 = _mm_shuffle_ps(xmm5, xmm9, 114);
   	xmm10 = _mm_shuffle_ps(xmm10, xmm7, 71);
   
{ __m128 t = xmm10;
  xmm10 = _mm_min_ps(xmm10, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   	xmm3 = _mm_shuffle_ps(xmm3, xmm2, 33);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm3, 141);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   	xmm3 = _mm_shuffle_ps(xmm3, xmm6, 103);
   	xmm6 = _mm_shuffle_ps(xmm6, xmm3, 131);
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   	xmm3 = _mm_shuffle_ps(xmm3, xmm11, 39);
   	xmm11 = _mm_shuffle_ps(xmm11, xmm3, 55);
   	xmm4 = _mm_shuffle_ps(xmm4, xmm4, 108);
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm11);
  xmm11 = _mm_max_ps(xmm11, t);
};
   	xmm3 = _mm_shuffle_ps(xmm3, xmm5, 38);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm3, 55);
   	xmm10 = _mm_shuffle_ps(xmm10, xmm10, 114);
   
{ __m128 t = xmm10;
  xmm10 = _mm_min_ps(xmm10, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   	xmm7 = _mm_movehl_ps(xmm7, xmm3);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm8, 17);
   	xmm9 = _mm_movehl_ps(xmm9, xmm3);
   
{ __m128 t = xmm9;
  xmm9 = _mm_min_ps(xmm9, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   	xmm3 = _mm_shuffle_ps(xmm3, xmm0, 32);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm2, 39);
   	xmm12 = xmm0;
   	xmm0 = _mm_movehl_ps(xmm0, xmm3);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm12, 40);
   _mm_storeu_ps(first + 0 * 4, xmm3);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm12, 23);
   	xmm0 = _mm_movelh_ps(xmm0, xmm2);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm0, 120);
   _mm_storeu_ps(first + 1 * 4, xmm2);
   	xmm12 = _mm_movehl_ps(xmm12, xmm1);
   	xmm0 = _mm_movelh_ps(xmm0, xmm1);
   	xmm1 = _mm_movehl_ps(xmm1, xmm6);
   	xmm12 = _mm_shuffle_ps(xmm12, xmm1, 195);
   _mm_storeu_ps(first + 2 * 4, xmm12);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm6, 59);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm0, 54);
   _mm_storeu_ps(first + 3 * 4, xmm0);
   	xmm6 = _mm_shuffle_ps(xmm6, xmm4, 49);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm4, 32);
   	xmm4 = _mm_shuffle_ps(xmm4, xmm11, 49);
   	xmm6 = _mm_shuffle_ps(xmm6, xmm4, 40);
   _mm_storeu_ps(first + 4 * 4, xmm6);
   	xmm4 = _mm_movelh_ps(xmm4, xmm11);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm11, 34);
   	xmm11 = _mm_movelh_ps(xmm11, xmm7);
   	xmm4 = _mm_shuffle_ps(xmm4, xmm7, 55);
   _mm_storeu_ps(first + 5 * 4, xmm4);
   	xmm7 = _mm_movehl_ps(xmm7, xmm10);
   	xmm8 = _mm_shuffle_ps(xmm8, xmm10, 3);
   	xmm10 = _mm_shuffle_ps(xmm10, xmm5, 49);
   	xmm0 = _mm_movelh_ps(xmm0, xmm7);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm10, 38);
   _mm_storeu_ps(first + 6 * 4, xmm7);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm5, 18);
   	xmm5 = _mm_movehl_ps(xmm5, xmm8);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm5, 34);
   _mm_storeu_ps(first + 7 * 4, xmm0);
   	xmm9 = _mm_shuffle_ps(xmm9, xmm10, 48);
   	xmm8 = _mm_shuffle_ps(xmm8, xmm11, 48);
   	xmm9 = _mm_shuffle_ps(xmm9, xmm8, 34);
   _mm_storeu_ps(first + 8 * 4, xmm9);
}

void rsort_u_10 (float* first) {

__m128 xmm0 = _mm_loadu_ps(first + 0 * 4);
__m128 xmm8 = _mm_loadu_ps(first + 8 * 4);
__m128 xmm1 = _mm_loadu_ps(first + 1 * 4);
__m128 xmm9 = _mm_loadu_ps(first + 9 * 4);
__m128 xmm4 = _mm_loadu_ps(first + 4 * 4);
__m128 xmm5 = _mm_loadu_ps(first + 5 * 4);
__m128 xmm2 = _mm_loadu_ps(first + 2 * 4);
__m128 xmm6 = _mm_loadu_ps(first + 6 * 4);
__m128 xmm3 = _mm_loadu_ps(first + 3 * 4);
__m128 xmm7 = _mm_loadu_ps(first + 7 * 4);
__m128 xmm10;
__m128 xmm11;
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   
{ __m128 t = xmm7;
  xmm7 = _mm_min_ps(xmm7, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm1);
  xmm1 = _mm_max_ps(xmm1, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   
{ __m128 t = xmm8;
  xmm8 = _mm_min_ps(xmm8, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   
{ __m128 t = xmm7;
  xmm7 = _mm_min_ps(xmm7, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   	xmm10 = _mm_movelh_ps(xmm10, xmm0);
   	xmm0 = _mm_movehl_ps(xmm0, xmm1);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm10, 228);
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm0);
  xmm0 = _mm_max_ps(xmm0, t);
};
   	xmm10 = _mm_movelh_ps(xmm10, xmm2);
   	xmm2 = _mm_movehl_ps(xmm2, xmm3);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm10, 228);
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   	xmm10 = _mm_movelh_ps(xmm10, xmm4);
   	xmm4 = _mm_movehl_ps(xmm4, xmm5);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm10, 228);
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   	xmm10 = _mm_movelh_ps(xmm10, xmm6);
   	xmm6 = _mm_movehl_ps(xmm6, xmm7);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm10, 228);
   
{ __m128 t = xmm7;
  xmm7 = _mm_min_ps(xmm7, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   	xmm10 = _mm_movelh_ps(xmm10, xmm8);
   	xmm8 = _mm_movehl_ps(xmm8, xmm9);
   	xmm9 = _mm_shuffle_ps(xmm9, xmm10, 228);
   
{ __m128 t = xmm9;
  xmm9 = _mm_min_ps(xmm9, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   	xmm10 = _mm_movelh_ps(xmm10, xmm1);
   	xmm10 = _mm_movehl_ps(xmm10, xmm3);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm10);
  xmm10 = _mm_max_ps(xmm10, t);
};
   	xmm3 = _mm_shuffle_ps(xmm3, xmm5, 177);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm2, 27);
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm5 = _mm_shuffle_ps(xmm5, xmm7, 177);
   	xmm4 = _mm_shuffle_ps(xmm4, xmm4, 27);
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   	xmm7 = _mm_shuffle_ps(xmm7, xmm9, 177);
   	xmm6 = _mm_shuffle_ps(xmm6, xmm6, 27);
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   	xmm11 = _mm_movehl_ps(xmm11, xmm8);
   
{ __m128 t = xmm11;
  xmm11 = _mm_min_ps(xmm11, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   	xmm1 = _mm_movehl_ps(xmm1, xmm10);
   	xmm8 = _mm_shuffle_ps(xmm8, xmm0, 33);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm1, 119);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm1, 32);
   	xmm1 = _mm_movehl_ps(xmm1, xmm8);
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm0);
  xmm0 = _mm_max_ps(xmm0, t);
};
   	xmm10 = _mm_movelh_ps(xmm10, xmm3);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm2, 123);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm10, 98);
   	xmm8 = _mm_movelh_ps(xmm8, xmm3);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm10, 62);
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   	xmm9 = _mm_shuffle_ps(xmm9, xmm5, 177);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm8, 49);
   	xmm8 = _mm_shuffle_ps(xmm8, xmm4, 118);
   	xmm4 = _mm_shuffle_ps(xmm4, xmm5, 98);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm8, 19);
   	xmm8 = _mm_shuffle_ps(xmm8, xmm5, 126);
   
{ __m128 t = xmm8;
  xmm8 = _mm_min_ps(xmm8, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   	xmm5 = _mm_shuffle_ps(xmm5, xmm7, 178);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm9, 49);
   	xmm9 = _mm_shuffle_ps(xmm9, xmm6, 118);
   	xmm6 = _mm_shuffle_ps(xmm6, xmm7, 98);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm9, 19);
   	xmm9 = _mm_shuffle_ps(xmm9, xmm7, 126);
   
{ __m128 t = xmm9;
  xmm9 = _mm_min_ps(xmm9, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   	xmm7 = _mm_shuffle_ps(xmm7, xmm11, 18);
   	xmm10 = xmm5;
   	xmm5 = _mm_shuffle_ps(xmm5, xmm7, 103);
   	xmm10 = _mm_shuffle_ps(xmm10, xmm7, 50);
   
{ __m128 t = xmm10;
  xmm10 = _mm_min_ps(xmm10, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm0, 198);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm10);
  xmm10 = _mm_max_ps(xmm10, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm0, 201);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   	xmm2 = _mm_shuffle_ps(xmm2, xmm2, 180);
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   	xmm4 = _mm_shuffle_ps(xmm4, xmm4, 210);
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm10);
  xmm10 = _mm_max_ps(xmm10, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm0, 180);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   	xmm4 = _mm_shuffle_ps(xmm4, xmm4, 201);
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   	xmm6 = _mm_shuffle_ps(xmm6, xmm6, 210);
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm10);
  xmm10 = _mm_max_ps(xmm10, t);
};
   	xmm7 = _mm_movelh_ps(xmm7, xmm0);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm3, 123);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm1, 33);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm3, 119);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm0, 27);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm7, 114);
   
{ __m128 t = xmm7;
  xmm7 = _mm_min_ps(xmm7, xmm1);
  xmm1 = _mm_max_ps(xmm1, t);
};
   	xmm3 = _mm_shuffle_ps(xmm3, xmm8, 98);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm2, 54);
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm8 = _mm_shuffle_ps(xmm8, xmm9, 99);
   	xmm4 = _mm_shuffle_ps(xmm4, xmm4, 54);
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   	xmm9 = _mm_shuffle_ps(xmm9, xmm10, 35);
   	xmm6 = _mm_shuffle_ps(xmm6, xmm6, 216);
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm5, 43);
   	xmm11 = _mm_unpackhi_ps(xmm11, xmm0);
   
{ __m128 t = xmm11;
  xmm11 = _mm_min_ps(xmm11, xmm10);
  xmm10 = _mm_max_ps(xmm10, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm1, 49);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm0, 118);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm7, 27);
   
{ __m128 t = xmm7;
  xmm7 = _mm_min_ps(xmm7, xmm1);
  xmm1 = _mm_max_ps(xmm1, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm3, 50);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm0, 54);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm2, 27);
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm8, 54);
   	xmm8 = _mm_shuffle_ps(xmm8, xmm0, 54);
   	xmm4 = _mm_shuffle_ps(xmm4, xmm4, 27);
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm9, 38);
   	xmm9 = _mm_shuffle_ps(xmm9, xmm0, 55);
   	xmm6 = _mm_shuffle_ps(xmm6, xmm6, 30);
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   	xmm10 = _mm_shuffle_ps(xmm10, xmm0, 39);
   	xmm11 = _mm_shuffle_ps(xmm11, xmm5, 55);
   	xmm11 = _mm_shuffle_ps(xmm11, xmm11, 9);
   
{ __m128 t = xmm11;
  xmm11 = _mm_min_ps(xmm11, xmm10);
  xmm10 = _mm_max_ps(xmm10, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm7, 49);
   	xmm5 = _mm_movelh_ps(xmm5, xmm7);
   	xmm7 = _mm_movehl_ps(xmm7, xmm1);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm7, 152);
   _mm_storeu_ps(first + 0 * 4, xmm0);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm5, 48);
   	xmm0 = _mm_movelh_ps(xmm0, xmm1);
   	xmm0 = _mm_movehl_ps(xmm0, xmm5);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm0, 56);
   _mm_storeu_ps(first + 1 * 4, xmm7);
   	xmm0 = _mm_movehl_ps(xmm0, xmm2);
   	xmm1 = _mm_movelh_ps(xmm1, xmm0);
   	xmm1 = _mm_movehl_ps(xmm1, xmm3);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm1, 150);
   _mm_storeu_ps(first + 2 * 4, xmm0);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm3, 97);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm2, 114);
   _mm_storeu_ps(first + 3 * 4, xmm2);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm4, 48);
   	xmm5 = _mm_movelh_ps(xmm5, xmm4);
   	xmm4 = _mm_movehl_ps(xmm4, xmm8);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm4, 152);
   _mm_storeu_ps(first + 4 * 4, xmm3);
   	xmm4 = _mm_shuffle_ps(xmm4, xmm5, 48);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm8, 6);
   	xmm8 = _mm_movelh_ps(xmm8, xmm5);
   	xmm4 = _mm_shuffle_ps(xmm4, xmm8, 152);
   _mm_storeu_ps(first + 5 * 4, xmm4);
   	xmm5 = _mm_movehl_ps(xmm5, xmm6);
   	xmm8 = _mm_shuffle_ps(xmm8, xmm6, 19);
   	xmm6 = _mm_movehl_ps(xmm6, xmm9);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm6, 150);
   _mm_storeu_ps(first + 6 * 4, xmm5);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm9, 96);
   	xmm0 = _mm_unpackhi_ps(xmm0, xmm8);
   _mm_storeu_ps(first + 7 * 4, xmm0);
   	xmm9 = _mm_shuffle_ps(xmm9, xmm11, 32);
   	xmm8 = _mm_movelh_ps(xmm8, xmm10);
   	xmm10 = _mm_movehl_ps(xmm10, xmm9);
   	xmm9 = _mm_shuffle_ps(xmm9, xmm10, 104);
   _mm_storeu_ps(first + 8 * 4, xmm9);
   	xmm11 = _mm_shuffle_ps(xmm11, xmm8, 33);
   	xmm11 = _mm_shuffle_ps(xmm11, xmm8, 50);
   _mm_storeu_ps(first + 9 * 4, xmm11);
}

void rsort_u_11 (float* first) {

__m128 xmm0 = _mm_loadu_ps(first + 0 * 4);
__m128 xmm8 = _mm_loadu_ps(first + 8 * 4);
__m128 xmm1 = _mm_loadu_ps(first + 1 * 4);
__m128 xmm9 = _mm_loadu_ps(first + 9 * 4);
__m128 xmm2 = _mm_loadu_ps(first + 2 * 4);
__m128 xmm10 = _mm_loadu_ps(first + 10 * 4);
__m128 xmm4 = _mm_loadu_ps(first + 4 * 4);
__m128 xmm5 = _mm_loadu_ps(first + 5 * 4);
__m128 xmm6 = _mm_loadu_ps(first + 6 * 4);
__m128 xmm7 = _mm_loadu_ps(first + 7 * 4);
__m128 xmm3 = _mm_loadu_ps(first + 3 * 4);
__m128 xmm11;
__m128 xmm12;
__m128 xmm13;
__m128 xmm14;
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm10);
  xmm10 = _mm_max_ps(xmm10, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm10);
  xmm10 = _mm_max_ps(xmm10, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   
{ __m128 t = xmm8;
  xmm8 = _mm_min_ps(xmm8, xmm10);
  xmm10 = _mm_max_ps(xmm10, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   
{ __m128 t = xmm7;
  xmm7 = _mm_min_ps(xmm7, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm1);
  xmm1 = _mm_max_ps(xmm1, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   
{ __m128 t = xmm8;
  xmm8 = _mm_min_ps(xmm8, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm10);
  xmm10 = _mm_max_ps(xmm10, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   
{ __m128 t = xmm7;
  xmm7 = _mm_min_ps(xmm7, xmm10);
  xmm10 = _mm_max_ps(xmm10, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   
{ __m128 t = xmm7;
  xmm7 = _mm_min_ps(xmm7, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   
{ __m128 t = xmm9;
  xmm9 = _mm_min_ps(xmm9, xmm10);
  xmm10 = _mm_max_ps(xmm10, t);
};
   	xmm11 = _mm_movelh_ps(xmm11, xmm0);
   	xmm0 = _mm_movehl_ps(xmm0, xmm1);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm11, 228);
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm0);
  xmm0 = _mm_max_ps(xmm0, t);
};
   	xmm11 = _mm_movelh_ps(xmm11, xmm2);
   	xmm2 = _mm_movehl_ps(xmm2, xmm3);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm11, 228);
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   	xmm11 = _mm_movelh_ps(xmm11, xmm4);
   	xmm4 = _mm_movehl_ps(xmm4, xmm5);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm11, 228);
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   	xmm11 = _mm_movelh_ps(xmm11, xmm6);
   	xmm6 = _mm_movehl_ps(xmm6, xmm7);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm11, 228);
   
{ __m128 t = xmm7;
  xmm7 = _mm_min_ps(xmm7, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   	xmm11 = _mm_movelh_ps(xmm11, xmm8);
   	xmm8 = _mm_movehl_ps(xmm8, xmm9);
   	xmm9 = _mm_shuffle_ps(xmm9, xmm11, 228);
   
{ __m128 t = xmm9;
  xmm9 = _mm_min_ps(xmm9, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   	xmm11 = _mm_movelh_ps(xmm11, xmm10);
   
{ __m128 t = xmm11;
  xmm11 = _mm_min_ps(xmm11, xmm10);
  xmm10 = _mm_max_ps(xmm10, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   	xmm12 = xmm2;
   
{ __m128 t = xmm12;
  xmm12 = _mm_min_ps(xmm12, xmm11);
  xmm11 = _mm_max_ps(xmm11, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   	xmm2 = _mm_shuffle_ps(xmm2, xmm12, 228);
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   	xmm12 = xmm6;
   
{ __m128 t = xmm12;
  xmm12 = _mm_min_ps(xmm12, xmm11);
  xmm11 = _mm_max_ps(xmm11, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   	xmm6 = _mm_shuffle_ps(xmm6, xmm12, 228);
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   	xmm12 = xmm8;
   
{ __m128 t = xmm12;
  xmm12 = _mm_min_ps(xmm12, xmm11);
  xmm11 = _mm_max_ps(xmm11, t);
};
   	xmm8 = _mm_movelh_ps(xmm8, xmm3);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm1, 78);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm1 = _mm_shuffle_ps(xmm1, xmm5, 27);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm8, 238);
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   	xmm8 = _mm_movelh_ps(xmm8, xmm7);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm1, 190);
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   	xmm1 = _mm_movelh_ps(xmm1, xmm8);
   	xmm8 = _mm_movehl_ps(xmm8, xmm9);
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   	xmm9 = _mm_shuffle_ps(xmm9, xmm11, 177);
   	xmm12 = _mm_shuffle_ps(xmm12, xmm1, 187);
   
{ __m128 t = xmm12;
  xmm12 = _mm_min_ps(xmm12, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   	xmm1 = _mm_shuffle_ps(xmm1, xmm3, 49);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm0, 38);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm1, 103);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm3, 19);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm1, 126);
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm0);
  xmm0 = _mm_max_ps(xmm0, t);
};
   	xmm1 = _mm_shuffle_ps(xmm1, xmm5, 50);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm1, 118);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm2, 114);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm5, 50);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm2, 75);
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm1);
  xmm1 = _mm_max_ps(xmm1, t);
};
   	xmm5 = _mm_shuffle_ps(xmm5, xmm7, 54);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm4, 38);
   	xmm4 = _mm_shuffle_ps(xmm4, xmm5, 103);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm7, 19);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm5, 126);
   
{ __m128 t = xmm7;
  xmm7 = _mm_min_ps(xmm7, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   	xmm5 = _mm_shuffle_ps(xmm5, xmm8, 50);
   	xmm8 = _mm_shuffle_ps(xmm8, xmm5, 118);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm6, 114);
   	xmm6 = _mm_shuffle_ps(xmm6, xmm8, 50);
   	xmm6 = _mm_shuffle_ps(xmm6, xmm6, 75);
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   	xmm8 = _mm_shuffle_ps(xmm8, xmm9, 22);
   	xmm9 = _mm_shuffle_ps(xmm9, xmm8, 123);
   	xmm8 = _mm_shuffle_ps(xmm8, xmm12, 114);
   	xmm10 = _mm_shuffle_ps(xmm10, xmm9, 27);
   	xmm9 = _mm_shuffle_ps(xmm9, xmm12, 46);
   
{ __m128 t = xmm8;
  xmm8 = _mm_min_ps(xmm8, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   	xmm11 = _mm_movelh_ps(xmm11, xmm10);
   	xmm11 = _mm_shuffle_ps(xmm11, xmm10, 51);
   
{ __m128 t = xmm11;
  xmm11 = _mm_min_ps(xmm11, xmm10);
  xmm10 = _mm_max_ps(xmm10, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm0, 30);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   	xmm1 = _mm_shuffle_ps(xmm1, xmm1, 30);
   	xmm12 = xmm1;
   
{ __m128 t = xmm12;
  xmm12 = _mm_min_ps(xmm12, xmm11);
  xmm11 = _mm_max_ps(xmm11, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm0, 75);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   	xmm1 = _mm_shuffle_ps(xmm1, xmm12, 39);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm1, 120);
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   	xmm4 = _mm_shuffle_ps(xmm4, xmm4, 30);
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   	xmm5 = _mm_shuffle_ps(xmm5, xmm5, 30);
   	xmm12 = xmm5;
   
{ __m128 t = xmm12;
  xmm12 = _mm_min_ps(xmm12, xmm11);
  xmm11 = _mm_max_ps(xmm11, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm0, 78);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   	xmm1 = _mm_shuffle_ps(xmm1, xmm1, 78);
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   	xmm4 = _mm_shuffle_ps(xmm4, xmm4, 180);
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   	xmm5 = _mm_shuffle_ps(xmm5, xmm12, 39);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm5, 216);
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   	xmm9 = _mm_shuffle_ps(xmm9, xmm9, 27);
   	xmm12 = xmm9;
   
{ __m128 t = xmm12;
  xmm12 = _mm_min_ps(xmm12, xmm11);
  xmm11 = _mm_max_ps(xmm11, t);
};
   	xmm9 = _mm_shuffle_ps(xmm9, xmm2, 55);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm3, 102);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm0, 147);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   	xmm3 = _mm_shuffle_ps(xmm3, xmm7, 99);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm9, 179);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm1, 54);
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   	xmm9 = _mm_movelh_ps(xmm9, xmm3);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm6, 107);
   	xmm4 = _mm_shuffle_ps(xmm4, xmm4, 54);
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm6 = _mm_shuffle_ps(xmm6, xmm8, 115);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm5, 39);
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   	xmm8 = _mm_shuffle_ps(xmm8, xmm11, 34);
   	xmm12 = _mm_shuffle_ps(xmm12, xmm9, 72);
   
{ __m128 t = xmm12;
  xmm12 = _mm_min_ps(xmm12, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   	xmm9 = _mm_shuffle_ps(xmm9, xmm2, 43);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm9, 141);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   	xmm9 = _mm_shuffle_ps(xmm9, xmm7, 103);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm9, 131);
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   	xmm9 = _mm_shuffle_ps(xmm9, xmm3, 39);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm9, 55);
   	xmm4 = _mm_shuffle_ps(xmm4, xmm4, 114);
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm9 = _mm_shuffle_ps(xmm9, xmm6, 38);
   	xmm6 = _mm_shuffle_ps(xmm6, xmm9, 55);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm5, 114);
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   	xmm9 = _mm_shuffle_ps(xmm9, xmm8, 54);
   	xmm8 = _mm_shuffle_ps(xmm8, xmm9, 54);
   	xmm12 = _mm_shuffle_ps(xmm12, xmm12, 99);
   
{ __m128 t = xmm12;
  xmm12 = _mm_min_ps(xmm12, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   	xmm11 = _mm_movehl_ps(xmm11, xmm9);
   	xmm13 = _mm_movehl_ps(xmm13, xmm10);
   
{ __m128 t = xmm13;
  xmm13 = _mm_min_ps(xmm13, xmm11);
  xmm11 = _mm_max_ps(xmm11, t);
};
   	xmm9 = _mm_shuffle_ps(xmm9, xmm0, 33);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm2, 39);
   	xmm14 = xmm0;
   	xmm0 = _mm_movehl_ps(xmm0, xmm9);
   	xmm9 = _mm_shuffle_ps(xmm9, xmm14, 40);
   _mm_storeu_ps(first + 0 * 4, xmm9);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm14, 23);
   	xmm0 = _mm_movelh_ps(xmm0, xmm2);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm0, 120);
   _mm_storeu_ps(first + 1 * 4, xmm2);
   	xmm14 = _mm_movehl_ps(xmm14, xmm1);
   	xmm0 = _mm_movelh_ps(xmm0, xmm1);
   	xmm1 = _mm_movehl_ps(xmm1, xmm7);
   	xmm14 = _mm_shuffle_ps(xmm14, xmm1, 195);
   _mm_storeu_ps(first + 2 * 4, xmm14);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm7, 59);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm0, 54);
   _mm_storeu_ps(first + 3 * 4, xmm0);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm4, 49);
   	xmm10 = _mm_shuffle_ps(xmm10, xmm4, 32);
   	xmm4 = _mm_shuffle_ps(xmm4, xmm3, 49);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm4, 40);
   _mm_storeu_ps(first + 4 * 4, xmm7);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm3, 144);
   	xmm0 = _mm_unpackhi_ps(xmm0, xmm10);
   _mm_storeu_ps(first + 5 * 4, xmm0);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm5, 48);
   	xmm4 = _mm_movelh_ps(xmm4, xmm5);
   	xmm4 = _mm_movehl_ps(xmm4, xmm6);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm4, 216);
   _mm_storeu_ps(first + 6 * 4, xmm3);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm6, 18);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm4, 130);
   _mm_storeu_ps(first + 7 * 4, xmm5);
   	xmm6 = _mm_shuffle_ps(xmm6, xmm12, 48);
   	xmm10 = _mm_shuffle_ps(xmm10, xmm12, 32);
   	xmm12 = _mm_shuffle_ps(xmm12, xmm8, 49);
   	xmm6 = _mm_shuffle_ps(xmm6, xmm12, 40);
   _mm_storeu_ps(first + 8 * 4, xmm6);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm8, 144);
   	xmm0 = _mm_unpackhi_ps(xmm0, xmm10);
   _mm_storeu_ps(first + 9 * 4, xmm0);
   	xmm8 = _mm_movelh_ps(xmm8, xmm13);
   	xmm10 = _mm_movelh_ps(xmm10, xmm11);
   	xmm8 = _mm_shuffle_ps(xmm8, xmm10, 40);
   _mm_storeu_ps(first + 10 * 4, xmm8);
}

void rsort_u_12 (float* first) {

__m128 xmm0 = _mm_loadu_ps(first + 0 * 4);
__m128 xmm8 = _mm_loadu_ps(first + 8 * 4);
__m128 xmm1 = _mm_loadu_ps(first + 1 * 4);
__m128 xmm9 = _mm_loadu_ps(first + 9 * 4);
__m128 xmm2 = _mm_loadu_ps(first + 2 * 4);
__m128 xmm10 = _mm_loadu_ps(first + 10 * 4);
__m128 xmm3 = _mm_loadu_ps(first + 3 * 4);
__m128 xmm11 = _mm_loadu_ps(first + 11 * 4);
__m128 xmm4 = _mm_loadu_ps(first + 4 * 4);
__m128 xmm5 = _mm_loadu_ps(first + 5 * 4);
__m128 xmm6 = _mm_loadu_ps(first + 6 * 4);
__m128 xmm7 = _mm_loadu_ps(first + 7 * 4);
__m128 xmm12;
__m128 xmm13;
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm10);
  xmm10 = _mm_max_ps(xmm10, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm11);
  xmm11 = _mm_max_ps(xmm11, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm10);
  xmm10 = _mm_max_ps(xmm10, t);
};
   
{ __m128 t = xmm7;
  xmm7 = _mm_min_ps(xmm7, xmm11);
  xmm11 = _mm_max_ps(xmm11, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   
{ __m128 t = xmm8;
  xmm8 = _mm_min_ps(xmm8, xmm10);
  xmm10 = _mm_max_ps(xmm10, t);
};
   
{ __m128 t = xmm9;
  xmm9 = _mm_min_ps(xmm9, xmm11);
  xmm11 = _mm_max_ps(xmm11, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   
{ __m128 t = xmm7;
  xmm7 = _mm_min_ps(xmm7, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm1);
  xmm1 = _mm_max_ps(xmm1, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   
{ __m128 t = xmm8;
  xmm8 = _mm_min_ps(xmm8, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   
{ __m128 t = xmm10;
  xmm10 = _mm_min_ps(xmm10, xmm11);
  xmm11 = _mm_max_ps(xmm11, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm10);
  xmm10 = _mm_max_ps(xmm10, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   
{ __m128 t = xmm7;
  xmm7 = _mm_min_ps(xmm7, xmm10);
  xmm10 = _mm_max_ps(xmm10, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   
{ __m128 t = xmm7;
  xmm7 = _mm_min_ps(xmm7, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   
{ __m128 t = xmm9;
  xmm9 = _mm_min_ps(xmm9, xmm10);
  xmm10 = _mm_max_ps(xmm10, t);
};
   	xmm12 = _mm_movelh_ps(xmm12, xmm0);
   	xmm0 = _mm_movehl_ps(xmm0, xmm1);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm12, 228);
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm0);
  xmm0 = _mm_max_ps(xmm0, t);
};
   	xmm12 = _mm_movelh_ps(xmm12, xmm2);
   	xmm2 = _mm_movehl_ps(xmm2, xmm3);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm12, 228);
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   	xmm12 = _mm_movelh_ps(xmm12, xmm4);
   	xmm4 = _mm_movehl_ps(xmm4, xmm5);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm12, 228);
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   	xmm12 = _mm_movelh_ps(xmm12, xmm6);
   	xmm6 = _mm_movehl_ps(xmm6, xmm7);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm12, 228);
   
{ __m128 t = xmm7;
  xmm7 = _mm_min_ps(xmm7, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   	xmm12 = _mm_movelh_ps(xmm12, xmm8);
   	xmm8 = _mm_movehl_ps(xmm8, xmm9);
   	xmm9 = _mm_shuffle_ps(xmm9, xmm12, 228);
   
{ __m128 t = xmm9;
  xmm9 = _mm_min_ps(xmm9, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   	xmm12 = _mm_movelh_ps(xmm12, xmm10);
   	xmm10 = _mm_movehl_ps(xmm10, xmm11);
   	xmm11 = _mm_shuffle_ps(xmm11, xmm12, 228);
   
{ __m128 t = xmm11;
  xmm11 = _mm_min_ps(xmm11, xmm10);
  xmm10 = _mm_max_ps(xmm10, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm11);
  xmm11 = _mm_max_ps(xmm11, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm11);
  xmm11 = _mm_max_ps(xmm11, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   
{ __m128 t = xmm8;
  xmm8 = _mm_min_ps(xmm8, xmm11);
  xmm11 = _mm_max_ps(xmm11, t);
};
   	xmm12 = _mm_movelh_ps(xmm12, xmm1);
   	xmm12 = _mm_movehl_ps(xmm12, xmm3);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm12);
  xmm12 = _mm_max_ps(xmm12, t);
};
   	xmm3 = _mm_shuffle_ps(xmm3, xmm5, 177);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm2, 27);
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm5 = _mm_shuffle_ps(xmm5, xmm7, 177);
   	xmm4 = _mm_shuffle_ps(xmm4, xmm4, 27);
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   	xmm7 = _mm_shuffle_ps(xmm7, xmm9, 177);
   	xmm6 = _mm_shuffle_ps(xmm6, xmm6, 27);
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   	xmm9 = _mm_shuffle_ps(xmm9, xmm11, 177);
   	xmm8 = _mm_shuffle_ps(xmm8, xmm8, 27);
   
{ __m128 t = xmm8;
  xmm8 = _mm_min_ps(xmm8, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   	xmm13 = _mm_movehl_ps(xmm13, xmm10);
   
{ __m128 t = xmm13;
  xmm13 = _mm_min_ps(xmm13, xmm11);
  xmm11 = _mm_max_ps(xmm11, t);
};
   	xmm1 = _mm_movehl_ps(xmm1, xmm12);
   	xmm10 = _mm_shuffle_ps(xmm10, xmm0, 33);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm1, 119);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm1, 32);
   	xmm1 = _mm_movehl_ps(xmm1, xmm10);
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm0);
  xmm0 = _mm_max_ps(xmm0, t);
};
   	xmm12 = _mm_movelh_ps(xmm12, xmm3);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm2, 123);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm12, 98);
   	xmm10 = _mm_movelh_ps(xmm10, xmm3);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm12, 62);
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   	xmm11 = _mm_shuffle_ps(xmm11, xmm5, 177);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm10, 49);
   	xmm10 = _mm_shuffle_ps(xmm10, xmm4, 118);
   	xmm4 = _mm_shuffle_ps(xmm4, xmm5, 98);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm10, 19);
   	xmm10 = _mm_shuffle_ps(xmm10, xmm5, 126);
   
{ __m128 t = xmm10;
  xmm10 = _mm_min_ps(xmm10, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   	xmm5 = _mm_shuffle_ps(xmm5, xmm7, 178);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm11, 49);
   	xmm11 = _mm_shuffle_ps(xmm11, xmm6, 118);
   	xmm6 = _mm_shuffle_ps(xmm6, xmm7, 98);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm11, 19);
   	xmm11 = _mm_shuffle_ps(xmm11, xmm7, 126);
   
{ __m128 t = xmm11;
  xmm11 = _mm_min_ps(xmm11, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   	xmm7 = _mm_shuffle_ps(xmm7, xmm5, 18);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm9, 11);
   	xmm12 = _mm_movelh_ps(xmm12, xmm5);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm8, 34);
   	xmm12 = _mm_shuffle_ps(xmm12, xmm9, 19);
   	xmm12 = _mm_shuffle_ps(xmm12, xmm8, 114);
   
{ __m128 t = xmm12;
  xmm12 = _mm_min_ps(xmm12, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   	xmm9 = _mm_shuffle_ps(xmm9, xmm13, 27);
   	xmm8 = xmm7;
   	xmm7 = _mm_shuffle_ps(xmm7, xmm9, 102);
   	xmm8 = _mm_shuffle_ps(xmm8, xmm9, 51);
   
{ __m128 t = xmm8;
  xmm8 = _mm_min_ps(xmm8, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm0, 27);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm12);
  xmm12 = _mm_max_ps(xmm12, t);
};
   	xmm2 = _mm_shuffle_ps(xmm2, xmm2, 216);
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm0, 30);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm10);
  xmm10 = _mm_max_ps(xmm10, t);
};
   	xmm2 = _mm_shuffle_ps(xmm2, xmm2, 120);
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm11);
  xmm11 = _mm_max_ps(xmm11, t);
};
   	xmm4 = _mm_shuffle_ps(xmm4, xmm4, 75);
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm12);
  xmm12 = _mm_max_ps(xmm12, t);
};
   	xmm6 = _mm_shuffle_ps(xmm6, xmm6, 156);
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm0, 180);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm10);
  xmm10 = _mm_max_ps(xmm10, t);
};
   	xmm4 = _mm_shuffle_ps(xmm4, xmm4, 30);
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm11);
  xmm11 = _mm_max_ps(xmm11, t);
};
   	xmm6 = _mm_shuffle_ps(xmm6, xmm6, 141);
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm12);
  xmm12 = _mm_max_ps(xmm12, t);
};
   	xmm5 = _mm_shuffle_ps(xmm5, xmm5, 114);
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   	xmm9 = _mm_movelh_ps(xmm9, xmm0);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm3, 123);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm1, 33);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm3, 119);
   	xmm9 = _mm_shuffle_ps(xmm9, xmm0, 27);
   	xmm9 = _mm_shuffle_ps(xmm9, xmm9, 114);
   
{ __m128 t = xmm9;
  xmm9 = _mm_min_ps(xmm9, xmm1);
  xmm1 = _mm_max_ps(xmm1, t);
};
   	xmm3 = _mm_shuffle_ps(xmm3, xmm10, 98);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm2, 54);
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm10 = _mm_shuffle_ps(xmm10, xmm11, 99);
   	xmm4 = _mm_shuffle_ps(xmm4, xmm4, 54);
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm10);
  xmm10 = _mm_max_ps(xmm10, t);
};
   	xmm11 = _mm_shuffle_ps(xmm11, xmm12, 115);
   	xmm6 = _mm_shuffle_ps(xmm6, xmm6, 45);
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm11);
  xmm11 = _mm_max_ps(xmm11, t);
};
   	xmm12 = _mm_shuffle_ps(xmm12, xmm8, 178);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm5, 30);
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm12);
  xmm12 = _mm_max_ps(xmm12, t);
};
   	xmm13 = _mm_movehl_ps(xmm13, xmm7);
   
{ __m128 t = xmm13;
  xmm13 = _mm_min_ps(xmm13, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   	xmm0 = _mm_movehl_ps(xmm0, xmm1);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm0, 49);
   	xmm9 = _mm_shuffle_ps(xmm9, xmm9, 198);
   
{ __m128 t = xmm9;
  xmm9 = _mm_min_ps(xmm9, xmm1);
  xmm1 = _mm_max_ps(xmm1, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm3, 54);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm0, 118);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm2, 27);
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm10, 50);
   	xmm10 = _mm_shuffle_ps(xmm10, xmm0, 54);
   	xmm4 = _mm_shuffle_ps(xmm4, xmm4, 27);
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm10);
  xmm10 = _mm_max_ps(xmm10, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm11, 38);
   	xmm11 = _mm_shuffle_ps(xmm11, xmm0, 55);
   	xmm6 = _mm_shuffle_ps(xmm6, xmm6, 30);
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm11);
  xmm11 = _mm_max_ps(xmm11, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm12, 54);
   	xmm12 = _mm_shuffle_ps(xmm12, xmm0, 54);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm5, 99);
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm12);
  xmm12 = _mm_max_ps(xmm12, t);
};
   	xmm8 = _mm_shuffle_ps(xmm8, xmm0, 33);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm0, 1);
   	xmm13 = _mm_unpacklo_ps(xmm13, xmm7);
   
{ __m128 t = xmm13;
  xmm13 = _mm_min_ps(xmm13, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   	xmm0 = _mm_shuffle_ps(xmm0, xmm9, 33);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm9, 49);
   	xmm9 = _mm_shuffle_ps(xmm9, xmm1, 33);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm9, 40);
   _mm_storeu_ps(first + 0 * 4, xmm0);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm7, 55);
   	xmm7 = _mm_movehl_ps(xmm7, xmm9);
   	xmm0 = xmm1;
   	xmm0 = _mm_shuffle_ps(xmm0, xmm7, 153);
   _mm_storeu_ps(first + 1 * 4, xmm0);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm2, 51);
   	xmm0 = _mm_movelh_ps(xmm0, xmm1);
   	xmm0 = _mm_movelh_ps(xmm0, xmm2);
   	xmm2 = _mm_movehl_ps(xmm2, xmm3);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm1, 11);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm2, 153);
   _mm_storeu_ps(first + 2 * 4, xmm1);
   	xmm1 = (__m128)_mm_shuffle_epi32(reinterpret_cast<__m128i>(xmm3), 6);
   	xmm1 = _mm_unpacklo_ps(xmm1, xmm0);
   _mm_storeu_ps(first + 3 * 4, xmm1);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm4, 48);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm4, 18);
   	xmm4 = _mm_movehl_ps(xmm4, xmm10);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm4, 152);
   _mm_storeu_ps(first + 4 * 4, xmm3);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm10, 96);
   	xmm1 = _mm_unpackhi_ps(xmm1, xmm0);
   _mm_storeu_ps(first + 5 * 4, xmm1);
   	xmm10 = _mm_shuffle_ps(xmm10, xmm6, 48);
   	xmm0 = _mm_movelh_ps(xmm0, xmm6);
   	xmm6 = _mm_movehl_ps(xmm6, xmm11);
   	xmm10 = _mm_shuffle_ps(xmm10, xmm6, 152);
   _mm_storeu_ps(first + 6 * 4, xmm10);
   	xmm6 = _mm_shuffle_ps(xmm6, xmm0, 48);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm11, 18);
   	xmm6 = _mm_shuffle_ps(xmm6, xmm0, 40);
   _mm_storeu_ps(first + 7 * 4, xmm6);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm5, 55);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm12, 54);
   	xmm11 = xmm5;
   	xmm1 = xmm0;
   	xmm0 = _mm_shuffle_ps(xmm0, xmm5, 104);
   _mm_storeu_ps(first + 8 * 4, xmm0);
   	xmm5 = _mm_movelh_ps(xmm5, xmm12);
   	xmm12 = _mm_movehl_ps(xmm12, xmm1);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm12, 99);
   _mm_storeu_ps(first + 9 * 4, xmm5);
   	xmm11 = _mm_movehl_ps(xmm11, xmm13);
   	xmm1 = _mm_movelh_ps(xmm1, xmm8);
   	xmm8 = _mm_shuffle_ps(xmm8, xmm13, 2);
   	xmm11 = _mm_shuffle_ps(xmm11, xmm8, 131);
   _mm_storeu_ps(first + 10 * 4, xmm11);
   	xmm8 = _mm_movelh_ps(xmm8, xmm13);
   	xmm8 = _mm_shuffle_ps(xmm8, xmm1, 125);
   _mm_storeu_ps(first + 11 * 4, xmm8);
}

void rsort_u_13 (float* first) {

__m128 xmm0 = _mm_loadu_ps(first + 0 * 4);
__m128 xmm8 = _mm_loadu_ps(first + 8 * 4);
__m128 xmm1 = _mm_loadu_ps(first + 1 * 4);
__m128 xmm9 = _mm_loadu_ps(first + 9 * 4);
__m128 xmm2 = _mm_loadu_ps(first + 2 * 4);
__m128 xmm10 = _mm_loadu_ps(first + 10 * 4);
__m128 xmm3 = _mm_loadu_ps(first + 3 * 4);
__m128 xmm11 = _mm_loadu_ps(first + 11 * 4);
__m128 xmm4 = _mm_loadu_ps(first + 4 * 4);
__m128 xmm12 = _mm_loadu_ps(first + 12 * 4);
__m128 xmm5 = _mm_loadu_ps(first + 5 * 4);
__m128 xmm6 = _mm_loadu_ps(first + 6 * 4);
__m128 xmm7 = _mm_loadu_ps(first + 7 * 4);
__m128 xmm13;
__m128 xmm14;
__m128 xmm15;
__m128 xmm16;
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm10);
  xmm10 = _mm_max_ps(xmm10, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm11);
  xmm11 = _mm_max_ps(xmm11, t);
};
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm12);
  xmm12 = _mm_max_ps(xmm12, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   
{ __m128 t = xmm8;
  xmm8 = _mm_min_ps(xmm8, xmm12);
  xmm12 = _mm_max_ps(xmm12, t);
};
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm10);
  xmm10 = _mm_max_ps(xmm10, t);
};
   
{ __m128 t = xmm7;
  xmm7 = _mm_min_ps(xmm7, xmm11);
  xmm11 = _mm_max_ps(xmm11, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   
{ __m128 t = xmm8;
  xmm8 = _mm_min_ps(xmm8, xmm10);
  xmm10 = _mm_max_ps(xmm10, t);
};
   
{ __m128 t = xmm9;
  xmm9 = _mm_min_ps(xmm9, xmm11);
  xmm11 = _mm_max_ps(xmm11, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm12);
  xmm12 = _mm_max_ps(xmm12, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   
{ __m128 t = xmm7;
  xmm7 = _mm_min_ps(xmm7, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   
{ __m128 t = xmm10;
  xmm10 = _mm_min_ps(xmm10, xmm12);
  xmm12 = _mm_max_ps(xmm12, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm1);
  xmm1 = _mm_max_ps(xmm1, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   
{ __m128 t = xmm8;
  xmm8 = _mm_min_ps(xmm8, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   
{ __m128 t = xmm10;
  xmm10 = _mm_min_ps(xmm10, xmm11);
  xmm11 = _mm_max_ps(xmm11, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm10);
  xmm10 = _mm_max_ps(xmm10, t);
};
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm12);
  xmm12 = _mm_max_ps(xmm12, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   
{ __m128 t = xmm7;
  xmm7 = _mm_min_ps(xmm7, xmm10);
  xmm10 = _mm_max_ps(xmm10, t);
};
   
{ __m128 t = xmm9;
  xmm9 = _mm_min_ps(xmm9, xmm12);
  xmm12 = _mm_max_ps(xmm12, t);
};
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   
{ __m128 t = xmm7;
  xmm7 = _mm_min_ps(xmm7, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   
{ __m128 t = xmm9;
  xmm9 = _mm_min_ps(xmm9, xmm10);
  xmm10 = _mm_max_ps(xmm10, t);
};
   
{ __m128 t = xmm11;
  xmm11 = _mm_min_ps(xmm11, xmm12);
  xmm12 = _mm_max_ps(xmm12, t);
};
   	xmm13 = _mm_movelh_ps(xmm13, xmm0);
   	xmm0 = _mm_movehl_ps(xmm0, xmm1);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm13, 228);
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm0);
  xmm0 = _mm_max_ps(xmm0, t);
};
   	xmm13 = _mm_movelh_ps(xmm13, xmm2);
   	xmm2 = _mm_movehl_ps(xmm2, xmm3);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm13, 228);
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   	xmm13 = _mm_movelh_ps(xmm13, xmm4);
   	xmm4 = _mm_movehl_ps(xmm4, xmm5);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm13, 228);
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   	xmm13 = _mm_movelh_ps(xmm13, xmm6);
   	xmm6 = _mm_movehl_ps(xmm6, xmm7);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm13, 228);
   
{ __m128 t = xmm7;
  xmm7 = _mm_min_ps(xmm7, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   	xmm13 = _mm_movelh_ps(xmm13, xmm8);
   	xmm8 = _mm_movehl_ps(xmm8, xmm9);
   	xmm9 = _mm_shuffle_ps(xmm9, xmm13, 228);
   
{ __m128 t = xmm9;
  xmm9 = _mm_min_ps(xmm9, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   	xmm13 = _mm_movelh_ps(xmm13, xmm10);
   	xmm10 = _mm_movehl_ps(xmm10, xmm11);
   	xmm11 = _mm_shuffle_ps(xmm11, xmm13, 228);
   
{ __m128 t = xmm11;
  xmm11 = _mm_min_ps(xmm11, xmm10);
  xmm10 = _mm_max_ps(xmm10, t);
};
   	xmm13 = _mm_movelh_ps(xmm13, xmm12);
   
{ __m128 t = xmm13;
  xmm13 = _mm_min_ps(xmm13, xmm12);
  xmm12 = _mm_max_ps(xmm12, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm11);
  xmm11 = _mm_max_ps(xmm11, t);
};
   	xmm14 = xmm4;
   
{ __m128 t = xmm14;
  xmm14 = _mm_min_ps(xmm14, xmm13);
  xmm13 = _mm_max_ps(xmm13, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   	xmm4 = _mm_shuffle_ps(xmm4, xmm14, 228);
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm11);
  xmm11 = _mm_max_ps(xmm11, t);
};
   	xmm14 = xmm8;
   
{ __m128 t = xmm14;
  xmm14 = _mm_min_ps(xmm14, xmm13);
  xmm13 = _mm_max_ps(xmm13, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   	xmm8 = _mm_shuffle_ps(xmm8, xmm14, 228);
   
{ __m128 t = xmm8;
  xmm8 = _mm_min_ps(xmm8, xmm11);
  xmm11 = _mm_max_ps(xmm11, t);
};
   	xmm14 = xmm10;
   
{ __m128 t = xmm14;
  xmm14 = _mm_min_ps(xmm14, xmm13);
  xmm13 = _mm_max_ps(xmm13, t);
};
   	xmm10 = _mm_movelh_ps(xmm10, xmm3);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm1, 78);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm1 = _mm_shuffle_ps(xmm1, xmm5, 27);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm10, 238);
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   	xmm10 = _mm_movelh_ps(xmm10, xmm7);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm1, 190);
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   	xmm1 = _mm_movelh_ps(xmm1, xmm9);
   	xmm9 = _mm_shuffle_ps(xmm9, xmm10, 238);
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   	xmm10 = _mm_movelh_ps(xmm10, xmm1);
   	xmm1 = _mm_movehl_ps(xmm1, xmm11);
   
{ __m128 t = xmm8;
  xmm8 = _mm_min_ps(xmm8, xmm1);
  xmm1 = _mm_max_ps(xmm1, t);
};
   	xmm11 = _mm_shuffle_ps(xmm11, xmm13, 177);
   	xmm14 = _mm_shuffle_ps(xmm14, xmm10, 27);
   
{ __m128 t = xmm14;
  xmm14 = _mm_min_ps(xmm14, xmm11);
  xmm11 = _mm_max_ps(xmm11, t);
};
   	xmm10 = _mm_movehl_ps(xmm10, xmm3);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm0, 33);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm10, 103);
   	xmm10 = _mm_shuffle_ps(xmm10, xmm3, 19);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm10, 78);
   
{ __m128 t = xmm3;
  xmm3 = _mm_min_ps(xmm3, xmm0);
  xmm0 = _mm_max_ps(xmm0, t);
};
   	xmm10 = _mm_movehl_ps(xmm10, xmm5);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm2, 33);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm10, 119);
   	xmm10 = _mm_shuffle_ps(xmm10, xmm5, 18);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm10, 78);
   
{ __m128 t = xmm5;
  xmm5 = _mm_min_ps(xmm5, xmm2);
  xmm2 = _mm_max_ps(xmm2, t);
};
   	xmm10 = _mm_movehl_ps(xmm10, xmm7);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm4, 33);
   	xmm4 = _mm_shuffle_ps(xmm4, xmm10, 119);
   	xmm10 = _mm_shuffle_ps(xmm10, xmm7, 18);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm10, 78);
   
{ __m128 t = xmm7;
  xmm7 = _mm_min_ps(xmm7, xmm4);
  xmm4 = _mm_max_ps(xmm4, t);
};
   	xmm10 = _mm_movehl_ps(xmm10, xmm9);
   	xmm9 = _mm_shuffle_ps(xmm9, xmm6, 33);
   	xmm6 = _mm_shuffle_ps(xmm6, xmm10, 119);
   	xmm10 = _mm_shuffle_ps(xmm10, xmm9, 18);
   	xmm9 = _mm_shuffle_ps(xmm9, xmm10, 78);
   
{ __m128 t = xmm9;
  xmm9 = _mm_min_ps(xmm9, xmm6);
  xmm6 = _mm_max_ps(xmm6, t);
};
   	xmm10 = _mm_movehl_ps(xmm10, xmm1);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm8, 33);
   	xmm8 = _mm_shuffle_ps(xmm8, xmm10, 119);
   	xmm10 = _mm_shuffle_ps(xmm10, xmm1, 18);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm10, 78);
   
{ __m128 t = xmm1;
  xmm1 = _mm_min_ps(xmm1, xmm8);
  xmm8 = _mm_max_ps(xmm8, t);
};
   	xmm10 = _mm_shuffle_ps(xmm10, xmm11, 27);
   	xmm11 = _mm_shuffle_ps(xmm11, xmm10, 59);
   	xmm10 = _mm_shuffle_ps(xmm10, xmm14, 118);
   	xmm12 = _mm_shuffle_ps(xmm12, xmm11, 27);
   	xmm11 = _mm_shuffle_ps(xmm11, xmm14, 46);
   
{ __m128 t = xmm10;
  xmm10 = _mm_min_ps(xmm10, xmm11);
  xmm11 = _mm_max_ps(xmm11, t);
};
   	xmm13 = _mm_movelh_ps(xmm13, xmm12);
   	xmm13 = _mm_shuffle_ps(xmm13, xmm12, 51);
   
{ __m128 t = xmm13;
  xmm13 = _mm_min_ps(xmm13, xmm12);
  xmm12 = _mm_max_ps(xmm12, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm1);
  xmm1 = _mm_max_ps(xmm1, t);
};
   	xmm2 = _mm_shuffle_ps(xmm2, xmm2, 27);
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm10);
  xmm10 = _mm_max_ps(xmm10, t);
};
   	xmm14 = xmm4;
   
{ __m128 t = xmm14;
  xmm14 = _mm_min_ps(xmm14, xmm13);
  xmm13 = _mm_max_ps(xmm13, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   	xmm2 = _mm_shuffle_ps(xmm2, xmm2, 27);
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   	xmm4 = _mm_shuffle_ps(xmm4, xmm14, 39);
   	xmm4 = _mm_shuffle_ps(xmm4, xmm4, 39);
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm1);
  xmm1 = _mm_max_ps(xmm1, t);
};
   	xmm6 = _mm_shuffle_ps(xmm6, xmm6, 27);
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm10);
  xmm10 = _mm_max_ps(xmm10, t);
};
   	xmm14 = xmm8;
   
{ __m128 t = xmm14;
  xmm14 = _mm_min_ps(xmm14, xmm13);
  xmm13 = _mm_max_ps(xmm13, t);
};
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   	xmm6 = _mm_shuffle_ps(xmm6, xmm6, 27);
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm1);
  xmm1 = _mm_max_ps(xmm1, t);
};
   	xmm8 = _mm_shuffle_ps(xmm8, xmm14, 39);
   	xmm8 = _mm_shuffle_ps(xmm8, xmm8, 216);
   
{ __m128 t = xmm8;
  xmm8 = _mm_min_ps(xmm8, xmm10);
  xmm10 = _mm_max_ps(xmm10, t);
};
   	xmm11 = _mm_shuffle_ps(xmm11, xmm11, 27);
   	xmm14 = xmm11;
   
{ __m128 t = xmm14;
  xmm14 = _mm_min_ps(xmm14, xmm13);
  xmm13 = _mm_max_ps(xmm13, t);
};
   	xmm11 = _mm_shuffle_ps(xmm11, xmm3, 39);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm5, 39);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm0, 114);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm5 = _mm_shuffle_ps(xmm5, xmm7, 39);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm2, 114);
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   	xmm7 = _mm_shuffle_ps(xmm7, xmm9, 39);
   	xmm4 = _mm_shuffle_ps(xmm4, xmm4, 114);
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   	xmm9 = _mm_shuffle_ps(xmm9, xmm1, 39);
   	xmm6 = _mm_shuffle_ps(xmm6, xmm6, 114);
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   	xmm1 = _mm_shuffle_ps(xmm1, xmm10, 119);
   	xmm8 = _mm_shuffle_ps(xmm8, xmm8, 45);
   
{ __m128 t = xmm8;
  xmm8 = _mm_min_ps(xmm8, xmm1);
  xmm1 = _mm_max_ps(xmm1, t);
};
   	xmm10 = _mm_shuffle_ps(xmm10, xmm13, 34);
   	xmm14 = _mm_shuffle_ps(xmm14, xmm11, 72);
   
{ __m128 t = xmm14;
  xmm14 = _mm_min_ps(xmm14, xmm10);
  xmm10 = _mm_max_ps(xmm10, t);
};
   	xmm11 = _mm_movehl_ps(xmm11, xmm3);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm11, 49);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm0, 198);
   
{ __m128 t = xmm0;
  xmm0 = _mm_min_ps(xmm0, xmm3);
  xmm3 = _mm_max_ps(xmm3, t);
};
   	xmm11 = _mm_shuffle_ps(xmm11, xmm5, 54);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm11, 118);
   	xmm2 = _mm_shuffle_ps(xmm2, xmm2, 27);
   
{ __m128 t = xmm2;
  xmm2 = _mm_min_ps(xmm2, xmm5);
  xmm5 = _mm_max_ps(xmm5, t);
};
   	xmm11 = _mm_shuffle_ps(xmm11, xmm7, 50);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm11, 54);
   	xmm4 = _mm_shuffle_ps(xmm4, xmm4, 27);
   
{ __m128 t = xmm4;
  xmm4 = _mm_min_ps(xmm4, xmm7);
  xmm7 = _mm_max_ps(xmm7, t);
};
   	xmm11 = _mm_shuffle_ps(xmm11, xmm9, 54);
   	xmm9 = _mm_shuffle_ps(xmm9, xmm11, 54);
   	xmm6 = _mm_shuffle_ps(xmm6, xmm6, 27);
   
{ __m128 t = xmm6;
  xmm6 = _mm_min_ps(xmm6, xmm9);
  xmm9 = _mm_max_ps(xmm9, t);
};
   	xmm11 = _mm_shuffle_ps(xmm11, xmm1, 38);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm11, 55);
   	xmm8 = _mm_shuffle_ps(xmm8, xmm8, 30);
   
{ __m128 t = xmm8;
  xmm8 = _mm_min_ps(xmm8, xmm1);
  xmm1 = _mm_max_ps(xmm1, t);
};
   	xmm11 = _mm_shuffle_ps(xmm11, xmm10, 54);
   	xmm10 = _mm_shuffle_ps(xmm10, xmm11, 54);
   	xmm14 = _mm_shuffle_ps(xmm14, xmm14, 99);
   
{ __m128 t = xmm14;
  xmm14 = _mm_min_ps(xmm14, xmm10);
  xmm10 = _mm_max_ps(xmm10, t);
};
   	xmm13 = _mm_movehl_ps(xmm13, xmm11);
   	xmm15 = _mm_movehl_ps(xmm15, xmm12);
   
{ __m128 t = xmm15;
  xmm15 = _mm_min_ps(xmm15, xmm13);
  xmm13 = _mm_max_ps(xmm13, t);
};
   	xmm11 = _mm_shuffle_ps(xmm11, xmm0, 33);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm3, 39);
   	xmm16 = xmm0;
   	xmm0 = _mm_movehl_ps(xmm0, xmm11);
   	xmm11 = _mm_shuffle_ps(xmm11, xmm16, 104);
   _mm_storeu_ps(first + 0 * 4, xmm11);
   	xmm0 = _mm_movelh_ps(xmm0, xmm3);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm16, 55);
   _mm_storeu_ps(first + 1 * 4, xmm0);
   	xmm3 = _mm_movehl_ps(xmm3, xmm2);
   	xmm0 = _mm_movelh_ps(xmm0, xmm2);
   	xmm2 = _mm_movehl_ps(xmm2, xmm5);
   	xmm3 = _mm_shuffle_ps(xmm3, xmm2, 151);
   _mm_storeu_ps(first + 2 * 4, xmm3);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm5, 107);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm0, 114);
   _mm_storeu_ps(first + 3 * 4, xmm0);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm4, 48);
   	xmm12 = _mm_movelh_ps(xmm12, xmm4);
   	xmm4 = _mm_movehl_ps(xmm4, xmm7);
   	xmm5 = _mm_shuffle_ps(xmm5, xmm4, 152);
   _mm_storeu_ps(first + 4 * 4, xmm5);
   	xmm4 = _mm_shuffle_ps(xmm4, xmm12, 48);
   	xmm12 = _mm_shuffle_ps(xmm12, xmm7, 18);
   	xmm4 = _mm_shuffle_ps(xmm4, xmm12, 40);
   _mm_storeu_ps(first + 5 * 4, xmm4);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm6, 48);
   	xmm12 = _mm_movelh_ps(xmm12, xmm6);
   	xmm6 = _mm_movehl_ps(xmm6, xmm9);
   	xmm7 = _mm_shuffle_ps(xmm7, xmm6, 152);
   _mm_storeu_ps(first + 6 * 4, xmm7);
   	xmm6 = _mm_shuffle_ps(xmm6, xmm12, 48);
   	xmm9 = _mm_movelh_ps(xmm9, xmm12);
   	xmm12 = _mm_shuffle_ps(xmm12, xmm9, 18);
   	xmm6 = _mm_shuffle_ps(xmm6, xmm12, 40);
   _mm_storeu_ps(first + 7 * 4, xmm6);
   	xmm9 = _mm_shuffle_ps(xmm9, xmm8, 51);
   	xmm0 = _mm_movehl_ps(xmm0, xmm1);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm8, 33);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm9, 2);
   	xmm9 = _mm_shuffle_ps(xmm9, xmm0, 25);
   _mm_storeu_ps(first + 8 * 4, xmm9);
   	xmm8 = _mm_shuffle_ps(xmm8, xmm1, 97);
   	xmm8 = _mm_shuffle_ps(xmm8, xmm8, 114);
   _mm_storeu_ps(first + 9 * 4, xmm8);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm14, 48);
   	xmm0 = _mm_movehl_ps(xmm0, xmm14);
   	xmm14 = _mm_shuffle_ps(xmm14, xmm10, 49);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm14, 40);
   _mm_storeu_ps(first + 10 * 4, xmm1);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm10, 18);
   	xmm10 = _mm_shuffle_ps(xmm10, xmm14, 18);
   	xmm1 = _mm_movelh_ps(xmm1, xmm0);
   	xmm0 = _mm_shuffle_ps(xmm0, xmm10, 134);
   _mm_storeu_ps(first + 11 * 4, xmm0);
   	xmm10 = _mm_movelh_ps(xmm10, xmm15);
   	xmm1 = _mm_shuffle_ps(xmm1, xmm13, 2);
   	xmm10 = _mm_shuffle_ps(xmm10, xmm1, 41);
   _mm_storeu_ps(first + 12 * 4, xmm10);
}


RegSort_Unaligned_FuncPtr rsort_u_ptrs[13] = {
  rsort_u_1,
  rsort_u_2,
  rsort_u_3,
  rsort_u_4,
  rsort_u_5,
  rsort_u_6,
  rsort_u_7,
  rsort_u_8,
  rsort_u_9,
  rsort_u_10,
  rsort_u_11,
  rsort_u_12,
  rsort_u_13
};
