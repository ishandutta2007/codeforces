#include <iostream>
#include <stdio.h>
#include <queue>
#include <set>
using namespace std;

const int MAX_N = 5e4 + 6;

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		set<int> s;
		priority_queue<int> pq;
		for (int x=1;n>=x;x++) {
			int i;
			scanf("%d",&i);
			pq.push(i);
			s.insert(i);
		}
		while (1) {
			int t=pq.top();
			int tmp=t;
			bool chg=false;
			while (tmp>0) {
				tmp/=2;
				if (tmp==0) break;
				else if (s.find(tmp) == s.end()) {
					pq.pop();
					pq.push(tmp);
					s.erase(t);
					s.insert(tmp);
					chg=true;
					break;
				}
			}
			if (!chg) break;
		}
		bool check=false;
		for (auto i=s.begin();i!=s.end();i++) {
			if (check) printf(" ");
			printf("%d",*i);
			check=true;
		}
		puts("");
	}
}