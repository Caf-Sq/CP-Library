#pragma once

#include <lib/Root.hpp>

ll SquareFreeCount(ll n) {
  const int I = Root(n, 5), D = sqrtl(n / I);
  vector<int> P(D + 1, 1), M(D + 1);
  M[1] = 1;
  for(int i = 2; i < D + 1; i++) {
    if(P[i]) {
      for(int j = D / i; j >= 1; j--) {
        if(j >= i && P[j]) { P[i * j] = 0; }
        if(M[j]) { M[i * j] = -M[j]; }
      }
    }
  }

  ll r = 0;
  for(ll i = 1; i <= D; i++) { r += M[i] * (n / (i * i)); }
  for(int i = 0; i < D; i++) { M[i + 1] += M[i]; }

  vector<ll> X(I);
  for(int i = I - 1; i >= 1; i--) {
    const int x = sqrtl(n / i), sq = sqrtl(x);
    X[i] = 1;
    for(int j = 2; j <= sq; j++) {
      if(x / j <= D) { X[i] -= M[x / j]; }
      else { X[i] -= X[i * j * j]; }
    }
    for(int j = 1; j <= x / (sq + 1); j++) { X[i] -= (x / j - x / (j + 1)) * M[j]; }
    r += X[i];
  }
  r -= ll(I - 1) * M[D];
  return r;
}