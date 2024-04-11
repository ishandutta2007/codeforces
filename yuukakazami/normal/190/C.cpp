#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <cstdlib>
using namespace std;

string next() {
	string s;
	if (!(cin >> s))
		return "";
	return s;
}

struct Node {
	Node*l, *r;
	Node() {
		l = r = 0;
	}
	void write() {
		if (l == 0) {
			printf("int");
		} else {
			printf("pair<");
			l->write();
			printf(",");
			r->write();
			printf(">");
		}
	}
};

int cnt;

Node*parse() {
	string s = next();
	if (s == "") {
		puts("Error occurred");
		exit(0);
	}
	if (s == "int") {
		++cnt;
		return new Node;
	} else {
		Node*t = new Node;
		t->l = parse();
		t->r = parse();
		return t;
	}
}

int main() {
//	freopen("in", "r", stdin);
	int n;
	cin >> n;

	cnt = 0;
	Node*t = parse();
	if (next() != "") {
		puts("Error occurred");
	} else {
		t->write();
		puts("");
	}
	return 0;
}