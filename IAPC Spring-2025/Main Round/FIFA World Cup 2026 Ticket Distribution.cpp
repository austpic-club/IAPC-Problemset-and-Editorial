#include<bits/stdc++.h>
using namespace std;

#define ll                 long long int
// #ifndef ONLINE_JUDGE
// #include "DEBUG.h"
// #define bug(...)           __f (#__VA_ARGS__, __VA_ARGS__)
// #endif


void solve()
{
    ll n, k;
    cin >> n >> k;

    vector<int>a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int left = 0, right = 1e9, mid, ans = -1;

    while (left <= right)
    {
        mid = (left + right) / 2;

        ll sum = 0;

        for (int i = 0; i < n; i++)
            sum += max(0, a[i] - mid);

        if (sum == k) {
            ans = mid;
            right = mid - 1;
        }
        else if (sum > k)
            left = mid + 1;
        else
            right = mid - 1;
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