#include <bits/stdc++.h>
using namespace std;
const int N=1<<19;
double PI=acos(-1.0);
int n,L,R[N];
struct C{
	double r,i;
	C(){}
	C(double a,double b){r=a,i=b;}
	C operator + (C x){return C(r+x.r,i+x.i);}
	C operator - (C x){return C(r-x.r,i-x.i);}
	C operator * (C x){return C(r*x.r-i*x.i,r*x.i+i*x.r);}
}w[N],X[N],Y[N],Z[N];
double x[N],y[N],z[N];
char str1[N],str2[N];
int cti[300];
int k,a[N],b[N],A,B,res[N];
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
		X[i]=C(x[i],0),Y[i]=C(y[i],0);
	FFT(X),FFT(Y);
	for (int i=0;i<n;i++)
		Z[i]=X[i]*Y[i],w[i].i*=-1.0;
	FFT(Z);
	for (int i=0;i<n;i++)
		z[i]=Z[i].r/n,w[i].i*=-1.0;
}
int main(){
	cti['A']=0,cti['C']=1,cti['G']=2,cti['T']=3;
	scanf("%d%d%d%s%s",&A,&B,&k,str1,str2);
	for (int i=0;i<A;i++)
		a[i]=cti[str1[i]];
	for (int i=0;i<B;i++)
		b[i]=cti[str2[i]];
	for (int i=0;i<B/2;i++)
		swap(b[i],b[B-i-1]);
	for (n=1,L=0;n<A+B;n<<=1,L++);
	for (int i=0;i<n;i++){
		R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
		w[i]=C(cos(2*i*PI/n),sin(2*i*PI/n));
	}
	memset(res,0,sizeof res);
	for (int i=0;i<4;i++){
		for (int j=0;j<n;j++)
			x[j]=y[j]=0;
		int cnt=0;
		for (int j=0;j<k;j++)
			cnt+=a[j]==i;
		for (int j=0;j<A;j++){
			if (j+k<A)
				cnt+=a[j+k]==i;
			if (j-k-1>=0)
				cnt-=a[j-k-1]==i;
			x[j]=cnt>0?1:0;
		}
		for (int j=0;j<B;j++)
			y[j]=b[j]==i?1:0;
		FFT_times(x,y,z);
		for (int j=B-1;j<A;j++)
			res[j]+=(int)(z[j]+0.5);
	}
	int ans=0;
	for (int i=B-1;i<A;i++)
		if (res[i]==B)
			ans++;
	printf("%d",ans);
	return 0;
}