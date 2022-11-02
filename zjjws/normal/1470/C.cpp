#include <cmath>
#include <stdio.h>
#include <iostream>
#define LL long long
using namespace std;
inline LL rin()
{
    LL s=0;
    bool bj=false;
    char c=getchar();
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')bj=true,c=getchar();
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)s=-s;
    return s;
}

int n,k;
inline int check(int x)
{
    if(x<0)x=(x%n+n-1)%n+1;
    if(x>n)x=((x-1)%n)+1;
    return x;
}

inline int work()
{
    int val;
    for(int i=0;true;i++)
    {
        cout<<"? "<<"1"<<endl;
        val=rin();
        if(val!=k){cout<<"! "<<check((val<k)?(1+i):(1-i))<<endl;return 0;}
        if((1+(i<<1))>n){cout<<"! "<<"1"<<endl;return 0;}
    }
    return 0;
}

inline int Gcd(int a,int b){return (!b)?(a):(Gcd(b,a%b));}
int main()
{
    int i,j;
    n=rin();k=rin();
    if(n<=500)return work();
    int lens=sqrt(n);
    int val;
    for(;Gcd(n,lens)!=1;lens++);
    for(i=1,j=1;true;i++){cout<<"? "<<j<<endl;val=rin();if(val!=k)break;j=check(j+lens);}
    int l,r;
    if(val>k)r=j-1,l=j-i;else l=j+1,r=j+i;
    for(;l<=r;)
    {
        int mid=(l+r)>>1;
        cout<<"? "<<check(mid)<<endl;
        val=rin();
        if(val==k){cout<<"! "<<check(mid)<<endl;return 0;}
        if(val<k)l=mid+1;
        else r=mid-1;
    }
    cout<<"! "<<"1"<<endl;
    return 0;
}