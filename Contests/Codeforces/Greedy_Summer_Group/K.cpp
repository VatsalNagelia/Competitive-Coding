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
    int n,m,s,f;
    cin>>n>>m>>s>>f;
    int t[m],l[m],r[m];
    for(int i=0;i<m;i++)
    {
        cin>>t[i]>>l[i]>>r[i];
    }
    string ans="";
    int i=0;
    for(int j=1;true;j++)
    {
        if(f>s)
        {
            if(j!=t[i])
            {
                ans+='R';
                s++;
            }
            else
            {
                if(s>r[i]||s+1<l[i])
                {
                    s++;
                    ans+='R';
                }
                else
                {
                    ans+='X';
                }
                i++;
            }
        }
        else
        {
            if(j!=t[i])
            {
                ans+='L';
                s--;
            }
            else{
            if(s<l[i]||(s-1)>r[i])
            {
                s--;
                ans+='L';
            }
            else
            {
                ans+='X';
            }
            i++;}
        }
        if(i>=m)
        i=0;
        if(f==s)
        break;
        
    }
    cout<<ans<<endl;
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