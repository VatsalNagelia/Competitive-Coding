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
    int ans=0;
    int v1=0;
    int v2=0;
    int p=0;
    for(int i=0;i<l;i++)
    {
        if(s[i]=='+')
        {
            p++;
            v1=max(v1,p);
        }
        else
        {
            p--;
            v2=min(v2,p);
        }
        
    }
    cout<<v1-v2<<endl;
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