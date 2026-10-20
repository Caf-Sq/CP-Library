#pragma once

ll Sqrt(ll N) {
  ll n = sqrtl(N);
  while(n * n > N) { n--; }
  while((n + 1) * (n + 1) <= N) { n++; }
  return n;
}