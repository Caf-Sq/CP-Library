#pragma once

#include <lib/Binomial.hpp>
#include <lib/FormalPowerSeries.hpp>

FPS Bernoulli(int N) {
  FPS f(N + 1);
  for(int i = 0; i <= N; i++) f[i] = C(-(i + 1));
  f = f.inv(N + 1);
  for(int i = 0; i <= N; i++) { f[i] *= C(i); }
  return f;
}