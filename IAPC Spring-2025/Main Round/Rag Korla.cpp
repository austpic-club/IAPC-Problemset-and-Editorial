#include <bits/stdc++.h>
using namespace std;

// Problem: for each query [l, r], smallest x >= 2 sharing no factor with any
// a_i inside [l, r] but sharing a factor with at least one a_j outside; else "rag korla?".
// Answer = smallest prime present in the array whose occurrences all lie outside [l, r].
//
// Constraints: n <= 1e5, q <= 100, 2 <= a_i <= 1e8.
// sqrt(1e8) = 1e4, so trial division only needs primes up to 10000 (1229 of them).

int main() {
    const int LIM = 10000;                 // floor(sqrt(1e8))
    vector<int> primesLE;                  // primes up to LIM, for factorization
    {
        vector<char> is(LIM + 1, 1);
        is[0] = is[1] = 0;
        for (int i = 2; i <= LIM; i++)
            if (is[i])
                for (int j = i * i; j <= LIM; j += i) is[j] = 0;
        for (int i = 2; i <= LIM; i++)
            if (is[i]) primesLE.push_back(i);
    }

    int n, q;
    if (scanf("%d %d", &n, &q) != 2) return 0;
    vector<int> a(n);
    for (auto &x : a) scanf("%d", &x);

    // For each distinct prime factor of each element, record (prime, 1-indexed position).
    vector<pair<int,int>> pp;
    pp.reserve((size_t)n * 2);
    for (int i = 0; i < n; i++) {
        int v = a[i];
        for (int p : primesLE) {
            if (p * p > v) break;          // p*p <= 1e8 fits in int
            if (v % p == 0) {
                pp.push_back({p, i + 1});
                while (v % p == 0) v /= p;
            }
        }
        if (v > 1) pp.push_back({v, i + 1});   // leftover prime factor (> LIM)
    }
    sort(pp.begin(), pp.end());

    // Group: primes[] ascending, occ[k] = ascending positions of primes[k].
    vector<int> primes;
    vector<vector<int>> occ;
    for (auto &pr : pp) {
        if (primes.empty() || pr.first != primes.back()) {
            primes.push_back(pr.first);
            occ.push_back({});
        }
        occ.back().push_back(pr.second);
    }

    string out;
    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        bool found = false;
        for (size_t k = 0; k < primes.size(); k++) {   // smallest prime first
            const auto &v = occ[k];
            auto lo = lower_bound(v.begin(), v.end(), l);
            if (lo != v.end() && *lo <= r) continue;     // an occurrence lies inside [l, r]
            out += to_string(primes[k]);                 // present, none inside => some outside
            out += '\n';
            found = true;
            break;
        }
        if (!found) out += "rag korla?\n";
    }
    fputs(out.c_str(), stdout);
    return 0;
}