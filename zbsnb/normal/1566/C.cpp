#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--) {
        int m;cin>>m;
        int n = 2;
        char a[n+2][m+2];
        int tag[m+2];
        int use[m+2]={};
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=m;i++){
            int f0=0,f1=0;
            for(int j=1;j<=n;j++){
                if(a[j][i]=='0')f0=1;
                if(a[j][i]=='1')f1=1;
            }
            if(f0&f1) tag[i]=2;
            else if (f0) tag[i]=0;
            else if (f1) tag[i]=1;
        }
        int ans = 0;
        tag[0] = 2;
        use[0] = 1;
        for(int i = 1;i <= m; i++) {
            if(tag[i] == 2) ans += 2, use[i] = 1;
            else if(tag[i] == 0) {
                if (tag[i-1] == 1 && use[i-1] == 0) {
                    ans += 2, use[i] = 1;
                }
                else ans += 1;
            }
            else {
                if(tag[i-1] == 0 && use[i-1] == 0) {
                    ans += 1, use[i] = 1;
                }
            }
        }
        cout<<ans<<endl;
    }
}