#include <cstdio>
#include <cstring>
const int N=60;
int T,n,m,cnt,nx[N],ny[N];
char s[N];
bool map[N][N];
void dfs(int x,int y){
	if(!map[x][y])return;
	++cnt,nx[cnt]=x,ny[cnt]=y,map[x][y]=false;
	dfs(x+1,y),dfs(x,y+1),dfs(x-1,y),dfs(x,y-1);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m);
		memset(map,0,sizeof(map));
		for(int i=1;i<=n;++i){
			scanf("%s",s+1);
			for(int j=1;j<=m;++j)map[i][j]=s[j]=='*';
		}
		bool tag=true;
		for(int i=1;i<n;++i){
			for(int j=1;j<m;++j){
				bool a=map[i][j],b=map[i+1][j],c=map[i][j+1],d=map[i+1][j+1];
				tag&=!(a&&d&&!b&&!c),tag&=!(!a&&!d&&b&&c);
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(!map[i][j])continue;
				cnt=0,dfs(i,j);
				if(cnt!=3){tag=false;break;}
				bool flag=false;
				flag|=ny[2]==ny[1]+1&&nx[2]==nx[1]&&ny[3]==ny[2]&&nx[3]==nx[1]+1;
				flag|=nx[2]==nx[1]+1&&ny[2]==ny[1]&&nx[3]==nx[1]&&ny[3]==ny[1]+1;
				flag|=nx[2]==nx[1]+1&&ny[2]==ny[1]&&nx[3]==nx[2]&&ny[3]==ny[1]+1;
				flag|=nx[2]==nx[1]+1&&ny[2]==ny[1]&&nx[3]==nx[2]&&ny[3]==ny[1]-1;
				tag&=flag;
			}
		}
		puts(tag?"Yes":"No");
	}
	return 0;
}