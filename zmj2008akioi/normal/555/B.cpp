#include <cstdio>
#include <set>
#include <algorithm>
const int N=2e5+10;
int n,m,cnt,qnt,ans[N];
long long l[N],r[N];
namespace basic{
	int lt,nw,dig[30];
	long long res;
	char cdc;
	inline long long read(){
		res=0;
		for(;cdc<'0'||cdc>'9';cdc=getchar());
		for(;!(cdc<'0'||cdc>'9');cdc=getchar())res=(res<<1)+(res<<3)+(cdc^48);
		return res;
	}
	inline void write(int x){
		for(;x;x=nw)nw=x/10,dig[++lt]=x-(nw<<1)-(nw<<3);
		for(;lt;--lt)putchar(dig[lt]^48);
		putchar(' ');
	}
}using basic::read;using basic::write;
struct option{
	int id,tp;
	long long l,r;
	option(){};
	option(int id,int tp,long long l,long long r):id(id),tp(tp),l(l),r(r){};
	inline bool operator<(const option &nxt)const{return l<nxt.l;}
}qrr[N<<1];std::multiset<option> set;
inline bool cmp(const option &a,const option &b){
	if(a.r!=b.r)return a.r<b.r;
	return a.tp>b.tp;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		l[i]=read(),r[i]=read();
		if(i!=1)qrr[++qnt]=option(i-1,0,l[i]-r[i-1],r[i]-l[i-1]);
	}
	long long w;
	for(int i=1;i<=m;++i)w=read(),qrr[++qnt]=option(i,1,w,w);
	std::sort(qrr+1,qrr+qnt+1,cmp);
	for(int i=1;i<=qnt;++i){
		if(qrr[i].tp==0){
			auto it=set.lower_bound(qrr[i]);
			if(it!=set.end()&&(*it).r<=qrr[i].r)ans[qrr[i].id]=(*it).id,set.erase(it);
			else{puts("No");return 0;}
		}
		if(qrr[i].tp==1)set.insert(qrr[i]);
	}
	puts("Yes");
	for(int i=1;i<n;++i)write(ans[i]);
	return 0;
}