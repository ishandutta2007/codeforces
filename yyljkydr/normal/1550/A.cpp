#include<bits/stdc++.h>
using namespace std;

int T,s;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&s);
        for(int i=1;;i++)
        {
            s-=i*2-1;
            if(s<=0)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
}