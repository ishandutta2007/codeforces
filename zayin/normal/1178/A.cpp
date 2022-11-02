#include<bits/stdc++.h>
#define maxn 105
using namespace std;
int n,a[maxn];
int pos[maxn];
int main()  {
    scanf("%d",&n);
    int sum=0;
    for (int i=1;i<=n;++i)
        scanf("%d",a+i),sum+=a[i];
    for (int i=2;i<=n;++i)  pos[i]=i;
    sort(pos+2,pos+n+1,[&](const int& i,const int&j){
        return a[i]<a[j];
    });
    int s=a[1],cnt=1;
    for (int i=2;i<=n;++i)
        if (a[1]>=a[pos[i]]*2)
            s+=a[pos[i]],++cnt;
    if (2*s>sum)    {
        printf("%d\n",cnt);
        printf("1 ");
        for (int i=2;i<=n;++i)
            if (a[1]>=a[pos[i]]*2)
                printf("%d ",pos[i]);
    } else puts("0");
    return 0;
}