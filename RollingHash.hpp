#pragma once

#include <lib/Modint2_61.hpp>

// https://github.com/tatyam-prime/kyopro_library/blob/master/RollingHash.cpp
// https://nyaannyaan.github.io/library/string/rolling-hash.hpp (hash(string),find)
struct RollingHash {
  vector<mint> hashed, power;
  int n;
  RollingHash() {}
  RollingHash(const string &s): n(s.size()) {
    hashed.assign(n + 1, 0);
    power.assign(n + 1, 0);
    power[0] = 1;
    for(ll i = 0; i < n; i++) {
      power[i + 1] = power[i] * base;
      hashed[i + 1] = hashed[i] * base + s[i];
    }
  }
  mint hash(ll l, ll r) const {
    return hashed[r] - hashed[l] * power[r - l];
  }
  static mint hash(const string &s) {
    mint r = 0;
    for(auto &i : s) { r = r * base + i; }
    return r;
  }
  mint connect(mint h1, mint h2, ll h2len) const {
    return h1 * power[h2len] + h2;
  }
  void connect(const string &s) {
    ll n = hashed.size() - 1, m = s.size();
    hashed.resize(n + m + 1);
    power.resize(n + m + 1);
    for(ll i = n; i < n + m; i++) {
      power[i + 1] = power[i] * base;
      hashed[i + 1] = hashed[i] * base + s[i - n];
    }
  }
  int find(string &s, int lhs = 0) const {
    mint h = hash(s);
    for(int i = lhs; i <= n - s.size(); i++) {
      if(h == hash(i, i + s.size())) { return i; }
    }
    return -1;
  }
  ll LCP(const RollingHash &b, ll l1, ll r1, ll l2, ll r2) {
    ll len = min(r1 - l1, r2 - l2);
    ll low = -1, high = len + 1;
    while(high - low > 1) {
      ll mid = (low + high) / 2;
      if(hash(l1, l1 + mid) == b.hash(l2, l2 + mid)) { low = mid; }
      else { high = mid; }
    }
    return low;
  }
};