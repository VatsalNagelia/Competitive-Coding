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
    int n,m,c0,d0; 
    cin>>n>>m>>c0>>d0;
    int a[m+1],b[m+1],c[m+1],d[m+1];
    for(int i=1;i<=m;i++)
        cin>>a[i]>>b[i]>>c[i]>>d[i];

    int dp[n+1][m+1]={0};
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=(i/c0)*d0;
    }
    for(int i=1;i<=m;i++)
        dp[0][i]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=0;((k<=a[j]/b[j])&&(i>=(k*c[j])));k++)
            {
                dp[i][j]=max(dp[i][j],dp[i-k*c[j]][j-1]+k*d[j]);
            }
        }
    }
    cout<<dp[n][m]<<endl;

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