#include<bits/stdc++.h>
using namespace std;
int a[555][555],s,q,n,m,ans,inf;

int doit(int w,int x,int y){
	int t=0;
	for (int i=x;i<=y;i++){
		t=max(t,a[w][i]);
	}
	return t;
}

int main(){
	scanf("%d%d%d%d",&n,&m,&s,&q);
	memset(a,127,sizeof a);
	ans=inf=a[0][0];
	int x,y,z;
	for (;q--;){
		scanf("%d%d%d",&x,&y,&z);
		a[x][y]=z;
	}
	for (int nnd=1;nnd<s;nnd++){
		for (int i=1;i<n;i++){
			for (int j=1;j<=m;j++){
				a[i][j]=max(a[i][j],a[i+1][j]);
			}
		}
	}
	for (int i=1;i+s-1<=n;i++){
		for (int j=1;j+s-1<=m;j++){
			ans=min(ans,doit(i,j,j+s-1));
		}
	}
	printf("%d\n",ans==inf?-1:ans);
}