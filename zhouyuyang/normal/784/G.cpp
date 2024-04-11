#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

char st[1231000];
int op[1231231],num[12313],cnt=0;

int calc(int l,int r)
{
    int x=0;
    for(int i=l;i<=r;i++)
        x=x*10+st[i]-'0';
    return x;
}

void work(int&th,int x)
{
    int to=x+48;
    while(th>to)th--,printf("-");
    while(th<to)th++,printf("+");
    printf(".\n");
}

int main()
{
    scanf("%s",st+1);int pre=0;
    for(int i=1;st[i];i++)
    {
        if(st[i]=='+'||st[i]=='-')
        {
            op[++cnt]=(st[i]=='+')?1:2;
            num[cnt]=calc(pre+1,i-1);
            pre=i;
        }
    }
    num[++cnt]=calc(pre+1,strlen(st+1));
    int x=num[1];
    for(int i=1;i<cnt;i++)
    {
        if(op[i]==1)x=x+num[i+1];
        else x=x-num[i+1];
    }
    int th=0;cnt=0;
    if(!x) {work(th,0);return 0;}
    while(x)
    {
        num[++cnt]=x%10;x/=10;
    }
    for(int i=cnt;i;i--)
        work(th,num[i]);
    return 0;
}