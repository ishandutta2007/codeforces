#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#define LL long long
using namespace std;
const int N=1e5+3;
const int M=1e9+7;
LL k;
int m;
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

string a,b,c;
string S1,S2,S3;
string x;

int last[N];

struct gyq
{
    LL a[4][4];
    inline void mem0(){memset(a,0,sizeof(a));return;}
};
struct zjj
{
    LL a[4];
    inline void mem0(){memset(a,0,sizeof(a));return;}
};
inline gyq operator *(gyq &x,gyq &y)
{
    gyq z;z.mem0();
    for(int i=1;i<=3;i++)for(int j=1;j<=3;j++){for(int k=1;k<=3;k++)z.a[i][j]+=x.a[i][k]*y.a[k][j]%M;z.a[i][j]%=M;}
    return z;
}
inline zjj operator *(zjj &x,gyq &y)
{
    zjj z;z.mem0();
    for(int i=1;i<=3;i++){for(int j=1;j<=3;j++)z.a[i]+=x.a[j]*y.a[j][i]%M;z.a[i]%=M;}
    return z;
}
inline void work()
{
    S1="a";S2="b";
    x.clear();
    cin>>x;x=" "+x;
    int lens=x.length()-1;
    LL step=k-2;
    if(step<0){printf("%d\n",x==" a");return;}
    for(;step&&S1.length()<lens;step--)
    {
        S3=S2;
        S2=S2+S1;
        S1=S3;
    }
    
    int i,j;
    int L;
    int s_b=0,s_c=0;
    for(i=2,j=0;i<=lens;i++)
    {
        for(;j&&x[i]!=x[j+1];j=last[j]);
        if(x[i]==x[j+1])j++;
        last[i]=j;
    }

    if(S2.length()<lens){puts("0");return;}
    if(S1.length()<lens)
    {
        L=S2.length();
        int cutt=0;
        for(i=0,j=0;i<L;i++)
        {
            for(;j&&S2[i]!=x[j+1];j=last[j]);
            if(S2[i]==x[j+1])j++;
            if(j==lens)cutt++;
        }
        printf("%d\n",cutt);
        return;
    }
    a=S2.substr(0,lens);
    b=S2.substr(S2.length()-lens,lens);
    c=S1.substr(S1.length()-lens,lens);
    b=b+a;c=c+a;
    L=(lens<<1)-1;

    // cout<<"S1:"<<S1<<endl;
    // cout<<"S2:"<<S2<<endl;
    for(i=1,j=0;i<L;i++)
    {
        for(;j&&b[i]!=x[j+1];j=last[j]);
        if(b[i]==x[j+1])j++;
        if(j==lens)s_b++;
    }
    for(i=1,j=0;i<L;i++)
    {
        for(;j&&c[i]!=x[j+1];j=last[j]);
        if(c[i]==x[j+1])j++;
        if(j==lens)s_c++;
    }

    // cout<<b<<" s_b:"<<s_b<<endl;
    // cout<<c<<" s_c:"<<s_c<<endl;

    gyq s[2];
    s[0].mem0();
    s[0].a[1][1]=s[0].a[2][1]=s[0].a[1][2]=s[0].a[3][3]=1;
    s[1]=s[0];
    s[0].a[3][1]=s_b;
    s[1].a[3][1]=s_c;

    gyq S=s[0]*s[1];
    // for(int i=1;i<=3;i++){for(int j=1;j<=3;j++)printf("%d ",S.a[i][j]);printf("\n");}
    zjj ans;ans.mem0();
    L=S2.length();
    for(i=0,j=0;i<L;i++)
    {
        for(;j&&S2[i]!=x[j+1];j=last[j]);
        if(S2[i]==x[j+1])j++;
        if(j==lens)ans.a[1]++;
    }
    L=S1.length();
    for(i=0,j=0;i<L;i++)
    {
        for(;j&&S1[i]!=x[j+1];j=last[j]);
        if(S1[i]==x[j+1])j++;
        if(j==lens)ans.a[2]++;
    }
    ans.a[3]=1;
    // printf("step:%lld\n",step);
    for(LL i=(step>>1);i;i>>=1){if(i&1)ans=ans*S;S=S*S;}
    if(step&1)ans=ans*s[0];
    printf("%lld\n",ans.a[1]);
}
int main()
{
    int i,j;
    k=rin();m=rin();
    for(i=1;i<=m;i++)work();
    return 0;
}