#include <cstdio>
#include <cctype>
#include <algorithm>
#define re register
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int MAXN=1e5+1;
struct num{
	int val,id;
	bool operator <(const num &q) const {
		return val>q.val;
	}
}a[MAXN];
int n,x,y,b[MAXN],c[MAXN];
int main(){
	n=read();
	for(re int i=1;i<=n;i++)a[i].val=read(),a[i].id=i;
	sort(a+1,a+n+1);
	for(re int i=1;i<=n;i+=2)
		b[++x]=a[i].id;
	for(re int i=2;i<=n;i+=2)
		c[++y]=a[i].id;
	printf("%d\n",x);
	for(re int i=1;i<=x;i++)printf("%d ",b[i]);
	printf("\n%d\n",y);
	for(re int i=1;i<=y;i++)printf("%d ",c[i]);
	return 0;
}