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
    int n;
    cin >> n;
    int st = -2e9;
    int dr = 2e9;
    int semn;
    string s, a;
    int x;
    for (int i = 1; i <= n; i++)
    {
        cin >> s >> x >> a;
        if (a == "N")
        {
            if (s == "<=")
                semn = 1;
            if (s == ">=")
                semn = 2;
            if (s == "<")
                semn = 3;
            if (s == ">")
                semn = 4;
        }
        else
        {
            if (s == "<=")
                semn = 4;
            if (s == ">=")
                semn = 3;
            if (s == "<")
                semn = 2;
            if (s == ">")
                semn = 1;
        }
        if (semn == 1)
            st = max(st, x + 1);
        if (semn == 2)
            dr = min(dr, x - 1);
        if (semn == 3)
            st = max(st, x);
        if (semn == 4)
            dr = min(dr, x);
    }
    if (st > dr)
    {
        cout << "Impossible";
        return;
    }
    cout << st;
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