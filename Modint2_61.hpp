#pragma once

struct Modint2_61 {
  static constexpr unsigned long long MOD = (1ULL << 61) - 1;
  unsigned long long x;
  constexpr Modint2_61(): x(0ULL) {}
  constexpr Modint2_61(unsigned long long y): x(y >= MOD ? y - MOD : y) { assert(y < MOD * 2); }
  unsigned long long val() const noexcept { return x; }
  Modint2_61 operator-() const { return Modint2_61(MOD - x); }
  Modint2_61 operator+(const Modint2_61 &a) const { return Modint2_61(x + a.x); }
  Modint2_61 operator-(const Modint2_61 &a) const { return Modint2_61(x + MOD - a.x); }
  Modint2_61 operator*(const Modint2_61 &a) const {
    __uint128_t r = __uint128_t(x) * a.x;
    r = (r >> 61) + (r & MOD);
    return Modint2_61(r);
  }
  Modint2_61 operator/(const Modint2_61 &a) const { return *this * a.inv(); }
  Modint2_61 pow(ll n) const {
    if(n < 0) { return inv().pow(-n); }
    Modint2_61 r(1), t = *this;
    while(n) {
      if(n & 1) { r *= t; }
      t *= t;
      n >>= 1;
    }
    return r;
  }
  Modint2_61 inv() const { return pow(MOD - 2); }
  Modint2_61 &operator+=(const Modint2_61 &a) { return *this = *this + a; }
  Modint2_61 &operator-=(const Modint2_61 &a) { return *this = *this - a; }
  Modint2_61 &operator*=(const Modint2_61 &a) { return *this = *this * a; }
  Modint2_61 &operator/=(const Modint2_61 &a) { return *this = *this / a; }
  template<typename T> friend Modint2_61 operator+(T a, const Modint2_61 &b) { return (Modint2_61(a) += b); }
  template<typename T> friend Modint2_61 operator-(T a, const Modint2_61 &b) { return (Modint2_61(a) -= b); }
  template<typename T> friend Modint2_61 operator*(T a, const Modint2_61 &b) { return (Modint2_61(a) *= b); }
  template<typename T> friend Modint2_61 operator/(T a, const Modint2_61 &b) { return (Modint2_61(a) /= b); }
  explicit operator bool() const { return x; }
  bool operator==(const Modint2_61 &a) const { return (x == a.x); }
  bool operator!=(const Modint2_61 &a) const { return (x != a.x); }
  bool operator<(const Modint2_61 &a) const { return x < a.x; }  // to use map
  friend ostream &operator<<(ostream &os, const Modint2_61 &a) { return os << a.x; }
};

using mint = Modint2_61;
const unsigned long long base = chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now().time_since_epoch()).count() % Modint2_61::MOD;
