#include<cstdio>
using namespace std;

int n,m,i;

int main(){
    scanf("%d%d",&n,&m);
    if (n*(n-1)/2<=m){
        puts("no solution");
        return 0;
    }
    for (i=1;i<=n;i++){
        printf("0 %d\n",2*i);
    }
}