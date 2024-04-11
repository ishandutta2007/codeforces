#include<iostream>
#include<cstdio> 
#include<algorithm>
#include<cmath>
#include<cstring>
#define ll long long
using namespace std;
const int maxn=8e5+5;///4*maxn
const double pi=acos(-1.0);
int n,lim=1,len,pos[maxn],x,a,s[maxn],cnt[maxn];
ll ans[maxn];
struct complex
{
	double x,y;
	complex(double xx=0,double yy=0){x=xx,y=yy;}
}f[maxn],g[maxn];
complex operator + (complex &a,complex &b){return complex(a.x+b.x,a.y+b.y);}
complex operator - (complex &a,complex &b){return complex(a.x-b.x,a.y-b.y);}
complex operator * (complex &a,complex &b){return complex(a.x*b.x-a.y*b.y,a.y*b.x+a.x*b.y);}
inline void fft(complex *a,int typ)
{
	for(int i=0;i<lim;++i)if(i<pos[i])swap(a[i],a[pos[i]]);
	for(int mid=1;mid<lim;mid<<=1)
	{
		complex wn=complex(cos(pi/mid),typ*sin(pi/mid));
		for(int j=0;j<lim;j+=(mid<<1))
		{
			complex w=complex(1,0);
			for(int k=0;k<mid;++k,w=w*wn)
			{
				complex x=a[j+k],y=a[j+mid+k]*w;
				a[j+k]=x+y,a[j+mid+k]=x-y;
			}
		}
	}
	if(typ==-1)
	{
		for(int i=0;i<=lim;++i)a[i].x/=lim;
	}
}
int main()
{
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;++i)scanf("%d",&a),s[i]=(x>a)+s[i-1];
	for(int i=1;i<=n;++i)f[s[i]].x++,cnt[s[i]]++;
	f[0].x++,cnt[0]++;/// 
	for(int i=0;i<=n;++i)g[i].x=f[n-i].x;
	while(lim<=(n<<1))len++,lim<<=1;
	for(int i=0;i<lim;++i)pos[i]=(pos[i>>1]>>1)|((i&1)<<(len-1)); 
	fft(f,1);
	fft(g,1);
	for(int i=0;i<=lim;++i)f[i]=f[i]*g[i];
	fft(f,-1);
	for(int i=0;i<=n;++i)ans[0]+=(1LL*(cnt[i])*(cnt[i]-1)/2);
	for(int i=1;i<=n;++i)ans[i]=f[n-i].x+0.5;
	for(int i=0;i<=n;++i)printf("%lld ",ans[i]);
	printf("\n");
	return 0;
}