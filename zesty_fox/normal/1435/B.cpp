#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int T,n,m,a[505][505],b[505][505],p[505];
int main(){
    cin>>T;
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++) scanf("%d",&b[i][j]);
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=m;k++){
                    if(b[i][1]==a[j][k]){
                        p[k]=i;
                        goto nxt;
                    }
                }
            }
            nxt:;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) printf("%d ",b[p[j]][i]);
            puts("");
        }

    }
    return 0;
}