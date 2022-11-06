#include<stdio.h>
#include<vector>
#include<queue>
std::vector<std::vector<bool> >a;
std::vector<std::vector<int> >c,d;
inline int Min(int a,int b){return a<b?a:b;}
int n,m,ans=1e9;
std::queue<std::pair<int,int> >Q;
int main(){
	scanf("%d%d",&n,&m);
	a.resize(n+2);c.resize(n+2);d.resize(n+2);
	for(int i=0;i<=n+1;i++)a[i].resize(m+2),c[i].resize(m+2),d[i].resize(m+2);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char c=0;
			while(c<'!')c=getchar();
			a[i][j]=c=='X';
		}
	}for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j])c[i][j]=j==1?1:c[i][j-1]+1;
			else c[i][j]=0;
		}for(int j=m;j>=1;j--){
			if(a[i][j])d[i][j]=j==m?1:d[i][j+1]+1;
			else d[i][j]=0;
			if(a[i][j])ans=Min(ans,c[i][j]+d[i][j]-1);
		}
	}for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			if(a[i][j])c[i][j]=i==1?1:c[i-1][j]+1;
			else c[i][j]=0;
		}for(int i=n;i>=1;i--){
			if(a[i][j])d[i][j]=i==n?1:d[i+1][j]+1;
			else d[i][j]=0;
			if(a[i][j])ans=Min(ans,c[i][j]+d[i][j]-1);
		}
	}ans=ans-1>>1;printf("%d\n",ans);
	for(int i=0;i<=n+1;i++){
		for(int j=0;j<=m+1;j++){
			if(a[i][j])c[i][j]=1e9;
			else c[i][j]=0,Q.push(std::make_pair(i,j));
		}
	}while(!Q.empty()){
		int x=Q.front().first,y=Q.front().second;Q.pop();
		if(x>=1&&c[x-1][y]>c[x][y]+1)c[x-1][y]=c[x][y]+1,Q.push(std::make_pair(x-1,y));
		if(x<=n&&c[x+1][y]>c[x][y]+1)c[x+1][y]=c[x][y]+1,Q.push(std::make_pair(x+1,y));
		if(y>=1&&c[x][y-1]>c[x][y]+1)c[x][y-1]=c[x][y]+1,Q.push(std::make_pair(x,y-1));
		if(y<=m&&c[x][y+1]>c[x][y]+1)c[x][y+1]=c[x][y]+1,Q.push(std::make_pair(x,y+1));
		if(x>=1&&y>=1&&c[x-1][y-1]>c[x][y]+1)c[x-1][y-1]=c[x][y]+1,Q.push(std::make_pair(x-1,y-1));
		if(x>=1&&y<=m&&c[x-1][y+1]>c[x][y]+1)c[x-1][y+1]=c[x][y]+1,Q.push(std::make_pair(x-1,y+1));
		if(x<=n&&y>=1&&c[x+1][y-1]>c[x][y]+1)c[x+1][y-1]=c[x][y]+1,Q.push(std::make_pair(x+1,y-1));
		if(x<=n&&y<=m&&c[x+1][y+1]>c[x][y]+1)c[x+1][y+1]=c[x][y]+1,Q.push(std::make_pair(x+1,y+1));
	}for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			putchar(c[i][j]>ans?'X':'.');
		}putchar('\n');
	}
}