#include <bits/stdc++.h>
using namespace std;

typedef long long          ll;
typedef long double        ld;
typedef unsigned long long ull;
typedef pair<int, int>     pii;
typedef pair<ll, ll>       pll;
typedef vector<int>        vi;
typedef vector<ll>         vll;

const int N      = (int) 2e5 + 5;
const int mxN    = (int) 1e6 + 6;
const int MOD    = (int) 1e9 + 7;
const int INF    = (int) 1e9 + 9;
const double EPS = (double) 1e-9;

#define all(x)   x.begin(), x.end()
#define szof(x)  (int) x.size()
#define ff       first
#define ss       second
#define pb       push_back
#define nl       '\n'
#define PI       acos(-1.0)
#define debug(x) cerr << #x << " = " << x << '\n';

/*................. let's try one more time .................*/

vector<pair<ll, pii>> edge;

class Dsu {
  vi par, rank;
  int n;

  int root(int x) { return par[x] = par[x] == x ? x : root(par[x]); }

public:
  Dsu(int n) {
    this->n = n;
    par.assign(n + 2, 0);
    rank.assign(n + 2, 0);
    for (int i = 0; i <= n; ++i) par[i] = i;
  }

  bool merge(int a, int b) {
    int x = root(a), y = root(b);
    if (x == y) return 0;
    if (rank[x] <= rank[y]) swap(x, y);
    par[y] = x;
    if (rank[x] == rank[y]) rank[x]++;
    return 1;
  }
};

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false); cin.tie(0);
  int test = 1, tc = 0;
  while (test--) {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
      int u, v;
      ll w; cin >> u >> v >> w;
      edge.pb({w, {u, v}});
    }
    Dsu ds(n);
    sort(all(edge));
    ll cost = 0;
    int k = 0;
    for (auto x : edge) {
      ll w = x.ff;
      int u = x.ss.ff, v = x.ss.ss;
      if (ds.merge(u, v)) {
        k++;
        cost += w;
      }
    }
    if (k != (n - 1)) cout << "IMPOSSIBLE" << nl;
    else cout << cost << nl;
  }
  return 0;
}
