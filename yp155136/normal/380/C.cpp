//XXXXXYYYYZZZZ  

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <assert.h>
using namespace std;

struct VAL {
	int type;
	int num;
	void change(int b,int c) {
		type=b;
		num=c;
	}
};

struct Val {
	VAL pre;
	VAL suf;
	int ans;
	void change_pre(int type,int num) {
		pre.change(type,num);
	}
	void change_suf(int type,int num) {
		suf.change(type,num);
	}
	void change_ans(int Ans) {
		ans = Ans;
	}
	int pre_type() {
		return pre.type;
	}
	int pre_num() {
		return pre.num;
	}
	int suf_num() {
		return suf.num;
	}
	int suf_type() {
		return suf.type;
	}
	int get_ans() {
		return ans;
	}
};

Val empty;

bool EMPTY(Val val){
	if (val.ans==2147483647) return true;
	else return false;
} 

Val PULL(Val a, Val b) {
	if (EMPTY(a)) return b;
	else if (EMPTY(b)) return a;
	Val val;
	int ans=a.get_ans() + b.get_ans();
	int type;
	int num;
	if (a.suf_type() == b.pre_type()) {
		if (a.pre_type() == a.suf_type() && b.pre_type()==b.suf_type()) { // >> + >> or << + << or 00+00 
//			puts("in-3");
			assert(a.pre_num() == a.suf_num());
			type=a.pre_type();
			num=a.pre_num() + b.pre_num();
			if (type==0) num=0;
			val.change_ans(ans);
			val.change_pre(type,num);
			val.change_suf(type,num);
		}
		else if (b.pre_type()==b.suf_type()) {   // >><< + << !!!
//			puts("in-2");
			assert(a.pre_type() == -1);
			val.change_pre(a.pre_type(),a.pre_num());
			val.change_ans(ans);
			assert(a.suf_type() == 1);
			val.change_suf(a.suf_type(),a.suf_num() + b.pre_num());
		}
		else if (a.pre_type()==a.suf_type()) {  // > + ><
			val.change_ans(ans);
			val.change_pre(a.pre_type(),a.pre_num()+b.pre_num());
			val.change_suf(b.suf_type(),b.suf_num());
		}
	}
	else if (a.suf_type()==0) {
		assert(a.pre_type() == 0);
		val.change_ans(ans);
		val.change_pre(b.pre_type(), b.pre_num());
		val.change_suf(b.suf_type(), b.suf_num());
	}
	else if (b.pre_type()==0) {
		assert(b.suf_type() == 0);
		val.change_ans(ans);
		val.change_pre(a.pre_type(), a.pre_num());
		val.change_suf(a.suf_type(), a.suf_num());
	}
	else if (a.suf_type()==1) { //<< + >><< or << + >> or >><< + >> or >><< + >>><<
		assert(b.pre_type()==-1);
		if (b.suf_type()==1) {  //case (>>)<< + >><<
			if (a.suf_num() > b.pre_num()) { //(>>)<< + ><< 
				ans+=b.pre_num();
				val.change_ans(ans);
				if (a.pre_type() == 1)val.change_pre(a.pre_type(),a.suf_num() - b.pre_num() + b.suf_num());
				else val.change_pre(a.pre_type(),a.pre_num());
				val.change_suf(b.suf_type(),a.suf_num() - b.pre_num() + b.suf_num());
			}
			else if (a.suf_num() < b.pre_num()) { //(>>)<< + >>><<
				ans+=a.suf_num();
				val.change_ans(ans);
				if (a.pre_type()==1) val.change_pre(b.pre_type(),b.pre_num() - a.suf_num());
				else if(a.pre_type()==-1) val.change_pre(a.pre_type(), a.pre_num() + b.pre_num() - a.suf_num());
				val.change_suf(b.suf_type(),b.suf_num());
			}
			else if (a.suf_num() == b.pre_num()) {
				ans+=a.suf_num();
				val.change_ans(ans);
				if (a.pre_type()==-1) val.change_pre(a.pre_type(),a.pre_num());
				else if (a.pre_type()==1) val.change_pre(b.suf_type(),b.suf_num());
				val.change_suf(b.suf_type(),b.suf_num());
			}
		}
		else if (b.suf_type() == -1) { //(>>)<< + >>
			if (a.suf_num() > b.pre_num()) { //(>>)<< + > 
				ans+=b.pre_num();
				val.change_ans(ans);
				if (a.pre_type() == 1)val.change_pre(a.pre_type(),a.suf_num() - b.pre_num());
				else if (a.pre_type() == -1)val.change_pre(a.pre_type(),a.pre_num());
				val.change_suf(a.suf_type(),a.suf_num()-b.pre_num());
			}
			else if (a.suf_num() < b.pre_num()) { //(>>)<< + >>>
				ans+=a.suf_num();
				val.change_ans(ans);
				int num=b.pre_num() - a.suf_num();
				if (a.pre_type()==1) ;
				else if(a.pre_type()==-1) num+=a.pre_num();
				val.change_pre(b.pre_type(),num);
				val.change_suf(b.suf_type(),num);
			}
			else if (a.suf_num() == b.pre_num()) { // >< + >
				ans += a.suf_num();
				val.change_ans(ans);
				if (a.pre_type()==-1) val.change_pre(a.pre_type(),a.pre_num());
				else if (a.pre_type()==1) val.change_pre(0,0);
				if (a.pre_type()==-1) val.change_suf(a.pre_type(),a.pre_num());
				else if (a.pre_type()==1) val.change_suf(0,0);
			}
		}
		
	}
	else if (b.suf_type() == 1) {  //>>>+<<
		val.change_pre(a.pre_type(),a.pre_num());
		val.change_suf(b.suf_type(),b.suf_num());
		val.change_ans(ans);
	}
	return val;
}

