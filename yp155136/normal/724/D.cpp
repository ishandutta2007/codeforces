#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_N = 1e5 + 6;

struct Node {
	Node *lc,*rc;
	int val;
	int tag;
	Node() {
		lc=rc=NULL;
		val=0;
		tag=0;
	}
	void pull() {
		val = lc->val + rc->val;
	}
};

void push(Node* node,int L,int R) {
	if (node->tag == 0) return;
	else if (L!= R) {
		int mid=(L+R)>>1;
		node->lc->tag += node->tag;
		node->rc->tag += node->tag;
		node->lc->val = (mid-L+1);
		node->rc->val = (R-mid);
	}
	node->tag = 0;
}

Node* Build(int L,int R) {
	Node* node = new Node();
	if (L==R) {
		return node;
	}
	int mid=(L+R)>>1;
	node->lc=Build(L,mid);
	node->rc=Build(mid+1,R);
	return node;
}

void modify(Node* node, int L,int R,int l,int r,int val) {
	if (l>R || L>r) return;
	else if (l<=L && R<=r) {
		node->tag = 1;
		node->val = (R-L+1);
		return;
	}
	push(node,L,R);
	int mid=(L+R)>>1;
	modify(node->lc,L,mid,l,r,val);
	modify(node->rc,mid+1,R,l,r,val);
	node->pull();
	return;
}

int query(Node* node,int L,int R,int l,int r) {
	if (l>R || L>r) return 0;
	else if (l<=L && R<=r) return node->val;
	push(node,L,R);
	int mid=(L+R)>>1;
	return query(node->lc,L,mid,l,r) + query(node->rc,mid+1,R,l,r);
}

int sz[173];

int main () {
	int m;
	while (scanf("%d",&m) != EOF) {
		memset(sz,0,sizeof(sz));
		string i;
		cin >>i;
		i=" "+i;
		string ans="";
		int idd=0;
		int len=i.size()-1;
		for (int x=1;len>=x;x++) {
			sz[i[x]]++;
		}
		Node* root = Build(1,len);
		for (char j='a';'z'>=j;j++) {
			vector<int> v;
			for (int x=1;len>=x;x++) {
				if (i[x] == j) {
//					cout<<"x = "<<x<<" , L = "<<max(1,x-m+1)<<" R = "<<x<<endl;
//					cout<<"Q = "<<query(root,1,len,max(1,x-m+1),x)<<endl;
					if (query(root,1,len,max(1,x-m+1),min(x,len-m+1)) != min(x,len-m+1) - max(1,x-m+1) + 1) {
//						ans += " ";
//						ans[id++]=j;
//						modify(root,1,len,max(1,x-m+1),min(len,x+m-1),1);
//						cout<<"get in\n";
						v.push_back(x);
					}
				}
			}
			int id=0;
			int need = 0;
			for (auto iter=v.begin();iter!=v.end();iter++) {
				int tmp = *iter;
//				cout<<"tmp = "<<tmp<<endl;
				if(id == 0 &&min(tmp,len-m+1) - max(1,tmp-m+1)+1 -query(root,1,len,max(1,tmp-m+1),min(tmp,len-m+1) ) > 0 ) {
//					cout<<"in11\n";
					id = tmp;
					need = min(tmp,len-m+1) - max(1,tmp-m+1)+1 - query(root,1,len,max(1,tmp-m+1),min(tmp,len-m+1));
				}
				else if (id == 0) {
					;
				}
				else {
//					cout<<"tmp = "<<tmp<<" , L = "<<max(1,tmp-m+1)<<", R = "<<min(id,len-m+1)<<" , need = "<<need<<" , Q = "<<query(root,1,len,max(1,tmp-m+1),min(id,len-m+1))<<endl;
					if (min(id,len-m+1) -max(1,tmp-m+1)+1- query(root,1,len,max(1,tmp-m+1),min(id,len-m+1)) >= need) {
						id = tmp;
						need = min(tmp,len-m+1) - max(1,tmp-m+1)+1 - query(root,1,len,max(1,tmp-m+1),min(tmp,len-m+1));
					}
					else {
//						cout<<"in33\n";
//						cout<<"tmp = "<<tmp<<endl;
						modify(root,1,len,max(1,id-m+1),min(id,len-m+1),1);
						ans+=" ";
						ans[idd++] = j;
						if (query(root,1,len,max(1,tmp-m+1),min(tmp,len-m+1)) >= min(tmp,len-m+1) - max(1,tmp-m+1) + 1) {
							id=0;
							need = 0;
						}
						else {
							id = tmp;
							need = min(tmp,len-m+1) - max(1,tmp-m+1)+1 - query(root,1,len,max(1,tmp-m+1),min(tmp,len-m+1));
						}
					}
				}
			}
			if (id != 0 && query(root,1,len,max(1,id-m+1),min(id,len-m+1)) < min(id,len-m+1)-max(1,id-m+1)+1 ) {
//				cout<<"in\n";
//				cout<<"id = "<<id<<endl;
				modify(root,1,len,max(1,id-m+1),min(id,len-m+1),1);
//				cout<<query(root,1,len,max(1,id-m+1),min(len,id+m-1))<<endl;
				ans += " ";
				ans[idd++] = j;
			}
		}
		int cnt[173];
		memset(cnt,0,sizeof(cnt));
		char b=ans[0];
		for (int x=0;ans.size() > x;x++) {
			cnt[ans[x]] ++;
			if (ans[x] != b) {
				for (char j='a';ans[x]>j;j++) {
					for (int i=cnt[j];sz[j] > i;i++) {
						cout<<j;
						cnt[j]++;
					}
				}
			}
			cout<<ans[x];
			b=ans[x];
		}
		cout<<endl;
	}
}