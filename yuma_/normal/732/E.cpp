#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

struct Node{
	int power;
	int id;
};
bool operator<(const Node&l, const Node&r) {
	return l.power < r.power;
}
bool operator ==(const Node&l, const Node&r) {
	return l.power == r.power;
}

int main() {
	vector<Node> nss;
	map<int, vector<int>>ncs;
	vector<int>pluss, connects;
	int N, M;
	{ cin >> N >> M;
		pluss.resize(M);
		connects.resize(N);
		vector<Node>cs, ss;
		for (int i = 0; i < N; ++i) {
			int a; scanf("%d",&a);
			ncs[a].push_back(i);
		}
		for (int i = 0; i < M; ++i) {
			int b; scanf("%d", &b);
			ss.push_back(Node{ b,i });
		}
		sort(cs.begin(), cs.end());
		sort(ss.begin(), ss.end());

		nss = ss;
	}
	
	int ans=0, socket=0;
	int num = 0;
	while (!ncs.empty()&&!nss.empty()) {
		vector<int>livess(nss.size(), true);
		for (int i = 0; i < nss.size(); ++i) {
			const int power = nss[i].power;
			auto it = ncs.find(power);
			if (it != ncs.end()) {
				livess[i] = false;
				pluss[nss[i].id] = num;
				connects[it->second.back()] = nss[i].id+1;
				it->second.pop_back();
				if (it->second.empty()) {
					ncs.erase(it->first);
				}
				ans++;
				socket += num;
			}
			else {
				if (ncs.begin()->first>power) {
					livess[i] = false;
				}
			}
		}
		vector<Node>nextss;
		for (int i = 0; i < nss.size(); ++i) {
			if (livess[i]) {
				auto ss = move(nss[i]);
				ss.power = (1 + ss.power) / 2;
				nextss.push_back(ss);
			}
		}
		nss = nextss;
		num++;

	}
	printf("%d %d\n", ans, socket);
	for (int i = 0; i < M; ++i) {
		printf("%d", pluss[i]);
		if (i == M - 1)printf("\n");
		else printf(" ");
	}
	for (int i = 0; i < N; ++i) {
		printf("%d", connects[i]);
		if (i == N - 1)printf("\n");
		else printf(" ");
	}
	return 0;
}