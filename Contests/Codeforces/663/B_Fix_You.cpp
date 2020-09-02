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
bool vis[101][101];
char a[101][101];
const int row[4] ={ -1, 1, 0, 0 };
const int col[4] ={ 0, 0, -1, 1 };
int n, m;
/*
bool check(int x, int y)
{
    if (x >= 0 && y >= 0 && x < n && y < m && !vis[x][y] && a[x][y] != '#')
        return true;
    return false;
}
void dfs(int x, int y)
{

    vis[x][y] = 1;
    int d, r;
    if (a[x][y]=='D')
    {
        d=1;r=0;
    }
    if (a[x][y]=='R')
    {
        r=1;d=0;
    }
    if (a[x][y]=='C')
    {
        return;
    }
    if ()

}*/
void solve()
{
    cin>>n>>m;
    int ans=0;

    if (n==1&&m==1)
    {
        cout<<0<<endl;
        return;
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            char ch;
            cin>>ch;
            a[i][j]=ch;
        }
    }
    for (int j=0;j<m;j++)
    {
        if (a[n-1][j]=='D')
        {
            ans++;
            a[n-1][j]='R';
        }
    }
    for (int i=0;i<n;i++)
    {
        if (a[i][m-1]=='R')
        {
            ans++;
            a[i][m-1]='D';
        }
    }
    cout<<ans<<endl;
}
int32_t main()
{
    IOS;
    int t;cin >> t;
    //int t=1;
    for (int tc = 1; tc <= t; tc++)
    {
        //cout<<"Case #"<<tc<<": ";
        solve();
    }
    return 0;
}