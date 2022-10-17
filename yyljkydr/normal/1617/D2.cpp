#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,ans[N];

int rd()
{
    return (1ll*rand()*rand()+rand())%INT_MAX;
}

int rnd(int l,int r)
{
    return rd()%(r-l+1)+l;
}

map<vector<int>,int >vis;

int query(int x,int y,int z)
{
    if(x>z)
        swap(x,z);
    if(x>y)
        swap(x,y);
    if(y>z)
        swap(y,z);
    if(vis.count({x,y,z}))
        return vis[{x,y,z}];
    printf("? %d %d %d\n",x,y,z);
    fflush(stdout);
    int &ret=vis[{x,y,z}];
    scanf("%d",&ret);
    return ret;
}

int val[N];

void solve1()
{
     for(int i=1;i<=n;i++)
        ans[i]=-1;
    vector<int>f0,f1;
    for(int i=1;i<=n;i+=3)
    {
        int k=query(i,i+1,i+2);
        val[i]=k;
        if(!k)
            f0={i,i+1,i+2};
        else
            f1={i,i+1,i+2};
    }
    int X=-1,Y=-1;
    {
        int x=f0[0],y=f1[0],z=f0[1],w=f1[1];
        int a=query(x,y,z),b=query(x,y,w);
        if(a!=b)
        {
            ans[z]=a,ans[w]=b;
            ans[x]=query(z,w,x),ans[y]=ans[x]^1;
            X=x,Y=y;
            ans[f0[2]]=query(X,Y,f0[2]);
            ans[f1[2]]=query(X,Y,f1[2]);
        }
        else
        {
            if(a==0)
            {
                X=x;
                ans[x]=0;
                int c=query(x,y,f1[2]);
                if(b!=1&&c!=1)
                    ans[y]=0,ans[w]=ans[f1[2]]=1,Y=w;
                else
                    ans[y]=1,ans[w]=b,ans[f1[2]]=c,Y=y;
                ans[z]=query(X,Y,z);
                ans[f0[2]]=query(X,Y,f0[2]);
            }    
            else
            {
                X=y;
                ans[y]=1;
                int c=query(x,y,f0[2]);
                if(a!=0&&c!=0)
                    ans[x]=1,ans[z]=ans[f0[2]]=0,Y=z;
                else
                    ans[x]=0,ans[z]=a,ans[f0[2]]=c,Y=x;
                ans[w]=query(X,Y,w);
                ans[f1[2]]=query(X,Y,f1[2]);
            }
            
        }
    }
    if(ans[X])
        swap(X,Y);
    for(int i=1;i<=n;i+=3)
    {
        if(ans[i]!=-1)
            continue;
        int p=val[i]?X:Y;
        int a=query(p,i,i+1);
        int b=query(p,i,i+2);
        if(a!=val[i]&&b!=val[i])
            ans[i]=!val[i],ans[i+1]=ans[i+2]=val[i];
        else
        {
            ans[i]=val[i];
            ans[i+1]=a;
            ans[i+2]=b;
        }
    }
    int k=0;
    for(int i=1;i<=n;i++)
        if(!ans[i])
            k++;
    printf("! %d ",k);
    for(int i=1;i<=n;i++)
        if(!ans[i])
            printf("%d ",i);
    puts("");
    fflush(stdout);
}

void solve0()
{
    for(int i=1;i<=n;i++)
        ans[i]=-1;
    int X=-1,Y=-1,last=-1;
    for(int i=0;i<n;i++)
    {
        int x=i,y=(i+1)%n,z=(i+2)%n;
        int k=query(x+1,y+1,z+1);
        if(last!=-1)
        {
            if(last!=k)
            {
                X=x+1,Y=y+1;
                ans[(x-1+n)%n+1]=last;
                ans[z+1]=k;
                ans[x+1]=query(z+1,(x-1+n)%n+1,x+1);
                ans[y+1]=ans[x+1]^1;
                break;
            }
        }
        last=k;
    }
    for(int i=1;i<=n;i++)
        if(ans[i]==-1)
            ans[i]=query(i,X,Y);
    int k=0;
    for(int i=1;i<=n;i++)
        if(!ans[i])
            k++;
    printf("! %d ",k);
    for(int i=1;i<=n;i++)
        if(!ans[i])
            printf("%d ",i);
    puts("");
    fflush(stdout);
}

int main()
{
    srand(time(NULL));
    scanf("%d",&T);
    while(T--)
    {
        vis.clear();
        scanf("%d",&n);
        // if(n==6)
        //     solve0();
        // else
            solve1();
    }
}
/*
001011
*/