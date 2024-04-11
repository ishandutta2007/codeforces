#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
typedef long long LL;
const int PW=20,N=2e5+10;
int n,q,qnt,a[N],r[N],ext[N],st[PW][N];LL fans,ans[N];
template<typename T>T lb(T x){return x&(-x);}
template<typename T>T min(T x,T y){return x<y?x:y;}
struct opt{
	int id,tp,w,x,y;opt(){};
	opt(int id,int tp,int w,int x,int y):id(id),tp(tp),w(w),x(x),y(y){};
	bool operator<(const opt &nxt)const{
		if(x!=nxt.x)return x<nxt.x;
		else return tp<nxt.tp;
	}
}qrr[N<<2];
struct dopt{
	int id,tp,w,x;dopt(){};
	dopt(int id,int tp,int w,int x):id(id),tp(tp),w(w),x(x){};
	bool operator<(const dopt &nxt)const{
		if(x!=nxt.x)return x>nxt.x;
		return tp<nxt.tp;
	}
};std::vector<dopt> vec[N];
struct trr{
	const int k=2e5+5;
	LL a[N];trr(){memset(a,0,sizeof(a));}
	void fm(int x,int d){++x;while(x<=k)a[x]+=d,x+=lb(x);}
	LL fq(int x){++x;LL res=0;while(x)res+=a[x],x-=lb(x);return res;}
}t1,t2;
int R(int x){return n+1-x;}
int nxt(int p,int w){
	if(p>n+1)p=n+1;
	for(int i=PW-1;~i;--i){
		if(p+(1<<i)-1>n)continue;
		if(st[i][p]>=w)p+=1<<i;
	}
	return p;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),st[0][i]=a[i]-i;
	for(int i=1;i<PW;++i)for(int j=1;j+(1<<i)-1<=n;++j)st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
	for(int p=1,i=1;i<=n;++i){
		while(p<n&&a[p+1]>=p+2-i)++p;
		fans+=p-i+1,qrr[++qnt]=opt(i,0,1,i,i),qrr[++qnt]=opt(i,0,-1,i,p+1);
		/*printf("Range [%d,%d]\n",i,p),*/r[i]=p,vec[p+1].push_back(dopt(0,0,nxt(p+2,1-i)-p-1,i-1));
	}
	scanf("%d",&q);
	for(int p,x,i=1;i<=q;++i){
		scanf("%d %d",&p,&x);
		qrr[++qnt]=opt(i,1,0,p-x,p);
		vec[p].push_back(dopt(i,1,0,p-x));
	}
	std::sort(qrr+1,qrr+qnt+1);
	for(int i=1;i<=qnt;++i){
		int y=qrr[i].y,id=qrr[i].id;
		if(qrr[i].tp==0){
			int w=qrr[i].w;
			t1.fm(y,w),t2.fm(y,w*r[id]);
			/*printf("T1 modify %d %d\n",y,w);
			printf("T2 modify %d %d\n",y,w*r[id]);*/
		}
		if(qrr[i].tp==1){
			ans[id]-=t2.fq(y)-(LL)(y-1)*t1.fq(y);
		}
	}
	for(int i=1;i<=n;++i){
		std::sort(vec[i].begin(),vec[i].end());LL ns=0;
		for(dopt o:vec[i]){
			if(o.tp==0)ns+=o.w;
			if(o.tp==1)ans[o.id]+=ns;
		}
	}
	for(int i=1;i<=q;++i)printf("%lld\n",fans+ans[i]);
	return 0;
}