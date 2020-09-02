 #include <bits/stdc++.h>
 #define int long long
    using namespace std;

    long long cost=1e18;
    struct cmp{
        bool operator() (const pair<int,int>& a, const pair<int,int>& b){
            int len1=a.second-a.first+1;
            int len2=b.second-b.first+1;
            if(len1==len2)
                return a.first<b.first;
            return len1>len2;
        }
    };
    int32_t main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int t;
        cin>>t;
        while(t--){
            int n;
            cin>>n;
            if(n==1){
                cout<<1<<"\n";
                continue;
            }
            vector<int>a(n);
            set<pair<int,int>,cmp>s;
            s.insert({0,n-1});
            for(int i=1;i<=n;i++){
                auto cur = *s.begin();
                s.erase(s.begin());
                int mid=(cur.first+cur.second)/2;
                a[mid]=i;
                if(cur.first<mid)
                s.insert({cur.first,mid-1});
                if(cur.second>mid)
                s.insert({mid+1,cur.second});
            }
            for(int i=0;i<n;i++)
                cout<<a[i]<<" ";
            cout<<"\n";
        }
        return 0;
    }
