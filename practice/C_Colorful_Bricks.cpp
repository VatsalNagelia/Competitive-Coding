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
int mod=998244353;
void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    int dp[n][++k];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            if(j==0)
            dp[i][j]=m;
            else
            {
                dp[i][j]=0;
            }
            
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<k;j++)
        {
            dp[i][j]=(dp[i-1][j]+dp[i-1][j-1]*(m-1))%mod;
        }
    }
    cout<<dp[n-1][k-1]<<endl;
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