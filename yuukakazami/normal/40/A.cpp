#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int main()
{
    //freopen("in","r",stdin);
    int x,y;cin>>x>>y;
    double _r=sqrt(x*x+y*y);
    int r=_r;
    if(r*r==x*x+y*y||!x||!y)
    {
        puts("black");
        return 0;
    }
    if(x*y>=0)
    {
        if(r%2)puts("white");
        else puts("black");
    }
    else
    {
        if(!(r%2))puts("white");
        else puts("black");
    }
}