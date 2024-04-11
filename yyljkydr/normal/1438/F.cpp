#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int h,n;

map<int,int>cnt;

int c;

int main()
{
    srand(time(NULL));
    scanf("%d",&h);
    n=(1<<h)-1;
    for(int i=1;i<=420;i++)
    {
        int x=(1ll*rand()*rand()+rand())%n+1,y=(1ll*rand()*rand()+rand())%n+1,z=(1ll*rand()*rand()+rand())%n+1;
        while(x==y||y==z||z==x)
            x=(1ll*rand()*rand()+rand())%n+1,y=(1ll*rand()*rand()+rand())%n+1,z=(1ll*rand()*rand()+rand())%n+1;
        printf("? %d %d %d\n",x,y,z);
        fflush(stdout);
        scanf("%d",&c);
        cnt[c]++;
    }
    int p=1,q=2;
    if(cnt[p]<cnt[q])
        swap(p,q);
    for(int i=3;i<=n;i++)
    {
        if(cnt[i]>cnt[p])
            q=p,p=i;
        else if(cnt[i]>cnt[q])
            q=i;
    }
    for(int i=1;i<=n;i++)
    {
        if(i==p||i==q)
            continue;
        printf("? %d %d %d\n",p,q,i);
        fflush(stdout);
        scanf("%d",&c);
        if(c==i)
        {
            printf("! %d\n",c);
            fflush(stdout);
            return 0;
        }
    }
    assert(0);
}