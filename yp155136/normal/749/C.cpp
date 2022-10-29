#include <iostream>
#include <stdio.h>
#include <utility>
#include <set>
using namespace std;

typedef pair<int,int> pii;
const int MAX_N = 2e5 + 6;
const int INF = 1e9 + 7;

pii operator+(const pii &p1,const pii &p2) {
	return make_pair(min(p1.first,p2.first),min(p1.second,p2.second));
}

pii empty=make_pair(INF,INF);

struct Node {
	Node *lc,*rc;
	pii val;
	Node() {
		lc=rc=NULL;
		val = empty;
	}
	void pull(){
		val = lc->val + rc->val;
	}
};

int a[MAX_N];

Node* Build(int L,int R) {
	Node* node= new Node();
	if (L==R) {
		if (a[L]==1) node->val = make_pair(L,INF);
		else node->val = make_pair(INF,R);
		return node;
	}
	int mid=(L+R)>>1;
	node->lc=Build(L,mid);
	node->rc=Build(mid+1,R);
	node->pull();
	return node;
}

void modify(Node* node,int L,int R,int pos) {
	if (L==R) {
		node->val = empty;
		return;
	}
	int mid=(L+R)>>1;
	if (pos<=mid) modify(node->lc,L,mid,pos);
	else modify(node->rc,mid+1,R,pos);
	node->pull();
	return;
}

pii query(Node* node,int L,int R,int l,int r) {
	if (l>R || L>r) return empty;
	else if(l<=L && R<=r) return node->val;
	int mid=(L+R)>>1;
	return query(node->lc,L,mid,l,r) + query(node->rc,mid+1,R,l,r);
}

int main () {
	int n;
	while (cin >>n) {
		string s;
		cin >> s;
		if (n==1) {
			cout<<s<<endl;
			continue;
		}
		else if (n==2) {
			cout<<s[0]<<endl;
			continue;
		}
		s=" "+s;
		set<int> st;
		for (int i=1;n>=i;i++) {
			a[i] = (s[i]=='D'?1:-1);
			st.insert(i);
		}
		Node* root=Build(1,n);
		char ans='A';
		while (1) {
			for (auto i:st) {
				pii ret=query(root,1,n,i+1,n);
				pii ret2=query(root,1,n,1,i-1);
				if (a[i]==1) {
					if (ret.second == INF && ret2.second == INF) {
						ans = 'D';
						break;
					}
					else if (ret.second != INF) {
						st.erase(ret.second);
						modify(root,1,n,ret.second);
					}
					else if (ret2.second!=INF) {
						st.erase(ret2.second);
						modify(root,1,n,ret2.second);
					}
				}
				else if (a[i]==-1) {
					if (ret.first == INF && ret2.first == INF) {
						ans = 'R';
						break;
					}
					else if (ret.first != INF) {
						st.erase(ret.first);
						modify(root,1,n,ret.first);
					}
					else if (ret2.first!=INF) {
						st.erase(ret2.first);
						modify(root,1,n,ret2.first);
					}
				}
			}
			if (ans !='A') break;
		}
		cout<<ans<<endl;
	}
}