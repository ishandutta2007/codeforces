#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt" > "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\b.answer"
int main() {
	int N; scanf("%d", &N);
	priority_queue<int,vector<int>,greater<int>>que;
	vector<pair<string,int>>ps;
	for (int i = 0; i < N; ++i) {
		char c[20];
		scanf("%s", c);
		string st; int a; st = c;
		if (st != "removeMin")scanf("%d", &a);
		if (st == "insert") {
			que.push(a);
			ps.emplace_back("insert", a);
		}
		else if (st == "getMin") {
			while (1) {
				if (que.empty()) {

					ps.emplace_back("insert", a);
					que.push(a);
					ps.emplace_back("getMin", a);
					break;
				}
				else {
					const int atop = que.top();
					if (atop == a) {
						ps.emplace_back("getMin", a);
						break;
					}
					else if (atop > a) {
						ps.emplace_back("insert", a);
						que.push(a);
						ps.emplace_back("getMin", a);
						break;
					}
					else {
						que.pop();
						ps.emplace_back("removeMin", 0);
					}
				}
			}
			
		}
		else {
			if (que.empty()) {
				ps.emplace_back("insert", 0);
				que.push(0);
			}
			const int num = que.top();
			ps.emplace_back("removeMin",num);
			que.pop();
		}
	}
	printf("%d\n", ps.size());
	for (auto p : ps) {
		printf("%s", p.first.c_str());
		if (p.first != "removeMin") {
			printf(" %d", p.second);
		}
		printf("\n");
	}
	return 0;
}