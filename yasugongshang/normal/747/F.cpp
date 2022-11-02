#include<iostream>
#include<stdio.h>
using namespace std;
long long k,t,deep;
long long c[20][20],f[20][20];
int a[23],num[20];
long long dp(int x){
    for(int i=0;i<=16;i++){
        f[0][i]=1;
    }
    for(int i=1;i<=x;i++){
        for(int j=1;j<=16;j++){
            f[i][j]=0;
            for(int k=0;k<=min(i,a[j]);k++){
                f[i][j]+=f[i-k][j-1]*c[i][k]; 
            }
        }
    }
    return f[x][16];
}
void prt(int x){
    if(x<10){
        putchar(x+'0');
    }else{
        putchar(x-10+'a');
    }
}
void dfs(int k,int x){
    if(x==0){
        return;
    }
    for(int i=(x==deep)?2:1;i<=16;i++){
        if(a[i]==0){
            continue;
        }
        a[i]--;
        long long size=dp(x-1);
        if(size>=k){
            prt(i-1);
            dfs(k,x-1);
            break;
        }
        k=k-size;
        a[i]++;
    }
}
int main(){
    cin>>k>>t;
    for(int i=1;i<=16;i++){
        a[i]=t;
    }
    c[1][0]=c[1][1]=1;
    for(int i=2;i<=10;i++){
        c[i][0]=1;
        for(int j=1;j<=i;j++){
            c[i][j]=c[i-1][j-1]+c[i-1][j];
        }
    }
    deep=1;
    while(1){
        a[2]--;
        long long size=dp(deep-1)*15;
        a[2]++;
        if(size>=k){
            break;
        }
        deep++,k-=size;
    }
    dfs(k,deep);
    return 0;
}
/*

in:
1000000 2

out:
fca2c

*/