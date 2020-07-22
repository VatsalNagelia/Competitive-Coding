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
const int nax = 1005;
char grid[nax][nax];
bool vis[nax][nax];

void check(vector<int> &v)
{
    for (int i = 1; i < (int)v.size(); ++i)
    {
        if (v[i] != v[i - 1] + 1)
        {
            puts("-1");
            exit(0);
        }
    }
}

int h, w;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

vector<int> in_row[nax], in_col[nax];

void dfs(int row, int col)
{
    vis[row][col] = true;
    for (int dir = 0; dir < 4; ++dir)
    {
        int r2 = row + dx[dir];
        int c2 = col + dy[dir];
        if (0 <= r2 && r2 < h && 0 <= c2 && c2 < w && grid[r2][c2] == '#' && !vis[r2][c2])
        {
            dfs(r2, c2);
        }
    }
}
void solve()
{
    cin >> h >> w;
    for (int row = 0; row < h; ++row)
    {
        cin >> grid[row];
        for (int col = 0; col < w; ++col)
        {
            if (grid[row][col] == '#')
            {
                // any = true;
                in_row[row].push_back(col);
                in_col[col].push_back(row);
            }
        }
    }
    int rows = 0, cols = 0;
    for (int row = 0; row < h; ++row)
    {
        check(in_row[row]);
        if (!in_row[row].empty())
        {
            rows++;
        }
    }
    for (int col = 0; col < w; ++col)
    {
        check(in_col[col]);
        if (!in_col[col].empty())
        {
            cols++;
        }
    
    }
    if ((rows == h) != (cols == w))
    {
        puts("-1");
        return;
    }
    int answer = 0;
    for (int row = 0; row < h; ++row)
    {
        for (int col = 0; col < w; ++col)
        {
            if (grid[row][col] == '#' && !vis[row][col])
            {
                ++answer;
                dfs(row, col);
            }
        }
    }
    cout<<answer<<endl;
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