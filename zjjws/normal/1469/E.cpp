#include <stdio.h>
#include <string>
#include <iostream>
#define LL long long
using namespace std;
const int N=2e6+3;
inline int rin()
{
    int s=0;
    bool bj=false;
    char c=getchar();
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')bj=true,c=getchar();
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)s=-s;
    return s;
}
inline int max(int x,int y){return x>y?x:y;}

string a;
string ans;

int d[N];
int tail;

bool vit[N];

inline void work()
{
    int n=rin(),k=rin();
    cin>>a;a=" "+a;
    int ed=max(n-k+1,1);
    int s=0;
    int p=0;
    int cutt=0;
    int lens=min(k,20);
    p=(1<<lens)-1;
    tail=0;
    for(int i=k-lens+1;i<k;i++)s=(s<<1)+('1'-a[i]);
    for(int i=k-lens,j=1;j<i;j++)if(a[j]=='0')cutt++;
    for(int i=1;i<=ed;i++)
    {
        s=(s<<1)+('1'-a[i+k-1]);
        s=s&p;
        if(a[i+k-1-lens]=='0')cutt++;
        if(a[i-1]=='0')cutt--;
        if(!cutt)vit[s]=true,d[++tail]=s;
    }
    for(int i=0;i<=ed;i++)
    {
        if(!vit[i])
        {
            ans="";
            for(;i;i>>=1)ans=(char)((i&1)+'0')+ans;
            if(ans.size()>k)puts("NO");
            else 
            {
                puts("YES");
                for(i=ans.size()+1;i<=k;i++)putchar(48);
                cout<<ans;
                putchar('\n');
            }
            break;
        }
    }
    for(;tail;tail--)vit[d[tail]]=false;
}
int main()
{
    // freopen("my.out","w",stdout);
    int i,j;
    for(int T=rin();T;T--)work();
    return 0;
}