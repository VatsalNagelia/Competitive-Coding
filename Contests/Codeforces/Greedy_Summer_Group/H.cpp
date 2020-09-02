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
    int n,sx,sy; 
    cin>>n>>sx>>sy;
    int r[8+1];
    for(int i=0;i<=8;i++)
    r[i]=0;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x>=0&&x<sx)
        {
            if(y>sy)
            r[1]++;
            else if(y==sy)
            r[4]++;
            else
            {
                r[6]++;
            }
        }
        else if(x==sx)
        {
            if(y>sy)
            r[2]++;
            else
            {
                r[7]++;
            }   
        }
        else
        {
            if(y>sy)
            r[3]++;
            else if(y==sy)
            r[5]++;
            else
            {
                r[8]++;
            }
        }
        
    }
    int a1=r[1]+r[2]+r[3];
    int a2=r[3]+r[5]+r[8];
    int a3=r[8]+r[7]+r[6];
    int a4=r[6]+r[4]+r[1];
    int m1=max(a1,a2);
    int m2=max(a3,a4);
    int m=max(m1,m2);
    cout<<m<<endl;
    if(a1==m)
    cout<<sx<<" "<<sy+1<<endl;
    else if(a2==m)
    cout<<sx+1<<" "<<sy<<endl;
    else if(a3==m)
    cout<<sx<<" "<<sy-1<<endl;
    else
    {
        cout<<sx-1<<" "<<sy<<endl;
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