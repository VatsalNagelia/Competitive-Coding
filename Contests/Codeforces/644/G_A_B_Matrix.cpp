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
    int nbLig, nbCol, tarLig, tarCol;
	cin >> nbLig >> nbCol >> tarLig >> tarCol;
	vector<vector<int>> mat(nbLig, vector<int>(nbCol, 0));
	int cur = 0;
	for (int col = 0; col < nbCol; ++col) {
		for (int i = 0; i < tarCol; ++i) {
			mat[cur][col] = 1;
			cur = (cur+1) % nbLig;
		}	
	}
	for (int lig = 0; lig < nbLig; ++lig) {
		if (accumulate(mat[lig].begin(), mat[lig].end(), 0LL) != tarLig) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	for (int lig = 0; lig < nbLig; ++lig) {
		for (int col = 0; col < nbCol; ++col) {
			cout << mat[lig][col];
		}
		cout << "\n";
    }
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