#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // int t;cin>>t;
    // while(t--){
        int n,k;cin>>n>>k;
        vector<int> t1,t2,t3;
        for(int i=1;i<=n;i++){
            int t,a,b;cin>>t>>a>>b;
            if(a==1&&b==1)t1.push_back(t);
            if(a==1&&b==0)t2.push_back(t);
            if(a==0&&b==1)t3.push_back(t);
        }
        
        sort(t2.begin(),t2.end());
        sort(t3.begin(),t3.end());
        for(int i=0;i<min(t2.size(),t3.size());i++){
            t1.push_back(t2[i]+t3[i]);
        }
        sort(t1.begin(),t1.end());

        if(t1.size()>=k){
            int ans=0;
            for(int i=0;i<k;i++){
                ans+=t1[i];
            }
            cout<<ans<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    // }
}