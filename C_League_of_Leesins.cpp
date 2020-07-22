#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define ll long long
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
//const int INF = 1e18;
const int N = 100005;
const ll maxn = 1e5 + 10, LG = 22, mod = 1e9 + 7, inf = 1e18;

ll n, m, k;
ll q[maxn][3], ted[maxn];
bool mk[maxn];
vector<ll> g[maxn];

bool cmp(ll i, ll j)
{
    return ted[i] < ted[j];
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n - 2; i++)
    {
        cin >> q[i][0] >> q[i][1] >> q[i][2];
        for (auto j : {0, 1, 2})
        {
            for (auto k : {0, 1, 2})
                if (j != k)
                    g[q[i][j]].pb(q[i][k]);
            ted[q[i][j]]++;
        }
    }
    ll s;
    for (int i = 1; i <= n; i++)
        if (ted[i] == 1)
            s = i;
    deque<ll> q;
    q.pb(s);
    while (sz(q))
    {
        ll v = q.front();
        q.pop_front();
        cout << v << ' ';
        mk[v] = 1;
        vector<ll> vv;
        for (auto u : g[v])
        {
            ted[u]--;
            if (!mk[u])
                mk[u] = 1, vv.pb(u);
        }
        sort(all(vv), cmp);
        for (auto x : vv)
            q.pb(x);
    }
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