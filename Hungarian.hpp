#pragma once

vector<ll> Hungarian(const vector<vector<ll>> &a) {
  const ll n = a.size();
  vector<ll> u(n + 1), v(n + 1), p(n + 1), way(n + 1);
  for(ll i = 1; i <= n; ++i) {
    p[0] = i;
    ll j0 = 0;
    vector<ll> minv(n + 1, 1e18);
    vector<bool> used(n + 1, false);
    do {
      used[j0] = true;
      ll i0 = p[j0], delta = 1e18, j1;
      for(ll j = 1; j <= n; ++j)
        if(!used[j]) {
          ll cur = a[i0 - 1][j - 1] - u[i0] - v[j];
          if(cur < minv[j]) { minv[j] = cur, way[j] = j0; }
          if(minv[j] < delta) { delta = minv[j], j1 = j; }
        }
      for(ll j = 0; j <= n; ++j) {
        if(used[j]) { u[p[j]] += delta, v[j] -= delta; }
        else { minv[j] -= delta; }
      }
      j0 = j1;
    } while(p[j0] != 0);
    do {
      ll j1 = way[j0];
      p[j0] = p[j1];
      j0 = j1;
    } while(j0);
  }
  vector<ll> ans(n);
  for(ll j = 1; j <= n; ++j) { ans[p[j] - 1] = j - 1; }
  return ans;
}