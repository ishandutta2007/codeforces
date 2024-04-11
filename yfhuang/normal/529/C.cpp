#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n,m;

const int maxn = 100000 + 5;
int k,q;


#define lson o * 2,l,mid
#define rson o * 2 + 1,mid + 1,r

struct segmenttree{
	int minv[maxn << 2];
	
	void pushup(int o){
		minv[o] = min(minv[o * 2],minv[o * 2 + 1]);
	}
	
	void build(int o,int l,int r){
		if(l == r){
			minv[o] = 0;
			return;
		}
		int mid = (l + r) / 2;
		build(lson);
		build(rson);
		pushup(o);
	}
	
	int query(int o,int l,int r,int ql,int qr){
		if(ql <= l && r <= qr){
			return minv[o];
		}
		int mid = (l + r) / 2;
		int ans = 1e9 + 5;
		if(ql <= mid) ans = min(ans,query(lson,ql,qr));
		if(qr > mid) ans = min(ans,query(rson,ql,qr));
		return ans;
	}
	
	void update(int o,int l,int r,int p,int v){
		if(l == r){
			minv[o] = v;
			return;
		}
		int mid = (l + r) / 2;
		if(p <= mid) update(lson,p,v);
		else update(rson,p,v);
		pushup(o);
	}
}lastc,lastr;

struct rook{
	int x,y;
}r[maxn * 2];

bool cmp1(rook a,rook b){
	return a.x < b.x;
}

bool cmp2(rook a,rook b){
	return a.y < b.y;
}

struct qujian{
	int x1,x2,y1,y2;
	int id;
}q1[maxn * 2];

bool cmpq1(qujian a,qujian b){
	return a.x2 < b.x2;
}

bool cmpq2(qujian a,qujian b){
	return a.y2 < b.y2;
}

bool ans1[maxn * 2];
bool ans2[maxn * 2];


int main(){
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for(int i = 1;i <= k;i++){
		scanf("%d%d",&r[i].x,&r[i].y);
	}
	for(int i = 1;i <= q;i++){
		scanf("%d%d%d%d",&q1[i].x1,&q1[i].y1,&q1[i].x2,&q1[i].y2);
		q1[i].id = i;
	}
	lastr.build(1,1,n);
	lastc.build(1,1,m);
	sort(q1 + 1,q1 + 1 + q,cmpq1);
	sort(r + 1,r + 1 + k,cmp1);
	int j = 1;
	for(int i = 1;i <= q;i++){
		while(j <= k && r[j].x <= q1[i].x2){
			lastc.update(1,1,m,r[j].y,r[j].x);
			j++;
		}
		//cout << q1[i].y1 << " " << q1[i].y2 << endl;
		//cout << lastc.query(1,1,m,q1[i].y1,q1[i].y2) << endl;
		ans1[q1[i].id] = (lastc.query(1,1,m,q1[i].y1,q1[i].y2) >= q1[i].x1);
	}
	sort(q1 + 1,q1 + 1 + q,cmpq2);
	sort(r + 1,r + 1 + k,cmp2);
	j = 1;
	for(int i = 1;i <= q;i++){
		while(j <= k && r[j].y <= q1[i].y2){
			lastr.update(1,1,n,r[j].x,r[j].y);
			j++;
		}
		ans2[q1[i].id] = (lastr.query(1,1,n,q1[i].x1,q1[i].x2) >= q1[i].y1);
	}
	for(int i = 1;i <= q;i++){
		//cout << ans1[i] << " " << ans2[i] << endl;
		if(ans1[i] || ans2[i]){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}