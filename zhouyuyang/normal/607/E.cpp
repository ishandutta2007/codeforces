#include<bits/stdc++.h>
#define db long double 
#define mk make_pair
#define fi first
#define se second
const int N=50005;
const db pi=acos(-1);
using namespace std;
db k[N],b[N],ang[N],g[N],x,y;
pair<db,db> p[N];
int n,m,c[N];
struct que{
	db l,r;
	int id;
	bool operator <(const que &a)const{
		return l<a.l;
	}
}q[N];
set<pair<db,int> > S;
db read(){
	int x;
	scanf("%d",&x);
	return x*0.001;
}
void add(int x,int lim){
	for (;x<=lim;x+=x&(-x)) c[x]++;
}
int ask(int x){
	int s=0;
	for (;x;x-=x&(-x))
		s+=c[x];
	return s;
}
int main(){
	scanf("%d",&n);
	x=read(); y=read();
	scanf("%d",&m);
	for (int i=1;i<=n;i++){
		k[i]=read(); b[i]=read();
		ang[i]=atan(k[i]);
		if (y<k[i]*x+b[i])
			ang[i]+=pi/2;
		else ang[i]-=pi/2;
	}
	db l=0,r=1e11;
	for (int t=1;t<=100;t++){
		db mid=(l+r)/2;
		int top=0;
		for (int i=1;i<=n;i++){
			db dis=fabs((k[i]*x+b[i]-y))/sqrt(k[i]*k[i]+1);
			if (dis>=mid) continue;
			dis=acos(dis/mid); 
			p[++top]=mk(ang[i]-dis,ang[i]+dis);
			if (p[top].fi<-pi) p[top].fi+=2*pi;
			if (p[top].se>pi) p[top].se-=2*pi;
			if (p[top].fi>p[top].se)
				swap(p[top].fi,p[top].se);
		}
		for (int i=1;i<=top;i++)
			g[i]=p[i].se;
		sort(g+1,g+top+1);
		sort(p+1,p+top+1);
		int sum=0;
		memset(c,0,sizeof(c));
		for (int i=1;i<=top&&sum<=m;i++){
			int L=lower_bound(g+1,g+top+1,p[i].fi)-g-1;
			int R=lower_bound(g+1,g+top+1,p[i].se)-g;
			sum+=ask(R)-ask(L); add(R,top);
		}
		if (sum<m) l=mid;
		else r=mid;
	}
	int top=0; db mid=r*(1+1e-8);
	for (int i=1;i<=n;i++){
		db dis=fabs((k[i]*x+b[i]-y))/sqrt(k[i]*k[i]+1);
		if (dis>=mid) continue;
		dis=acos(dis/mid); 
		q[++top]=(que){ang[i]-dis,ang[i]+dis,i};
		if (q[top].l<-pi) q[top].l+=2*pi;
		if (q[top].r>pi) q[top].r-=2*pi;
		if (q[top].l>q[top].r)
			swap(q[top].l,q[top].r);
	}
	sort(q+1,q+top+1);
	db ans=0; int cnt=0;
	for (int i=1;i<=top&&cnt!=m;i++){
		set<pair<db,int> >::iterator it;
		it=S.lower_bound(mk(q[i].l,0));
		for (;it!=S.end()&&cnt!=m;){
			if (it->fi>q[i].r) break;
			db X=(b[it->se]-b[q[i].id])/(k[q[i].id]-k[it->se]);
			db Y=k[q[i].id]*X+b[q[i].id];
			ans+=sqrt((X-x)*(X-x)+(Y-y)*(Y-y));
			++cnt; ++it;
		} 
		S.insert(mk(q[i].r,q[i].id));
	}
	printf("%.20lf",(double)ans);
}