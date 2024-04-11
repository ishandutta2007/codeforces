#include <cstdio>
const int N=1e6+10;
int T,n,m;
char a[N],b[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m);
		scanf("%s %s",a+1,b+1);
		bool tag=false;
		for(int i=1;i<=n-m+1;++i)tag|=a[i]==b[1];
		for(int i=2;i<=m;++i)tag&=a[n-m+i]==b[i];
		puts(tag?"Yes":"No");
	}
	return 0;
}