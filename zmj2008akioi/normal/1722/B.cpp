#include <cstdio>
const int N=110;
int T,n;
char a[N],b[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %s %s",&n,a,b);bool tag=false;
		for(int i=0;i<n;++i)tag|=(a[i]=='R')^(b[i]=='R');
		puts(tag?"No":"Yes");
	}
	return 0;
}