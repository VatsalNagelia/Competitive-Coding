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
    int n; 
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int pr[11]={2,3,5,7,11,13,17,19,23,29,31};
    int ans[11]={0};
    int ans2[n]={1};
    int k=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<11;j++)
        {
            if(a[i]%pr[j]==0)
            {
                if(ans[j]==0)
                {   k++;
                    ans[j]=k;}
                ans2[i]=ans[j];
                break;
            }
        }
    }
    cout<<k<<endl;
    for(int i=0;i<n;i++)
    cout<<ans2[i]<<" ";
    cout<<endl;
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