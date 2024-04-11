#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_N = 1e5 +6;

int main () {
	int n,t,k,d;
	while (cin >> n >> t >> k >> d) {
		int need_num = (n)/k + (n%k==0?0:1);
		int need_one_time = t*need_num;
		if (need_num == 1) puts("NO");
		else if (t*(need_num-1) > d) puts("YES");
		else puts("NO");
	}
}