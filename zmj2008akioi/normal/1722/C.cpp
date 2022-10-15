#include <cstdio>
const int N=1e3+10,M=1e6+10;
const int t[5]={0,3,1,0};
int T,n,bkt[M],a[3][N];char s[10];
int idx(char c){return c-'a';}
int hash(char *s){return idx(s[0])+50*idx(s[1])+2500*idx(s[2]);}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<3;++i){
			for(int j=1;j<=n;++j){
				scanf("%s",s);
				++bkt[a[i][j]=hash(s)];
			}
		}
		for(int i=0;i<3;++i){
			int ans=0;
			for(int j=1;j<=n;++j)ans+=t[bkt[a[i][j]]];
			printf("%d ",ans);
		}
		for(int i=0;i<3;++i)for(int j=1;j<=n;++j)bkt[a[i][j]]=0;
		putchar('\n');
	}
	return 0;
}