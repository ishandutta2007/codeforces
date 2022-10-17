#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7;

stack<int>up,dw;

int n,h[N],f[N];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&h[i]);
    f[1]=0;
    up.push(1);
    dw.push(1);
    for(int i=2;i<=n;i++)
    {
        f[i]=f[i-1]+1;
        while(up.size()&&h[i]<h[up.top()])
        {
            up.pop();
            if(up.size())
                f[i]=min(f[i],f[up.top()]+1);
        }
        while(up.size()&&h[i]==h[up.top()])
            up.pop();
        up.push(i);
        while(dw.size()&&h[i]>h[dw.top()])
        {
            dw.pop();
            if(dw.size())
                f[i]=min(f[i],f[dw.top()]+1);
        }
        while(dw.size()&&h[i]==h[dw.top()])
            dw.pop();
        dw.push(i);
    }
    printf("%d\n",f[n]);
}