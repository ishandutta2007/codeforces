#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int a[MAXN];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,x;
        scanf("%d%d",&n,&x);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        if(n-x>=x+1)
        {
            printf("YES\n");
            continue;
        }
        vector<int> tmp;
        for(int i=1;i<=n-x;i++)
            tmp.push_back(a[i]);
        for(int i=x+1;i<=n;i++)
            tmp.push_back(a[i]);
        sort(tmp.begin(),tmp.end());
        int idx=0;
        for(int i=1;i<=n-x;i++,idx++)
            a[i]=tmp[idx];
        for(int i=x+1;i<=n;i++,idx++)
            a[i]=tmp[idx];
        bool isok=1;
        for(int i=1;i+1<=n;i++)
            isok&=(a[i]<=a[i+1]);
        printf("%s\n",isok ? "YES" : "NO");
    }
    return 0;
}