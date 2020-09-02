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
vector<int> mxs(vector<int> a)
{
    int n = a.size();
    vector<int> res(n + 1);
    int i = 0;
    while (i < n)
    {
        if (a[i] == 0)
        {
            i++;
            continue;
        }

        int j = i;
        while (j < n && a[j] == 1)
        {
            j++;
        }
        for (int len = 1; len <= j - i; len++)
        {
            res[len] += j - i - len + 1;
        }
        i = j;
    }

    return res;
}
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    vector<int> resa = mxs(a);
    vector<int> resb = mxs(b);
    int ans = 0;
    for (int i = 1; i < resa.size(); i++)
    {
        if (k % i == 0 && k / i <= m)
        {
            ans += resa[i] * resb[k / i];
        }
    }
    cout << ans << endl;
}
int32_t main()
{
    IOS;
    //int t; cin>>t;
    int t = 1;
    for (int tc = 1; tc <= t; tc++)
    {
        //cout<<"Case #"<<tc<<": ";
        solve();
    }
    return 0;
}