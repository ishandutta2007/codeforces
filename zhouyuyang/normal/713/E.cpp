#include<bits/stdc++.h>
#define N 100005
using namespace std;
int f[N][2],a[N],n,m;
bool chk(int x){
	int st0=0,st1=0;
	for (;st0<=x;){
		if (!st0) f[0][0]=-x;
		else f[0][0]=st0;
		f[0][1]=st1;
		for (int i=1;i<=n;i++)
			f[i][0]=1e9,f[i][1]=0;
		for (int i=0;i<n;i++){
			if (f[i][0]>x) return 0;
			int k1;
			if (f[i][0]>0) k1=a[i+1]-a[i]+f[i][0];
			else{
				k1=a[i+1]-a[i]-x;
				if (k1>0) k1--;
			}
			if (k1<0) f[i+1][0]=-x;
			else f[i+1][0]=min(f[i+1][0],k1);
			int k2=a[i+1]-a[i]+f[i][1];
			if (k2>0) k2--;
			if (k2<0) f[i+1][0]=-x;
			else f[i+1][0]=min(f[i+1][0],k2);
			if (k1<=x) f[i+1][1]=min(f[i+1][1],a[i+1]-a[i]-x);
			f[i+1][1]=min(f[i+1][1],k2);
		}
		if (f[n][0]<=st0&&f[n][1]<=st1) return 1;
		st0=f[n][0]; st1=f[n][1];
	}
	return 0;
}
int main(){
	scanf("%d%d",&m,&n);
	for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
	a[n]=a[0]+m;
	int l=0,r=m-n,ans=0;
	while (l<=r){
		int mid=(l+r)/2;
		if (chk(mid))
			r=mid-1,ans=mid;
		else l=mid+1;
	}
	printf("%d",ans);
}