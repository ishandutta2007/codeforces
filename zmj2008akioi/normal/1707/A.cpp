#include <cstdio>
const int N=1e6+10;
int T,n,q,a[N];
bool ans[N];
inline int md(int x,int y){return (x+y)>>1;}
void proc(int x){
	for(int i=1;i<x;++i)ans[i]=a[i]<=q;
	for(int i=x;i<=n;++i)ans[i]=true;
}
bool check(){
	int nq=q;
	for(int i=1;i<=n;++i){
		if(nq<=0&&ans[i])return false;
		if(ans[i]&&nq<a[i])--nq;
	}
	return true;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&q);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		int l=0,r=n,mid;
		while(l!=r){
			mid=md(l,r),proc(mid);
			if(check())r=mid;
			else l=mid+1;
		}
		proc(l);
		for(int i=1;i<=n;++i)putchar(ans[i]?'1':'0');
		putchar('\n');
	}
	return 0;
}