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
bool isSubSequence(string str1, string str2, int m, int n)
{
    //checks if str1 of size m is a substring of str2 of size n
    if (m == 0)
        return true;
    if (n == 0)
        return false;
    if (str1[m - 1] == str2[n - 1])
        return isSubSequence(str1, str2, m - 1, n - 1);
    return isSubSequence(str1, str2, m, n - 1);
}
void solve()
{
    int n, m, x, k, y;
    cin >> n >> m >> x >> k >> y;
    int a[n], b[m];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    if (m > n)
    {
        cout << -1 << endl;
        return;
    }
    int l = 0, r = 0, mx = -1LL, cnt = 0, ans = 0;

    while (l < n && r < m)
    {
        if (a[l] != b[r])
        {
            mx = max(a[l], mx);
            l++;
            cnt++;
        }
        else
        {
            if (cnt >= k)
            {
                int rem = cnt % k;
                if ((cnt / k) * x + rem * y <= cnt * y)
                    ans += (cnt / k) * x + rem * y;
                else
                {
                    if (r != 0)
                    {
                        if (b[r - 1] > mx || b[r] > mx)
                            ans += cnt * y;
                        else
                            ans += (cnt - k) * y + x;
                    }
                    else
                    {
                        if (b[r] > mx)
                            ans += cnt * y;
                        else
                            ans += (cnt - k) * y + x;
                    }
                }
            }
            else
            {
                if (r != 0)
                {
                    if (b[r - 1] > mx || b[r] > mx)
                        ans += cnt * y;
                    else
                    {
                        cout << -1 << endl;
                        return;
                    }
                }
                else
                {
                    if (b[r] > mx)
                        ans += cnt * y;
                    else
                    {
                        cout << -1 << endl;
                        return;
                    }
                }
            }
            mx = -1LL;
            cnt = 0LL;
            r++;
            l++;
        }
        //cerr<<((l<n)&&(r<m))<<endl;
    }
    //cerr<<l<<" "<<r<<endl;
    if (l == n && r < m)
    {
        cout << -1 << endl;
        return;
    }
    else if (r == m && l < n)
    {
        mx = -1LL;
        cnt = n - l;
        while (l < n)
        {
            mx = max(mx, a[l]);
            l++;
        }
        //cout<<mx<<" "<<b[m-1]<<endl;
        if (cnt >= k)
        {
            int rem = cnt % k;
            if ((cnt / k) * x + rem * y <= cnt * y)
                ans += (cnt / k) * x + rem * y;
            else
            {
                if (b[m - 1] > mx)
                    ans += cnt * y;
                else
                    ans += (cnt - k) * y + x;
            }
        }
        else
        {
            if (b[m - 1] > mx)
                ans += cnt * y;
            else
            {
                cout << -1 << endl;
                return;
            }
        }
        cout << ans << endl;
    }
    else
        cout << ans << endl;
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