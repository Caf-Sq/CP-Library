#pragma once

// n 個から k 個選ぶ
// 中身を取り出して使うことでMLEを回避できる，時間的にもだいぶ速い
vector<vector<ll>> EnumCombination(int n, int k) {
  vector<vector<ll>> r;
  vector<ll> v(k);
  auto DFS = [&](auto &&DFS, int p, int s) -> void {
    if(p == k) {
      r.emplace_back(v);
      return;
    }
    for(ll i = s + 1; i < n; i++) {
      v[p] = i;
      DFS(DFS, p + 1, i);
    }
  };
  DFS(DFS, 0, -1);
  return r;
}