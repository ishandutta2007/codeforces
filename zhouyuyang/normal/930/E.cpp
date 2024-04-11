#include<bits/stdc++.h>
#define pa pair<int,int>
#define mo 1000000007
#define inv 500000004 
#define N 100005
#define fi first
#define se second
using namespace std;
int n,cnt[2],tp[2];
int pre[2][2][N];
int sum[2][2][N];
pa a[2][N];
void upd(int &x,int y){
	(x+=y)>=mo?x-=mo:233;
}
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int main(){
	scanf("%d%d%d",&n,&cnt[0],&cnt[1]);
	for (int i=0;i<2;i++){
		for (int j=0;j<cnt[i];j++){
			int r;
			scanf("%d%d",&a[i][j].fi,&r);
			a[i][j].se=-r-1;
		}
		int sz=0;
		sort(a[i],a[i]+cnt[i]);
		for (int j=0;j<cnt[i];j++){
			for (;sz&&-a[i][j].se<=a[i][sz-1].se;sz--);
			a[i][sz]=a[i][j]; a[i][sz++].se*=-1;
		}
		cnt[i]=sz;
	}
	for (int i=0;i<2;i++)
		for (int j=0;j<2;j++){
			int p=-1;
			for (int k=0;k<cnt[i];k++){
				for (;p+1<cnt[j]&&a[j][p+1].se<=a[i][k].fi;p++);
				pre[i][j][k]=p+1;
			}
		}
	sum[0][0][0]=1;
	for (;tp[0]<cnt[0]||tp[1]<cnt[1];){
		int k=(tp[0]==cnt[0]||(tp[1]<cnt[1]&&a[0][tp[0]].se>a[1][tp[1]].se));
		int& i=tp[k];
		int dp=1ll*(mo-power(inv,a[k][i].se-a[k][i].fi))*(sum[0][k^1][pre[k][k^1][i]]+sum[0][k][pre[k][k][i]])%mo;// 
		upd(dp,1ll*(mo-power(inv,a[k][i].se))*(sum[1][k][i]+mo-sum[1][k][pre[k][k][i]])%mo);// 
		sum[0][k][i+1]=sum[0][k][i]; upd(sum[0][k][i+1],dp);
		sum[1][k][i+1]=sum[1][k][i]; upd(sum[1][k][i+1],1ll*dp*power(2,a[k][i].se)%mo);
		i++;
	}
	int ans=sum[0][0][cnt[0]];
	upd(ans,sum[0][1][cnt[1]]);
	printf("%d",1ll*power(2,n)*ans%mo);
}
/*
pre[i][j][k]:jik
sum[i][j][k]:j,dpjki:(?1:0); 
*/