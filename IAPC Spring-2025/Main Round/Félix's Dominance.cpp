#include<bits/stdc++.h>
using namespace std;

#define ll                 long long int
/*#ifndef ONLINE_JUDGE
#include "DEBUG.h"
#define bug(...)           __f (#__VA_ARGS__, __VA_ARGS__)
#endif*/

string yo(string &s)
{
  stack<char>st;
  vector<int>last(26, -1), seen(26);
  int n = s.size();

  for (int i = 0; i < n; i++)
    last[s[i] - 'a'] = i;

  for (int i = 0; i < n; i++) {

    while (st.size() and st.top() > s[i] and !seen[s[i] - 'a']) {
      if (last[st.top() - 'a'] > i)
        seen[st.top() - 'a'] = 0, st.pop();
      else
        break;
    }

    if (!seen[s[i] - 'a'])
      st.push(s[i]), seen[s[i] - 'a'] = 1;
  }


  string res;
  while (st.size()) {
    res += st.top();
    st.pop();
  }

  reverse(res.begin(), res.end());
  return res;

}

void solve()
{
  vector<string>v(4);

  for (int i = 0; i < 4; i++)
    cin >> v[i];

  sort(v.begin(), v.end());
  set<string>st;
  do
  {
    string t;
    for (auto x : v) 
      t += x;
    


    st.insert(yo(t));

  } while (next_permutation(v.begin(), v.end()));

  cout << *st.begin() << "\n";
}


int main()
{
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int t = 1;
  //cin >> t;

  while (t--)
    solve();

}