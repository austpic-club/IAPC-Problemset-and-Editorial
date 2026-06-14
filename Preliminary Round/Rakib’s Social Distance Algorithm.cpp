#include<bits/stdc++.h>
using namespace std;

#define ll                 long long int
// #ifndef ONLINE_JUDGE
// #include "DEBUG.h"
// #define bug(...)           __f (#__VA_ARGS__, __VA_ARGS__)
// #endif



void solve()
{
	int n, k;
	cin >> n >> k;
	vector<string>v(n);
	string s;
	cin.ignore(1, '\n');

	for (int i = 0; i < n; i++)
	{
		getline(cin, s);
		v[i] = s;
	}
	vector<tuple<int, ll, int>>ans;

	for (int i = 0; i < n; i++)
	{
		bool f = 1;
		int cnt = 0;
		ll sum = 0;
		s = v[i];

		for (int j = 0; j < v[i].size(); j++)
		{

			if (s[j] == '*') {
				f = 0;
				break;
			}
			else if (s[j] == '#')
				;
			else if (isdigit(s[j]))
			{

				int num = 0;
				while (j < v[i].size() and isdigit(s[j]))
				{
					num = (num * 10) + s[j] - '0';
					j++;
				}
				j--;


				if (num < k)
				{
					f = 0;
					break;
				}


				sum += num;
				cnt++;
			}

		}

		if (f)
			ans.push_back({cnt, sum, i});
	}

	sort(ans.begin(), ans.end(), [&](auto & a, auto & b)
	{
		if (get<0>(a) == get<0>(b))
		{
			if (get<1>(a) == get<1>(b))
				return get<2>(a) < get<2>(b);
			return get<1>(a) > get<1>(b);
		}
		return get<0>(a) < get<0>(b);
	});

	if (ans.empty())
		cout << "Rag korla?";
	else
		cout << get<2>(ans[0]) + 1 << " " << get<0>(ans[0]);

	//cout << "\n";



}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t = 1;
	//cin >> t;

	while (t--)
		solve();

}