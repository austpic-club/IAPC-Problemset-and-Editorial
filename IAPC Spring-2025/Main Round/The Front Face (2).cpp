#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

vector<int> par;
int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    ll y;
    cin >> y;
    vector<ll> B(n + 1);
    for (int k = 0; k <= n; k++) cin >> B[k];

    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) { return a[i] > a[j]; });

    int mb = 0;
    for (int v : b) mb = max(mb, v);
    par.assign(mb + 1, 0);
    iota(par.begin(), par.end(), 0);
    vector<int> cnt(mb + 1, 0);

    vector<ll> S;
    S.push_back(0);
    for (int id : idx) {
        if (y == 0) break;
        int m = find(b[id]);
        if (m >= 1) {
            if (++cnt[m] == y) par[m] = find(m - 1);
            S.push_back(S.back() + a[id]);
        }
    }

    ll ans = LLONG_MIN;
    for (int k = 0; k < (int)S.size(); k++) ans = max(ans, S[k] + B[k]);
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;
    while (tc--) {
        solve();
    }
    return 0;
}