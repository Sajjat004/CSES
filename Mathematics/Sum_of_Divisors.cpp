#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using vll = vector<ll>;
using vi  = vector<int>;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

const int N   = (int) 2e5 + 5;
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9 + 9;

#define nl      '\n'
#define ff      first
#define ss      second
#define szof(x) (int) x.size()
#define all(x)  x.begin(), x.end()

ll get(ll l, ll r) {
  return ((((r - l + 1) % MOD) * ((l + r) % MOD) % MOD) * 500000004 % MOD);
}

int main() {
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0);
  int test = 1, tc = 0;
  while (test--) {
    ll n; cin >> n;
    int ans = 0;
    ll m = n;
    while (m) {
      ll val = n / m;
      ll l = 1, r = m;
      ll idx;
      while (l <= r) {
        ll mid = (l + r) >> 1;
        ll x = n / mid;
        if (x > val) {
          l = mid + 1;
        } else {
          idx = mid;
          r = mid - 1;
        }
      }
      ll sub = get(idx, m); 
      ans += (1LL * (val % MOD) * sub) % MOD;
      m = idx - 1;
      ans %= MOD;
    }
    cout << ans << nl;
  }
  return 0;
}