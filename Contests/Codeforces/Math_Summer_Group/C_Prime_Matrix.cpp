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
int dp[N];
void solve()
{
    int n,m; 
    cin>>n>>m;
    int a[n][m];
    int row[n]={0};
    int col[m]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
            int x=dp[a[i][j]];
            row[i]+=x;
            col[j]+=x;
        }
    }
    int ans=3e9;
    for(int i=0;i<n;i++)
    ans=min(ans,row[i]);
    for(int i=0;i<m;i++)
    ans=min(ans,col[i]);
    cout<<ans<<endl;

}
int32_t main()
{
    IOS;
    //int t; cin>>t;
    int t=1;
    int sieve[N];
    for(int i = 2; i < N; i++)
		sieve[i] = 1;
	for(int i = 2; i < N; i++)
	{
		if(sieve[i])
		{
			for(int j = 2; i * j < N; j++)
				sieve[i * j] = 0;
		}
	}
	for(int i = N - 2; i >= 1; i--)
	{
		dp[i] = dp[i + 1] + 1;
		if(sieve[i])
			dp[i] = 0;
	}
    for(int tc=1;tc<=t;tc++)
    {
        //cout<<"Case #"<<tc<<": ";
        solve();
    }
    return 0;
}