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
    int n; 
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int k=0;
    vector<pair<int,int>> vp;
    for(int i=0;i<n;i++)
    {
        int m=a[i];
        int c=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<m)
            {
                m=a[j];
                c=j;
            }
        }
        if(c>i)
        {
            swap(a[i],a[c]);
            k++;
            pair<int,int> p={i,c};
            vp.pb(p);
        }
    }
    cout<<k<<endl;
    for(int i=0;i<k;i++)
    {
        cout<<vp[i].first<<" "<<vp[i].second<<endl;
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