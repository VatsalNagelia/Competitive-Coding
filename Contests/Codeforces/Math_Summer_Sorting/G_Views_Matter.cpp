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
    ll m;
    cin >> n >> m;
    ll arr[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    sort(arr + 1, arr + n + 1);
    ll val = arr[n];
    ll val2 = 0;
    ll sum = 0;
    for (int i = 1; i < n ; i++)
    {
        if (val2 + 1 <= val)
        {
            if (val2 < arr[i])
                val2++;
        }
        sum += (arr[i] - 1);
    }
    sum += min(arr[n] - 1, arr[n] - (val - val2));
    cout << sum;
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