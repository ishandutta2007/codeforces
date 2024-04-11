#include<iostream>
using namespace std;

int n,m;
int muki[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
char a[502][502];

int dfs(int x,int y,int k){
	if(k<=0)return 0;
	a[x][y]='X';
	k--;
	for(int i=0;i<4;i++)if(a[x+muki[i][0]][y+muki[i][1]]=='.')k=dfs(x+muki[i][0],y+muki[i][1],k);
	return k;
}

int main(){
	int x,y,k,s=0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("\n");
		for(int j=1;j<=m;j++){
			scanf("%c",&a[i][j]);
			if(a[i][j]=='.'){x=i; y=j; s++;}
		}
	}
	x=dfs(x,y,s-k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='X')printf(".");
			else if(a[i][j]=='.')printf("X");
			else printf("#");
		}
		printf("\n");
	}
}