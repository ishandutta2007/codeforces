#include <cstdio>
const int G=26,N=100;
int T,ans;char a[N],b[N];bool bkt[N];
int idx(char c){return c-'a';}
void clr(){ans=0;for(int i=0;i<G;++i)bkt[i]=0;}
void ins(char c){
	int w=idx(c);
	ans+=!bkt[w],bkt[w]=true;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s %s",a,b),clr();
		ins(a[0]),ins(a[1]),ins(b[0]),ins(b[1]);
		printf("%d\n",ans-1);
	}
	return 0;
}