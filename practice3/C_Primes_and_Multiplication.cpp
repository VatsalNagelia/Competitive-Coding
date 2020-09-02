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
int fastexpom(int a, int b, int m)
{
    int res = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            res = (((res) % m) * ((a) % m)) % m;
        a = (((a) % m) * ((a) % m)) % m;
        b /= 2LL;
    }
    return res;
}
void solve()
{
    int x, n;
    cin >>x>>n;
    set<int> s;
    for (int i=2;i*i<=x;i++)
    {
        if (x%i==0)
        {
            s.insert(i);
            while (x%i==0)
            {
                x/=i;
            }
        }
    }
    if (x>1)
    {
        s.insert(x);
    }
    int ans=1;
    for (auto ele:s)
    {
        int val=ele;
        int add=0;
        int n2=n/val;
        while (n2>0)
        {
            add+=n2;
            n2/=ele;
        }
        add%=(mod-1);
        int p=fastexpom(ele, add, mod);
        ans=((ans*p)+mod)%mod;
    }
    cout<<(ans%mod)<<endl;
}
int32_t main()
{
    IOS;
    //int t;cin >> t;
    int t=1;
    for (int tc = 1; tc <= t; tc++)
    {
        //cout<<"Case #"<<tc<<": ";
        solve();
    }
    return 0;
}