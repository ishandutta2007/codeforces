//By BLADEVIL
#include <cmath>
#include <cstdio>
#define maxn 25;

using namespace std;


int main() {
    int task; scanf("%d",&task);
    while (task--) {
        int n,p; scanf("%d%d",&n,&p);
        int rest(2*n+p);
        for (int i=1;(i<=n)&&rest;i++)
            for (int j=i+1;(j<=n)&&rest;j++) printf("%d %d\n",i,j),rest--;
    } 
    return 0;
}