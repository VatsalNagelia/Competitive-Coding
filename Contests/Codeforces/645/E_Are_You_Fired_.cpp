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
#define ld long double
const int INF=1e18;
const int N=100005;
void solve()
{
    ld n; 
    cin>>n;
    int nx=n;
    ld lim=ceil(n/2.0);
    int a[nx];
    int sum[nx];
    for(int i=1;i<lim;i++)
    {
        cin>>a[i];
        if(i>0)
        sum[i]=sum[i-1]+a[i];
        else
        {
            sum[i]=a[i];
        }
    }
    int x;
    cin>>x;
    for(int i=lim;i<n;i++)
    {
        a[i]=x;
        if(i>0)
        sum[i]=sum[i-1]+a[i];
        else
        {
            sum[i]=a[i];
        }
    }
    int k=n;
    for(int i=n-1;i>-1;i--)
    {
        if(sum[i]>0)
        {
            k=i+1;
            break;
        }
    }
    if(k<0)
    {
        cout<<-1<<endl;
        return;
    }
    int temp=1;
    for(int i=1;i<=(n-k);i++)
    {
        int f=sum[i+k-1]-sum[i-1];
        if(f<=0)
        {
            temp=0;
            break;
        }
    }
    if(temp==1)
    cout<<k<<endl;
    else
    {
        cout<<-1<<endl;
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