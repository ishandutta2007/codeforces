#include <cstdio>
const int N=510;
int T,n,m,map[N][N];
char s[N][N];
void cmin(int &x,int y){if(x>y)x=y;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m);
		int cnt=0,w=3;
		for(int i=1;i<=n;++i){
			scanf("%s",s[i]+1);
			for(int j=1;j<=m;++j)cnt+=(map[i][j]=(s[i][j]^48));
		}
		if(!cnt){puts("0");continue;}
		for(int i=1;i<n;++i){
			for(int j=1;j<m;++j){
				int c=map[i][j]+map[i+1][j]+map[i][j+1]+map[i+1][j+1];
				for(int a=0;a<2;++a)for(int b=0;b<2;++b)if(c-map[i+a][j+b])cmin(w,c-map[i+a][j+b]);
			}
		}
		printf("%d\n",cnt-w+1);
	}
	return 0;
}