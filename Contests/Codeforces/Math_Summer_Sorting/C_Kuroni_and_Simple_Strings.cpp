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
    string rs=s;
    size_t f1=-1;
    size_t f2=-1;
    reverse(rs.begin(),rs.end());
    vector<int> p;
    int ans=0;
    for(int i=0;i<l;i++)
    {
        char ch1='(';
        char ch2=')';
        f1=s.find(ch1,f1+1);
        f2=rs.find(ch2,f2+1);
        size_t j=l-f2-1;
        if(f1==string::npos||f2==string::npos)
        break;
        if(f1<j)
        {
            ans=1;
            p.pb(f1+1);
            p.pb(j+1);
        }
        else
        {
            break;
        }
    }
    cout<<ans<<endl;
    if(ans)
    {
        cout<<p.size()<<endl;
        sort(all(p));
        for(int i=0;i<p.size();i++)
        cout<<p[i]<<" ";
        cout<<endl;
    }


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