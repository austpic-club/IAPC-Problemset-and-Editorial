#include<bits/stdc++.h>
using namespace std;

#define ll                 long long int
// #ifndef ONLINE_JUDGE
// #include "DEBUG.h"
// #define bug(...)           __f (#__VA_ARGS__, __VA_ARGS__)
// #endif


int op(int a, int b, int c)
{
	c %= 4;
	if (c == 0)
		return a + b;
	else if (c == 1)
		return (a & b);
	else if (c == 2)
		return (a | b);

	return (a ^ b);
}

void solve()
{
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int ans = 0, sum = 0;

	for (int i = 1; i < (1 << n); i++)
	{
		sum = -1;
		int j = 0, num = i;
		int c = 0;

		while (num)
		{
			if (num & 1) {
				if (sum == -1)
					sum = a[j];
				else
					sum = op(sum, a[j], c++);

			}
			j++;
			num >>= 1;
			ans = max(ans, sum);
		}

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