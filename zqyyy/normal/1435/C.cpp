#include <cstdio>
#include <cctype>
#include <algorithm>
#define re register
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=1e5+1;
struct Pair{
	int val,d;
	bool operator <(const Pair &q) const {
		return val<q.val;
	}
}c[N*6];
int n,m,a[7],vis[N];
int main(){
	for(re int i=1;i<=6;i++)a[i]=read();
	n=read();
	for(re int i=1;i<=n;i++){
		int b=read();
		for(re int j=1;j<=6;j++)
			c[++m].val=b-a[j],c[m].d=i;
	}
	sort(c+1,c+m+1);
	int l=0,r=0,num=0,ans=1e9;
	while(l<m && r<=m){
		vis[c[l].d]--;
		if(!vis[c[l].d])num--;
		++l;
		while(r<=m && num<n){
			r++;if(r>m)break;
			if(!vis[c[r].d])num++;
			vis[c[r].d]++;
		}
		if(r<=m)ans=min(ans,c[r].val-c[l].val);
	}
	printf("%d\n",ans);
	return 0;
}