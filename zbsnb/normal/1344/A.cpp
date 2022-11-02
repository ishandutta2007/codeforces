#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        int vis[n]={};
        int flg=0;
        for(int i=1;i<=n;i++){
            int now=(i+n+a[i]%n)%n;
            vis[now]++;
            if(vis[now]==2){
                flg=1;
                break;
            }
        }
        cout<<(flg?"NO":"YES")<<endl;
    }
}