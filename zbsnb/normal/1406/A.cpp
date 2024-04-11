#include<bits/stdc++.h>
using namespace std;
int cnt[110];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=0;i<=100;i++) cnt[i]=0;
        for(int i=1;i<=n;i++){
            int tmp;cin>>tmp;
            cnt[tmp]++;
        }
        int ans=0;
        for(int t=0;t<2;t++)
        for(int i=0;i<=100;i++){
            if(!cnt[i]){
                ans+=i;
                break;
            }
            else cnt[i]--;
        }
        cout<<ans<<endl;
    }
}