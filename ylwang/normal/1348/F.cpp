#include <bits/stdc++.h>
using namespace std;
const int MAXN=200010;
struct P {
	int l,r,id;
}p[MAXN];
struct cmp {
	bool operator () (P a,P b) {return a.r>b.r;}
};
int n,a[MAXN],b[MAXN],xl[MAXN],xr[MAXN],rev[MAXN];
bool cmp1 (P a,P b) {return a.l<b.l;}
bool cmp2 (P a,P b) {return a.r>b.r;}
priority_queue <P,vector<P>,cmp> q,q2;
multiset <int> ms;
int main () {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%d%d",&p[i].l,&p[i].r);
		p[i].id=i;
	}
	multiset<int>::iterator it;
	sort(p+1,p+n+1,cmp1);
	int cur=1,flg=0;
	for (int i=1;i<=n;i++) {
		while (cur<=n&&p[cur].l<=i) {
			q.push(p[cur]);
			cur++;
		}
		P tmp=q.top();
		q.pop();
		a[tmp.id]=b[tmp.id]=i,xl[tmp.id]=tmp.l,xr[tmp.id]=tmp.r,rev[i]=tmp.id;
		q2.push(tmp);
		while (!q2.empty()&&q2.top().r<i) {
			P tmp2=q2.top();
			q2.pop();
			it=ms.find(a[tmp2.id]);
			ms.erase(it);
		}
		if (!ms.empty()&&!flg) {
			it=ms.end();
			it--;
			if (*it>=tmp.l) {
				flg=1;
				swap(b[tmp.id],b[rev[*it]]);
			}
		}
		ms.insert(i);
	}
	if (flg) {
		printf("NO\n");
		for (int i=1;i<=n;i++) {printf("%d ",a[i]);}
		printf("\n");
		for (int i=1;i<=n;i++) {printf("%d ",b[i]);}
		printf("\n");
	} else {
		printf("YES\n");
		for (int i=1;i<=n;i++) {printf("%d ",a[i]);}
		printf("\n");
	}
	return 0;
}