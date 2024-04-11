#include<bits/stdc++.h>
using namespace std;
const int MAXN=1005;
int a[MAXN];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,H;
        scanf("%d%d",&n,&H);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1,greater<int>());
        int res=H/(a[1]+a[2])*2;
        H%=(a[1]+a[2]);
        for(int i=1;H>0;i=i%2+1)
            H-=a[i],res++;
        printf("%d\n",res);
    }
    return 0;
}