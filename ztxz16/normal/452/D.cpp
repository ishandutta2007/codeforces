#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <string>
#define PQ priority_queue
#define OO 2147483647
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define mp make_pair

int FASTBUFFER;

using namespace std;

int k, n1, n2, n3, t1, t2, t3, ans;
int wait, s11, s12, s21, s22, s31, s32;

PQ <pair <int, int> > q;

int main() {
	scanf("%d %d %d %d %d %d %d", &k, &n1, &n2, &n3, &t1, &t2, &t3);
	wait = max(0, k - n1);
	for (int i = 1; i <= min(k, n1); i++) {
		q.push(mp(-t1, 1));
	}
	
	s11 = n1;
	while (q.size()) {
		pair <int, int> now = q.top();
		ans = -now.first;
		q.pop();
		if (now.second == 1) {
			s11--;
			if (s21 < n2) {
				q.push(mp(now.first - t2, 2));
				s21++;
			} else {
				s22++;
			}
			
			if (wait) {
				wait--;
				s11++;
				q.push(mp(now.first - t1, 1));
			}
		} else if (now.second == 2) {
			s21--;
			if (s31 < n3) {
				q.push(mp(now.first - t3, 3));
				s31++;
			} else {
				s32++;
			}
			
			if (s22) {
				s22--;
				s21++;
				q.push(mp(now.first - t2, 2));
			}
		} else {
			s31--;
			if (s32) {
				s32--;
				s31++;
				q.push(mp(now.first - t3, 3));
			}
		}
	}
	
	printf("%d\n", ans);
	return 0;
}