#include<bits/stdc++.h>
#define mo 1000000007
using namespace std;
int f[2][(1<<16)+1][2];
int n,m,ans,d;
char s[257][257];
void upd(int &x,int y){
	(x+=y)>=mo?x-=mo:233;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) scanf("%s",s[i]);
	if (n<m){
		for (int i=0;i<n;i++)
			for (int j=i;j<m;j++)
				swap(s[i][j],s[j][i]);
		swap(n,m);
	}
	f[0][0][0]=1;
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			d^=1;
			memset(f[d],0,sizeof(f[d]));
			for (int S=0;S<1<<(m+1);S++){
				int x=j,y=j+1,p=(S>>x)&1,q=(S>>y)&1;
				int T=S^(p<<x)^(q<<y),v0=f[d^1][S][0],v1=f[d^1][S][1];
				if (!v0&&!v1) continue;
				if (s[i][j]=='x'){
					upd(f[d][T][0],v0);
					upd(f[d][T][1],v1);
					continue;
				}
				upd(f[d][T|(1<<x)|(1<<y)][0],v0);
				upd(f[d][T|(1<<x)|(1<<y)][1],v1);
				if (p||q){
					upd(f[d][T|(q<<x)|(p<<y)][0],v0);
					upd(f[d][T|(q<<x)|(p<<y)][1],v1);
				}
				else upd(f[d][T][1],v0);
			}
		}
		d^=1;
		memset(f[d],0,sizeof(f[d]));
		for (int S=0;S<1<<(m+1);S++){
			upd(f[d][(S<<1)&((1<<(m+1))-1)][0],f[d^1][S][0]);
			upd(f[d][(S<<1)&((1<<(m+1))-1)][1],f[d^1][S][1]);
		}
	}
	for (int S=0;S<1<<(m+1);S++)
		upd(ans,f[d][S][0]),upd(ans,f[d][S][1]); 
	printf("%d",ans);
}