#include<bits/stdc++.h>
#define maxn 1050
using namespace std;

int n,a[maxn],pos[maxn];

int vis[maxn];

int main()  {
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%d",a+i),pos[i]=i;
    sort(pos+1,pos+n+1,[&](int i,int j){
        return a[i]>a[j]||(a[i]==a[j]&&i>j);
    });

    int cnt=0;
    for (int i=1;i<=n;++i)
        for (int j=1;j<i;++j)
            if (a[i]<a[j])
                ++cnt;
    
    printf("%d\n",cnt);

    for (int i=1;i<=n;++i)    {
        int k=pos[i];
        for (int j=1;j<k;++j)
            if (vis[j]) {
                printf("%d %d\n",j,k);
                swap(a[j],a[k]);
            }
        vis[k]=1;
    }

    for (int i=2;i<=n;++i) assert(a[i-1]<=a[i]);
    return 0;
}