#include <cstdio>
const int N=1e6+10;
int T,n,a[N];
int main(){
	scanf("%d",&T);
	while(T--){
		int n=3,cnt=0,x=0;scanf("%d",&x);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		while(x)++cnt,x=a[x];
		puts(cnt==3?"YES":"NO");
	}
	return 0;
}