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
int n,k,a,b;
vector<int> aven;
int ans(int l,int r)
{
    int lo=lower_bound(aven.begin(),aven.end(),l)-aven.begin();
    int hi=upper_bound(aven.begin(),aven.end(),r)-aven.begin();
    hi--;
    int x=hi-lo+1;
    int pow;
    if(x==0)
    pow=a;
    else
    {
        pow=b*x*(r-l+1);
    }
    if(l==r||x==0)
    return(pow);
    else
    {
        int mid=l+(r-l)/2;
        int m=min(pow,(ans(l,mid)+ans(mid+1,r)));
        return(m);
    }
}
void solve()
{
    cin>>n>>k>>a>>b;
    int p=(int)(1<<n);
    for(int i=0;i<k;i++)
    {
        int l;
        cin>>l;
        aven.pb(l);
    }
    sort(aven.begin(),aven.end());
    int answer=ans(1,p);
    cout<<answer<<endl;

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