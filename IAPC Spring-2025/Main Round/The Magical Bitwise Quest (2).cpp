#include<bits/stdc++.h>
#define iamspeed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
#define ll long long int
using namespace std;
const int N = 2e5 + 5;
const ll mod = 1e9 + 7;
string s, ss;
ll d, cnt, t, tt, cnt2, sum, ans, res, q, n, m, k, x, y, z;

bool check(int a, int b, int c) {
    return (((a & b) == x) && ((b & c) == y) && ((c & a) == z));
}

int main() {
    iamspeed

    for (cin >> t; t--;) {
        cin >> x >> y >> z;
        int a = (x | z);
        int c_bar = (((1 << 31) - 1) ^ a);
        int c = (z | c_bar);
        int b_bar = (((1 << 31) - 1) ^ c);
        b_bar = (x & b_bar);
        int b = (y | b_bar);
        ///cout << (a & b) << ' ' << (b & c) << ' ' << (c & a) << endl;
        if (check(a, b, c))
        {
            cout << a << ' ' << b << ' ' << c << endl;
        }
        else cout << -1 << endl;
    }


    return 0;
}