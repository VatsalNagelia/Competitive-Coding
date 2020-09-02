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
string s[51];
int n;
vector<pii>v1,v2;
map<pii,int> m1,m2;
void dfs(int r,int c,vector<pii> &v,map<pii,int> &m)
{
    if(m[mp(r,c)]==1)
    return;
    m[mp(r,c)]=1;
    if(s[r][c]=='0')
    {
        v.pb(mp(r,c));
    }
    else
    return;
    if(r>0)
    dfs(r-1,c,v,m);
    if(c>0)
    dfs(r,c-1,v,m);
    if(c<n-1)
    dfs(r,c+1,v,m);
    if(r<n-1)
    dfs(r+1,c,v,m);
}
void solve()
{ 
    cin>>n;
    int r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;
    r1--;c1--;c2--;r2--;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    dfs(r1,c1,v1,m1);
    dfs(r2,c2,v2,m2);
    int ans=1e5;
    for(int i=0;i<v1.size();i++)
    {
        for(int j=0;j<v2.size();j++)
        {
            int cnt=(v1[i].ff-v2[j].ff)*(v1[i].ff-v2[j].ff)+(v1[i].ss-v2[j].ss)*(v1[i].ss-v2[j].ss);
            ans=min(ans,cnt);
        }
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