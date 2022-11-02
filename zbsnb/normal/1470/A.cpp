#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        vector<int> a(n+1,0);
        vector<int> b(m+1,0);
        set<int> s;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            s.insert(i);
        }
        sort(a.begin()+1,a.end(),greater<int>());
        for(int i=1;i<=m;i++){
            cin>>b[i];
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            int tmp=n+1;
            if(s.size()) tmp=*s.begin();
            int val;
            if(tmp<a[i]){
                val=b[tmp];
                s.erase(tmp);
            }
            else val=b[a[i]];

            // cout<<tmp<<endl;
            // cout<<i<<" "<<val<<endl;

            ans+=val;
        }
        cout<<ans<<endl;
    }
}