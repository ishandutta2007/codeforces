#include<cstdio>
#include<cstring>
#include<cmath>
const int N=530005;
const double pi=acos(-1.0);
struct cp{
	double x,y;
	cp(double _x=0,double _y=0):x(_x),y(_y){}
	cp operator+(const cp&rhs)const{
		return cp(x+rhs.x,y+rhs.y);
	}
	cp operator-(const cp&rhs)const{
		return cp(x-rhs.x,y-rhs.y);
	}
	cp operator*(const cp&rhs)const{
		return cp(x*rhs.x-y*rhs.y,y*rhs.x+x*rhs.y);
	}
};
namespace FFT{
	cp b[N];
	int l;
	inline void DFT(cp*a,int z){
		int i,j,k;
		for(i=l;i>1;i>>=1){
			memcpy(b,a,sizeof b);
			int n=i>>1;
			for(j=0;j<l;j+=i)
				for(k=0;k<n;++k)a[j+k]=b[j+(k<<1)],a[j+k+n]=b[j+(k<<1|1)]; 
		}
		for(i=2;i<=l;i<<=1){
			cp wn=cp(cos(2*pi/i),z*sin(2*pi/i)),w;
			int n=i>>1;
			for(j=0;j<l;j+=i)
				for(w=1,k=j;k<j+n;++k,w=w*wn){
					cp u=a[k],v=a[k+n]*w;
					a[k]=u+v;
					a[k+n]=u-v;
				}
		}
		if(z==-1)for(i=0;i<l;++i)a[i].x/=l;
	}
	inline void mul(cp*a,cp*b,cp*c,int n){
		l=1;
		while(l<=n)l<<=1;
		DFT(a,1);
		DFT(b,1);
		for(int i=0;i<l;++i)c[i]=a[i]*b[i];
		DFT(c,-1);
	}
}
int id[150],ss[N],s[N],t[N],f[5][N],n,m,k,i,j,a[N],ans;
cp b[N],c[N],d[N];
char c1[N],c2[N];
inline int min(const int&a,const int&b){
	return a>b?b:a;
}
inline int max(const int&a,const int&b){
	return a<b?b:a;
}
inline void solve(int x){
	memset(b,0,sizeof b);
	memset(c,0,sizeof c);
	for(int i=0;i<m;++i)c[m-1-i]=t[i+1]==x;
	for(int i=0;i<n;++i)b[i]=f[x][i+1];
	FFT::mul(b,c,d,n+m);
	for(int i=1;i<=n;++i)ss[i]+=(int)(d[i+m-2].x+0.5);
}
int main(){
	scanf("%d%d%d%s%s",&n,&m,&k,c1+1,c2+1);
	id['A']=0;
	id['C']=1;
	id['G']=2;
	id['T']=3;
	for(i=1;i<=n;++i)s[i]=id[c1[i]];
	for(i=1;i<=m;++i)t[i]=id[c2[i]];
	for(i=0;i<4;++i){
		memset(a,0,sizeof a);
		for(j=1;j<=n;++j)if(s[j]==i)++a[max(1,j-k)],--a[min(n+1,j+k+1)];
		for(j=1;j<=n;++j)f[i][j]=(a[j]+=a[j-1])?1:0;
		solve(i);
	}
	for(i=1;i<=n;++i)ans+=ss[i]==m;
	return printf("%d\n",ans),0;	
}