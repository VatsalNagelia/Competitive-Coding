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
bool comp(string &s1,string &s2)
{
    int l1=s1.size();
    int l2=s2.size();
    if(l1!=l2)
    return l1<l2;
    return s1<s2;
    
}
bool check(string &s1,string &s2)
{
    if(s2.find(s1)!=string::npos)
    {
        return 1;
    }
    return 0;
}
void solve()
{
    int n; 
    cin>>n;
    string s[n];
    for(int i=0;i<n;i++)
    cin>>s[i];
    sort(s,s+n,comp);
    for(int i=0;i<n-1;i++)
    {
        if(!(check(s[i],s[i+1])))
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<s[i]<<endl;
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