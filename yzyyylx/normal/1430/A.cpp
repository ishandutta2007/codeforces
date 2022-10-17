#include<bits/stdc++.h>
using namespace std;
 
int T,n;
 
int main()
{
    int i,j;
    cin>>T;
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<=n/3;i++)
        {
            for(j=0;j*5+i*3<=n;j++)
            {
                if((n-i*3-j*5)%7==0)
                {
                    printf("%d %d %d\n",i,j,(n-i*3-j*5)/7);
                    break;
                }
            }
            if(j*5+i*3<=n) break;
        }
        if(i>n/3) puts("-1");
    }
}