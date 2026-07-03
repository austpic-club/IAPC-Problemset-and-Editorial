#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int MOD = 998244353;
const int INF = 1e18;
const int N = 2e5;
/**/
void solve(int tc) {
    int n,m; cin >> n >> m;
    vector<vector<int>>tree(n + 1);
    for(int i=0;i<n-1;i++){
        int u,v; cin >> u >> v;
        u++;
        v++;
        tree[u].push_back(v);
    }
    vector<int>val(n + 1);
    vector<vector<int>>dp(n + 1 , vector<int>(m , INF));
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        val[i] = x;
    }
    function<void(int,int)>dfs = [&](int v,int p){
        vector<int>childs;
        for(auto c : tree[v]){
            if(c == p)continue;
            childs.push_back(c);
            dfs(c,v);
        }
        for(int i=m-1;i>=0;i--){
            int cost = 0;
            for(auto c : childs)
                cost += dp[c][i];
            dp[v][i] = (val[v] != i) + cost;
            if(i + 1 < m)dp[v][i] = min(dp[v][i] , dp[v][i+1]);
        }
    };
    dfs(1,0);
    cout << dp[1][0] << endl;
}   
int32_t main() {
    FAST
    int t = 1;
    // cin >> t;
    for (int tc = 1; tc <= t; tc++)
        solve(tc);
    return 0;
}