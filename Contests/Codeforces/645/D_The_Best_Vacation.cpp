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
using vi=vector<int>;
const int INF=1e18;
const int N=100005;
void solve()
{
    int n,x; 
    cin>>n>>x;
    vi d(2*n);
    vi pred(2*n);
    vi pres(2*n);
    for(int i=0;i<n;i++)
    {
        cin>>d[i];
        d[n+i]=d[i];
    }
    for(int i=0;i<(2*n);i++)
    {
        if(i>0)
        {
            pred[i]=pred[i-1]+d[i];
            pres[i]=pres[i-1]+((d[i]*(d[i]+1))/2);
        }
        else
        {
            pred[0]=d[0];
            pres[0]=(d[0]*(d[0]+1))/2;
        }
    }
    n*=2;
    int ans=x;
    int days=0;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(pred[i]>=x)
        {
            int f=upper_bound(all(pred),pred[i]-x)-pred.begin();
            days=pred[i]-pred[f];
            cnt=pres[i]-pres[f];
            int ext=x-days;
            cnt+=(d[f]*(d[f]+1))/2;
            cnt-=((d[f]-ext)*(d[f]-ext+1))/2;
            ans=max(ans,cnt); 
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