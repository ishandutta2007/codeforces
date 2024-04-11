#include <bits/stdc++.h>
using namespace std;

const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};

int n,m,k;
char a[1005][1005];
int b[1005][1005];
int c[1000010];

void dfs(int x,int y,int t){
	if(a[x][y]=='*'||b[x][y]!=0)return;
	b[x][y]=t;
	for(int s=0;s<4;s++){
		dfs(x+dx[s],y+dy[s],t);
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=n+1;i++){
		for(int j=0;j<=m+1;j++){
			a[i][j]='*';
		}
	}
	for(int i=1;i<=n;i++){
		scanf("\n");
		for(int j=1;j<=m;j++){
			scanf("%c",&a[i][j]);
		}
	}
	int x=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='.'&&b[i][j]==0)dfs(i,j,x++);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='.')continue;
			for(int t=0;t<4;t++){
				c[b[i+dx[t]][j+dy[t]]]++;
			}
			/*vector<int> vec;
			for(int t=0;t<4;t++){
				vec.push_back(b[i+dx[t]][j+dy[t]]);
			}
			sort(vec.begin(),vec.end());
			vec.erase(unique(vec.begin(),vec.end()),vec.end());
			for(int t: vec){
				c[t]++;
			}*/
		}
	}
	for(;k>0;k--){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",c[b[x][y]]);
	}
}