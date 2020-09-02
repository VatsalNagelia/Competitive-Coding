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
    int a,b,c,d; 
    cin>>a>>b>>c>>d;
    int ans=0;
    int sub=0;
    int k=0;
    for(int i=a;i<=b;i++)
    {
        if(i==a)
        {
        for(int j=c;j>=b;j--)
        {
            if((i+j)>c)
            {
                k=max(k,min((i+j),d+1)-c);
                sub+=min((i+j),d+1)-c;
            }
            else break;
        }
        }
        ans+=sub;
        if(i+1+c-d<2&&b!=c)
        {
            sub+=(k+1);
        }
        else
        {
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