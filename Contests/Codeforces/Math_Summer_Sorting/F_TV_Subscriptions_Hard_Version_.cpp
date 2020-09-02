#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define int long long
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define BS binary_search
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define get(a, t) get<a>(t)
#define EPS 0.000000001 //1e-9
using pii = pair<int, int>;
const int INF = 1e18;
const int N = 100005;
void solve()
{
    int n, k, d;
    cin >> n >> k >> d;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    map<int, int> m;
    int ans = d;
    for (int i = 1; i <= d; i++)
        m[a[i]]++;
    ans = min(ans, (int)m.size());
    for (int i = d + 1; i <= n; i++)
    {
        m[a[i]]++;
        m[a[i - d]]--;
        if (m[a[i - d]] == 0)
            m.erase(a[i - d]);
        ans = min(ans, (int)m.size());
    }
    cout << ans << endl;
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