#pragma once

#include <atcoder/string>
using namespace atcoder;

template<typename STR> tuple<ll, ll, ll, ll> ConsecutiveLCS(STR &S, STR &T) {
  int M = max<int>(ranges::max(S), ranges::max(T)) + 1;
  STR ST;
  for(auto &x : S) { ST.push_back(x); }
  ST.push_back(M);
  for(auto &x : T) { ST.push_back(x); }

  auto SA = suffix_array(ST);
  auto LCP = lcp_array(ST, SA);

  tuple<ll, ll, ll, ll> r = {0, 0, 0, 0};
  int N = 0;
  for(ll i = 0; i < ST.size() - 1; i++) {
    int p = SA[i], q = SA[i + 1];
    if(p > q) { swap(p, q); }
    if(p < S.size() && S.size() < q && N < LCP[i]) {
      N = LCP[i];
      int a = p, b = q - S.size() - 1;
      r = {a, a + N, b, b + N};
    }
  }
  return r;
}