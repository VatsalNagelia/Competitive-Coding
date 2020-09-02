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
    int a,b; 
    cin>>a>>b;
    if(b==a)
    {
        cout<<0<<endl;
        return;
    }
    if(b<a)
    swap(a,b);
    if(b>a)
    {
        int pow=0;
        if(b%a==0)
        {
            int d=b/a;
            int temp=1;
            while(d>1)
            {
                if(d%2!=0)
                {
                    temp=0;
                    break;
                }
                d=d/2;
                pow++;
            }
            int p8=pow/3;
            pow%=3;
            int p4=pow/2;
            pow%=2;
            int p2=pow;
            if(temp==1)
            {
                cout<<(p8+p4+p2)<<endl;
                return;
            }

            
        }
    }
    cout<<-1<<endl;
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