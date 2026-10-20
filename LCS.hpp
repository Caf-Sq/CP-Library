#pragma once

ll LCS(auto &S, auto &T) {
  int N = T.size();
  vector<int> dp(N + 1);
  for(auto &c : S) {
    for(ll i = N - 1; i >= 0; i--) {
      if(c == T[i]) { dp[i + 1] = max(dp[i + 1], dp[i] + 1); }
    }
    for(ll i = 0; i < N; i++) { dp[i + 1] = max(dp[i + 1], dp[i]); }
  }
  return dp[N];
}