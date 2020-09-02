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
string s1,s2;
string minim(string s)
{
    if(s.size()%2==1)
    return(s);
    else
    {
        string l=minim(s.substr(s.begin()-s.begin(),s.begin()+s.size()/2-s.begin()));
        string r=minim(s.substr(s.begin()+s.size()/2-s.begin(),s.end()-s.begin()));
        if(l<r)
        return(l+r);
        else
        {
            return(r+l);
        }
        
    }
    
    
}
void solve()
{
    cin>>s1>>s2;
    string a1=minim(s1);
    string a2=minim(s2);
    cout<<((a1==a2)?"YES":"NO")<<endl;
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