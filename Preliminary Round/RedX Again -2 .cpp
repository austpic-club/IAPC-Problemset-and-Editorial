#include<bits/stdc++.h>
using namespace std;

#define ll                 long long int
// #ifndef ONLINE_JUDGE
// #include "DEBUG.h"
// #define bug(...)           __f (#__VA_ARGS__, __VA_ARGS__)
// #endif


void solve()
{
	int n, m, x, y;
	cin >> n >> m >> x >> y;

	vector<pair<int, int>>a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;

	int ans = 0;
	map<pair<int, int>, int>mp;

	for (int i = 0; i < n; i++)
	{

		int dx = x - a[i].first;
		int dy = y - a[i].second;
		int gc = abs( __gcd(dx, dy));
		dx /= gc;
		dy /= gc;
		mp[ {dx, dy}]++;
	}

	for (auto &[x, y] : mp)
		ans = max(ans, y);


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