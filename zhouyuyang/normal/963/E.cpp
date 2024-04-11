#include<bits/stdc++.h>
#define mo 1000000007
using namespace std;
#define N 7850
int a[N][N],res[N];
int R,a1,a2,a3,a4,cnt,wzp[105][105],ans;
int &id(int x,int y){
	return wzp[x+R+1][y+R+1];
}
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
} 
void gauss(){
	for (int i=1;i<=cnt;i++){
		if (!a[i][i])
			for (int j=i+1;j<=cnt&&j<=i+2*R;j++)
				if (a[j][i]){
					for (int k=i;k<=i+2*R&&k<=cnt;k++)
						swap(a[i][k],a[j][k]);
					swap(a[i][cnt+1],a[j][cnt+1]);
					break;
				}
		if (!a[i][i]) continue;
		int inv=power(a[i][i],mo-2);
		for (int j=i+1;j<=cnt&&j<=i+2*R;j++){
			if (!a[j][i]) continue;
			int t=1ll*inv*a[j][i]%mo;
			for (int k=i;k<=cnt&&k<=i+2*R;k++)
				a[j][k]=(a[j][k]-1ll*a[i][k]*t%mo+mo)%mo;
			a[j][cnt+1]=(a[j][cnt+1]-1ll*a[i][cnt+1]*t%mo+mo)%mo;
		}
	}
	for (int i=cnt;i;i--){
		int t=a[i][cnt+1];
		for (int j=i+1;j<=cnt&&j<=i+100;j++)
			t=(t-1ll*a[i][j]*res[j]%mo+mo)%mo;
		res[i]=1ll*t*power(a[i][i],mo-2)%mo;
		ans=(ans+res[i])%mo;
	}
}
int main(){
	scanf("%d%d%d%d%d",&R,&a1,&a2,&a3,&a4);
	int inv=power(a1+a2+a3+a4,mo-2);
	for (int i=-R;i<=R;i++)
		for (int j=-R;j<=R;j++)
			if (i*i+j*j<=R*R)
				id(i,j)=++cnt,a[cnt][cnt]=1;
	a[id(0,0)][cnt+1]=1;
	for (int i=-R;i<=R;i++)
		for (int j=-R;j<=R;j++)
			if (i*i+j*j<=R*R){
				if (id(i-1,j)) a[id(i-1,j)][id(i,j)]=mo-1ll*a1*inv%mo;
				if (id(i,j-1)) a[id(i,j-1)][id(i,j)]=mo-1ll*a2*inv%mo;
				if (id(i+1,j)) a[id(i+1,j)][id(i,j)]=mo-1ll*a3*inv%mo;
				if (id(i,j+1)) a[id(i,j+1)][id(i,j)]=mo-1ll*a4*inv%mo;
			}
	gauss();
	printf("%d\n",ans);
}