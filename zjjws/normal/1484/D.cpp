#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#define LL long long
using namespace std;
inline LL rin()
{
    LL x=0;
    char c;
    bool tag=false;
    for(c=getchar();c>'9'||c<'0';c=getchar())if(c=='-'){c=getchar();tag=true;break;}
    for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^'0');
    if(tag)x=-x;
    return x;
}
inline void jh(int &x,int &y){if(x^y)x^=y^=x^=y;return;}
inline void jh(LL &x,LL &y){if(x^y)x^=y^=x^=y;return;}

const int N=3e5+3;
int n;
int a[N];
int l[N];
int r[N];
inline int Gcd(int a,int b){return (!b)?(a):(Gcd(b,a%b));}

vector<int>d;
set<int>gyq;
inline void work()
{
    gyq.clear();d.clear();
    n=rin();for(int i=1;i<=n;i++)a[i]=rin(),l[i]=i-1,r[i]=i+1;
    l[1]=n;r[n]=1;for(int i=1;i<=n;i++)if(Gcd(a[i],a[r[i]])==1)gyq.insert(i);
    if(n==1){puts(a[n]!=1?"0":"1 1");return;}
    int now=1;
    for(int L,R;!gyq.empty();)
    {
        set<int>::iterator i=gyq.upper_bound(now-1);
        if(i==gyq.end())i=gyq.begin();
        d.push_back(R=r[*i]);gyq.erase(R);
        if(l[*i]==R){if(a[*i]==1)d.push_back(*i);break;}
        //delete
        r[l[R]]=r[R];l[r[R]]=l[R];now=r[*i];
        gyq.erase(i);
        if(Gcd(a[now],a[l[now]])==1)gyq.insert(l[now]);
    }
    printf("%d ",d.size());for(vector<int>::iterator i=d.begin();i!=d.end();i++)printf("%d ",*i);
    printf("\n");
    return;
}
int main()
{
    for(int T=rin();T;T--)work();
    return 0;
}

//vjudge 