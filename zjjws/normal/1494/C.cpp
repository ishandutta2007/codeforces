#include <set>
#include <queue>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define LL long long
using namespace std;
inline int rin()
{
    int s=0;
    bool bj=false;
    char c=getchar();
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')bj=true,c=getchar();
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)return -s;
    return s;
}
inline void jh(int &x,int &y){if(x^y)x^=y^=x^=y;return;}
inline void jh(LL &x,LL &y){if(x^y)x^=y^=x^=y;return;}
const int N=3e5+3;

int n,m;
int a[N];
int b[N];

vector<int>A;
vector<int>B;
vector<int>C;
inline int cs()
{
    int s_1=0,cut=0;
    C.resize(B.size());
    for(vector<int>::iterator i=B.begin(),j;i!=B.end();i++)
    {
        if(cut)C[cut]=C[cut-1];else C[cut]=0;
        j=lower_bound(A.begin(),A.end(),*i);
        if(j!=A.end()&&(*j)==(*i))C[cut]++;
        cut++;
    }
    cut=0;
    for(vector<int>::iterator i=B.begin();i!=B.end();i++)
    {
        int sl=(upper_bound(A.begin(),A.end(),*i)-A.begin()),sr;
        if(!sl){cut++;continue;}
        int sk=(*i)-sl+1;sr=(lower_bound(B.begin(),B.end(),sk)-B.begin()-1);
        s_1=max(s_1,cut-C[cut]-sr+C.back());
        cut++;
    }
    return s_1;
}
inline void work()
{
    A.clear();B.clear();C.clear();
    n=rin();m=rin();for(int i=1;i<=n;i++)a[i]=rin();for(int i=1;i<=m;i++)b[i]=rin();
    int s_1=0,ans=0;
    for(int i=n;i>=1;i--)if(a[i]<0)A.push_back(-a[i]);for(int i=m;i>=1;i--)if(b[i]<0)B.push_back(-b[i]);
    ans+=cs();

    A.clear();B.clear();C.clear();
    for(int i=1;i<=n;i++)if(a[i]>0)A.push_back(a[i]);for(int i=1;i<=m;i++)if(b[i]>0)B.push_back(b[i]);
    ans+=cs();
    printf("%d\n",ans);
    return;
}
//
int main()
{
    for(int T=rin();T;T--)work();
    return 0;
}