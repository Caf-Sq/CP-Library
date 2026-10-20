#pragma once

template<typename T> struct WeightedUnionfind {
  vector<ll> p;
  vector<T> w;
  WeightedUnionfind(ll N): p(N, -1), w(N, T()) {}
  ll root(ll x) {
    if(p[x] < 0) { return x; }
    ll r = root(p[x]);
    w[x] += w[p[x]];
    return p[x] = r;
  }
  // return w[x] - w[root(x)]
  T potential(ll x) {
    root(x);
    return w[x];
  }
  bool same(ll x, ll y) {
    return root(x) == root(y);
  }
  // return w[y] - w[x]
  T diff(ll x, ll y) { return potential(y) - potential(x); };
  // w[y] = w[x] + p, return satisfiability
  bool unite(ll x, ll y, T d) {
    d += potential(x) - potential(y);
    y = root(y), x = root(x);
    if(y == x) { return d == T(); }
    if(p[y] < p[x]) {
      swap(y, x);
      d = -d;
    }
    p[x] += p[y];
    p[y] = x;
    w[y] = d;
    return true;
  }
  ll size(ll x) { return -p[root(x)]; }
};