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
    int moves=8;
    if(s[0]=='a'||s[0]=='h')
    {
        moves=5;
    }
    if(moves==5)
    {
        if(s[1]=='1'||s[1]=='8')
        moves=3;
    }
    else
    {
        if(s[1]=='1'||s[1]=='8')
        moves=5;
    }
    cout<<moves<<endl;
    
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