#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t,n,f[1005][4],vis[1005];
const int ch[]={3,5,7};
int main(){
    cin>>t;memset(f,-1,sizeof(f));
    f[0][0]=f[0][1]=f[0][2]=0;vis[0]=1;
    for(int i=1;i<=1000;i++){
        for(int j=0;j<3;j++){
            if(i>=ch[j]&&vis[i-ch[j]]){
                vis[i]=1;
                for(int k=0;k<3;k++) f[i][k]=f[i-ch[j]][k]+(k==j);
                break;
            }
        }
    }
    while(t--){
        scanf("%d",&n);
        if(!vis[n]) puts("-1");
        else{
            for(int i=0;i<3;i++) printf("%d ",f[n][i]);
            puts("");
        }
    }
    return 0;
}