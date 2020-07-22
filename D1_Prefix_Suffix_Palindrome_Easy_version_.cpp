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
int n;
string s;
bool check_pal(string a)
{
    int l = a.length();
    int temp = 1;
    for (int i = 0; i < (l / 2); i++)
    {
        if (a[i] != a[l - i - 1])
        {
            return 0;
        }
    }
    return 1;
}
bool check(int m,string enter)
{
    for (int l = 0, r = m + l; (l < n && r <= n); l++, r++)
    {
        string a = enter.substr(0, l);
        string b = enter.substr(r, n - m - l);
        string comb = a + b;
        if (check_pal(comb))
        {
            return 1;
        }
    }
    for (int l = 0, r = m + l; (l < n && r <= n); l++, r++)
    {
        string a = enter.substr(0, l);
        string b = enter.substr(r, n - m - l);
        string comb = a + b;
        if (check_pal(comb))
        {
            return 1;
        }
    }
    return 0;
}
int binsearc(int lo, int hi,string a)
{
    int mid = (lo + hi) / 2;
    while (lo < hi)
    {
        mid = (lo + hi) / 2;
        if (check(mid,a))
        {
            hi = mid;
        }
        else
            lo = mid + 1;
    }
    if (!check(lo,a))
        lo = -1;
    return lo;
}
void solve()
{
    cin >> s;
    n = s.length();
    int ans = binsearc(0, n,s);
    string ans1 = "";
    for (int i = 0; i < n; i++)
    {
        for (int l = 0, r = ans + l; (l < n && r <= n); l++, r++)
        {
            string a = s.substr(0, l);
            string b = s.substr(r, n - ans - l);
            string comb = a + b;
            if (check_pal(comb))
            {
                ans1 = comb;
                break;
            }
        }
        if (ans1 != "")
            break;
    }
    string s1=s;
    reverse(s.begin(),s.end());
    ans = binsearc(0, n-1,s);
    string ans2 = "";
    for (int i = 0; i < n; i++)
    {
        for (int l = 0, r = ans + l; (l < n && r <= n); l++, r++)
        {
            string a = s.substr(0, l);
            string b = s.substr(r, n - ans - l);
            string comb = a + b;
            if (check_pal(comb))
            {
                ans2 = comb;
                break;
            }
        }
        if (ans2 != "")
            break;
    }
    reverse(all(ans2));
    if(ans2>ans1)
    cout<<ans2<<endl;
    else
    {
        cout<<ans1<<endl;
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