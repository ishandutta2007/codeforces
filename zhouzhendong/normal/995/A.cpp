#include <bits/stdc++.h>
using namespace std;
const int N=55,M=20005;
int n,k,a[5][N];
int tot=0,id[M],xx[M],yy[M];
void Move(int nowx,int nowy,int x,int y){
	if (a[nowx][nowy]==0)
		return;
	tot++;
	id[tot]=a[nowx][nowy];
	xx[tot]=x,yy[tot]=y;
	swap(a[nowx][nowy],a[x][y]);
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=4;i++)
		for (int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	int cnt=0;
	while (tot<=20000&&cnt<k){
		for (int i=1;i<=n;i++){
			if (a[1][i]!=0&&a[1][i]==a[2][i]){
				Move(2,i,1,i);
				cnt++;
				a[2][i]=0;
			}
			if (a[3][i]!=0&&a[3][i]==a[4][i]){
				Move(3,i,4,i);
				cnt++;
				a[3][i]=0;
			}
		}
		int px=0,py=0;
		for (int i=1;i<=n;i++){
			if (a[2][i]==0)
				px=2,py=i;
			if (a[3][i]==0)
				px=3,py=i;
		}
		if (!px||!py){
			tot=20001;
			break;
		}
		if (n==1){
			if (a[2][1])
				Move(2,1,3,1);
			else
				Move(3,1,2,1);
			continue;
		}
		if (px==2){
			for (int i=py-1;i>=1;i--)
				Move(2,i,2,i+1);
			Move(3,1,2,1);
			for (int i=2;i<=n;i++)
				Move(3,i,3,i-1);
			Move(2,n,3,n);
			for (int i=n-1;i>py;i--)
				Move(2,i,2,i+1);
		}
		else {
			for (int i=py;i<n;i++)
				Move(3,i+1,3,i);
			Move(2,n,3,n);
			for (int i=n;i>1;i--)
				Move(2,i-1,2,i);
			Move(3,1,2,1);
			for (int i=2;i<py;i++)
				Move(3,i,3,i-1);
		}
	}
	if (tot>20000)
		puts("-1");
	else {
		printf("%d\n",tot);
		for (int i=1;i<=tot;i++)
			printf("%d %d %d\n",id[i],xx[i],yy[i]);
	}
	return 0;
}