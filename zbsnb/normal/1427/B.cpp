#include<bits/stdc++.h>
using namespace std;
#define ll long long
char s[1000010];
int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;cin>>(s+1);
        vector<int> tmp;
        int cnt=0;int ans=0;int flg=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='L')cnt++;
            else{
                if(flg){
                    if(cnt!=0){
                        tmp.push_back(cnt);
                    }
                }
                flg=1;
                cnt=0;
                ans++;
            }
        }
        sort(tmp.begin(),tmp.end());
        ans=min(n,ans+k);
        if(ans==0){
            cout<<0<<endl;
            continue;
        }
        int d=tmp.size()+1;
        for(auto &it:tmp){
            // cout<<"?:"<<k<<" "<<it<<" "<<d<<" "<<ans<<endl;
            if(k>=it){
                k-=it;
                d--;
            }
        }
        cout<<2*ans-d<<endl;
    }
}