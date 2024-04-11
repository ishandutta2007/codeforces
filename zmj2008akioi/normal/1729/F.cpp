//w is constant...
#include <cstdio>
#include <cstring>
const int inf=1e9,M=20,N=2e5+10;
int T,n,m,w,a[N],ps[N],tag[N],gtag[N],f[M][M];
char s[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s %d %d",s+1,&w,&m),memset(tag,0,sizeof(tag)),memset(gtag,0,sizeof(gtag));
		n=strlen(s+1);for(int i=1;i<=n;++i)ps[i]=(ps[i-1]+(s[i]^48))%9;
		for(int i=1;i+w-1<=n;++i){
			int nv=(ps[i+w-1]-ps[i-1]+9)%9;
			if(!tag[nv])tag[nv]=i;
			else if(!gtag[nv])gtag[nv]=i;
		}
		for(int l,r,k,i=1;i<=m;++i){
			scanf("%d %d %d",&l,&r,&k);
			int nv=(ps[r]-ps[l-1]+9)%9,l1=inf,l2=inf;
			for(int i=0;i<9;++i){
				if(!tag[i])continue;
				int rm=(k-nv*i+90)%9,nl1,nl2;
				nl1=tag[i],nl2=tag[rm];if(!nl2)continue;
				if(nl1==nl2)nl2=gtag[rm];if(!nl2)continue;
				if(nl1<l1||(nl1==l1&&nl2<l2))l1=nl1,l2=nl2;
			}
			if(l1==inf&&l2==inf)puts("-1 -1");
			else printf("%d %d\n",l1,l2);
		}
	}
	return 0;
}