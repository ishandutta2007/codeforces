#include <iostream>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <map>
using namespace std;

struct Treap {
	Treap *lc;
	Treap *rc;
	int pri;
	int key;
	int sn;
	Treap(int _key) {
		lc=rc=NULL;
		pri=rand();
		key= _key;
		sn = 0;
	}
};

int Sn(Treap *t) {
	return t?t->sn:0;
}

void pull(Treap *t) {
	t->sn = Sn(t->lc) + Sn(t->rc) +1;
}

Treap* merge(Treap *a,Treap *b) {
	if (!a || !b) return a?a:b;
	else if (a->pri > b->pri) {
		a->rc = merge(a->rc,b);
		pull(a);
		return a;
	}
	else {
		b->lc = merge(a,b->lc);
		pull(b);
		return b;
	}
}

void split(Treap *t,int x,Treap *&a,Treap *&b) {
	if (!t) a=b=NULL;
	else if (t->key<=x) {
		a=t;
		split(t->rc,x,a->rc,b);
		pull(a);
 	}
 	else {
		b=t;
		split(t->lc,x,a,b->lc);
		pull(b);
 	}
}

map<int,int> cnt;

int main () {
	srand(time(NULL));
	int q;
	while (cin >> q) {
		Treap* root=new Treap(0);
		for (int x=0;q>x;x++) {
			char a;
			int b;
			cin >> a >> b;
			if (a=='+') {
				cnt[b]++;
				if (cnt[b]!=1) continue;
				Treap *tl, *tr;
				split(root,b-1,tl,root);
				split(root,b,root,tr);
				root = merge(root,new Treap(b));
				root=merge(merge(tl,root),tr); 
//				cout<<"insert "<<b<<endl;
			}
			else if (a=='-') {
				cnt[b]--;
				if (cnt[b] != 0) continue;
				Treap *tl, *tr;
				split(root,b-1,tl,root);
				split(root,b,root,tr);
				root = NULL;
				root=merge(merge(tl,root),tr); 
			}
			else if (a=='?'){
				int t=0;
				for (int x=30;x>=0;x--) {
//					cout<<"t="<<t<<endl;
					int tmp=(1LL<<x);
//					cout<<"tmp="<<tmp<<endl;
//					cout<<"b="<<b<<" , t+tmp="<<t+tmp<<" , t="<<t<<endl;
					if ((b ^ (t+tmp) )> (b^t)) {
//						cout<<"in\n";
						Treap *tl,*tr;
//						if (root==NULL) puts("GGGGGG");
						split(root,t+tmp-1,tl,root);
//						if (root!=NULL) cout<<root->key<<endl;
						split(root,t+2*(tmp-1)+1,root,tr);
						if (root != NULL) {
//							cout<<"key : "<<root->key << endl;
							t += tmp;
						}
						else {
							t=t;
						}
						root=merge(merge(tl,root),tr);
					}
					else {
//						cout<<"in2\n";
						Treap *tl,*tr;
						split(root,t-1,tl,root);
//						if (root!=NULL) cout<<root->key<<endl;
						split(root,t+tmp-1,root,tr);
						if (root != NULL) {
							t =t;
						}
						else {
							t+=tmp;
						}
						root=merge(merge(tl,root),tr);
					}
				}
				printf("%d\n",b^t);
			}
		}
	}
}