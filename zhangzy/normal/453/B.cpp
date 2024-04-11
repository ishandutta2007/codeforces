#include<bits/stdc++.h>
using namespace std;
int p[16]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
int inf,f[111][1<<16],n,a[111],num[66];
int pre[111][1<<16],val[111][1<<16];

int abss(int x){
	return x<0?-x:x;
}

void dfs(int x,int y){
	if (x<=0) return;
	dfs(x-1,pre[x][y]);
	printf("%d ",val[x][y]);
}

int main(){
	int now,x,y;
	memset(num,0,sizeof num);
	for (int i=2;i<=60;i++){
		for (int j=0;j<16;j++){
			if (i%p[j]==0){
				num[i]|=(1<<j);
			}
		}
	}
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	
	memset(f,38,sizeof f);
	inf=f[0][0];
	f[0][0]=0;
	for (int i=0;i<n;i++){
		for (int j=0;j<(1<<16);j++){
			if ((now=f[i][j])<inf){
				for (int k=1;k<59;k++){
					if ((j&num[k])>0) continue;
					x=now+abss(k-a[i+1]);
					if (x<f[i+1][j|num[k]]){
						f[i+1][j|num[k]]=x;
						val[i+1][j|num[k]]=k;
						pre[i+1][j|num[k]]=j;
					}
				}
			}
		}
	}
	int mn=23333333;
	for (int i=0;i<(1<<16);i++) mn=min(mn,f[n][i]);
	for (int i=0;i<(1<<16);i++){
		if (mn==f[n][i]){
			dfs(n,i);
			return 0;
		}
	} 
}