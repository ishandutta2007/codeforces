#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<vector>
using namespace std;
#define ll long long

signed main(){
    int t;cin>>t;
    while(t--){
        int cnt[10000]={};
        int a[100];
        int n;cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            cnt[a[i]]++;
        }
        int ans=0;
        for(int i=0;i<=9999;i++){
            if(cnt[i])ans+=cnt[i]-1;
        }
        cout<<ans<<endl;

        for(int i=1;i<=n;i++){
            if(cnt[a[i]]==1){
                if(a[i]<=999)cout<<"0";
                if(a[i]<=99)cout<<"0";
                if(a[i]<=9)cout<<"0";
                cout<<a[i]<<endl;
            }
            if(cnt[a[i]]>=2){
                int now=a[i]/10*10;
                while(cnt[now])now++;
                cnt[now]=1;

                if(now<=999)cout<<"0";
                if(now<=99)cout<<"0";
                if(now<=9)cout<<"0";
                cout<<now<<endl;
                cnt[a[i]]--;
            }
        }
    }
}