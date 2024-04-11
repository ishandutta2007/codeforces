#include <cstdio>
int t,n,m,r,c,nw,ans;
char s[100];
inline int min(int x,int y){return x<y?x:y;}
int main(){
	scanf("%d",&t);
	do{
		scanf("%d %d %d %d",&n,&m,&r,&c);
		ans=1e9;
		for(register int i=1;i<=n;++i){
			scanf("%s",s+1);
			for(register int j=1;j<=m;++j){
				if(s[j]=='B'){
					nw=2;
					if(i==r)--nw;
					if(j==c)--nw;
					ans=min(ans,nw);
				}
			}
		}
		if(ans==1e9)puts("-1");
		else printf("%d\n",ans);
	}while(--t);
	return 0;
}