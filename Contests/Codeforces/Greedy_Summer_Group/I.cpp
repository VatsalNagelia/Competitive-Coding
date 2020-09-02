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
    int n,v; 
    cin>>n>>v;
    pair<int,int> ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i].first>>ar[i].second;
    }
    sort(ar,ar+n);
    int k=0;
    int pl=0;
    int dc=0;
    int ans=0;
    for(int i=1;i<=ar[n-1].first;i++)
    {
        dc=0;
        for(int j=k;j<n;j++)
        {
            if(ar[j].first>i)
            {
                k=j;
                break;
            }
            else
            {
                if(ar[j].ff==i)
                {
                    dc+=ar[j].ss;
                }
            }
            
        }
        int m=min(v,pl);
        if(m==v)
        {
            pl=dc;
            ans+=v;
        }
        else
        {
            int y=m+dc;
            m=min(v,y);
            pl=y-m;
            ans+=m;
        }
        
    }
    ans+=min(v,pl);
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