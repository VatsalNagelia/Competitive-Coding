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
    int m; 
    cin>>m;
    int a[m];
    for(int i=0;i<m;i++)
    cin>>a[i];
    int n;
    cin>>n;
    int dp[n+1][m];
    for(int i=0;i<m;i++)
    dp[0][i]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int x=(i-a[j]>=0)?dp[i-a[j]][j]:0;
            int y=(j>0)?dp[i][j-1]:0;
            dp[i][j]=x+y;
        }
    }
    cout<<dp[n][m-1]<<endl;
}
int32_t main()
{
    IOS;
    int t; cin>>t;
    //int t=1;
    for(int tc=1;tc<=t;tc++)
    {
        //cout<<"Case #"<<tc<<": ";
        solve();
    }
    return 0;
}