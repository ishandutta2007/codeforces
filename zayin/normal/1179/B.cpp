#include<bits/stdc++.h>
using namespace std;

int n,m;

int main()  {
    scanf("%d%d",&n,&m);
    int c=n*m;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)  {
            int a=n-i+1,b=m-j+1;
            printf("%d %d\n",i,j);
            if (--c==0) return 0;
            printf("%d %d\n",a,b);
            if (--c==0) return 0;
        }
    return 0;
}