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
    int a1,k; 
    cin>>a1>>k;
    if(k==1)
    cout<<a1<<endl;
    else
    {
        int num=a1;
        for(int i=2;i<=k;i++)
        {
            string s=to_string(num);
            int l=s.size();
            int mi=9;
            int ma=0;
            for(int j=0;j<l;j++)
            {
                int d=(s[j]-48);
                if(d<=mi)
                mi=d;
                if(d>=ma)
                ma=d;
            }
            if(mi==0)
            {
                break;
            }
            else
            {
                num+=(mi*ma);
            }
            
        }
        cout<<num<<endl;
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