#pragma once

#include <atcoder/modint>
using namespace atcoder;

ll mod_sqrt(const ll &a, const ll &MOD = 998244353) {
  modint::set_mod(MOD);
  ll m = MOD - 1, e = 0;
  if(!a) { return 0; }
  if(MOD == 2) { return a; }
  if(modint(a).pow(m >> 1) != 1) { return -1; }
  modint b = 1;
  while(b.pow(m >> 1) == 1) { b++; }
  while(~m & 1) {
    m >>= 1;
    e++;
  }
  modint x = modint(a).pow((m - 1) >> 1), y = modint(a) * x * x, z = modint(b).pow(m);
  x *= a;
  while(y != 1) {
    ll j = 0;
    modint t = y;
    while(t != 1) {
      j++;
      t *= t;
    }
    z = z.pow(1LL << (e - j - 1));
    x *= z;
    z *= z;
    y *= z;
    e = j;
  }
  return x.val();
}