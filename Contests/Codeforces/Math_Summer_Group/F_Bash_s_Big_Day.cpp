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
    int s[n];
    for(int i=0;i<n;i++)
    cin>>s[i];
    unordered_map<int,int> factors;
    for(int i=0;i<n;i++)
    {
        int root = sqrt(s[i]);
		for(int j = 2; j <= root; j++)
		{
			if(s[i]%j == 0)
				factors[j]++;

			while(s[i]%j==0)
            {
                s[i]/= j;
            }
		}
		if(s[i]>1)factors[s[i]]++; 
    }
    int ans=1;
    for(auto it=factors.begin();it!=factors.end();it++)
    {
        ans=max(ans,(*it).ss);
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