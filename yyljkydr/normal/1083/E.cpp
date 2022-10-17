#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e6+1e3+7;

int n;

struct P{
    int x,y,a;
}p[N];

int f[N];

int K(int i)
{
    return -p[i].x;
}

int B(int i)
{
    return f[i];
}

//f[i] = f[j] + -xj * yi + xi * yi - a

//inter(i,j) = (B(j) - B(i)) / (K(i) - K(j))

bool cmp(int i,int j,int k)
{
    return ((long double)B(k)-B(i))*(K(i)-K(j))>=((long double)B(j)-B(i))*(K(i)-K(k));
}

int eval(int i,int x)
{
    return K(i)*x+B(i);
}

int head,tail,q[N];

int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

signed main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        p[i].x=read(),p[i].y=read(),p[i].a=read();
    sort(p+1,p+n+1,[&](const P &a,const P &b){return a.x<b.x;});
    head=1,tail=0;
    q[++tail]=0;
    for(int i=1;i<=n;i++)
    {
        while(head<tail&&eval(q[head+1],p[i].y)>=eval(q[head],p[i].y))
            head++;
        f[i]=eval(q[head],p[i].y)+p[i].x*p[i].y-p[i].a;
        while(head<tail&&cmp(q[tail-1],q[tail],i))
            tail--;
        q[++tail]=i;
    }
    printf("%lld\n",*max_element(f+1,f+n+1));
}