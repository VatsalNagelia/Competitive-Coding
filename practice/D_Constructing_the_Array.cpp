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
struct cmp{
    bool operator() (const pii& a,const pii& b)
    {
        int l1=a.ss-a.ff+1;
        int l2=b.ss-b.ff+1;
        if(l1==l2)
            return a.ff<b.ff;
        else
            return l1>l2;
    }
};
void solve()
{
    int n; 
    cin>>n;
    vector<int> a(n);
    set<pii,cmp> s;
    s.insert({0,n-1});
    for(int i=1;i<=n;i++)
    {
        auto cur=*s.begin();
        s.erase(s.begin());
        int mid=(cur.ff+cur.ss)/2;
        a[mid]=i;
        if(cur.ff<mid)
        s.insert({cur.ff,mid-1});
        if(cur.ss>mid)
        s.insert(mid+1,cur.ss);
    }
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
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