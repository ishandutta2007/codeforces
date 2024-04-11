#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cassert>
#include <set>
#include <map>

#define ll long long
#define dbl long double

using namespace std;
int t;


const long long MOD = 998244353;
struct Node {
	Node() {}
	Node(int x) {
		rid = x;
	}
	vector<Node*> res;
	int rid;
	bool par;
};

string s;
int nid;
pair<Node*, int> create(int start) {
	int c = 0;
	bool par = false;
	Node *n = new Node();
	int i;
	for (i = start + 1; i < s.size(); i++)
	{
		if (s[i] == ' ')
			continue;
		if (s[i] == '(') {
			auto ans = create(i);
			n->res.push_back(ans.first);
			i = ans.second;
			continue;
		}
		if (s[i] == 'P') {
			par = true;
			continue;
		}
		if (s[i] == '*') {
			n->res.push_back(new Node(nid++));
		}
		if (s[i] == ')')
			break;
	}
	n->par = par;
	return make_pair(n, i);
}

vector<int> getnans(Node* node) {
	if (node->res.empty()) {
		vector<int> v;
		v.push_back(node->rid);
		return v;
	}
	if (node->par) {
		vector<int> v, v1;
		for (size_t i = 0; i < node->res.size(); i++)
		{
			v1 = getnans(node->res[i]);
			if (v1.size() > v.size())
				swap(v, v1);
			for (size_t i = 0; i < v1.size(); i++)
			{
				v.push_back(v1[i]);
			}
		}
		return v;
	}
	else {
		vector<int> v, v1;
		for (size_t i = 0; i < node->res.size(); i++)
		{
			v1 = getnans(node->res[i]);
			if (v.empty() || v.size() > v1.size())
				v = v1;
		}
		return v;
	}
}
void solve(int testid) {
	nid = 0;
	int x;
	cin >> x;
	getline(cin, s);
	if (s.size() == 2) {
		cout << "REVOLTING " << x << endl;
		return;
	}
	Node *n = create(1).first;
	vector<ll> rs(nid);
	vector<int> v = getnans(n);
	for (size_t i = 0; i < v.size(); i++)
	{
		rs[v[i]] = x;
		rs[v[i]] *= v.size();
	}
	cout << "REVOLTING ";
	for (size_t i = 0; i < rs.size(); i++)
	{
		cout << rs[i] << " ";
	}
	cout << endl;
	return;
}

int main() {
	t = 1;
	cin >> t;
	for (size_t i = 0; i < t; i++)
	{
		solve(i + 1);
	}
	return 0;
}
/*

*/