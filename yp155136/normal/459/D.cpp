//XDDD 
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 1000003;
vector<int> b;
int a[MAX_N];
int dp[MAX_N];
int dp2[MAX_N];
int cnt[MAX_N];

typedef long long LL;

struct Node {
	Node* lc;
	Node* rc;
	LL val;
	Node() {
		lc=rc=NULL;
		val=-1;
	}
};

void modify(Node* node,int L,int R,int pos,int val) {
	if (L==R) {
		node->val=val;
		return;
	}
	int mid=(L+R)>>1;
	if (pos<=mid) {
		if (node->lc==NULL) node->lc=new Node();
		modify(node->lc,L,mid,pos,val);
	}
	else {
		if (node->rc==NULL) node->rc=new Node();
		modify(node->rc,mid+1,R,pos,val);
	}
	
}

int query(Node* node,int L,int R,int pos) {
	if (pos>R || L>pos) return -1;
	if (L==R) {
		return node->val;
	}
	int mid=(L+R)>>1;
	if (pos<=mid) {
		if (node->lc==NULL) return -1;
		else return query(node->lc,L,mid,pos);
	}
	else if (pos>mid) {
		if (node->rc==NULL) return -1;
		else return query(node->rc,mid+1,R,pos);
	}
}

struct Query {
	Query* lc;
	Query* rc;
	int val;
	Query() {
		lc=rc=NULL;
		val=0;
	}
	void pull() {
		val=lc->val + rc->val;
	}
};

Query* Build(int L,int R) {
	Query* queRy = new Query();
	if (L==R) {
		queRy->val = cnt[L];
		return queRy;
	}
	int mid=(L+R)>>1;
	queRy->lc=Build(L,mid);
	queRy->rc=Build(mid+1,R);
	queRy->pull();
	return queRy;
}

void modify(Query* quEry,int L,int R,int pos,int val) {
	if (L==R) {
		quEry->val=val;
		return;
	}
	int mid=(L+R)>>1;
	if (pos<=mid) modify(quEry->lc,L,mid,pos,val);
	else modify(quEry->rc,mid+1,R,pos,val);
	quEry->pull();
}

int QUERY(Query* quEry,int L,int R,int l,int r) {
	if (L>r || l>R) return 0;
	else if (l<=L && R<=r) {
		return quEry->val;
	}
	int mid=(L+R)>>1;
	return QUERY(quEry->lc,L,mid,l,r)+QUERY(quEry->rc,mid+1,R,l,r);
}

const int MAX_A = 1e09 + 2;

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		memset(dp,0,sizeof(dp));
		memset(dp2,0,sizeof(dp2));
		Node* root = new Node();
		for (int x=0;n>x;x++) {
			scanf("%d",&a[x]);
			b.push_back(a[x]);
		}
		sort(b.begin(),b.end());
		b.resize(unique(b.begin(),b.end()) - b.begin());
		for (int x=0;n>x;x++) {
			a[x] = lower_bound(b.begin(),b.end(),a[x]) - b.begin();
			a[x]+=1;
			int val=a[x];
			int pos=query(root,1,MAX_A,val);
//			cout<<"pos="<<pos<<endl;
			if (pos==-1) {
				dp[x]=1;
				modify(root,1,MAX_A,val,x);
			}
			else {
				dp[x]=dp[pos]+1;
				modify(root,1,MAX_A,val,x);
			}
		}
		for (int x=n-1;x>=0;x--) {
			int val=a[x];
			int pos=query(root,1,MAX_A,val);
			if (pos==-1) {
				dp2[x]=1;
				modify(root,1,MAX_A,val,x);
			}
			else {
				dp2[x]=dp2[pos]+1;
				modify(root,1,MAX_A,val,x);
			}
		}
		memset(cnt,0,sizeof(cnt));
//		for (int x=0;n>x;x++) cout<<dp[x]<<endl;
//		for (int x=0;n>x;x++) cout <<dp2[x]<<endl;
		long long ans=0;
		for (int x=0;n>x;x++) cnt[dp2[x]]++;
		Query* qUery = Build(1,n);
		for (int x=0;n>x;x++) {
//			cout<<"x="<<x<<" ; ans="<<ans<<endl;
			modify(qUery,1,n,dp2[x],(--cnt[dp2[x]]));
			if (dp[x]!=1)ans+= QUERY(qUery,1,n,1,dp[x]-1);
		}
		printf("%I64d\n",ans);
	}
}