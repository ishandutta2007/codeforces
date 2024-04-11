#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <map>
using namespace std;

const int MAX_N = int(1e5);

struct Truck {
	int v, c, l, r, id;
	void read() {
		scanf("%d%d%d%d", &v, &c, &l, &r);
	}
	int total() {
		return c + l + r;
	}
};

int n;

struct Answer {
	Answer*prev;
	Truck last;
	int v;
	Answer(Answer*prev, Truck last) :
			prev(prev), last(last) {
		v = prev->v + last.v;
	}
	Answer(Truck truck) :
			last(truck) {
		prev = 0;
		v = last.v;
	}
};

int main() {
	map<int, vector<Truck> > byTotal;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		Truck t;
		t.read();
		t.id = i + 1;
		byTotal[t.total()].push_back(t);
	}

	Answer* ans = 0;
	for (map<int, vector<Truck> >::iterator it = byTotal.begin(); it != byTotal.end(); ++it) {
		vector<Truck> trucks = it->second;
		int total = it->first;
		//(l,c,r)->(l',c',r')
		//l+c=l'
		map<int, Answer*> dp;
		for (vector<Truck>::iterator e = trucks.begin(); e != trucks.end(); ++e) {
			if (dp.count(e->l)) {
				Answer*c = dp[e->l];
				Answer*&ref = dp[e->l + e->c];
				if (!ref || c->v + e->v > ref->v) {
					ref = new Answer(c, *e);
				}
			}
			if (e->l == 0) {
				Answer*&ref = dp[e->l + e->c];
				if (!ref || e->v > ref->v) {
					ref = new Answer(*e);
				}
			}
		}

		if (dp.count(total)) {
			Answer* tmp = dp[total];
			if (ans == 0 || tmp->v > ans->v) {
				ans = tmp;
			}
		}
	}

	vector<int> output;
	while (ans != 0)
		output.push_back(ans->last.id), ans = ans->prev;
	reverse(output.begin(), output.end());
	cout << output.size() << endl;
	for (int i = 0; i < output.size(); ++i) {
		cout << output[i] << " ";
	}
	cout << endl;
	return 0;
}