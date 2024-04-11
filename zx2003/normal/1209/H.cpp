#include<bits/stdc++.h>
using namespace std;
const int N=4e5+5;
typedef pair<double,double>pdd;
struct seg{
	int l,r;
	double s;
	inline void in(){scanf("%d%d%lf",&l,&r,&s);++s;}
	inline bool operator<(const seg&rhs)const{return l<rhs.l;}
}a[N];
int n,L,m,i;
double ans;
priority_queue<pdd,vector<pdd>,greater<pdd>>q;
int main(){
	scanf("%d%d",&n,&L);m=n;
	for(i=1;i<=n;++i)a[i].in();
	sort(a+1,a+n+1);
	if(a[1].l>0)a[++m]=(seg){0,a[1].l,1};
	if(a[n].r<L)a[++m]=(seg){a[n].r,L,1};
	for(i=1;i<n;++i)if(a[i].r<a[i+1].l)a[++m]=(seg){a[i].r,a[i+1].l,1};
	sort(a+1,a+m+1);
	for(i=m;i;--i){
		int len=a[i].r-a[i].l;double lb=a[i].s==1?0:len/(1-a[i].s),rb=len/(1+a[i].s),x,dt=0;pdd u;
		ans+=len/a[i].s;
		for(;dt+lb<0 && !q.empty() && (u=q.top(),u.first<a[i].s);){
			x=min(-dt-lb,u.second);q.pop();
			ans-=x/u.first-x/a[i].s;
			dt+=x;u.second-=x;if(u.second>0)q.push(u);
		}
		q.push(pdd(a[i].s,rb+dt));
	}
	printf("%.12f\n",ans);
	return 0;
}