struct Node {
	Node* lc;
	Node* rc;
	Val val;
	Node() {
		lc = rc=NULL;
		val.change_pre(0,0);
		val.change_suf(0,0);
		val.change_ans(0);
	}
	void pull() {
		val = PULL(lc->val,rc->val);
	}
};


string s;

Node* Build(int L,int R) {
	Node* node = new Node();
	if (L==R) {
		if (s[L]=='(') {
			node->val.change_pre(1,1);
			node->val.change_suf(1,1);
			node->val.change_ans(0);
		}
		else {
			node->val.change_pre(-1,1);
			node->val.change_suf(-1,1);
			node->val.change_ans(0);
		}
		return node;
	}
	int mid=(L+R)>>1;
	node->lc=Build(L,mid);
	node->rc=Build(mid+1,R);
	node->pull();
//	cout<<L<<"~"<<R<<" : "<<node->val.get_ans()<<endl;
//	cout<<"pre_type = "<<node->val.pre_type() << " , num = "<<node->val.pre_num()<<endl;
//	cout<<"suf_type = "<<node->val.suf_type() << " , num = "<<node->val.suf_num()<<endl;
	
	
	return node;
}


Val query(Node* node,int L,int R,int l,int r) {
	if (L>r || l>R) return empty;
	else if (l<=L && R<=r) {
		Val c = node->val;
//		cout<<L<<"~"<<R<<" : ans = "<<c.get_ans()<<endl;
//		cout<<"pre_type = "<<c.pre_type() << " , num = "<<c.pre_num()<<endl;
//		cout<<"suf_type = "<<c.suf_type() << " , num = "<<c.suf_num()<<endl;
		return node->val;
	}
	int mid=(L+R)>>1;
	Val a=query(node->lc,L,mid,l,r);
	Val b=query(node->rc,mid+1,R,l,r);
	Val c=PULL(a,b);
//	cout<<L<<"~"<<R<<" : ans = "<<c.get_ans()<<endl;
//	cout<<"pre_type = "<<c.pre_type() << " , num = "<<c.pre_num()<<endl;
//	cout<<"suf_type = "<<c.suf_type() << " , num = "<<c.suf_num()<<endl;
	
	return c;
//	return PULL(query(node->lc,L,mid,l,r),query(node->rc,mid+1,R,l,r));
}

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string tmp;
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	while (cin >> tmp) {
		empty.change_pre(0,0);
		empty.change_suf(0,0);
		empty.change_ans(2147483647);
		s = " " + tmp;
		int n=tmp.size();
		Node* root = Build(1,n);
		int m;
		cin >> m;
		for (int x=0;m>x;x++) {
			int i,j;
			cin >> i >> j;
			cout << query(root,1,n,i,j).ans * 2<<endl;
		}
	}
}