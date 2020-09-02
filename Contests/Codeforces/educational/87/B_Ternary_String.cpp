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
    string s; 
    cin>>s;
    int l=s.size();
    int p1=-1,p2=-1,p3=-1;
    int ans=2000001;
    for(int i=0;i<l;i++)
    {
        if(s[i]=='1')
        {
            p1=i;
        }
        else
        {
            if(s[i]=='2')
            p2=i;
            else
            {
                p3=i;
            }
            
        }
        if(p1>-1&&p2>-1&&p3>-1)
        {
            int m1=min(p1,p2);
            int m2=min(m1,p3);
            int m3=max(p1,p2);
            int m4=max(m3,p3);
            int l=m4-m2+1;
            if(l<ans)
            {
                ans=l;
            }
        }
        
    }
    if(ans!=2000001)
    cout<<ans<<endl;
    else
    {
        cout<<0<<endl;
    }
    
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