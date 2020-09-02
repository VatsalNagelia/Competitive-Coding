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
const int N = 1e7 + 6;
int mod = 1e9 + 7;
int prime[N];
void SieveOfEratosthenes()
{
    int n = 1e7 + 1;
    for (int i = 0; i <= n; i++)
    {
        prime[i] = i;
    }
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == p)
        {
            for (int i = p * p; i <= n; i += p)
            {
                prime[i] = p;
            }
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    SieveOfEratosthenes();
    int a[n];
    int a1[n];
    int a2[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        vector<int> v;
        int x = a[i];
        while (x > 1)
        {
            if(prime[x]<=1)
            break;
            v.pb(prime[x]);
            int p=prime[x];
            while (x % p == 0)
            {
                x = x / p;
            }
        }
        if (v.size() < 2)
        {
            a1[i] = -1;
            a2[i] = -1;
        }
        else
        {
            a1[i] = v[0];
            a2[i] = 1;
            for (int j = 1; j < v.size(); j++)
            {
                a2[i] *= v[j];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a1[i] << " ";
    }
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << a2[i] << " " ;
    }
    cout<<endl;
}
int32_t main()
{
    IOS;
    //int t;cin >> t;
    int t = 1;
    for (int tc = 1; tc <= t; tc++)
    {
        //cout<<"Case #"<<tc<<": ";
        solve();
    }
    return 0;
}