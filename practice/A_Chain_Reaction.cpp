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
const int N=100005;    ll x[1000001],b[1000001];
    ll dp[1000000];
void solve()
{
    int n; 
    cin>>n;
    for(ll i=0;i<100001;i++)
            x[i]=0;
        for(ll i=0;i<n;i++)
        {
            ll a,q;
            cin>>a>>q;
            x[a]=1;
            b[a]=q;
        }
        for(ll i=0;i<1000001;i++)
            dp[i]=0;
        if(x[0]==1)
            dp[0]=1;
        for(ll i=1;i<=1000000;i++)
        {
            if(x[i]!=1)
            {
                dp[i]=max((ll)0,dp[i-1]);
                continue;
            }
            if(i-b[i]-1<0)
            {
                dp[i]=1;
                continue;
            }
            dp[i]=1+dp[i-b[i]-1];
        }
        ll  val=-1;
        for(ll i=0;i<=1000000;i++)
            val=max(val,dp[i]);
        cout<<n-val;
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