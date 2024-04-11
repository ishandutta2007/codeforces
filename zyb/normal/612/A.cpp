#include<stdio.h>
using namespace std;
int n,p,q,gt;
char c[105];
inline void print(int o) {
    printf("%d\n",o+(n-o*p)/q);
    gt=0;
    for (int i=1;i<=o;i++) {
        for (int j=1;j<=p;j++) printf("%c",c[gt++]);
        puts("");
    }
    for (int i=1;i<=(n-(o*p))/q;i++) {
        for (int j=1;j<=q;j++) printf("%c",c[gt++]);
        puts("");
    }
}       
int main() {
    scanf("%d%d%d",&n,&p,&q);
    scanf("%s",c);
    for (int i=0;i<=n/p;i++) {
        int gt=n-i*p;
        if (!(gt%q)) return print(i),0;
    }
    puts("-1");
}