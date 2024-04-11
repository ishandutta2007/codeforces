#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=(1<<20)+1,mod=998244353;
int T,n,m,d,a[N],b[N];
int w[N],R[N],vis[N];
char s[N];
vector <int> ans;
int Pow(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1)
			ans=1LL*ans*x%mod;
	return ans;
}
void FFT(int a[],int n){
	for (int i=0;i<n;i++)
		if (R[i]<i)
			swap(a[i],a[R[i]]);
	for (int t=n>>1,d=1;d<n;t>>=1,d<<=1)
		for (int i=0;i<n;i+=(d<<1))
			for (int j=0;j<d;j++){
				int tmp=1LL*w[t*j]*a[i+j+d]%mod;
				a[i+j+d]=(a[i+j]-tmp+mod)%mod;
				a[i+j]=(a[i+j]+tmp)%mod;
			}
}
void solve(){
	scanf("%d%s",&n,s);
	for (m=1,d=0;m<=n*2;m<<=1,d++);
	for (int i=0;i<m;i++)
		R[i]=(R[i>>1]>>1)|((i&1)<<(d-1));
	for (int i=0;i<m;i++)
		a[i]=b[i]=0;
	for (int i=0;i<n;i++){
		a[i]=s[i]=='V';
		b[n-i]=s[i]=='K';
	}
	w[0]=1,w[1]=Pow(3,(mod-1)/m);
	for (int i=2;i<m;i++)
		w[i]=1LL*w[i-1]*w[1]%mod;
	FFT(a,m),FFT(b,m);
	for (int i=0;i<m;i++)
		a[i]=1LL*a[i]*b[i]%mod;
	w[1]=Pow(w[1],mod-2);
	for (int i=2;i<m;i++)
		w[i]=1LL*w[i-1]*w[1]%mod;
	FFT(a,m);
	for (int i=0,inv=Pow(m,mod-2);i<m;i++)
		a[i]=1LL*a[i]*inv%mod;
	for (int i=1;i<=n;i++)
		vis[i]=0;
	for (int i=1;i<=n;i++)
		if (!a[n-i]&&!a[n+i])
			vis[i]=1;
	for (int i=1;i<=n;i++)
		for (int j=i+i;j<=n;j+=i)
			vis[i]&=vis[j];
	int cnt=0;
	for (int i=1;i<=n;i++)
		if (vis[i])
			cnt++;
	printf("%d\n",cnt);
	for (int i=1;i<=n;i++)
		if (vis[i])
			printf("%d ",i);
	puts("");
}
int main(){
	scanf("%d",&T);
	while (T--)
		solve();
	return 0;
}