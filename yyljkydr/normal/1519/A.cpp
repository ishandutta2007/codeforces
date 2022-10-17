#include<bits/stdc++.h>
using namespace std;

int r,b,d,T;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&r,&b,&d);
        if(r>b)
            swap(b,r);
        puts((b-r+r-1)/r<=d?"Yes":"No");
    }
}