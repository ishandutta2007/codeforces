#include<bits/stdc++.h>
using namespace std;

int n,m,ans=0,a[33][33],b[33][33];
int dx[]={ 2, 2, 1, 1};
int dy[]={ 1,-1, 2,-2};

void dfs(int x,int y,int tot){
	if (x>n){
		ans=max(ans,tot);
		return;
	}
	if (y>m) {
		dfs(x+1,1,tot);
		return;
	}
	dfs(x,y+1,tot);
	if (a[x][y]) return;
	for (int i=0;i<4;i++){
		if (min(x+dx[i],y+dy[i])>0)
			a[x+dx[i]][y+dy[i]]++;
	}
	b[x][y]=1;
	dfs(x,y+1,tot+1);
	for (int i=0;i<4;i++){
		if (min(x+dx[i],y+dy[i])>0)
			a[x+dx[i]][y+dy[i]]--;
	}
	b[x][y]=0;
}

int realmain(int x,int y){
	ans=0; memset(a,0,sizeof a);
	n=x; m=y;
	dfs(1,1,0);
	return ans;
}

int main(){
	int x,y;
	scanf("%d%d",&x,&y);
	if (x>y) swap(x,y);
	if (x==1) return 0*printf("%d\n",x*y);
	if (x==2) return 0*printf("%d\n",y/4*4+min(y%4,2)*2);
	if (x*y<20) return 0*printf("%d\n",realmain(x,y));
	printf("%d\n",(x*y+1)/2);
}