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
int gcd(int i,int j)
{
    int a=min(i,j);
    int b=max(i,j);
    int m=1;
    while(a>0)
    {
        int temp=b%a;
        if(temp==0)
        break;
        b=a;
        a=temp;
    }
    return a;
    
}
void solve()
{
    int n; 
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
    cin>>ar[i];
    int num=999999937;
    int k=0;
    int arr[n+n];
    int j=0;
    for(int i=0;i<n-1;i++)
    {
        arr[j]=ar[i];
        j++;
        if(gcd(ar[i],ar[i+1])!=1)
        {
            if(ar[i]==num)
            {
                arr[j]=2;

            }
            else
            {
                arr[j]=num;
            }
            j++;
            k++;
            
        }
    }
    arr[j]=ar[n-1];
    cout<<k<<endl;
    for(int i=0;i<n+k;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
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