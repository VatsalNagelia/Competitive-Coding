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
    int n; 
    cin>>n;
    int a[n+1];
    a[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int dp[n+1][3]={0};
    dp[0][0]=0;dp[0][1]=0;dp[0][2]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<3;j++)
        {
            dp[i][0]=max(dp[i-1][j],dp[i][0]);
            if(a[i]==2||a[i]==3)
            {
                dp[i][2]=max(dp[i-1][1]+1,dp[i-1][0]+1);
            }
            if(a[i]==1||a[i]==3)
            {
                dp[i][1]=max(dp[i-1][2]+1,dp[i-1][0]+1);
            }
        }
    }
    int ans=max({dp[n][0],dp[n][1],dp[n][2]});
    cout<<n-ans<<endl;

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