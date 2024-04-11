#include<bits/stdc++.h>
using namespace std;
typedef long double ldb;
struct pdd{
	ldb first,second;
	int id;
	pdd(){}
	pdd(ldb first,ldb second,int id):
		first(first),second(second),id(id){}
};
int n,a[100100],tp,b[100100];
ldb mx,pi[101000];
pdd sta[101000],g[101000];
long long T;
ldb cal1(ldb p,ldb T){
	return (pow(p,T)-1)/(p-1);
}
ldb cal2(ldb p,ldb T){
	return (cal1(p,T)-(T-1)*pow(p,T)-1)/(1-p);
}
int chk(pdd a,pdd b,pdd c){
	ldb a1=(b.second-a.second)/(a.first-b.first);
	ldb a2=(c.second-b.second)/(b.first-c.first);
	return a1>=a2;
}
int cmp(pdd a,pdd b){
	if(fabs(a.first-b.first)<=1e-10)return a.second>b.second;
	return a.first<b.first;
}
ldb trans(int x,ldb ans,long long pos,long long nxt){
	if(nxt==pos)return ans;
	long long X=nxt-pos;
	ldb ai=a[sta[x].id],bi=b[sta[x].id],P=pi[sta[x].id],Q=1-P;
	ldb val=pow(Q,X)*ans+ai*P*cal1(Q,X);
	val+=mx*P*nxt*cal1(Q,X);
	val-=mx*P*cal2(Q,X);
	return val;
}
int main(){
	scanf("%d%lld",&n,&T);
	mx=0;
	for(int i=1;i<=n;++i){
		scanf("%d%d%Lf",&a[i],&b[i],&pi[i]);
		mx=max(mx,b[i]*pi[i]);
		g[i]=pdd(pi[i],pi[i]*a[i],i);
	}
	sort(g+1,g+n+1,cmp);
	for(int i=1;i<=n;++i){
		if(tp&&fabs(sta[tp].first-g[i].first)<=1e-10)continue;
		while(tp>=2&&chk(sta[tp-1],sta[tp],g[i]))tp--;
		sta[++tp]=g[i];
	} 
//	printf("[%d]",tp);
	ldb ans=0;
	for(int i=1;i<=n;++i)ans=max(ans,pi[i]*a[i]);
	long long pos=0,x=1;
	while(pos<T){
		if(x==tp){
		//	printf("{%d}",sta[tp].id);
			ans=trans(tp,ans,pos,T-1);
			break;
		} else {
			long long l=pos+1,r=T-1,nxt=pos;
			ldb X=(sta[x].second-sta[x+1].second)/(sta[x+1].first-sta[x].first);
			while(l<=r){
				long long mid=l+r>>1;
				ldb d=-trans(x,ans,pos,mid-1)+mx*mid;
				if(d<=X)nxt=mid,l=mid+1;
				else r=mid-1;
			}
//			printf("[%lld]",nxt);
			ans=trans(x,ans,pos,nxt);
			pos=nxt;
			x++;
		}
	}
	printf("%.15Lf",ans);
}