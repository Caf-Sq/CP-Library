#pragma once

vector<vector<ll>> DivisorTable(int N) {
  vector<vector<ll>> div(N + 1);
  for(ll i = 1; i <= N; i++) {
    for(ll j = i; j <= N; j += i) { div[j].emplace_back(i); }
  }
  return div;
}