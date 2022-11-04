#include<bits/stdc++.h>
#define mo 998244353
#define N 524300
using namespace std;
int R[N],b[N],c[N];
int S[N],cnt[N][4];
int n,m,k,C[233];
int A[N],B[N];
char s[N];
int ans[N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void FFT(int *a,int n,int f){
	for (int i=1;i<n;i++)
		if (i<R[i]) swap(a[i],a[R[i]]);
	for (int d=1;d<n;d<<=1){
		int wn=power(3,(mo-1)/(d<<1));
		if (f==-1) wn=power(wn,mo-2);
		for (int i=0;i<n;i+=(d<<1))
			for (int j=i,w=1;j<i+d;j++){
				int y=1ll*a[j+d]*w%mo;
				a[j+d]=(a[j]+mo-y)%mo;
				a[j]=(a[j]+y)%mo;
				w=1ll*w*wn%mo;
			}
	}
	if (f==-1){
		int v=power(n,mo-2);
		for (int i=0;i<n;i++)
			a[i]=1ll*a[i]*v%mo;
	}
} 
int main(){
	scanf("%d%d%d",&n,&m,&k);
	C['A']=0; C['C']=1;
	C['G']=2; C['T']=3;
	scanf("%s",s+1);
	for (int i=1;i<=n;i++) A[i]=C[s[i]];
	scanf("%s",s+1);
	for (int i=1;i<=m;i++)
		B[i]=C[s[i]],S[B[i]]++;
	for (int i=1;i<=n;i++){
		for (int j=0;j<=3;j++)
			cnt[i][j]=cnt[i-1][j];
		cnt[i][A[i]]++;
	}
	int lbc=1,l=0;
	for (;lbc<=n+m;lbc<<=1,l++);
	for (int i=1;i<lbc;i++)
		R[i]=(R[i>>1]>>1)|((i&1)<<(l-1));
	for (int j=0;j<=3;j++){
		memset(c,0,sizeof(c));
		memset(b,0,sizeof(b));
		for (int i=1;i<=n;i++)
			c[i]=(cnt[min(n,i+k)][j]!=cnt[max(0,i-k-1)][j]);
		for (int i=1;i<=m;i++) b[i]=(B[m-i+1]==j);
		FFT(c,lbc,1); FFT(b,lbc,1);
		for (int i=0;i<lbc;i++)
			c[i]=1ll*c[i]*b[i]%mo;
		FFT(c,lbc,-1);
		for (int i=1;i<=n-m+1;i++)
			if (c[m+i]==S[j]) ans[i]++;
	}
	int Ans=0;
	for (int i=1;i<=n-m+1;i++)
		Ans+=(ans[i]==4);
	printf("%d",Ans);
}