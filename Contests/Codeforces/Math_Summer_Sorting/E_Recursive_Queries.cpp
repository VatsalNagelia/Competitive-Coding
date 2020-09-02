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
const int N=1e6+1;
int ans[N];
int b[N][10];
void solve()
{
    int l,r,k; 
    cin>>l>>r>>k;
    int c=0;
    c=b[r][k]-b[l-1][k];
    cout<<c<<endl;

}
int32_t main()
{
    IOS;
    int t; cin>>t;
    //int t=1;
    for(int i=0;i<10;i++)
    {
        b[0][i]=0;
    }
    for(int i=1;i<10;i++)
    {
        ans[i]=i;
        for(int j=1;j<10;j++)
        {
            b[i][j]=b[i-1][j];
            if(j==ans[i])
            b[i][j]++;
        }
    }
    for(int i=10;i<N;i++)
    {
        int j=i;
        int pdt=1;
        while(j>0)
        {
            int d=j%10;
            if(d>0)
            {
                pdt*=d;
            }
            j/=10;
        }
        ans[i]=ans[pdt];
        for(int j=1;j<10;j++)
        {
            b[i][j]=b[i-1][j];
            if(j==ans[i])
            b[i][j]++;
        }
    }
    for(int tc=1;tc<=t;tc++)
    {
        //cout<<"Case #"<<tc<<": ";
        solve();
    }
    return 0;
}