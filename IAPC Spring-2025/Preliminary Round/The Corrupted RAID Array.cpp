#include<bits/stdc++.h>
using namespace std;

#define ll                 long long int
// #ifndef ONLINE_JUDGE
// #include "DEBUG.h"
// #define bug(...)           __f (#__VA_ARGS__, __VA_ARGS__)
// #endif



void solve()
{
	int n;
	cin >> n;

	vector<int>a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int q;
	cin >> q;

	vector<ll>pref(n + 1);
	for (int i = 1; i <= n; i++)
	{
		pref[i] = a[i - 1];
		pref[i] += pref[i - 1];
	}

	vector<ll>v;


	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j += i)
			v.push_back(pref[j] - pref[j - i]);
	}
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()),v.end());


	while (q--)
	{
		ll x;
		cin >> x;

		auto it = upper_bound(v.begin(), v.end(), x) - v.begin();
		it--;

		cout << it+1 << "\n";

	}
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t = 1;
	//cin >> t;

	while (t--)
		solve();

}