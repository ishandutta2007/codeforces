#include<bits/stdc++.h>
using namespace std;
int n,m,f[5][233][2],ok;
char s[5][233];

int main(){
    int T;
    scanf("%d\n",&T);
    while (T--){
        scanf("%d%d\n",&n,&m);
        for (int i=1;i<=3;i++){
            scanf("%s",s[i]+1);
        }
        memset(f,0,sizeof(f));
        ok=0;
        for (int i=1;i<=3;i++){
            for (int j=1;j<=n;j++){
                if (s[i][j]=='s'){
                    f[i][j][0]=1;
                }
            }
        }
        for (int nnd=100;nnd;nnd--){
            for (int i=1;i<=3;i++){
                for (int j=1;j<=n;j++){
                    if (f[i][j][0]==1){
                        if (j==n) ok=1;
                        else{
                            if (s[i][j+1]=='.'){
                                f[i][j+1][1]=1;
                                if (i-1>0) f[i-1][j+1][1]|=s[i-1][j+1]=='.'?1:0;
                                if (i+1<=3) f[i+1][j+1][1]|=s[i+1][j+1]=='.'?1:0;
                            }
                        }
                    }
                }
            }
            
            for (int i=1;i<=3;i++){
                for (int j=1;j<=n;j++){
                    if (f[i][j][1]==1){
                        if (j+2>=n){
                            if (j==n){
                                ok=1;
                            }else if(j==n-1){
                                if (s[i][j+1]=='.'){
                                    ok=1;
                                }
                            }else{
                                if (s[i][j+1]=='.'&&s[i][j+2]=='.'){
                                    ok=1;
                                }
                            }
                        }else{
                            if (s[i][j+1]=='.'&&s[i][j+2]=='.'){
                                f[i][j+2][0]=1;
                            }
                        }
                    }
                }
            }
            if (ok) break;
        }
        if (ok){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}