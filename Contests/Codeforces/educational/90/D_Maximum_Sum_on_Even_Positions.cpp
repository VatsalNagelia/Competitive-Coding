#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define int long long
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
int dirx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int diry[8] = {0, 1, -1, 0, -1, 1, -1, 1};

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
    int n;
    cin >> n;
    int a[n];
    vector<int> dif1;
    vector<int> dif2;
    int psum = 0;
    int osum = 0;
    if (n == 1)
    {
        cin>>a[0];
        cout << a[0] << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i % 2 == 0)
        {
            psum += a[i];
        }
        else
        {
            osum += a[i];
        }
    }
    for (int i = 1; i < n; i += 2)
    {
        int d = a[i] - a[i - 1];
        dif1.pb(d);
        if ((i + 1LL) < n)
        {
            d = a[i] - a[i + 1];
            dif2.pb(d);
        }
    }
    int ans1 = 0, sum1 = 0, ans2 = 0, sum2 = 0;
    if ((sz(dif1) > 0))
    {
        ans1 = dif1[0];
        sum1 = 0;
    }
    for (int r = 0; r < sz(dif1); ++r)
    {
        //cout << r << " " << dif1[r] << endl;
        sum1 += dif1[r];
        ans1 = max(ans1, sum1);
        sum1 = max(sum1, 0LL);
    }
    if (sz(dif2) > 0)
    {
        ans2 = dif2[0];
        sum2 = 0;
    }
    for (int r = 0; r < sz(dif2); ++r)
    {
        //cout << r << " " << dif2[r] << endl;

        sum2 += dif2[r];
        ans2 = max(ans2, sum2);
        sum2 = max(sum2, 0LL);
    }
    int pr = max(ans2, ans1);
    pr = max(psum + pr, psum);
    pr = max(pr, osum);
    cout << pr << endl;
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