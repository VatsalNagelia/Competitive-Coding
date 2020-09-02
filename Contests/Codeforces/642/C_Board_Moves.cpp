#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
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
const int N=100005;
void solve()
{
    long long n; 
    cin>>n;
    if(n==1)
    cout<<0<<endl;
    else
    {
        long long p=8;
        long long ans=0;
        long long j=n/2;
        for(long long i=1;i<=j;i++)
        {
            ans=ans+(long long)(p*i);
            p+=8;
        }
        cout<<ans<<endl;
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