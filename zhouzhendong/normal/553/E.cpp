#include <bits/stdc++.h>
using namespace std;
const int N=55,M=105,T=20005,S=1<<15;
double PI=acos(-1.0);
int n,m,t,punish;
int a[M],b[M],c[M],dis[N][N];
double dp[N][T],sum[M][T],p[M][T];
int s,d,Rev[S];
struct C{
	double r,i;
	C(){}
	C(double a,double b){r=a,i=b;}
	C operator + (C x){return C(r+x.r,i+x.i);}
	C operator - (C x){return C(r-x.r,i-x.i);}
	C operator * (C x){return C(r*x.r-i*x.i,r*x.i+i*x.r);}
}w[S],A[S],B[S];
void FFT(C a[],int n){
	for (int i=0;i<n;i++)
		if (i<Rev[i])
			swap(a[i],a[Rev[i]]);
	for (int t=n>>1,d=1;d<n;d<<=1,t>>=1)
		for (int i=0;i<n;i+=(d<<1))
			for (int j=0;j<d;j++){
				C tmp=w[t*j]*a[i+j+d];
				a[i+j+d]=a[i+j]-tmp;
				a[i+j]=a[i+j]+tmp;
			}
}
void solve(int L,int R){
	if (L==R){
		for (int e=1;e<=m;e++)
			dp[a[e]][L]=min(dp[a[e]][L],sum[e][L]+c[e]);
		return;
	}
	int mid=(L+R)>>1;
	solve(mid+1,R);
	//sum[e][L...mid]+=dp[mid+1...R]#p[e][1...R-L]
	//sum[e][L...mid]+=dp[mid+1...R]*p[e][R-L-1...0]
	for (s=1,d=0;s<R-mid+R-L;s<<=1,d++);
	for (int i=0;i<s;i++){
		Rev[i]=(Rev[i>>1]>>1)|((i&1)<<(d-1));
		w[i]=C(cos(2*i*PI/s),sin(2*i*PI/s));
	}
	for (int e=1;e<=m;e++){
		for (int i=0;i<s;i++)
			A[i]=B[i]=C(0,0);
		for (int i=mid+1;i<=R;i++)
			A[i-mid-1]=C(dp[b[e]][i],0);
		for (int i=1;i<=R-L;i++)
			B[R-L-i]=C(p[e][i],0);
		FFT(A,s),FFT(B,s);
		for (int i=0;i<s;i++)
			A[i]=A[i]*B[i],w[i].i*=-1.0;
		FFT(A,s);
		for (int i=0;i<s;i++)
			A[i].r/=s,w[i].i*=-1.0;
		for (int i=L;i<=mid;i++)
			sum[e][i]+=A[i-mid-1+(R-L)].r;
	}
	solve(L,mid);
}
int main(){
	scanf("%d%d%d%d",&n,&m,&t,&punish);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			dis[i][j]=i==j?0:1e9;
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		dis[a[i]][b[i]]=min(dis[a[i]][b[i]],c[i]);
		for (int j=1;j<=t;j++)
			scanf("%lf",&p[i][j]),p[i][j]/=100000;
	}
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for (int i=0;i<N;i++)
		for (int j=0;j<T;j++)
			dp[i][j]=1e9;
	for (int i=1;i<=n;i++)
		dp[i][t+1]=punish+dis[i][n];
	for (int i=0;i<=t;i++)
		dp[n][i]=0;
	memset(sum,0,sizeof sum);
	for (int e=1;e<=m;e++){
		double P=0;
		for (int i=1;i<=t;i++){
			P+=p[e][t-i+1];
			sum[e][i]+=P*dp[b[e]][t+1];
		}
	}
	solve(0,t);
	printf("%.8lf",dp[1][0]);
	return 0;
}