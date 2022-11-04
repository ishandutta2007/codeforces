#include<bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;
struct addq{
	int tp,v,id;
	ll a,b;
	bool operator <(const addq &x)const{
		return v>x.v;
	}
};
struct mulq{
	int tp,id,addid1,addid2;
	ll a,b;
	bool operator <(const mulq &x)const{
		return a*x.b<b*x.a;
	}
};
struct Ans{
	int tp,id;
	bool operator <(const Ans &x)const{
		return tp<x.tp;
	}
};
vector<addq> add[N];
priority_queue<mulq> q;
Ans ans[N];
int a[N],mx[N],id[N];
int n,m,k,tot,x,y,z;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),mx[i]=a[i];
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		if (x==1){
			if (z>mx[y])
				mx[y]=z,id[y]=i;
		}
		else if (x==2)
			add[y].push_back((addq){2,z,i});
		else q.push((mulq){3,i,-1,-1,z-1,1});
	}
	for (int i=1;i<=n;i++){
		if (mx[i]>a[i])
			add[i].push_back((addq){1,mx[i]-a[i],id[i]});
		if (!add[i].size()) continue;
		sort(add[i].begin(),add[i].end());
		ll sum=a[i];
		for (int j=0;j<add[i].size();j++){
			add[i][j].b=sum;
			sum+=add[i][j].v;
			add[i][j].a=add[i][j].v;
		}
		q.push((mulq){add[i][0].tp,add[i][0].id,i,0,add[i][0].a,add[i][0].b});
	}
	int tot=0;
	while (k--&&!q.empty()){
		mulq tmp=q.top(); q.pop();
		if (tmp.a==0) break;
		ans[tot++]=(Ans){tmp.tp,tmp.id};
		if (tmp.tp==3) continue;
		int id1=tmp.addid1;
		int id2=tmp.addid2+1;
		if (id2<add[id1].size())
			q.push((mulq){add[id1][id2].tp,add[id1][id2].id,id1,id2,add[id1][id2].a,add[id1][id2].b});
	}
	printf("%d\n",tot);
	sort(ans,ans+tot);
	for (int i=0;i<tot;i++)
		printf("%d%c",ans[i].id,i==tot-1?'\n':' ');
}