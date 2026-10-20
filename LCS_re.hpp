#pragma once

vector<pair<ll, ll>> LCS_re(auto &S, auto &T) {
  int N = S.size(), M = T.size();
  vector<vector<int>> DP(N + 1, vector<int>(M + 1));
  for(ll i = 0; i < N; i++) {
    auto &dp = DP[i], &ndp = DP[i + 1];
    ndp = dp;
    for(ll j = 0; j < M; j++) {
      ndp[j + 1] = max(ndp[j + 1], ndp[j]);
      if(S[i] == T[j]) { ndp[j + 1] = max(ndp[j + 1], dp[j] + 1); }
    }
  }

  vector<pair<ll, ll>> r;
  int n = N, m = M;
  while(DP[n][m]) {
    if(DP[n][m] == DP[n - 1][m]) { n--; }
    else if(DP[n][m] == DP[n][m - 1]) { m--; }
    else {
      n--, m--;
      r.emplace_back(n, m);
    }
  }
  ranges::reverse(r);
  return r;
}