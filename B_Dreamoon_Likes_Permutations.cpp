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
const int N = 200005;
int mod = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    int s = 0;
    int cnt = 0;
    ;
    vector<pii> v;
    for (int i = 0; i < n - 1; i++)
    {
        int per = ((i + 1) * (i + 2)) / 2;
        s += a[i];
        int per2 = ((n - i - 1) * (n - i)) / 2;
        if (s == per && (sum - s) == per2)
        {
            cnt++;
            v.pb({i + 1LL, n - i - 1LL});
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        int l1 = v[i].ff;
        int l2 = v[i].ss;
        int f[l1];
        int f2[l2];
        for(int i=0;i<l1;i++)
        {
            f[i]=0;
        }
        for(int i=0;i<l2;i++)
        {
            f2[i]=0;
        }
        int temp = 1;
        for (int j = 0; j < l1; j++)
        {
            if (a[j] > l1)
            {
                temp = 0;
                break;
            }
            if (f[a[j] - 1] == 1)
            {
                temp = 0;
                break;
            }
            f[a[j] - 1] = 1;
        }
        for (int j = 0; j < l1; j++)
        {
            if (f[j] == 0)
            {
                temp = 0;
                break;
            }
        }
        for (int j = l1; j < (l1 + l2); j++)
        {
            if (a[j] > l2)
            {
                temp = 0;
                break;
            }
            if (f2[a[j] - 1] == 1)
            {
                temp = 0;
                break;
            }
            f2[a[j] - 1] = 1;
        }
        for (int j = 0; j < l2; j++)
        {
            if (f2[j] == 0)
            {
                temp = 0;
                break;
            }
        }
        if (temp == 0)
        {
            v[i].ff = v[i].ss = 0;
            cnt--;
        }
    }
    cout << cnt << endl;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].ff != 0)
            cout << v[i].ff << " " << v[i].ss << endl;
    }
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