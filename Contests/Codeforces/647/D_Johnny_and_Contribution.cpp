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
    ll n, m;
    cin >> n >> m;

    vector<ll> gr[n + 1];
    for (ll i = 1; i <= m; i++)
    {
        ll u, v;
        cin >> u >> v;

        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    vector<ll> v[n + 1];
    ll colour_graph[n + 1];
    for (ll i = 1; i <= n; i++)
    {
        ll colour;
        cin >> colour;

        colour_graph[i] = colour;
        v[colour].push_back(i);
    }

    ll flag = 0;
    vector<ll> result;
    for (ll i = 1; i <= n; i++)
    {
        for (auto nodes : v[i])
        {

            set<ll> s;
            for (auto neigh : gr[nodes])
            {
                if (colour_graph[neigh] < colour_graph[nodes])
                {
                    s.insert(colour_graph[neigh]);
                }
                if (colour_graph[neigh] == colour_graph[nodes])
                {
                    flag = 1;
                    break;
                }
            }

            if (s.size() != colour_graph[nodes] - 1)
            {
                flag = 1;
                break;
            }

            result.push_back(nodes);
        }
        if (flag == 1)
            break;
    }

    if (flag == 1)
    {
        cout << "-1"
             << "\n";
    }
    else
    {
        for (ll i = 0; i < result.size(); i++)
        {
            cout << result[i] << " ";
        }
    }
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