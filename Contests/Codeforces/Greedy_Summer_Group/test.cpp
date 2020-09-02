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
bool sortcol( const vector<int>& v1, 
               const vector<int>& v2 ) { 
 return v1[0] > v2[0]; 
} 
void solve()
{
    //int n; 
    //cin>>n;
    vector<vector<int>> v(5,vector<int>(4));
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<4;j++)
        cin>>v[i][j];
    }
    sort(v.begin(),v.end(),sortcol);
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<v[i][j]<<" ";
        }
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