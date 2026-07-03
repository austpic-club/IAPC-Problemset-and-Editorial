#include<bits/stdc++.h>
#define iamspeed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define endl '\n'
using namespace std;
const int N = 3e5 + 10;
const int mod = 998244353;

void solveYe() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> pos(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > n)continue;
        pos[a[i]] = i;
    }
    int mx = 0, mn = n;
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        mx = max(mx, pos[i]);
        mn = min(mn, pos[i]);
        if (mn == -1) break;
        int left = mn, right = n - mx + 1;
        ans += left * right;
        // cout << left * right << ' ' << i << endl;
    }
    cout << ans << endl;
}

int32_t main() {
    iamspeed
    int t = 1;
    cin >> t;
    while (t--) {
        solveYe();
    }

    return 0;
}