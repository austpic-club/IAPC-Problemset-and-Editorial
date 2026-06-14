#include<bits/stdc++.h>
#define iamspeed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// #define int long long
#define endl '\n'
using namespace std;
const int N = 3e5 + 10;
const int mod = 998244353;

void solveYe() {
	int A, B;
	cin >> A >> B;
	int lo = 0, hi = 1e9 + 7;
	int ans = -1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (1LL * 2 * (mid + B) >= A + mid) {
			ans = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	cout << (1LL * 2 * (ans + B) == A + ans ? ans : -1) << endl;
}

int32_t main() {
	iamspeed
	int t = 1;
	cin >> t;
	while (t--) {
		solveYe();
	}

	return 0;
}