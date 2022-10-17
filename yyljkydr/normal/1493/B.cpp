#include<bits/stdc++.h>
using namespace std;

int T,h,m,a,b;

int rev[11]={0,1,5,-1,-1,2,-1,-1,8,-1};

int chk(int x,int y)
{
    int a=x/10,b=x%10,c=y/10,d=y%10;
    if(rev[a]==-1||rev[b]==-1||rev[c]==-1||rev[d]==-1)
        return 0;
    int rh=rev[d]*10+rev[c];
    int rm=rev[b]*10+rev[a];
    if(rh>=h||rm>=m)
        return 0;
    return 1;
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&h,&m);
        scanf("%d:%d",&a,&b);
        while(!chk(a,b))
        {
            b++;
            if(b==m)
                b=0,a++;
            if(a==h)
                a=0;
        }
        printf("%02d:%02d\n",a,b);
    }
}