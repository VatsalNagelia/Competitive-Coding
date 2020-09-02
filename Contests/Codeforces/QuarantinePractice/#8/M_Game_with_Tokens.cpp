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
    int n,m,x,y; 
    cin>>n>>m>>x>>y;
    string s[n];
    for(int i=0;i<n;i++)
    cin>>s[i];
    if((2*x)<y)
    {
        y=2*x;
    }
    int paved[n][m];
    paved[n][m]={};
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='.')
            {
                if(paved[i][j]==0)
                {
                    paved[i][j]=1;
                    if(j<m-1)
                    {
                        if(s[i][j+1]=='.')
                        {
                            ans+=y;
                            paved[i][j+1]=1;
                        }
                        else
                        {
                            ans+=x;
                        }
                           
                    }
                    else
                    {
                        ans+=x;
                    }
                }
            }
            
        }
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