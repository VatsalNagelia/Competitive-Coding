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
vector<int> v[N];
vector<int> sz(N, 0);
vector<int> big;

void dfs(int a, int p = 0)
{
    sz[a] = 1;
    for (int to : v[a])
    {
        if (to == p)
            continue;
        dfs(to, a);
        sz[a] += sz[to];
    }
    if (p != 0)
        big.push_back((int)sz[a] * (n - sz[a]));
}
void solve()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    sort(big.begin(), big.end(), greater<int>());
    for (int i = 0; i < n - 1; i++)
        big[i] %= mod;
    int m;
    cin >> m;
    vector<int> p(m);
    for (int i = 0; i < m; i++)
        cin >> p[i];
    sort(p.begin(), p.end(), greater<int>());
    int idx = 0;
    int one = max(1LL, m - (n - 1) + 1);
    int x = 1;
    for (int i = 0; i < one; i++)
    {
        x = (x * p[i]) % mod;
        idx++;
    }
    int res = (x * big[0]) % mod;
    for (int i = 1; i < n - 1; i++)
    {
        x = 1;
        if (idx < m)
            x = p[idx++];
        res = (res + big[i] * x) % mod;
    }
    cout << res << endl;
    for (int i = 1; i <= n; i++)
    {
        v[i].clear();
        sz[i] = 0;
    }
    big.clear();
    int distance[n + 1];
    priority_queue<pair<int,int>> q;
    int processed[n + 1];
    int x=1;
    // x denotes starting node from which we want to get minimum paths
    for (int i = 1; i <= n; i++)
    {
        distance[i] = INF;
        processed[i] = 0;
    }
    distance[x] = 0;
    q.push({0LL, x});
    while (!q.empty())
    {
        int a = q.top().second;
        q.pop();
        if (processed[a])
            continue;
        processed[a] = true;
        for (auto u : adj[a])
        {
            int b = u.first, w = u.second;
            if (distance[a] + w < distance[b])
            {
                distance[b] = distance[a] + w;
                q.push({-distance[b], b});
            }
        }
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