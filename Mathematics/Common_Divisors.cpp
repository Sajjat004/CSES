#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef unsigned long long  ull;
typedef pair <int, int>     pii;
typedef pair <ll, ll>       pll;
typedef vector <int>        vi;
typedef vector <ll>         vll;

const int N       = (int) 2e5 + 5;
const int mxN     = (int) 1e6 + 6;
const int MOD     = (int) 1e9 + 7;
const int INF     = (int) 1e9 + 9;
const double EPS  = (double) 1e-9;

#define debug(x)  cerr << #x << " = " << x << '\n';
#define all(x)    x.begin(), x.end()
#define szof(x)   (int) x.size()
#define ff        first
#define ss        second
#define pb        push_back
#define mp        make_pair
#define PI        acos(-1.0)
#define nl        '\n'
#define Fast_IO   ios_base::sync_with_stdio(false); cin.tie(0);

/*........................ let's try one more time ........................*/

#ifdef LOCAL
#include "headerFile/debug.h"
#endif

vi cnt(mxN, 0);

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  Fast_IO
  int test = 1, tc = 0;
  while (test--) {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
      int x; cin >> x;
      cnt[x]++;
    }
    vi cntDiv(mxN, 0);
    for (int i = 2; i < mxN; ++i) {
      for (int j = i; j < mxN; j += i) {
        if (cnt[j]) {
          cntDiv[i] += cnt[j];
        }
      }
    }
    int res = 1;
    
    for (int i = mxN - 1; i > 1; --i) {
      if (cntDiv[i] > 1) {
        res = i;
        break;
      }
    }
    cout << res << nl;
  }
  return 0;
}
