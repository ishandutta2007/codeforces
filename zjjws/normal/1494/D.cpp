#include <queue>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
#include <algorithm>
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
    if(bj)return -s;
    return s;
}
inline void jh(int &x,int &y){if(x^y)x^=y^=x^=y;return;}
inline void jh(LL &x,LL &y){if(x^y)x^=y^=x^=y;return;}
const int N=1e3+3;

int n,m;
int a[N][N];
int nxt[N];
int c[N<<1];
vector<int>B;

inline int cs(vector<int>B)
{
    vector<int>C;C.clear();C.resize(B.size());
    if(B.empty())return 0;
    if(B.size()==1){c[B[0]]=a[B[0]][B[0]];return B[0];}
	int maxl=0,sl=++m;
	
    for(int i=1;i<(int)B.size();i++)maxl=max(maxl,a[B[0]][B[i]]);
	c[sl]=maxl;for(int i=0;i<(int)B.size();i++)
    {
		if(C[i])continue;
        vector<int>D;
		for(int j=i;j<(int)B.size();j++)if(a[B[i]][B[j]]!=maxl)C[j]=true,D.push_back(B[j]);
		nxt[cs(D)]=sl;
	}
	return sl;
}
inline void work()
{
    m=n=rin();for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]=rin();
    for(int i=1;i<=n;i++)B.push_back(i);
    int sk=cs(B);printf("%d\n",m);
    for(int i=1;i<=m;i++)printf("%d ",c[i]);printf("\n");
    printf("%d\n",sk);for(int i=1;i<=m;i++){if(i!=sk)printf("%d %d\n",i,nxt[i]);}
    return;
}
int main()
{
    work();
    return 0;
}