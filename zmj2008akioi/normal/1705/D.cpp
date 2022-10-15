#include <cstdio>
const int N=2e5+10;
int q,n,a[N],b[N];
char s[N],t[N];
inline int abs(int x){return x>0?x:(-x);}
int main(){
	scanf("%d",&q);
	for(int i=1;i<=q;++i){
		scanf("%d",&n);
		scanf("%s",s+1),scanf("%s",t+1);
		int suma=0,sumb=0;long long ans=0;
		for(int i=1;i<n;++i){
			a[i]=s[i]^s[i+1],b[i]=t[i]^t[i+1];
			suma+=a[i],sumb+=b[i],ans+=abs(suma-sumb);
		}
		if(suma!=sumb||s[1]!=t[1])puts("-1");
		else printf("%lld\n",ans);
	}
	return 0;
}