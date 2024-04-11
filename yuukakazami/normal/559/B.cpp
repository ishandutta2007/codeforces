#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
using namespace std;

map<string, int> memos;
map<pair<int, int>, int> memop;

const int OFFSET = 1 << 25;

int getId(string str) {
	int n = str.size();
	if (n % 2) {
		if (memos.count(str))
			return memos[str];
		int me = memos.size();
		return memos[str] = me;
	}
	string a = str.substr(0, n / 2);
	string b = str.substr(n / 2, n / 2);
	int x = getId(a), y = getId(b);
	if (x > y)
		swap(x, y);
	pair<int, int> key = make_pair(x, y);
	if (memop.count(key))
		return memop[key];
	int me = memop.size() + OFFSET;
	return memop[key] = me;
}

int main() {
	string a, b;
	cin >> a >> b;
	if (getId(a) == getId(b)) {
		puts("YES");
	} else {
		puts("NO");
	}
}