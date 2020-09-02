#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define int long long
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define BS binary_search
#define all(c) (c).begin(),(c).end()
#define sz(x) (int)(x).size()
#define get(a,t) get<a>(t)
#define EPS 0.000000001 //1e-9
using pii=pair<int,int>;
const int INF=1e18;
const int N=100005;
void solve()
{
    int n,k; 
    cin>>n>>k;
    map<vector<int>,int> m;
    int ans=0;
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        int p = 1;
        int x = a[i];
        vector<int> b;
        while (p * p <= x)
        {
            p++;
            if (a[i] % p == 0)
            {
                int t = 0;
                while(a[i] % p == 0)
                    a[i] /= p, t++;
                if (t % k == 0)
                    continue;
                t %= k;
                b.pb(t);
                b.pb(p);
            }
        }
        if (a[i] != 1)
            b.pb(1), b.pb(a[i]);
        vector<int> c = b;
        for (int j = 0; j < c.size(); j += 2)
            c[j] = k - c[j];
        ans=ans+m[c];
        m[b]++;
    }
    cout<<ans<<endl;
}
int32_t main()
{
    IOS;
    //int t; cin>>t;
    int t=1;
    for(int tc=1;tc<=t;tc++)
    {
        //cout<<"Case #"<<tc<<": ";
        solve();
    }
    return 0;
}