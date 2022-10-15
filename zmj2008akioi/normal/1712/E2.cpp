#include <cstdio>
#include <vector>
const int n=2e5,N=2e5+10;
int q,fac[N];
long long ans[N];
struct option{
	int r,id;option(){};
	option(int r,int id):r(r),id(id){};
};std::vector<option> vec[N];
namespace BIT{
	long long trr[N];
	int lb(int x){return x&(-x);}
	void fm(int x,long long d){while(x<=n)trr[x]+=d,x+=lb(x);}
	long long fq(int x){long long res=0;while(x)res+=trr[x],x-=lb(x);return res;}
}
int max(int x,int y){return x>y?x:y;}
long long f(int x){return (long long)x*(x-1)/2;}
void add(int x){BIT::fm(x,-f(fac[x])),BIT::fm(x,f(++fac[x]));}
long long fq(int l,int r){return BIT::fq(r)-BIT::fq(l-1);}
int main(){
	scanf("%d",&q);
	for(int l,r,t,i=1;i<=q;++i){
		scanf("%d %d",&l,&r),vec[l].push_back(option(r,i));
		t=r-l+1,ans[i]=(long long)t*(t-1)*(t-2)/6;
	}
	for(int i=n;i;--i){
		for(int j=i<<1;j<=n;j+=i)add(j);
		for(option j:vec[i]){
			int id=j.id;ans[id]-=fq(i,j.r);
			int m1=i<<1;if(m1<=j.r)ans[id]-=j.r/6-(m1-1)/6;
			int m2=(int)(2.5*i+0.6);if(m2<=j.r)ans[id]-=j.r/15-(m2-1)/15;
		}
	}
	for(int i=1;i<=q;++i)printf("%lld\n",ans[i]);
	return 0;
}