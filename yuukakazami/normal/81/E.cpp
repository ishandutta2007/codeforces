/*
 * E. Pairs.cpp
 *
 *  Created on: 2011-5-15
 *      Author: user
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <utility>
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;

typedef pair<int, int> ipair;

ipair operator+(const ipair&a, const ipair&b) {
	return make_pair(a.first + b.first, a.second + b.second);
}

ipair operator-(const ipair&a, const ipair&b) {
	return make_pair(a.first - b.first, a.second - b.second);
}

const int MAX_N_STUDENTS = 100000 + 10;

vector<ipair> ansPairs;
ipair ans;

struct Student {
	bool gender;
	vector<Student*> friendOf;
	Student*Friend;
	int index;
	void read(int _index);

	bool marked;
	ipair best, notTake;
	Student() :
		marked(false) {
	}
	Student*childTaken;

	void removeChild(Student*a) {
		friendOf.erase(find(friendOf.begin(), friendOf.end(), a));
	}

	void solveTree() {
		marked = true;
		childTaken = 0;
		best = notTake = make_pair(0, 0);
		foreach(iter,friendOf) {
			Student*c = *iter;
			c->solveTree();
			notTake = notTake + c->best;
			ipair delta = make_pair(1, gender != c->gender) - c->best
					+ c->notTake;
			if (delta > best) {
				best = delta;
				childTaken = c;
			}
		}
		best = best + notTake;
	}
	Student*findCycle() {
		Student*cur;
		for (cur = this; !cur->marked; cur = cur->Friend)
			cur->marked = true;
		return cur;
	}

	void build(bool isNotTaken, vector<ipair>&pairs) {
		foreach(iter,friendOf) {
			Student*c = *iter;
			if (isNotTaken) {
				c->build(false, pairs);
			} else {
				if (c == childTaken) {
					pairs.push_back(make_pair(index, c->index));
					c->build(true, pairs);
				} else {
					c->build(false, pairs);
				}
			}
		}
	}

	void solveCycle() {
		//it's on cycle
		vector<Student*> cycle;
		Student*cur = this;
		cycle.push_back(cur);
		cur = cur->Friend;
		while (cur != this) {
			cycle.push_back(cur);
			cur = cur->Friend;
		}

		ipair best = make_pair(0, 0);

		vector<ipair> way;
		Student*u = this;
		for (int i = 0; i < 2; ++i) {
			Student*w = u->Friend;
			w->removeChild(u);
			u->solveTree();
			if (u->best > best) {
				best = u->best;
				way.clear();
				u->build(false, way);
			}
			w->friendOf.push_back(u);
			u = w;
		}
		ans = ans + best;
		ansPairs.insert(ansPairs.end(), way.begin(), way.end());
	}
};

Student students[MAX_N_STUDENTS];
int nStudents;

void Student::read(int _index) {
	index = _index;
	int f;
	scanf("%d", &f);
	Friend = students + --f;
	int s;
	scanf("%d", &s);
	gender = s == 1;
	Friend->friendOf.push_back(this);
}

void readInput() {
	scanf("%d", &nStudents);
	for (int i = 0; i < nStudents; ++i) {
		students[i].read(i + 1);
	}
}

void printPair(ipair p) {
	printf("%d %d\n", p.first, p.second);
}

void work() {
	ans = make_pair(0, 0);
	ansPairs.clear();
	for (int i = 0; i < nStudents; ++i) {
		Student*me = students + i;
		if (me->marked)
			continue;
		me = me->findCycle();
		me->solveCycle();
	}

	printPair(ans);
	foreach(iter,ansPairs)
		printPair(*iter);
}

int main() {
	readInput();
	work();
}