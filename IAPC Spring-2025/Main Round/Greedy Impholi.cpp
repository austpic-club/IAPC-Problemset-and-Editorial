#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;

    vector<long long> res;
    long long cur = 1;
    long long rem = n;

    while (rem - cur > cur) {
        res.push_back(cur);
        rem -= cur;
        cur++;
    }

    res.push_back(rem);

    cout << res.size() << "\n";

    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i] << (i == 0 ? "" : " ");
    }
    cout << "\n";

    return 0;
}