#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

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
    sort(idx.begin(), idx.end(), [&](int i, int j) { return b[i] < b[j]; });

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int id : idx) {
        pq.push(a[id]);
        while ((ll)pq.size() > (ll)b[id] * y) pq.pop();
    }

    vector<ll> basis;
    while (!pq.empty()) { basis.push_back(pq.top()); pq.pop(); }
    sort(basis.rbegin(), basis.rend());
    vector<ll> S(basis.size() + 1, 0);
    for (int k = 0; k < (int)basis.size(); k++) S[k + 1] = S[k] + basis[k];

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