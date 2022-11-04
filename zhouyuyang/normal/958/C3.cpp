#include<bits/stdc++.h>
using namespace std;

int f[2][105][105];
int a[500005],val[105];
int n,k,mo;
void add(int *t,int x,int v){
	for (x++;x<=mo+1;x+=x&(-x))
		t[x]=min(t[x],v);
}
int ask(int *f,int x){
	int ans=1e9;
	for (x++;x;x-=x&(-x))
		ans=min(ans,f[x]);
	return ans;
}
int main(){
	scanf("%d%d%d",&n,&k,&mo);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]=(a[i]+a[i-1])%mo;
	}
	for (int i=0;i<=k;i++)
		for (int j=0;j<=mo+1;j++)
			f[0][i][j]=f[1][i][j]=1e9;
	add(f[0][0],0,0);
	add(f[1][0],mo,0);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=k;j++)
			val[j]=min(ask(f[0][j-1],mo-1-a[i])+a[i],ask(f[1][j-1],a[i])+a[i]-mo);
		for (int j=1;j<=k;j++){
			int tmp=(a[i]?mo-a[i]:0);
			add(f[0][j],tmp,val[j]+tmp);
			add(f[1][j],mo-tmp,val[j]+tmp);
		}
	}
	printf("%d",val[k]);
}