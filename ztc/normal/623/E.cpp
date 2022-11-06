#include<stdio.h>
#include<cmath>
#define inf 1000000007
const double pi=acos((long double)-1);
struct comp{
	double a,b;
	comp(){}
	comp(double A,double B){
		a=A;b=B;
	}
	comp(double P){
		a=cos(P);b=sin(P);
	}
	inline comp operator+(const double &A)const{return comp(a+A,b);}
	inline comp operator+(const comp &A)const{return comp(a+A.a,b+A.b);}
	inline comp operator-(const double &A)const{return comp(a-A,b);}
	inline comp operator-(const comp &A)const{return comp(a-A.a,b-A.b);}
	inline comp operator*(const double &A)const{return comp(a*A,b*A);}
	inline comp operator*(const comp &A)const{return comp(a*A.a-b*A.b,a*A.b+b*A.a);}
}tmp1[131072],tmp2[131072],tmp3[131072],tmp4[131072],tmp[131072];
inline void Swap(comp &a,comp &b){comp tmp=a;a=b;b=tmp;}
int _0[131072],_lset=-1,inv[131072];
inline void mod(int &p){p-=p>=inf?inf:0;}
inline int ksm(long long a,int b){register int ans=1;while(b)(b&1)&&(ans=a*ans%inf),a=a*a%inf,b>>=1;return ans;}
inline void init(int n){if(_lset==n)return;_lset=n;_0[0]=0;for(register int i=1;i<n;i++)_0[i]=i&1?_0[i^1]|n>>1:_0[i>>1]>>1;}
inline void clr(int a[],int l,int r){for(register int i=l;i<r;i++)a[i]=0;}
inline void cpy(int a[],int b[],int n){for(register int i=0;i<n;i++)b[i]=a[i];}
inline int gett(int n){while(n!=(n&-n))n^=n&-n;return n<<1;}
inline int getint(double p){
	p+=0.5;
	return int(p-double(1)*inf*floor(p/double(inf)));
}
inline void dft(comp a[],int n,bool typ){
	init(n);register comp q;tmp[0]=comp(1,0);
	for(register int i=0;i<n;i++)if(i<_0[i])Swap(a[i],a[_0[i]]);
	for(register int i=1;i<n;i<<=1){
		comp w=comp(typ?-pi/i:pi/i);
		for(register int k=i-2;k>=0;k-=2)
			tmp[k^1]=(tmp[k]=tmp[k>>1])*w;
		for(register int j=0;j<n;j+=i<<1)
			for(register int k=0;k<i;k++)
				q=tmp[k]*a[i+j+k],a[i+j+k]=a[j+k]-q,a[j+k]=a[j+k]+q;
	}if(typ)for(register int i=0;i<n;i++)a[i].a/=double(n),a[i].b/=double(n);
}
inline void fft(int a[],int b[],int c[],int n){
	for(register int i=0;i<n;i++)tmp1[i]=comp(a[i]&32767,a[i]>>15),tmp2[i]=comp(b[i]&32767,b[i]>>15);
	dft(tmp1,n,0);dft(tmp2,n,0);
	for(register int i=0,j;i<n;i++)
		j=i?n-i:0,tmp3[i]=comp(tmp1[i].a+tmp1[j].a,tmp1[i].b-tmp1[j].b)*tmp2[i]*0.5,tmp4[i]=comp(tmp1[i].b+tmp1[j].b,tmp1[j].a-tmp1[i].a)*tmp2[i]*0.5;
	dft(tmp3,n,1);dft(tmp4,n,1);
	int val2=32768%inf,val3=1073741824%inf;
	for(register int i=0;i<n;i++){
		register int v1=getint(tmp3[i].a),v2=getint(tmp3[i].b+tmp4[i].a),v3=getint(tmp4[i].b);
		c[i]=(1ull*val2*v2+1ull*val3*v3+v1)%inf;
	}
}
int a[131072],b[131072],fac[131072],ifac[131072],n,m;
void calc(int len){
	if(len==1){for(int i=1;i<65536;i++)a[i]=ifac[i];return;}
	if(len&1){
		calc(len^1);int d=ksm(2,len^1);
		for(int i=1,tot=d;i<65536;i++)b[i]=1ull*ifac[i]*tot%inf,tot=1ull*tot*d%inf;
	}else{
		calc(len>>1);int d=ksm(2,len>>1);
		for(int i=0,tot=1;i<65536;i++)b[i]=1ull*a[i]*tot%inf,tot=1ull*tot*d%inf;
	}fft(a,b,a,131072);clr(a,65536,131072);
}
int main(){long long k;
	scanf("%lld%d",&k,&m);
	if(k>m)return puts("0")&0;n=k;
	fac[0]=1;for(int i=1;i<=65536;i++)fac[i]=1ull*fac[i-1]*i%inf;
	ifac[65536]=ksm(fac[65536],inf-2);for(int i=65536;i;i--)ifac[i-1]=1ull*i*ifac[i]%inf;
	int ans=0;calc(n);for(int i=0;i<=m;i++)ans=(1ull*a[i]*ifac[m-i]+ans)%inf;
	printf("%lld",1ll*ans*fac[m]%inf);
}