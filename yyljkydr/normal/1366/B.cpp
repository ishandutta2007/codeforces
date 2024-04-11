#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T;

int n,m,x;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&x,&m);
        int l=x,r=x;
        for(int i=1;i<=m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if(!(r<a||b<l))
                l=min(l,a),r=max(r,b);
        }
        printf("%d\n",r-l+1);
    }   
}