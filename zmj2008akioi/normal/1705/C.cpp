#include <cstdio>
const int N=2e5+10;
int T,n,c,q;
long long l[N],r[N],len[N];
char s[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d",&n,&c,&q);
		scanf("%s",s+1),len[0]=n;
		for(int i=1;i<=c;++i){
			scanf("%lld %lld",&l[i],&r[i]);
			len[i]=len[i-1]+r[i]-l[i]+1;
		}
		for(int i=1;i<=q;++i){
			long long k;scanf("%lld",&k);
			for(int j=c;j;--j)if(k>len[j-1])k=l[j]+(k-len[j-1])-1;
			putchar(s[k]),putchar('\n');
		}
	}
	return 0;
}