#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int N = 500000;
int n;
string s[3];

struct Node {
	int c;
	bool lr; //  top left -> top right and bottom left -> bottom right
	bool lft2, rght2;
	Node(){}
	Node(int a, bool b, bool e, bool f){c=a;lr=b;lft2=e;rght2=f;}
	void print(){
		cerr << "c: " << c << endl << "lr: " << lr << endl << "lft2: " << lft2 << endl << "rght2: " << rght2 << endl;
	}
} nodes[4 * N];

vector<Node> base = {
	Node(0, 0, 0, 0),
	Node(1, 0, 0, 0),
	Node(1, 0, 0, 0),
	Node(1, 0, 0, 0),
	Node(1, 0, 0, 0),
	Node(2, 1, 0, 0),
	Node(1, 0, 0, 0),
	Node(1, 0, 1, 1)
};

vector<int> dc = {
	0,
	1,
	1,
	1,
	1,
	-1,
	1,
	-1
};

Node merge(Node a, Node b, int r){
	if (b.c == -1) return a;
	if (a.c == -1) return b;
	bool tp = (s[0][r] == '1') && (s[0][r-1] == '1');
	bool mid = (s[1][r] == '1') && (s[1][r-1] == '1');
	bool bot = (s[2][r] == '1') && (s[2][r-1] == '1');

	int c = (tp * 4 + mid * 2 + bot);

	if (dc[c] != -1) {
		return Node(
			a.c + b.c - dc[c],
			a.lr && b.lr,
			a.lft2,
			b.rght2
		);
	}

	bool lft2 = a.lft2 || (a.lr && b.lft2);
	bool rght2 = b.rght2 || (b.lr && a.rght2);

	int ddc = 0;
	if (a.rght2){
		if (b.lft2) {
			ddc = 1;
		} else {
			ddc = 2;
		}
	} else {
		if (b.lft2) {
			ddc = 2;
		} else {
			ddc = 2;
		}
	}

	return Node(
		a.c + b.c - ddc,
		a.lr & b.lr,
		lft2,
		rght2
	);
}

void build(int l=0, int r=-1, int v=1){
	if (r == -1) r = n;
	if (l + 1 == r) {
		nodes[v] = base[(s[0][l]=='1') * 4 + (s[1][l] == '1')*2+(s[2][l]=='1')];
		// cout << l << " " << r << endl;
		// nodes[v].print();
		return;
	}
	int m = (l + r) / 2;
	build(l, m, v*2);
	build(m, r, v*2+1);
	nodes[v] = merge(nodes[v*2], nodes[v*2+1], m);
	// cout << l << " " << r << endl;
	// nodes[v].print();
}

Node query(int ql, int qr, int l=0, int r=-1, int v=1){
	if (r == -1) r = n;
	if (ql <= l && qr >= r) return nodes[v];
	if (qr <= l || ql >= r) return Node(-1, 0, 0, 0);
	int m = (l + r) / 2;
	return merge(query(ql, qr, l, m, 2*v), query(ql, qr, m, r, 2*v+1), m);
}

void solve(int test_ind){
	cin >> n;
	cin >> s[0] >> s[1] >> s[2];
	build();
	int q;
	cin >> q;
	for (int i=0;i<q;++i){
		int l, r;
		scanf("%d%d", &l, &r);
		l--;
		printf("%d\n", query(l, r).c);
	}
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}