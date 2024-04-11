#include <cstdio>
#include <cstring>
const int N=510;
int T,n,k,r,c,map[N][N];
int main(){
	scanf("%d",&T);
	while(T--){
		memset(map,0,sizeof(map));
		scanf("%d %d %d %d",&n,&k,&r,&c);
		r=(r-1)%k,c=(c-1)%k,map[r][c]=map[c][r]=1;
		for(int i=0;i<k;++i)if(i!=r&&i!=c)map[i][i]=1;
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j)putchar(map[i%k][j%k]?'X':'.');
			putchar('\n');
		}
	}
	return 0;
}