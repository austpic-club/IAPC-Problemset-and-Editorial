#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define ff first
#define ss second
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(a) a.size()
#define pii pair<int,int>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int MOD = 998244353;
const int N = 2e5;
int binpow(int a, int b) {
    a %= MOD;
    int res = 1;
    while (b > 0) {
        if (b & 1)res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
void solve(int tc) {
    int n, m; cin >> n >> m;
    int mx = 1 << n;
    vector<int>valid(mx, 1), dp(mx);
    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        int mask = 0;
        while (k--) {
            int l; cin >> l;
            l--;
            mask += 1 << l;
        }
        valid[mask] = 0;
    }
    int bp[65];
    bp[0] = 1;
    for (int i = 1; i < 62; i++)bp[i] = bp[i - 1] * 2;
    for (int mask = 1; mask < mx; mask++) {
        dp[mask] = bp[__builtin_popcount(mask)];
        int cnt = 0;
        for (int submask = mask ; submask ; submask = (submask - 1) & mask) {
            if (valid[submask]) {
                cnt++;
                dp[mask] += dp[mask ^ submask];
                dp[mask] %= MOD;
            }
        }
        if (cnt == 0) {
            cout << -1 << endl;
            return;
        }
        dp[mask] = (dp[mask] * binpow(cnt, MOD - 2)) % MOD;
    }
    cout << dp[mx - 1] << endl;
}
int32_t main() {
    FAST
    int t = 1;
    // cin >> t;
    for (int tc = 1; tc <= t; tc++)
        solve(tc);
    return 0;
}