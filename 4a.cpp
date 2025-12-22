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

vector<pair<int, int>> dirs{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

vector<vector<int>> bfs(pair<int, int> start) {}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int H = 137;
  vector<string> a;
  for (int i = 0; i < H; i++) {
    cin >> a[i];
  }
  int W = (int)a[0].length();
  auto inside = [&](int row, int col) {
    return 0 <= row && row < H && 0 <= col && col < W;
  };
  int ans = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
    }
  }
  cout << ans << '\n';
  return 0;
}
