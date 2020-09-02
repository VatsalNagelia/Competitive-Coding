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
 return v1[0] < v2[0]; 
}
int cnt[55];
bool banned[111];
int powe[8];
void solve()
{
	int n; cin>>n;
	powe[0]=1;
	for(int i=1;i<=7;i++) powe[i]=powe[i-1]*10;
	for(int i=0;i<n;i++)
	{
		string s; cin>>s;
		banned[s[0]-'a']=1;
		for(int j=0;j<s.length();j++)
		{
			int coeff = powe[((s.length()) - 1 - j)];
			cnt[s[j]-'a']+=coeff;
		}
	}
	vector<int> vec;
	for(int i=0;i<10;i++) vec.pb(i);
	int ans=INT_MAX;
	do
	{
		if(!banned[vec[0]])
		{
			int res=0;
			for(int i=1;i<=9;i++)
			{
				res+=cnt[vec[i]]*i;
			}
			ans=min(ans,res);
		}
	}while(next_permutation(vec.begin(),vec.end()));
	cout<<ans<<'\n';

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