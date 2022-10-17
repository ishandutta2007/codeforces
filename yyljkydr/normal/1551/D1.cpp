#include<bits/stdc++.h>
using namespace std;

const int N=1e2+1e1+7;

int T,n,m,k;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&k);
        if(n%2==0&&m%2==0)
        {
            puts(k%2==0?"YES":"NO");
        }
        else
        {
            int swp=0;
            if(m%2==1)
                swap(n,m),k=n*m/2-k,swp=1;
            if(k<m/2)
                puts("NO");
            else if((k-m/2)%2!=0)
                puts("NO");
            else
                puts("YES");
        }
    }
}