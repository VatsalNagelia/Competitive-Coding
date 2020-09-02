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
    long double h,c,t; 
    cin>>h>>c>>t;
    if(t>=h)
    {
        cout<<1<<endl;
        return;
    }
    if(t<=((h+c)/2.0))
    {
        cout<<2<<endl;
        return;
    }
    long double ans1=((t)/((-h-c+1)+(2*t)));
    int ans=floor(ans1);
    if(ans%2==0)
    {
        long double mid=(ans/2.0)+1.0;
        long double temp=((mid*h)+((mid-1)*c))/(2.0*mid-1.0);
        long double dif=abs((temp-t));
        long double dif2=abs((t)-((h+c)/2.0));
        if(dif<dif2)
        {
            ans++;
        }
        else
        {
            ans=2;
        }
        ans=max(1ll,ans);
        
    }
    cout<<ans<<endl;

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