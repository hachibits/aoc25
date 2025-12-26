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
  int H = 137;
  vector<string> a(H);
  vector<pair<int, int>> dirs{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                              {0, 1},   {1, -1}, {1, 0},  {1, 1}};
  for (int i = 0; i < H; i++) {
    cin >> a[i];
  }
  int W = (int)a[0].length();
  auto inside = [&](int row, int col) {
    return 0 <= row && row < H && 0 <= col && col < W;
  };
  auto valid = [&](int r, int c) {
    int cnt = 0;
    for (auto [dx, dy] : dirs) {
      if (inside(r + dx, c + dy) && a[r + dx][c + dy] == '@') {
        cnt++;
      }
    }
    return cnt < 4 && a[r][c] == '@';
  };
  int ans = 0;
  int n;
  while (n != 0) {
    n = 0;
    for (int r = 0; r < H; r++) {
      for (int c = 0; c < W; c++) {
        n += valid(r, c);
        if (valid(r, c) && a[r][c] == '@') {
          a[r][c] = '.';
        }
      }
    }
    ans += n;
  }
  cout << ans << '\n';
  return 0;
}
