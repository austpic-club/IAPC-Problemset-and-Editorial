#include<bits/stdc++.h>
using namespace std;

#define ll                 long long int
// #ifndef ONLINE_JUDGE
// #include "DEBUG.h"
// #define bug(...)           __f (#__VA_ARGS__, __VA_ARGS__)
// #endif

bool co(int x, int y, int x1, int y1, int x2, int y2) {

	bool line = (1ll * (y1 - y) * (x2 - x) == 1ll * (y2 - y) * (x1 - x));
	bool dir = (1ll * (x1 - x) * (x2 - x) >= 0) && (1ll * (y1 - y) * (y2 - y) >= 0);

	return line and dir;
}

void solve()
{
	int n, m, x, y;
	cin >> n >> m >> x >> y;

	vector<pair<int, int>>a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;

	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;
			if (co(x, y, a[i].first, a[i].second, a[j].first, a[j].second))
				cnt++;
		}
		ans = max(ans, cnt + 1);
	}


	cout << ans << "\n";

}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t = 1;
	cin >> t;

	while (t--)
		solve();

}