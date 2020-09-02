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
    int k,a,b; 
    cin>>k>>a>>b;
    string s;
    cin>>s;
    int l=s.size();
    int d=l/k;
    int r=l%k;
    int temp=1;
    if(d>=a&&(d<=b))
    {
        if(d==b)
        {
            if(!r==0)
            {
                temp=0;
            }
        }
        if(temp==1)
        {
            int cnt=0;
            for(int i=0;i<l;)
            {
                if(r>0)
                {
                    cnt=1;
                    r--;
                }
                string k=s.substr(i,(d+cnt));
                i+=(d+cnt);
                cnt=0;
                cout<<k<<endl;
            }
        }
        else
        {
            cout<<"No solution"<<endl;
        }
    }
    else
    {
        cout<<"No solution"<<endl;
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