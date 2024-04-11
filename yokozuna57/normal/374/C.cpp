#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
char a[1002][1002];
char dima[4]={'D','I','M','A'};
int muki[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool b[1002][1002];
bool c[1002][1002];
int d[1002][1002];

int solve(int x,int y){
	if(d[x][y]!=NULL)return d[x][y];
	if(c[x][y])return 100000000;
	b[x][y]=true;
	c[x][y]=true;
	int ret=1;
	for(int i=0;i<4;i++){
		if(a[x][y]==dima[i]){
			char nex=dima[(i+1)%4];
			for(int j=0;j<4;j++){
				if(a[x+muki[j][0]][y+muki[j][1]]==nex)ret=max(ret,solve(x+muki[j][0],y+muki[j][1])+1);
			}
		}
	}
	c[x][y]=false;
	d[x][y]=ret;
	return ret;
}


int main(){
	int ans=0;
	scanf("%d %d\n",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%c",&a[i][j]);
		}
		if(i!=n)scanf("\n");
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!b[i][j]&&a[i][j]=='D'){
				ans=max(ans,solve(i,j));
			}
		}
	}
	if(ans<4)printf("Poor Dima!\n");
	else if(ans>=100000000)printf("Poor Inna!\n");
	else printf("%d\n",ans/4);
}