#include<bits/stdc++.h>
using namespace std;

#define ll                 long long int
/*#ifndef ONLINE_JUDGE
#include "DEBUG.h"
#define bug(...)           __f (#__VA_ARGS__, __VA_ARGS__)
#endif*/

ll getsum(ll n)
{
	return (n * (n + 1)) / 2;
}

void solve()
{
	ll n;
	cin >> n;

	int left = 1, right = 2e9, mid, ans = 1;

	while (left <= right)
	{
		mid = left + (right - left) / 2;

		ll sum = getsum(mid);

		if (sum <= n)
		{
			ans = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;

	}

	cout << ans << "\n";

	ll sum = getsum(ans);
	ll rem = n - sum;

	cout << ans + rem << " ";

	for (ll i = ans - 1; i >= 1; i--)
		cout << i << " ";


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