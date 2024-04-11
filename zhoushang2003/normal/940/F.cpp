#include<bits/stdc++.h>
using namespace std;
const int N=2e6,B=2e3;
struct Q{
	int l,r,t,i;
	int operator<(Q x)const{
		return l/B!=x.l/B?l<x.l:(r/B!=x.r/B?r<x.r:t<x.t);
	}
}q[N];
int n,m,a[N],o,x,y,e,c,d,l=1,r,t,s[N],f[N],A[N];
pair<int,int>p[N];
map<int,int>b;
int F(int x){
	if(!b[x])
		b[x]=++e;
	return b[x];
}
void R(int x){
	f[s[x]]--,f[++s[x]]++;
}
void W(int x){
	f[s[x]]--,f[--s[x]]++;
}
void C(int x,int y){
	if(q[y].l<=p[x].first&&p[x].first<=q[y].r)
		R(p[x].second),W(a[p[x].first]);
	swap(p[x].second,a[p[x].first]);
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>x,a[i]=F(x);
	while(m--&&cin>>o>>x>>y)
		if(o==1)
			c++,q[c]={x,y,d,c};
		else
			p[++d]={x,F(y)};
	sort(q+1,q+c+1);
	for(int i=1;i<=c;i++){
		while(l>q[i].l)
			R(a[--l]);
		while(r<q[i].r)
			R(a[++r]);
		while(l<q[i].l)
			W(a[l++]);
		while(r>q[i].r)
			W(a[r--]);
		while(t<q[i].t)
			C(++t,i);
		while(t>q[i].t)
			C(t--,i);
		x=1;
		while(f[x])
			x++;
		A[q[i].i]=x;
	}
	for(int i=1;i<=c;i++)
		cout<<A[i]<<'\n';
}