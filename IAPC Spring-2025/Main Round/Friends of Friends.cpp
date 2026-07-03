#include<bits/stdc++.h>
using namespace std;

#define ll                 long long int
// #ifndef ONLINE_JUDGE
// #include "DEBUG.h"
// #define bug(...)           __f (#__VA_ARGS__, __VA_ARGS__)
// #endif

const int N = 1e5 + 2;
vector<int>a(N);

struct DSU
{
	vector<int>par; vector<int>sz; vector<int>cycle;
	stack<tuple<int, int, int>> stk;
	vector<ll>sum;
	DSU(int _n)
	{
		par.resize(_n + 1); sz.resize(_n + 1); cycle.resize(_n + 1);
		sum.resize(_n + 1);

		for (int i = 0; i <= _n; i++)
			make(i);
	}
	void make(int node)
	{
		par[node] = node;
		sz[node] = 1;
		sum[node] = a[node];
	}

	int find(int node)
	{
		if (par[node] == node)
			return node;
		return par[node] = find(par[node]);
	}

	void Union(int nodeA, int nodeB)
	{
		nodeA = find(nodeA);
		nodeB = find(nodeB);
		if (nodeA != nodeB)
		{
			if (sz[nodeA] < sz[nodeB])
				swap(nodeA, nodeB);

			if (cycle[nodeB])
				cycle[nodeA] = 1;
			//stk.emplace(nodeB, par[nodeB], sz[nodeA]);
			par[nodeB] = nodeA;
			sz[nodeA] += sz[nodeB];
			sum[nodeA] += sum[nodeB];

		}
		else
			cycle[nodeA] = 1;
		// stk.emplace(-1, -1, -1);
	}

	void rollback() {
		if (stk.empty())
			return;

		auto [nodeB, old_par_B, old_sz_A] = stk.top();
		stk.pop();
		if (nodeB == -1)
			return;
		int nodeA = par[nodeB];
		par[nodeB] = old_par_B;
		sz[nodeA] = old_sz_A;
	}
};


void solve()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	DSU ds(n);

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		ds.Union(x, y);
	}

	for (int i = 1; i <= n; i++) {
		ll sum = ds.sum[ds.find(i)] - a[i];
		cout << sum << " ";
	}

	cout << "\n";


}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t = 1;
	//cin >> t;

	while (t--)
		solve();

}