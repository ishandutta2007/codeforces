#include <cstdio>
const int G=26,N=210;
int T,n,k,ans[N],bkt[N];char s[N];
int idx(char c){return c-'a';}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %s",&n,&k,s+1);
		for(int i=0;i<G;++i)bkt[i]=0;
		for(int i=1;i<=n;++i)++bkt[idx(s[i])];
		for(int t=n/k,i=1;i<=k;++i){
			ans[i]=0;
			while(ans[i]<t&&bkt[ans[i]])--bkt[ans[i]++];
		}
		for(int i=1;i<=k;++i)putchar(ans[i]+'a');putchar('\n');
	}
	return 0;
}