#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define fast ios_base::sync_with_stdio(0); cin.tie(0);

typedef tree<
    pair<pair<int,int>, int>, 
    null_type, 
    less<pair<pair<int,int>, int>>, 
    rb_tree_tag, 
    tree_order_statistics_node_update
> pbds;

const int MAXN = 1000005;
int divisorCount[MAXN];

void precompute(int n) {
    for (int i = 1; i <= n; i++) divisorCount[i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            divisorCount[j]++;
        }
    }
}

void solve() {
    int N, Q;
    cin >> N >> Q;

    precompute(N);

    pbds st;
    int id = 0;

    for (int i = 1; i <= N; i++) {
        st.insert({{divisorCount[i], -i}, id++});
    }

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            auto it = st.lower_bound({{divisorCount[x], -x}, -1});
            if (it != st.end() && -it->first.second == x) {
                st.erase(it);
            }
        }
        else if (type == 2) {
            int x;
            cin >> x;
            st.insert({{divisorCount[x], -x}, id++});
        }
        else {
            int n;
            cin >> n;
            auto it = st.find_by_order(n - 1);
            cout << -it->first.second << "\n";
        }
    }
}

int main() {
    fast;
    solve();
    return 0;
}