#include <bits/stdc++.h>
using namespace std;

long long solve(vector<long long>& points, long long K)
{
    int n = points.size();

    sort(points.begin(), points.end());

    vector<long long> suffix(n + 1, 0);

    for(int i = n - 1; i >= 0; i--)
    {
        suffix[i] = suffix[i + 1] + points[i];
    }

    if(K == 0)
        return points.back();

    for(int i = 0; i < n; i++)
    {
        long long cnt = n - i;
        long long numerator = suffix[i] - K;

        if(numerator < 0)
            continue;

        if(numerator % cnt != 0)
            continue;

        long long H = numerator / cnt;

        long long left =
            (i == 0 ? 0 : points[i - 1]);

        long long right = points[i];

        if(H >= left && H < right)
        {
            long long total = 0;

            for(long long p : points)
                total += max(0LL, p - H);

            if(total == K)
                return H;
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        long long K;

        cin >> n >> K;

        vector<long long> points(n);

        for(int i = 0; i < n; i++)
            cin >> points[i];

        cout << solve(points, K) << '\n';
    }
}