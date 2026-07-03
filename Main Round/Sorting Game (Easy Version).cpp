/*
    Author: MEHEDI ISLAM REMON
    AUST CSE 44th Batch

*/
#include<bits/stdc++.h>
#define ll      long long int
#define fast    ios_base::sync_with_stdio(0);cin.tie(0);cin.tie(nullptr); cout.tie(nullptr);
#define pb      push_back
#define pi      acos(-1)
#define Mod     100000007
#define sn      10000000011
#define MAX     LLONG_MAX
using namespace std;

bool compare1(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
    return (a.second < b.second) || (a.second == b.second && a.first > b.first);
}

bool compare(ll a, ll b)
{
    return a < b;
}

int main()
{
    fast;


    ll t;
    cin >> t;
    vector<pair<ll, ll>>v(1000001);
    v[0].first = LLONG_MAX;
    v[0].second = LLONG_MIN;
    for (ll j = 1; j <= 1000000; j++)
    {
        for (ll k = j; k <= 1000000; k += j)
        {
            v[k].first = k;
            v[k].second++;
        }
    }
    sort(v.begin(), v.end(), compare1);
    /*for(ll i=1; i<=1000; i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<endl;

    }*/
    for (ll i = 0; i < t; i++)
    {
        ll x;
        cin >> x;
        //cout<<"Case "<<i+1<<": "<<v[x].first<<endl;
        cout << v[x].first << endl;
    }

}