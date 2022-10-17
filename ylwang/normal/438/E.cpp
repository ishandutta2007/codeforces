#include<iostream>
#include<cstdio>
#include<algorithm>
#define swap(x,y) (x^=y,y^=x,x^=y)
#define mul(x,y) (1ll*x*y%P)
#define add(x,y) (x+y>=P?x+y-P:x+y)
#define dec(x,y) (x-y<0?x-y+P:x-y)
using namespace std;
#define getc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
inline int read(){
    #define num ch-'0'
    char ch;bool flag=0;int res;
    while(!isdigit(ch=getc()))
    (ch=='-')&&(flag=true);
    for(res=num;isdigit(ch=getc());res=res*10+num);
    (flag)&&(res=-res);
    #undef num
    return res;
}
char sr[1<<21],z[20];int K=-1,Z;
inline void Ot(){fwrite(sr,1,K+1,stdout),K=-1;}
inline void print(int x){
    if(K>1<<20)Ot();if(x<0)sr[++K]=45,x=-x;
    while(z[++Z]=x%10+48,x/=10);
    while(sr[++K]=z[Z],--Z);sr[++K]='\n';
}
const int N=500005,P=998244353,G=3,inv2=499122177;
inline int ksm(int a,int b){
	int res=1;
	while(b){
		if(b&1) res=mul(res,a);
		a=mul(a,a),b>>=1;
	}
	return res;
}
int n,m,r[N],A[N],B[N],C[N],D[N],O[N],d[N],c[N];
void NTT(int *A,int type,int len){
	int limit=1,l=0;
	while(limit<len) limit<<=1,++l;
	for(int i=0;i<limit;++i)
	r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
	for(int i=0;i<limit;++i)
	if(i<r[i]) swap(A[i],A[r[i]]);
	for(int mid=1;mid<limit;mid<<=1){
		int R=mid<<1,Wn=ksm(G,(P-1)/R);O[0]=1;
		for(int j=1;j<mid;++j) O[j]=mul(O[j-1],Wn);
		for(int j=0;j<limit;j+=R){
			for(int k=0;k<mid;++k){
				int x=A[j+k],y=mul(O[k],A[j+k+mid]);
				A[j+k]=add(x,y),A[j+k+mid]=dec(x,y);
			}
		}
	}
	if(type==-1){
		reverse(A+1,A+limit);
		for(int i=0,inv=ksm(limit,P-2);i<limit;++i)
		A[i]=mul(A[i],inv);
	}
}
void Inv(int *a,int *b,int len){
	if(len==1) return (void)(b[0]=ksm(a[0],P-2));
	Inv(a,b,len>>1);
	for(int i=0;i<len;++i) A[i]=a[i],B[i]=b[i];
	NTT(A,1,len<<1),NTT(B,1,len<<1);
	for(int i=0,l=(len<<1);i<l;++i) A[i]=mul(mul(A[i],B[i]),B[i]);
	NTT(A,-1,len<<1);
	for(int i=0;i<len;++i) b[i]=dec(1ll*(b[i]<<1)%P,A[i]);
	for(int i=0,l=(len<<1);i<l;++i) A[i]=B[i]=0;
}
void Sqrt(int *a,int *b,int len){
	if(len==1) return (void)(b[0]=a[0]);
	Sqrt(a,b,len>>1);
	for(int i=0;i<len;++i) C[i]=a[i];
	Inv(b,D,len);
	NTT(C,1,len<<1),NTT(D,1,len<<1);
	for(int i=0,l=len<<1;i<l;++i) D[i]=mul(D[i],C[i]);
	NTT(D,-1,len<<1);
	for(int i=0;i<len;++i) b[i]=mul(add(b[i],D[i]),inv2);
	for(int i=0,l=(len<<1);i<l;++i) C[i]=D[i]=0;
}
int main(){
//	freopen("testdata.in","r",stdin);
	n=read(),m=read();
	for(int i=1,x;i<=n;++i) x=read(),++d[x];
	int len;for(len=1;len<=m;len<<=1);
	for(int i=1;i<len;++i) d[i]=(-4*d[i]+P)%P;
	++d[0];
	Sqrt(d,c,len);
	for(int i=0;i<len;++i) d[i]=0;
	c[0]=add(c[0],1);
	Inv(c,d,len);
	for(int i=0;i<=m;++i) d[i]=add(d[i],d[i]);
	for(int i=1;i<=m;++i) print(d[i]);
	Ot();
	return 0;
}