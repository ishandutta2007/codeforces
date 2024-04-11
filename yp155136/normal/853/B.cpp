#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
const int MAX_N = 1e5 + 6;
const int MAX_M = 1e6 + 6;

vector<pii> arrive[MAX_N];
vector<pii> depart[MAX_N];

LL cha[MAX_M];
LL can[MAX_M];
LL ppre[2*MAX_M];

#define SZ(x) ((int)(x).size())

struct Node {
	Node *lc,*rc;
	LL val,tag;
	Node() {
		lc=rc=NULL;
		val=0;
		tag=0;
	}
	void pull() {
		val = lc->val + rc->val;
	}
};

Node* Build(int L,int R) {
	Node* node = new Node();
	if (L==R) return node;
	int mid=(L+R)>>1;
	node->lc=Build(L,mid);
	node->rc=Build(mid+1,R);
	return node;
}

void push(Node* node,int L,int R) {
	if (node==NULL) return;
	if (L==R) node->tag=0;
	if (node->tag == 0) return;
	int mid=(L+R)>>1;
	node->lc->tag += node->tag;
	node->rc->tag += node->tag;
	node->lc->val += (mid-L+1)*node->tag;
	node->rc->val += (R-mid)*node->tag;
	node->tag=0;
	return;
}

void modify(Node* node,int L,int R,int l,int r,LL val) {
	if (l>R || L>r) return;
	else if (l<=L && R<=r) {
		node->tag += val;
		node->val += (R-L+1)*val;
		return;
	}
	push(node,L,R);
	int mid=(L+R)>>1;
	modify(node->lc,L,mid,l,r,val);
	modify(node->rc,mid+1,R,l,r,val);
	node->pull();
	return;
}

LL query(Node* node,int L,int R,int l,int r) {
	if (l>R || L>r) return 0;
	else if (l<=L && R<=r) return node->val;
	push(node,L,R);
	int mid=(L+R)>>1;
	return query(node->lc,L,mid,l,r) + query(node->rc,mid+1,R,l,r);
}

int main () {
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for (int i=1;m>=i;i++) {
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		if (c==0) {
			arrive[b].push_back(make_pair(a+1,d));
		}
		else {
			depart[c].push_back(make_pair(a-1,d));
		}
	}
	LL kk=1e6 + 1;
	Node* root=Build(1,kk);
	for (int i=1;n>=i;i++) {
		sort(depart[i].begin(),depart[i].end());
		sort(arrive[i].begin(),arrive[i].end());
		if (SZ(depart[i]) == 0 || SZ(arrive[i])==0 ) {
			puts("-1");
			return 0;
		}
		LL mn=arrive[i][0].first, mx = depart[i][SZ(depart[i])-1].first;
		if (!(mx - mn + 1 >= k)) {
			puts("-1");
			return 0;
		}
//		cout<<"i = "<<i<<" , mn = "<<mn<<" , mx = "<<mx-k<<endl;
		mx -= (k);
		mx++;
		cha[mn]++;
		cha[mx+1]--;
		deque<pii> dq;
		for (pii p:depart[i]) {
			pii now=make_pair(p.second,p.first);
			while (SZ(dq) && dq.back()>now) {
				dq.pop_back();
			}
			dq.push_back(now);
		}
		LL last=-1;
		LL cost=123456789;
		for (int j=0;SZ(arrive[i])>j;j++) {
			pii p=arrive[i][j];
			while (SZ(dq) && dq.front().second - p.first < k-1) {
				dq.pop_front();
			}
			if (!SZ(dq)) break;
			cost = min(cost,p.second);
			LL nxt=123456789;
			if (j+1 != SZ(arrive[i])) {
				nxt = arrive[i][j+1].first-1;
			}
//			cout<<"modify : L = "<<p.first<<" , R = "<<min(dq[0].second-k+1,nxt)<<" , val = "<<cost + dq[0].first<<endl;
			modify(root,1,kk,p.first,min(dq[0].second-k+1,nxt),cost + dq[0].first);
			LL now=min(dq[0].second-k+1,nxt)+1;
			while (SZ(dq) && min(dq[0].second-k+1,nxt) == dq[0].second-k+1) {
				dq.pop_front();
				if (!SZ(dq)) break;
				modify(root,1,kk,now,min(dq[0].second-k+1,nxt),cost+dq[0].first);
				now = min(dq[0].second-k+1,nxt)+1;
			}
			if (j+1 == SZ(arrive[i]) && SZ(dq)) {
				LL last=dq[0].second-k+2;
				dq.pop_front();
				while (SZ(dq)) {
					modify(root,1,kk,last,dq[0].second-k+1,cost + dq[0].first);
//					cout<<"modify : L = "<<last<<" , R  = "<<dq[0].second-k+1<<" , cost = "<<dq[0].first+cost<<endl;
					last = dq[0].second-k+2;
					dq.pop_front();
				}
			}
		}
	}
	LL pre=0;
	for (int i=1;kk>=i;i++) {
		pre += cha[i];
		can[i] = pre;
		if (can[i] != n) can[i]=0;
		ppre[i] = ppre[i-1] + can[i];
	}
	LL ans=-1;
	for (int i=1;kk>=i;i++) {
		if (can[i]) {
//			cout<<"i = "<<i<<endl;
			if (ans == -1) ans=query(root,1,kk,i,i);
			else ans=min(ans,query(root,1,kk,i,i));
		}
	}
	printf("%lld\n",ans);
}