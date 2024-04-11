#include<bits/stdc++.h>
#define maxn 105
using namespace std;

int n,a[maxn];
bool used[maxn];

int main()  {
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%d",a+i),used[a[i]]=1;
    int cnt=0;
    for (int i=1;i<maxn;++i)    {
        if (!used[i])   continue;
        ++cnt;
        for (int j=i;j<maxn;j+=i)
            used[j]=0;
    }
    printf("%d\n",cnt);
    return 0;
}