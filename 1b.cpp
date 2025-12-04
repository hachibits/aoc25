#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << H;
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll MOD = (ll)(1e9)+7ll;
const ll INF = (1ll << 60);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  vector<int> a;
  string x;
  while (cin >> x) {
    char dir = x[0];
    int n = stoi(x.substr(1));
    if (dir == 'L') {
      a.push_back(-n);
    } else {
      a.push_back(n);
    }
  }
  int d = 50;
  int ans = 0;
  for (int i = 0; i < (int) a.size(); i++) {
    int dx = a[i];
    while (dx >= 100) {
      dx -= 100;
      ans++;
    }
    while (dx <= -100) {
      dx += 100;
      ans++;
    }
    if (dx > 0) {
      d += dx;
      if (d >= 100) {
        ans++;
      }
      if (d == 100) {
        d = 0;
      }
      d %= 100;
    } else {
      if (d > 0  && -dx >= d) {
        ans++;
      }
      d += dx;
      if (d < 0) {
        d += 100;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
