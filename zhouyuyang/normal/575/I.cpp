#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct que{
	int tp,x,y,v,qid;
}q[N*4];
bool cmpx(que a,que b){
	if (a.x!=b.x)
		return a.x<b.x;
	return a.tp<b.tp;
}
bool cmpqid(que a,que b){
	return a.qid<b.qid;
}
struct Tarr{
	int a[N*2+5],lim;
	void init(int _lim){
		lim=_lim;
	}
	void add(int x,int v){
		x=lim-x;
		for (;x<=lim;x+=x&(-x)) a[x]+=v;
	}
	int ask(int x){
		x=lim-x; int ans=0;
		for (;x;x-=x&(-x)) ans+=a[x];
		return ans;
	}
}T1,T2,T3;
int ans[N];
int n,m,tp,id;
void CDQ(int l,int r){
	if (l==r) return;
	int mid=(l+r)/2;
	CDQ(l,mid);
	sort(q+l,q+r+1,cmpx);
	for (int i=l;i<=r;i++){
		if (q[i].tp==1&&q[i].qid<=mid)
			T1.add(q[i].y,q[i].v);
		if (q[i].tp==2&&q[i].qid<=mid)
			T2.add(q[i].x+q[i].y,q[i].v);
		if (q[i].tp==3&&q[i].qid<=mid)
			T3.add(q[i].y-q[i].x+N,q[i].v);
		if (q[i].tp==4&&q[i].qid>mid){
			ans[q[i].v]+=T1.ask(q[i].y);
			ans[q[i].v]+=T2.ask(q[i].x+q[i].y);
			ans[q[i].v]+=T3.ask(q[i].y-q[i].x+N);
		}
	}
	for (int i=l;i<=r;i++){
		if (q[i].tp==1&&q[i].qid<=mid)
			T1.add(q[i].y,-q[i].v);
		if (q[i].tp==2&&q[i].qid<=mid)
			T2.add(q[i].x+q[i].y,-q[i].v);
		if (q[i].tp==3&&q[i].qid<=mid)
			T3.add(q[i].y-q[i].x+N,-q[i].v);
	}
	sort(q+l,q+r+1,cmpqid);
	CDQ(mid+1,r);
}
int main(){
	T1.init(N);
	T2.init(N*2);
	T3.init(N*2);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int fl,k,x,y,d;
		scanf("%d",&fl);
		if (fl==2){
			scanf("%d%d",&x,&y);
			q[++tp]=(que){4,x,y,++id};
		}
		else{
			scanf("%d%d%d%d",&k,&x,&y,&d);
			if (k==1){
				q[++tp]=(que){1,x,y-1,-1};
				q[++tp]=(que){1,x+d+1,y-1,1};
				q[++tp]=(que){2,x,y+d,1};
				q[++tp]=(que){2,x+d+1,y-1,-1};
			}
			if (k==2){
				q[++tp]=(que){1,x,y,1};
				q[++tp]=(que){1,x+d+1,y,-1};
				q[++tp]=(que){3,x,y-d-1,-1};
				q[++tp]=(que){3,x+d+1,y,1};
			}
			if (k==3){
				q[++tp]=(que){1,x-d,y-1,-1};
				q[++tp]=(que){1,x+1,y-1,1};
				q[++tp]=(que){3,x-d,y,1};
				q[++tp]=(que){3,x+1,y+d+1,-1};
			}
			if (k==4){
				q[++tp]=(que){1,x-d,y,1};
				q[++tp]=(que){1,x+1,y,-1};
				q[++tp]=(que){2,x-d,y-1,-1};
				q[++tp]=(que){2,x+1,y-d-2,1};
			}
		}
	}
	for (int i=1;i<=tp;i++)
		q[i].qid=i;
	CDQ(1,tp);
	for (int i=1;i<=id;i++)
		printf("%d\n",ans[i]); 
}
//1(1,0),2(1,-1),3(1,1);