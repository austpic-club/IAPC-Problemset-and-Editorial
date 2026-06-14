#include<bits/stdc++.h>
using namespace std;

#define ll                 long long int
// #ifndef ONLINE_JUDGE
// #include "DEBUG.h"
// #define bug(...)           __f (#__VA_ARGS__, __VA_ARGS__)
// #endif



void solve()
{
	ll a, b;
	cin >> a >> b;

	ll y = a - 2 * b;
	if (y < 0)
		cout << -1 << "\n";
	else
		cout << y << "\n";
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t = 1;
	cin >> t;

	while (t--)
		solve();

}