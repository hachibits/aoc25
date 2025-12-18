#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
  cerr << " " << H;
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll MOD = (ll)(1e9) + 7ll;
const ll INF = (1ll << 60);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  // auto Max = [&](const string &s, int k) {
  //   int m = (int)s.size();
  //   if (m <= k) {
  //     long long x = 0;
  //     for (char c : s) {
  //       x = x * 10 + (c - '0');
  //     }
  //     return x;
  //   }
  //   int drop = m - k;
  //   string z;
  //   z.reserve(m);
  //   for (char c : s) {
  //     while (drop > 0 && !z.empty() && z.back() < c) {
  //       z.pop_back();
  //       drop--;
  //     }
  //     z.push_back(c);
  //   }
  //   z.resize(k);
  //   long long v = 0;
  //   for (char c : z) {
  //     v = v * 10 + (c - '0');
  //   }
  //   return v;
  // };
  // int ans = 0;
  // const int k = 12;
  // string s;
  // while (cin >> s) {
  //   //  cerr << "s='" << s << "' len=" << s.size() << "\n";
  //   ans += Max(s, k);
  // }
  auto Max = [&](const vector<int> &v) {
    const size_t k = 12;
    array<long long, k + 1> mx{};
    mx.fill(0);
    for (int n : v) {
      array<long long, k + 1> new_mx = mx;
      for (int i = 0; i < k; i++) {
        long long x = 10ULL * mx[i] + (long long)n;
        if (x > new_mx[i + 1]) {
          new_mx[i + 1] = x;
        }
      }
      mx = new_mx;
    }
    long long res = 0;
    for (size_t i = 1; i < mx.size(); i++) {
      res = max(res, mx[i]);
    }
    return res;
  };
  long long ans = 0;
  string s;
  while (cin >> s) {
    vector<int> v;
    for (char c : s) {
      if (c >= '0' && c <= '9') {
        v.push_back(c - '0');
      }
    }
    ans += Max(v);
  }
  cout << ans << '\n';
  return 0;
}
