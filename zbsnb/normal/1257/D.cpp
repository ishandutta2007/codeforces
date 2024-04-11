#include<iostream>
#include<map>
using namespace std;
#define ll long long
int a[200010];
int num[200010];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
   while(t--){
       int n;cin>>n;
        for(int i=1;i<=n;i++){
           cin>>a[i];
        }
        for(int i=1;i<=n;i++)num[i]=0;
        int m;cin>>m;
        for(int i=1;i<=m;i++){
           int a,b;cin>>a>>b;
           num[b]=max(num[b],a);
        }
        for(int i=n-1;i>=1;i--){
            num[i]=max(num[i+1],num[i]);
        }
        // for(int i=1;i<=n;i++){
        //     cout<<num[i]<<" ";
        // }cout<<endl;
        int now=0;
        int cnt=1;
        int ans=1;
       for(int i=1;i<=n;i++){
           now=max(now,a[i]);
           //cout<<i<<" "<<now<<endl;
            if(num[cnt]>=now){
                cnt++;
            }
            else{
                if(cnt==1){
                    ans=-1;
                    break;
                }
                else{
                    ans++;
                    now=0;
                    cnt=1;
                    i--;
                }
            }
       }
       cout<<ans<<'\n';
   }
}