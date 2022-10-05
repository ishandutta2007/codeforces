#include<bits/stdc++.h>
using namespace std;
int n,m,now;
char s[233][233];
char col[7][4]={
{' ',' ',' ',' '},
{' ','B','R','G'},
{' ','B','G','R'},
{' ','R','B','G'},
{' ','R','G','B'},
{' ','G','B','R'},
{' ','G','R','B'},
};


bool ok1(){
    int h=n/3;
    char c;
    for (int i=1;i<=n;i++){
        c=col[now][(i-1)/h+1];
        for (int j=1;j<=m;j++){
            if (s[i][j]!=c){
                return 0;
            }
        }
    }
    return 1;
}

bool ok2(){
    int h=m/3;
    char c;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            c=col[now][(j-1)/h+1];
            if (s[i][j]!=c){
                return 0;
            }
        }
    }
    return 1;
}

bool C(){
    if (n%3==0){
        if (ok1()){
            return 1;
        }
    }
    if (m%3==0){
        if (ok2()){
            return 1;
        }
    }
    return 0;
}

int main(){
    scanf("%d%d\n",&n,&m);
    for (int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
    }
    for (int i=1;i<=6;i++){
        now=i;
        if (C()){
            printf("YES");
            return 0;
        }
    }
    
    printf("NO");
}