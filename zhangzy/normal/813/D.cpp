#include<bits/stdc++.h>
using namespace std;

int f[5555][5555],mx[7],g[101000];
int n,a[5555],ans=0;

void R(int &x,int y){
	x=max(x,y);
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;scanf("%d",&a[i++]));
	for (int i=0;i<n;i++){
		memset(mx,0,sizeof mx);
		memset(g,0,sizeof g);
		for (int j=1;j<i;j++){
			R(mx[a[j]%7],f[i][j]);
			R(g[a[j]],f[i][j]);
		}
		for (int j=i+1;j<=n;j++){
			R(f[i][j],max(g[a[j]+1],g[a[j]-1])+1);
			R(f[i][j],mx[a[j]%7]+1);
			R(f[i][j],f[i][0]+1);
			R(mx[a[j]%7],f[i][j]);
			R(g[a[j]],f[i][j]);
			R(f[j][i],f[i][j]);
		}
	}
	for (int i=0;i<=n;i++) R(ans,*max_element(f[i],f[i]+n+1));
	cout<<ans;
}