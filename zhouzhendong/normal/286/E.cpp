#include <bits/stdc++.h>
using namespace std;
const int N=1<<21;
double PI=acos(-1.0);
int read(){
	int x=0;
	char ch=getchar();
	while (!('0'<=ch&&ch<='9'))
		ch=getchar();
	while ('0'<=ch&&ch<='9')
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x;
}
int nn,m,a[N],b[N];
int n,L,R[N];
struct C{
	double r,i;
	C(){}
	C(double a,double b){r=a,i=b;}
	C operator + (C x){return C(r+x.r,i+x.i);}
	C operator - (C x){return C(r-x.r,i-x.i);}
	C operator * (C x){return C(r*x.r-i*x.i,r*x.i+i*x.r);}
}A[N],B[N],CC[N],w[N];
double x[N],y[N],z[N];
void FFT(C a[]){
	for (int i=0;i<n;i++)
		if (i>R[i])
			swap(a[i],a[R[i]]);
	for (int t=n>>1,d=1;d<n;d<<=1,t>>=1)
		for (int i=0;i<n;i+=(d<<1))
			for (int j=0;j<d;j++){
				C tmp=w[t*j]*a[i+j+d];
				a[i+j+d]=a[i+j]-tmp;
				a[i+j]=a[i+j]+tmp;
			}
}
void FFT_times(double x[],double y[],double z[]){
	for (int i=0;i<n;i++)
		A[i]=C(x[i],0),B[i]=C(y[i],0);
	FFT(A),FFT(B);
	for (int i=0;i<n;i++)
		CC[i]=A[i]*B[i],w[i].i*=-1.0;
	FFT(CC);
	for (int i=0;i<n;i++)
		z[i]=CC[i].r/n,w[i].i*=-1.0;
}
int main(){
	nn=read(),m=read();
	memset(a,0,sizeof a);
	a[0]=1;
	for (int i=1,x;i<=nn;i++)
		a[read()]=1;
	for (n=1,L=0;n<(m+1)*2;n<<=1,L++);
	for (int i=0;i<n;i++){
		R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
		w[i]=C(cos(2*i*PI/n),sin(2*i*PI/n));
	}
	for (int i=0;i<n;i++)
		x[i]=y[i]=i<=m?a[i]:0;
	FFT_times(x,y,z);
	for (int i=1;i<=m;i++)
		b[i]=(int)(z[i]+0.5);
	int flag=0;
	for (int i=1;i<=m;i++)
		if (!a[i]&&b[i]){
			flag=-1;
			break;
		}
		else if (a[i]&&b[i]==2)
			flag++;
	if (flag==-1)
		puts("NO");
	else {
		puts("YES");
		printf("%d\n",flag);
		for (int i=1;i<=m;i++)
			if (a[i]&&b[i]==2)
				printf("%d ",i);
	}
	return 0;
}