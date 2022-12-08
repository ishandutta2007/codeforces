#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#define MOD 1000000007
#define forn(a, n) for(int a = 0; a<(int) (n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define EPS 0.000000000001
typedef long long tint;
using namespace std;

int main()
{
	//freopen("f.out", "w", stdout);
	vector<string> program(10000);
	string s;
	cin >> s;
	int buf = 0, curl = 0;
	forn(i, s.size()) {
		int goal = s[i];
		while(buf != goal+1) {
			program[curl] += ".X.";
			program[curl+1] += "...";
			buf = (buf + 255)%256;
		}
		curl += 2;
		
		buf--;
		program[curl] += ".X.";
		program[curl+1] += ".X.";
		program[curl+2] += "...";
		curl += 3;
	}
	int bestl = 0;
	forn(i, curl) {
		bestl = max(bestl, (int) program[i].size());
	}
	
	forn(i, curl) {
		while((int) program[i].size() < bestl) {
			program[i] += '.';
		}
		cout << program[i] << endl;
	}
	return 0;
}