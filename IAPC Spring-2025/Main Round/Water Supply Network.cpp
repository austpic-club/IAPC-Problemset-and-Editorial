#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long int lli;
typedef unsigned long long ul;
 
#define pii  pair<lli, lli>
#define PI acos(-1.0)
#define vi vector<lli>
#define pb push_back
#define mp make_pair
#define YES cout << "YES" << "\n";
#define NO cout << "NO" << "\n";
#define yes cout << "Yes" << "\n";
#define no cout << "No" << "\n";
#define mnp cout << "-1" << "\n";
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SORT(vec) sort(vec.begin(),vec.end())
#define CLR(vec) vec.clear()
#define REV(vec) reverse(vec.begin(),vec.end())
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define display(vec) for(auto it:vec){cout << it << " ";}cout << endl;
 
 
void solve(){
    lli n, x, y, c, xx = 0, sum = 0;
    cin >> n;
    lli from[107]={0};
    lli to[107]={0};
    for(lli i=0; i<n; i++){
        cin >> x >> y >> c;
        xx += c;
        if(from[x]||to[y]){
            from[y] = 1;
            to[x] = 1;
            sum += c;
        }
        else{
            from[x] = 1;
            to[y] = 1;
        }
    }
    cout << min(sum, xx-sum) << endl;
}
 
 
int main()
{
    FAST
 
    lli t = 1;
 
    //cin >> t;
    while(t--){
        solve();
    }
 
    return 0;
}