#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
#define ll long long
vector<int> vc[200010];
int sum[200010];
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=1;i<=n;i++){
            vc[i].clear();
        }
        for(int i=1;i<=n;i++){
            int a,b;cin>>a>>b;
            vc[a+1].push_back(b);
        }
        for(int i=1;i<=n;i++)sum[i]=sum[i-1]+vc[i].size();
        for(int i=1;i<=n;i++)sort(vc[i].begin(),vc[i].end());
        multiset<int> s;
        int now=0;
        ll ans=0;
        for(int i=n;i>=1;i--){
            while(now+sum[i]<i){
                auto it=s.begin();
                ans+=*it;
                s.erase(it);
                now++;
            }
            
            for(int j=0;j<vc[i].size();j++){
                s.insert(vc[i][j]);
            }
        }
        cout<<ans<<endl;
    }
}