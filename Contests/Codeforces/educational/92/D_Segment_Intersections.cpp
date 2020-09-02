#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define int long long
#define ld long double
#define ff first
#define ss second
#define BS binary_search
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define get(a, t) get<a>(t)
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;
double EPS = 1e-9;
double PI = acos(-1);
int dirx[8] ={ -1, 0, 0, 1, -1, -1, 1, 1 };
int diry[8] ={ 0, 1, -1, 0, -1, 1, -1, 1 };

#ifdef TESTING
#define DEBUG fprintf(stderr, "====TESTING====\n")
#define VALUE(x) cerr << "The value of " << #x << " is " << x << endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define DEBUG
#define VALUE(x)
#define debug(...)
#endif
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define FORC(a, b, c) for (char(a) = (b); (a) <= (c); ++(a))
#define FOREACH(a, b) for (auto &(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define SQR(x) ((LL)(x) * (x))
#define RESET(a, b) memset(a, b, sizeof(a))
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PERMUTE next_permutation
const int INF = 1e18;
const int N = 100005;
int mod = 1e9 + 7;
void solve()
{
    int n, k;
    cin >> n >> k;
    int l1, l2, r1, r2, mx1, mx2, mn1, mn2;
    cin >> l1 >> r1;
    cin >> l2 >> r2;
    if (l2 < l1)
    {
        swap(l1, l2);
        swap(r1, r2);
    }
    int cr = max(0LL, min(r2, r1) - max(l1, l2)) * n;
    if (cr >= k)
    {
        cout << 0 << endl;
        return;
    }
    if (r1 >= r2 && r2 >= l2)
    {
        int dif = k - cr;
        int inc = ((r1 - r2) + (l2 - l1)) * n;
        if (dif <= inc)
        {
            cout << dif << endl;
            return;
        }
        int ans = inc;
        dif -= inc;
        ans += (dif * 2);
        cout << ans << endl;
        return;
    }
    if (l2<r1)
    {
        int dif = k - cr;
        int inc = ((r2 - r1) + (l2 - l1)) * n;
        if (dif <= inc)
        {
            cout << dif << endl;
            return;
        }
        int ans = inc;
        dif -= inc;
        ans += (dif * 2);
        cout << ans << endl;
        return;
    }
    int ans = INF;
    for (int i = 1; i <= n; ++i) {
        int cur = (l2 - r1) * i, free = (r2 - l1) * i, steps = cur, taken = 0;
        steps += min(free, k), taken += min(free, k);
        if (taken < k) steps += 2 * (k - taken);
        ans=min(steps, ans);
    }
    cout << ans << endl;
    return;
}
int32_t main()
{
    IOS;
    int t;
    cin >> t;
    //int t=1;
    for (int tc = 1; tc <= t; tc++)
    {
        //cout<<"Case #"<<tc<<": ";
        solve();
    }
    return 0;
}