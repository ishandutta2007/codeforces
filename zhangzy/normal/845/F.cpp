#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int n,m,f[2][(1<<16)][2][2],a[255][16],now,fr,ans=0;
char s[255][255];

void R(int &x,int y){
	x=(x+y)%mod;
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) scanf("%s",s[i]);
	if (n<m){
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				a[j][i]= s[i][j]=='.'? 0: 1;
			}
		}
		swap(n,m);
	}else{
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				a[i][j]= s[i][j]=='.'? 0: 1;
			}
		}
	}
	
	memset(f,0,sizeof f);
	f[0][0][0][0]=1;
	now=1;fr=0;
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			memset(f[now],0,sizeof f[now]);
			for (int b=0;b<(1<<m);b++){
				for (int c=0;c<2;c++){
					for (int d=0;d<2;d++){
						if (a[i][j]){
							R(f[now][(b|(1<<j))^(1<<j)][0][d],f[fr][b][c][d]);
						}else{
							if (c&&j){
								R(f[now][b][1][d],f[fr][b][c][d]);
								R(f[now][b|(1<<j)][1][d],f[fr][b][c][d]);
							}else{
				 				if (!d||(b&(1<<j))) R(f[now][b][0][d|(!(b&(1<<j)))],f[fr][b][c][d]);
								R(f[now][b|(1<<j)][1][d],f[fr][b][c][d]);
							}
						}
					}
				}
			}
			swap(fr,now);
		}
	}
	
	for (int b=0;b<(1<<m);b++){
		for (int c=0;c<2;c++){
			for (int d=0;d<2;d++){
				R(ans,f[fr][b][c][d]);
			}
		}
	}
	cout<<ans;
}