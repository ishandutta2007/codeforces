#include <bits/stdc++.h>
using namespace std ;
#define N 30010
#define M 610
int s[N] ;
int dp[N][M] ;//
//dp[i][j]i,dj-300 
//  sqrt(n)300 
int n,d,x ;
bool ok(int x,int c){ // 
    int delta=d+c-300 ;
    if (delta<=0) return false ;
    if (delta+x>30000) return false ; 
    return true ;
}
int dfs(int x,int c){
    int &ret=dp[x][c] ;
    if (ret==-1){ // 
        ret=0;
        if (ok(x,c)) ret=max(ret,dfs(x+d+c-300,c)) ;
        if (ok(x,c-1)) ret=max(ret,dfs(x+d+c-1-300,c-1)) ;
        if (ok(x,c+1)) ret=max(ret,dfs(x+d+c+1-300,c+1)) ;
        ret+=s[x] ;
    } 
    return ret ;
} 
int main(){
    scanf("%d%d",&n,&d);
    memset(dp,-1,sizeof(dp)) ;// 
    for (int i=1;i<=n;i++){
        scanf("%d",&x) ;
        s[x]++;// 
    }
    printf("%d\n",dfs(d,300)) ;// 
}