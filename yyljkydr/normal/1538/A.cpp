#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,a[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int p=min_element(a+1,a+n+1)-a;
        int q=max_element(a+1,a+n+1)-a;
        if(p>q)
            swap(p,q);
        int ans=min({q,n-p+1,p+n-q+1});
        printf("%d\n",ans);
    }
}