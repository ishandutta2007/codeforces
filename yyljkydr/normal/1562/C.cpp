#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n;

char s[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        scanf("%s",s+1);
        int z=*min_element(s+1,s+n+1);
        if(z=='0')
        {
            int p=min_element(s+1,s+n+1)-s;
            if(p<=n/2)
            {
                printf("%d %d %d %d\n",p,n,p+1,n);
            }
            else
            {
                printf("%d %d %d %d\n",1,p,1,p-1);
            }
        }
        else
            printf("%d %d %d %d\n",1,n-(n&1),1,(n-(n&1))>>1);
    }
}