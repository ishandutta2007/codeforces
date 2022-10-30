#include<bits/stdc++.h>
#define maxn 1050
using namespace std;

const int M=2e6;

int n,m;
int x[maxn],y[maxn];

int main()  {
    scanf("%d",&n);
    for (int i=1;i<=n;++i)  {
        scanf("%d%d",x+i,y+i);
        x[i]+=M,y[i]+=M;
    }

    // if (n==2)   {
    //     printf("1\n2\n");
    //     return 0;
    // }

    for (int b=0;b<30;++b)  {
        int m=0;
        for (int i=1;i<=n;++i)
            if ((x[i]>>b&1)^(y[i]>>b&1))
                ++m;
        if (m&&m<n) {
            printf("%d\n",m);
            for (int i=1;i<=n;++i)
                if ((x[i]>>b&1)^(y[i]>>b&1))
                    printf("%d ",i);
        } else  {
            m=0;
            for (int i=1;i<=n;++i)
                if (x[i]>>b&1)
                    ++m;
            if (m==0||m==n) continue;
            printf("%d\n",m);
            for (int i=1;i<=n;++i)
                if (x[i]>>b&1)
                    printf("%d ",i);
        }
        return 0;
    }
    assert(0);
    return 0;
}