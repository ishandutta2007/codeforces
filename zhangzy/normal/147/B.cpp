#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct MP{
	ll g[310][310];
}f[10],nil,tmp,c;
int n,m,x,y,z1,z2,ans;

void U(ll &x,ll y){
	x=max(x,y);
}

MP CC(MP &f1,MP &f2){
	MP res=nil;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			for (int k=1;k<=n;k++)
				U(res.g[i][j],f1.g[i][k]+f2.g[k][j]);
			U(res.g[i][j],min(f1.g[i][j],f2.g[i][j]));
		}
	return res;
}

bool pd(MP &t){
	for (int i=1;i<=n;i++)
		if (t.g[i][i]>0)
			return 1;
	return 0;
}

int main(){
	scanf("%d%d",&n,&m);
	memset(nil.g,-38,sizeof nil.g);
	for (int i=0;i<10;i++) f[i]=nil;
	for (;m--;){
		scanf("%d%d%d%d",&x,&y,&z1,&z2);
		f[0].g[x][y]=z1;
		f[0].g[y][x]=z2;
	}
	for (int i=1;i<10;i++){
		f[i]=CC(f[i-1],f[i-1]);
		if (pd(f[i])){
			ans=1<<i>>1;
			tmp=f[i-1];
			for (int j=i-2;j>=0;j--){
				c=CC(tmp,f[j]);
				if (!pd(c)){
					tmp=c;
					ans+=1<<j;
				}
			}
			return 0*printf("%d",ans+1);
		}
	}
	printf("0");
}