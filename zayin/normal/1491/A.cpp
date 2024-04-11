#include<bits/stdc++.h>
#define maxn 1000050
using namespace std;

int n,m;
int a[maxn];

int cnt[maxn];

int main()  {
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i)
        scanf("%d",a+i),++cnt[a[i]];
    while (m--) {
        int op,x;
        scanf("%d%d",&op,&x);
        if (op==1)  {
            --cnt[a[x]];
            a[x]^=1;
            ++cnt[a[x]];
        } else  {
            if (cnt[1]>=x)
                puts("1");
            else
                puts("0");
        }
    }
    return 0;
}