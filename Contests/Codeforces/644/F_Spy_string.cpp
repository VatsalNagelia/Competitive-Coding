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
    int n,m; 
    cin>>n>>m;
    string s[n];
    for(int i=0;i<n;i++)
    cin>>s[i];
    string ans=s[0];
    int temp=1;
    for(int i=0;i<m;i++)
    {
        temp=1;
        char ch1=ans[i];
        for(char ch='a';ch<='z';ch++)
        {
            ans[i]=ch;
            temp=1;
            for(int j=1;j<n;j++)
            {
                int cnt=0;
                for(int k=0;k<m;k++)
                {
                    if(ans[k]!=s[j][k])
                    {
                        cnt++;
                    }
                }
                if(cnt>1)
                {
                    temp=0;
                    break;
                }
            }
            if(temp==1)
            {
                cout<<ans<<endl;
                return;
            }
        }
        ans[i]=ch1;
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