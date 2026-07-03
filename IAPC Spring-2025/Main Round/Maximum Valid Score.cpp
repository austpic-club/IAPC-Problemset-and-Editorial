#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int ACTIVE_L = 0;
const int ACTIVE_R = 1;
const int ACTIVE_NOONE = 2;

const int INF = 1000000000;
const int MX = 100;
const int MX_LEN = 10;
int dp[MX][MX][MX_LEN + 1][3];
int A[MX], Sn[MX];
string S[MX];

bool check_palindrome_self(string& s, int l, int r) {
  while (l < r) {
    if (s[l] != s[r]) return 0;
    ++l; --r;
  }
  return 1;
}

int get_next_taken_len(int L, int R, int taken_len, int who) {
  string& sl = S[L];
  string& sr = S[R];

  int l = 0, r = Sn[R] - 1;
  if (taken_len > 0) {
    if (who == ACTIVE_L) l += taken_len;
    else r -= taken_len;
  }

  int ntaken_len = 0;
  while ((l < Sn[L]) && (r >= 0)) {
    if (sl[l] != sr[r]) return -1;
    ++l; --r;
    ntaken_len += 1;
  }

  return ntaken_len;
}

int solve(int l, int r, int taken_len, int who) {
  if (l > r) {
    if (who == ACTIVE_NOONE) return -INF;
    if (taken_len == 0) return 0;
    return -INF;
  }
  if (l == r) {
    int ans = -INF;
    if (taken_len == 0) {
      if (who != ACTIVE_NOONE) ans = max(ans, 0);
      if (check_palindrome_self(S[l], 0, Sn[l] - 1)) ans = max(ans, A[l]);
    } else if (who == ACTIVE_L) {
      if (check_palindrome_self(S[l], taken_len, Sn[l] - 1)) ans = max(ans, A[l]);
    } else {
      if (check_palindrome_self(S[l], 0, Sn[l] - 1 - taken_len)) return ans = max(ans, A[l]);
    }
    return ans;
  }

  int& curr = dp[l][r][taken_len][who];
  if (curr != -1) return curr;

  curr = -INF;
  if (taken_len == 0) {
    curr = max(curr, solve(l + 1, r, taken_len, who));
    curr = max(curr, solve(l, r - 1, taken_len, who));
  } else if (who == ACTIVE_L) {
    curr = max(curr, solve(l, r - 1, taken_len, who));
  } else {
    curr = max(curr, solve(l + 1, r, taken_len, who));
  }

  int ntaken_len = get_next_taken_len(l, r, taken_len, who);
  int taken_len_l = 0;
  int taken_len_r = 0;
  if (who == ACTIVE_L) taken_len_l += taken_len;
  else taken_len_r += taken_len;

  if (ntaken_len != -1) {
    taken_len_l += ntaken_len;
    taken_len_r += ntaken_len;
    if ((taken_len_l == Sn[l]) && (taken_len_r == Sn[r])) curr = max(curr, A[l] + A[r] + solve(l + 1, r - 1, 0, ACTIVE_L));
    else if (taken_len_l == Sn[l]) curr = max(curr, A[l] + solve(l + 1, r, taken_len_r, ACTIVE_R));
    else if (taken_len_r == Sn[r]) curr = max(curr, A[r] + solve(l, r - 1, taken_len_l, ACTIVE_L));
  }

  return curr;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int tc = 1;
  cin >> tc;
  assert((1 <= tc) && (tc <= 100));

  for (int ti = 1; ti <= tc; ++ti) {
    int n;
    cin >> n;
    assert((1 <= n) && (n <= 100));

    for (int i = 0; i < n; ++i) {
      cin >> S[i] >> A[i];
      assert((1 <= (int)S[i].size()) && ((int)S[i].size() <= 10));
      assert((-100000 <= A[i]) && (A[i] <= 100000));
    }

    for (int i = 0; i < n; ++i) {
      Sn[i] = (int)S[i].size();
    }

    memset(dp, -1, sizeof(dp));

    int ans = solve(0, n - 1, 0, ACTIVE_NOONE);

    if (ans < -INF / 2) cout << "impossible" << "\n";
    else cout << ans << "\n";
  }

  return 0;
}