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
    int n,x; 
    cin>>n>>x;
    int deg=0;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a==x||b==x)
        deg++;
    }
    if(deg<=1)
    cout<<"Ayush"<<endl;
    else
    {
        if((n-1)%2==0)
        {
            cout<<"Ashish"<<endl;
        }
        else
        {
            cout<<"Ayush"<<endl;
        }
        
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