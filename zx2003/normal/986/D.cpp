/*complie file is too large?*/
#include<bits/stdc++.h>
using namespace std;
typedef vector<int>V;
typedef long long ll;
const int M=55e4,N=21e5;
const double pi=acos(-1);
struct C{
double x,y;
inline C operator+(const C&rhs)const{return (C){x+rhs.x,y+rhs.y};}
inline C operator-(const C&rhs)const{return (C){x-rhs.x,y-rhs.y};}
inline C operator*(const C&rhs)const{return (C){x*rhs.x-y*rhs.y,x*rhs.y+y*rhs.x};}
~C() {}
};
static C w[M],c[M];
struct FFT{
C*wn;int*b,l;
inline void ini(int n){
	l=n;int i;
	wn=new C[l];b=new int[l];b[0]=0;
assert(l>0);
	for(i=1;i<l;++i)b[i]=b[i>>1]>>1|(i&1?l>>1:0);
	for(i=0;i<l;++i)wn[i]=(C){cos(pi*2*i/l),sin(pi*2*i/l)};
}
inline void DFT(C*a,int key){
	C u;int i,j,k,m;
	memcpy(c,a,l<<4);for(i=0;i<l;++i)a[b[i]]=c[i];
	for(i=2;i<=l;i<<=1){
		for(j=k=0,m=i>>1;k<m;++k,j+=l/i)w[k]=wn[j];
		for(j=0;j<l;j+=i)for(k=0;k<m;++k)u=w[k]*a[j+k+m],
			a[j+k+m]=a[j+k]-u,a[j+k]=a[j+k]+u;
	}
	if(key==-1)for(reverse(a+1,a+l),i=0;i<l;++i)a[i].y/=l;
}
void deletee(){delete []wn;delete []b;}
}F[20];
int lo[M];
C A[M];
inline V operator*(const V&a,const V&b){
	static int mi[4]={1,10,100,1000};
	int l=lo[(a.size()+3)/4+(b.size()+3)/4-1],i;
	memset(A,0,16<<l);
	for(i=0;i<a.size();++i)A[i>>2].x+=a[i]*mi[i&3];
	for(i=0;i<b.size();++i)A[i>>2].y+=b[i]*mi[i&3];
	F[l].ini(1<<l);
	F[l].DFT(A,1);for(i=0;i<1<<l;++i)A[i]=A[i]*A[i];F[l].DFT(A,-1);
	F[l].deletee();
	static ll c[N];ll jw=0;
	int w=a.size()+b.size()-1;
	memset(c,0,w<<3);
	memset(c,0,32<<l);
	for(i=0;i<1<<l;++i)c[i<<2]=ll(A[i].y/2+0.5);
	for(i=0;i<w;++i)c[i]+=jw,jw=c[i]/10,c[i]%=10;
	for(;jw;)c[w++]=jw%10,jw/=10;
	V d(w);for(i=0;i<w;++i)d[i]=c[i];
	return d;
}
inline V operator*(const V&a,int x){
	static int c[N];int jw=0,i,l=a.size();
	for(i=0;i<l;++i)c[i]=a[i]*x+jw,jw=c[i]/10,c[i]%=10;
	for(;jw;)c[l++]=jw%10,jw/=10;
	return V(c,c+l);
}
inline bool operator<=(const V&a,const V&b){
	if(a.size()!=b.size())return a.size()<b.size();
	for(int i=a.size()-1;i>=0;--i)if(a[i]!=b[i])return a[i]<b[i];
	return 1;
}
V n,x={1},mi={3};int l,i,le,ans;
char cc[N];
int main(){
	for(i=2;i<M;++i)lo[i]=lo[i-1]+((1<<lo[i-1])<i);
	scanf("%s",cc);l=strlen(cc);n.resize(l);
	for(i=0;i<l;++i)n[l-1-i]=cc[i]-'0';
	le=(l-1)*2.095901-1;le=max(le,0);ans=le*3;
	for(;le;){if(le&1)x=x*mi;if(le>>=1)mi=mi*mi;}
	for(;!(n<=x*4);)x=x*3,ans+=3;
	if(n<=x)ans++;else if(n<=x*2)ans+=2;else if(n<=x*4 && !(n<=x*3))ans+=4;else ans+=3;
	printf("%d\n",ans);
	return 0;
}