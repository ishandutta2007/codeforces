#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int cnt=0;
        map<vector<int>,int> mp;
        for(int i=1;i<=n;i++){
            int tmp;cin>>tmp;
            vector<int> vec;
            for(int j=2;j*j<=tmp;j++){
                int c=0;
                while(tmp%j==0){
                    c++;
                    tmp/=j;
                }
                if(c%2==1) vec.push_back(j);
            }
            if(tmp!=1) vec.push_back(tmp);

            if(vec.size()==0) cnt++;
            else mp[vec]++; 
        }
        int cnt2=cnt;
        int cnt3=0;
        for(auto &it:mp){
            // cout<<"iter:"<<endl;
            // for(auto &it:it.first) cout<<it<<" ";cout<<endl;
            // cout<<it.second<<endl;
            cnt=max(cnt,it.second);
            if(it.second%2==0){
                cnt2+=it.second;
            }
            else cnt3=max(cnt3,it.second);
        }

        // cout<<cnt<<" "<<cnt2<<endl;

        int q;cin>>q;
        while(q--){
            long long tmp;cin>>tmp;
            if(tmp==0) cout<<cnt<<"\n";
            else cout<<max(cnt2,cnt3)<<"\n";
        }
    }
}