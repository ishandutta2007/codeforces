#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000010];
int flg[1000010];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            flg[i]=0;
        }
        int cnt1=0,cnt2=0;
        for(int i=1;i<=n;i++){
            if(a[i]>cnt1+i){
                cnt1++;
                flg[i]++;
                // cout<<"?"<<i<<endl;
            }
        }
        for(int i=n;i>=1;i--){
            if(a[i]<2*n+1-(cnt2+(n+1-i))){
                cnt2++;
                flg[i]++;
                // cout<<"!"<<i<<endl;
            }
        }
        int ans=1;
        for(int i=1;i<=n;i++) ans+=flg[i]==2;
        cout<<ans<<endl;
    }
}