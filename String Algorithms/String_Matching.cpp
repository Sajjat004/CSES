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

class Hashing {
  int add(int a, int b, int mod) { a += b; return a >= mod ? a - mod : a < 0 ? a + mod : a; }
  int mult(int a, int b, int mod) { return (ll) a * b % mod; }
  int power(ll base, ll exp, const int mod) {
    int res = 1;
    base %= mod;
    if (base < 0) base += mod;
    while (exp) {
      if (exp & 1) res = (1LL * res * base) % mod;
      base = (1LL * base * base) % mod;
      exp >>= 1;
    }
    return res;
  }
  int get(char ch) { return ch - 'a' + 1; }
  const int MOD1 = 127657753, MOD2 = 987654319;
  const int BASE1 = 137, BASE2 = 277;
  const int inveMod1 = power(BASE1, MOD1 - 2, MOD1);
  const int inveMod2 = power(BASE2, MOD2 - 2, MOD2);
  vector<pii> pw, invPw;
  vector<pii> hash;
  int n;
  string s;
  void build() {
    hash.push_back({0, 0});
    for (int i = 0; i < n; ++i) {
      pii p;
      p.ff = add(hash[i].ff, mult(get(s[i]), pw[i].ff, MOD1), MOD1);
      p.ss = add(hash[i].ss, mult(get(s[i]), pw[i].ss, MOD2), MOD2);
      hash.push_back(p);
    }
  }
public:
  Hashing(string _s) {
    s = _s;
    n = szof(s);
    pw.assign(n + 2, {1, 1});
    invPw.assign(n + 2, {1, 1});
    for (int i = 1; i <= n; ++i) {
      pw[i].ff = mult(pw[i - 1].ff, BASE1, MOD1);
      pw[i].ss = mult(pw[i - 1].ss, BASE2, MOD2);
      invPw[i].ff = mult(invPw[i - 1].ff, inveMod1, MOD1);
      invPw[i].ss = mult(invPw[i - 1].ss, inveMod2, MOD2);
    }
    build();
  }
  pii getHash(int l, int r) {
    pii p;
    p.ff = mult(add(hash[r].ff, -hash[l - 1].ff, MOD1), invPw[l - 1].ff, MOD1);
    p.ss = mult(add(hash[r].ss, -hash[l - 1].ss, MOD2), invPw[l - 1].ss, MOD2);
    return p;
  }
};

int main() {
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0);
  int test = 1, tc = 0;
  while (test--) {
    string s, t; cin >> s >> t;
    int n = szof(s), m = szof(t);
    Hashing hash(s);
    auto hs = Hashing(t).getHash(1, m);
    int ans = 0;
    for (int i = 1; i + m - 1 <= n; ++i) {
      if (hash.getHash(i, i + m - 1) == hs) ans++;
    }
    cout << ans << nl;
  }
  return 0;
}