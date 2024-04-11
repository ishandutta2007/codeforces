#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 100005
#define ll long long
using namespace std;
int n,m,x,y,k1,k2,k3;
struct data{int x,y;ll v;}f[N*3];
int a[N],b[N],c[N];
ll sum[N],ans;
bool cmp(int x,int y){
	return x>y; 
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		if (x==1) a[++k1]=y;
		if (x==2) b[++k2]=y;
		if (x==3) c[++k3]=y; 
	}
	sort(a+1,a+k1+1,cmp);
	sort(b+1,b+k2+1,cmp);
	sort(c+1,c+k3+1,cmp);
	for (int i=1;i<=m;i++){
		f[i]=f[i-1];
		if (f[i].x!=k1){
			f[i].x++;
			f[i].v+=a[f[i].x];
		}
		if (i>1&&f[i-2].y!=k2&&f[i-2].v+b[f[i-2].y+1]>f[i].v){
			f[i]=f[i-2];
			f[i].y++;
			f[i].v+=b[f[i].y];
		}
	}
	for (int i=1;i<=k3;i++)
		sum[i]=sum[i-1]+c[i];
	for (int i=0;i<=k3&&3*i<=m;i++)
		ans=max(ans,sum[i]+f[m-3*i].v);
	printf("%lld",ans);
}