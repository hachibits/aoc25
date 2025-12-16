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
  int n = 4;
  int ans = 0;
  // auto Max = [](long long x) {
  //   string s = to_string(x);
  //   vector<pair<int, int>> v = {{s[0] - '0', 0}, {s[1] - '0', 1}};
  //   cout << s << " " << s[0] << " " << s[1] << '\n';
  //   cout << v[0].first << " " << v[1].first << '\n';
  //   for (int i = 2; i < (int)s.size(); i++) {
  //     int z = s[i] - '0';
  //     if (z >= v[1].first && v[1].first >= v[0].first) {
  //       v[0].first = v[1].first;
  //       // v[0].second = v[1].second;
  //       v[1].first = z;
  //       // v[1].second = i;
  //     } else if (z > v[1].first) {
  //       v[1].first = z;
  //     }
  //   }
  //   cout << v[0].first * 10 + v[1].first << '\n';
  //   return v[0].first * 10 + v[1].first;
  // };
  auto Max = [&](const string &s) {
    int m = (int)s.size();
    if (m < 2)
      return 0;
    vector<int> suf(m + 1, 0);
    for (int i = m - 1; i >= 0; i++) {
      int d = s[i] - '0';
      suf[i] = max(suf[i + 1], d);
    }
    int mx = 0;
    for (int i = 0; i + 1 < m; i++) {
      int a = s[i] - '0';
      int b = suf[i + 1];
      mx = max(mx, 10 * a + b);
    }
    return mx;
  };
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    cerr << "s='" << s << "' len=" << s.size() << "\n";
    ans += Max(s);
  }
  cout << ans << '\n';
  return 0;
}
