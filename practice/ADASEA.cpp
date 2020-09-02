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
string s[1001];
map<pii,int> m1;
int n,m;
int cnt;
void dfs(int r,int c)
{
    if(m1[mp(r,c)]==1)
    return;
    m1[mp(r,c)]=1;
    if(s[r][c]=='~')
    {
        return;
    }
    if(s[r][c]=='#'){
    cnt++;
    if(r<n-1)
    dfs(r+1,c);
    if(c<m-1)
    dfs(r,c+1);
    return;
    }
    return;
}
void solve()
{
    int n,m; 
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cnt=0;
            if(s[i][j]=='#')
            {
                dfs(i,j);
                cnt*=cnt;
                ans+=cnt;
            }
        }
    }
    cout<<ans/(n*m)<<endl;
    
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