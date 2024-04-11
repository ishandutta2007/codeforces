#include<iostream>
#include<string>
using namespace std;

const int muki[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

char a[102][102];
char b[102][102];

void bfs(int x,int y){
	a[x][y]='-';
	if((x+y)%2==0)b[x][y]='B';
	else b[x][y]='W';

	for(int i=0;i<4;i++){
		int nx=x+muki[i][0]; int ny=y+muki[i][1];
		if(a[nx][ny]=='.'){
			bfs(nx,ny);
		}
	}
}

int main(){
	int n,m;

	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("\n");
		for(int j=1;j<=m;j++){
			scanf("%c",&a[i][j]);
			b[i][j]='-';
		}
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='.'){
				bfs(i,j);
			}
		}
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%c",b[i][j]);
		}
		printf("\n");
	}
}