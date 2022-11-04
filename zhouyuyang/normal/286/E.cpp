#include<bits/stdc++.h>
#define For(i,j,k) for (int i=j;i<=k;i++)
#define GG return puts("NO"),0;
using namespace std;
const int N=2100000;
const int mo=998244353;
int a[N],b[N],R[N],ans[N];
int n,m,C,L;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void FFT(int *a,int n,int f){
	For(i,0,n-1) if (i<R[i]) swap(a[i],a[R[i]]);
	for (int d=1;d<n;d<<=1){
		int wn=power(3,(mo-1)/(d<<1));
		if (f==-1) wn=power(wn,mo-2);
		for (int i=0;i<n;i+=(d<<1))
			for (int j=i,w=1;j<i+d;j++){
				int y=1ll*w*a[j+d]%mo;
				a[j+d]=(a[j]+mo-y)%mo;
				a[j]=(a[j]+y)%mo;
				w=1ll*w*wn%mo;
			}
	}
	if (f==-1){
		int v=power(n,mo-2);
		For(i,0,n-1) a[i]=1ll*a[i]*v%mo;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d",&C),a[C]=1;
	C=1; L=0; memcpy(b,a,sizeof(b));
	for (;C<=2*m;C<<=1,L++);
	For(i,0,C-1) R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
	FFT(a,C,1);
	For(i,0,C-1) a[i]=1ll*a[i]*a[i]%mo;
	FFT(a,C,-1);
	For(i,0,m) if (a[i]&&!b[i]) GG;
	For(i,0,m) if (b[i]&&!a[i]) ans[++*ans]=i;
	printf("YES\n%d\n",*ans);
	For(i,1,*ans) printf("%d ",ans[i]);
}