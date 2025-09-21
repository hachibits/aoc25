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
  vector<string> a;
  string x;
  while (cin >> x) {
    a.push_back(x);
  }
  int ans = 0;
  int d = 50;
  for (int i = 0; i < (int) a.size(); i++) {
    char dir = a[i][0];
    int n = stoi(a[i].substr(1));
    assert(dir == 'L' || dir == 'R');
    if (dir == 'L') {
      d -= n % 100;
    } else {
      d += n % 100;
    }
    d %= 100;
    if (d == 0) {
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
