#include<bits/stdc++.h>
using namespace std;

#define ll                 long long int
// #ifndef ONLINE_JUDGE
// #include "DEBUG.h"
// #define bug(...)           __f (#__VA_ARGS__, __VA_ARGS__)
// #endif



void solve()
{
  int p, q, r;
  cin >> p >> q >> r;

  int x = (p | r);
  int y = (p | q);
  int z = (q | r);

  if ((x & y) == p and (y & z) == q and (x & z) == r)
    cout << x << " " << y << " " << z << "\n";
  else
    cout << -1 << "\n";
}


int main()
{
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int t = 1;
  cin >> t;

  while (t--)
    solve();

}