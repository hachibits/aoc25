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
  string s;
  cin >> s;
  vector<pair<ll, ll>> a;
  for (int i = 0; i < (int)s.size();) {
    ll x = 0, y = 0;
    while (i < (int)s.size() && isdigit(s[i])) {
      x = x * 10 + (s[i++] - '0');
    }
    ++i;
    while (i < (int)s.size() && isdigit(s[i])) {
      y = y * 10 + (s[i++] - '0');
    }
    a.emplace_back(x, y);
    if (i < (int)s.size() && s[i] == ',') {
      ++i;
    }
  }
  auto valid = [&](string x) {
    for (int k = 2; k <= (int)x.size(); k++) {
      if (x.size() % k != 0) {
        continue;
      }
      string z = x.substr(0, x.size() / k);
      string t;
      for (int j = 0; j < k; j++) {
        t += z;
      }
      if (t == x) {
        return false;
      }
    }
    return true;
  };
  ll ans = 0;
  for (auto [x, y] : a) {
    for (ll i = x; i <= y; i++) {
      if (!valid(to_string(i))) {
        ans += i;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
