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
int mod=1e9+7;
int k;
int n[N+1];
int s[N+1];
void solve()
{
    int a,b; 
    cin>>a>>b;
    int val=s[b]-s[a-1];
    if(val<0)
    val=val+mod;
    cout<<val<<endl;
}
int32_t main()
{
    IOS;
    int t; cin>>t;
    cin>>k;
    n[0]=0;
    for(int i=1;i<k;i++)
    {
        n[i]=1;
    }
    n[k]=2;
    for(int i=k+1;i<=N;i++)
    {
        n[i]=(n[i-1]+n[i-k])%mod;
    }
    s[0]=n[0];
    for(int i=1;i<=N;i++)
    {
        s[i]=(s[i-1]+n[i])%mod;
    }
    //int t=1;
    for(int tc=1;tc<=t;tc++)
    {
        //cout<<"Case #"<<tc<<": ";
        solve();
    }
    return 0;
}