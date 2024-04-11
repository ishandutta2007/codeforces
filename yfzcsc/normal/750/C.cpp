#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define lim 1900
#define inf (1<<30)
using namespace std;
int main(){
	int l=-inf,r=inf,n,sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int c,d;scanf("%d%d",&c,&d);
		if(d==1){
			l=max(l,lim-sum);
		} else r=min(r,lim-sum-1);
		sum+=c;
	}
	if(l>r)printf("Impossible");
	else if(r==(inf))printf("Infinity");
	else printf("%d",r+sum);
}