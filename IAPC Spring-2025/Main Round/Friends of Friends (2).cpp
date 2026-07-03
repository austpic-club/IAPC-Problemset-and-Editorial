#include<bits/stdc++.h>
using namespace std;

#define ll                 long long int
// #ifndef ONLINE_JUDGE
// #include "DEBUG.h"
// #define bug(...)           __f (#__VA_ARGS__, __VA_ARGS__)
// #endif

const int N = 1e5 + 2;
vector<int>v[N], a(N), clr(N);
vector<ll>sum(N);

void dfs(int node, int c)
{
	clr[node] = c;
	sum[c] += a[node];

	for (auto x : v[node])
	{
		if (clr[x] == 0)
			dfs(x, c);
	}
}

void solve()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	for (int i = 1, c = 1; i <= n; i++)
	{
		if (clr[i] == 0)
			dfs(i, c++);
	}

	for (int i = 1; i <= n; i++)
		cout << sum[clr[i]] - a[i] << " ";


}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t = 1;
	//cin >> t;

	while (t--)
		solve();

}