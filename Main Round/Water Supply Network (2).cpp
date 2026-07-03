#include<bits/stdc++.h>
using namespace std;

#define ll                 long long int
// #ifndef ONLINE_JUDGE
// #include "DEBUG.h"
// #define bug(...)           __f (#__VA_ARGS__, __VA_ARGS__)
// #endif

const int N = 101;
vector<pair<int, int>>v[N];

int dfs(int node, int par)
{
    if (node == 1)
        return 0;

    int ans = 0;

    for (auto [x, cost] : v[node])
    {
        if (x == par)
            continue;
        ans += cost + dfs(x, node);
    }

    return ans;
}
void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, 0});
        v[b].push_back({a, c});
    }

    int ans = INT_MAX;

    for (auto [x, cost] : v[1])
        ans = min(ans, cost + dfs(x, 1));

    cout << ans << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    //cin >> t;

    while (t--)
        solve();

}