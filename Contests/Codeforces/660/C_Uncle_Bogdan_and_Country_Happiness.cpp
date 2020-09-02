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
int p[N];
int h[N];
int sub[N];
int g[N];
int b[N];
int mx=0;
vi adj[N + 1];
bool vis[N + 1];
bool vis1[N + 1];
int n, m;
void addEdge(int v, int u)
{
    adj[v].pb(u);
    adj[u].pb(v);
}
void dfs1(int x)
{
    vis1[x] = 1;
    int counter = p[x];
    for (auto u : adj[x])
    {
        if (vis1[u] == 0)
        {
            dfs1(u);
            counter += sub[u];
        }
    }
    sub[x] = counter;
}
bool dfs(int x)
{
    vis[x] = 1;
    bool temp=true;
    if (abs(h[x]) <= sub[x])
    {
        temp = true;
    }
    else
    {
        temp = false;
    }
    g[x] = (sub[x] + h[x]) / 2;
    b[x] = (sub[x] - h[x]) / 2;
    if ((g[x] + b[x]) != sub[x])
    {
        temp = false;
    }
    int sum = 0;
    for (auto u : adj[x])
    {
        if (vis[u] == 0)
        {
            temp = (temp && dfs(u));
            sum += g[u];
            /*if (temp == false)
                cout << x << endl;*/
        }
    }
    if (sum > g[x])
    {
        temp = false;
    }
    /*if (!temp)
    {
        cout << x << endl;
    }*/
    return temp;
}
void solve()
{
    cin >> n >> m;
    mx=max(n,mx);
    for(int i=0;i<=mx;i++)
    {
        adj[i].clear();
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        vis[i] = 0;
        vis1[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        addEdge(x, y);
    }
    dfs1(1);
    /*for (int i = 1; i <= n; i++)
    {
        cout << sub[i] << " ";
    }
    cout << endl;*/
    bool ans = dfs(1);
    if (ans)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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