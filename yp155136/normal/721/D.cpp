#include <iostream>
#include <stdio.h>
#include <utility>
#include <cmath>
#include <queue>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
const int MAX_N = 2e5 + 6;

LL a[MAX_N];

int main (){
	int n,k;
	LL x;
	while (scanf("%d %d %I64d",&n,&k,&x) != EOF) {
		int minus=0;
		int _0=0;
		priority_queue<pii, vector<pii>, greater<pii> > pq;
		for (int i=1;n>=i;i++) {
			scanf("%I64d",&a[i]);
			pq.push(make_pair(abs(a[i]),i));
			minus += (a[i]<0);
			_0 += (a[i]==0);
		}
		while (k--) {
//			cout<<"minus = "<<minus<<" _0 = "<<_0 <<endl;
			pii tmp=pq.top();
			pq.pop();
			if (_0 > 1) {
				_0 --;
				a[tmp.second] -= x;
				minus++;
			}
			else if (_0 == 1) {
				if (minus%2==0) {
					a[tmp.second] -= x;
					minus++;
				}
				else {
					a[tmp.second] += x;
				}
				_0--;
			}
			else if (minus % 2 == 0) {
				if (a[tmp.second] <0 ) {
					a[tmp.second] += x;
					if (a[tmp.second] == 0) _0 ++;
					if (a[tmp.second] >= 0) minus--;
				}
				else {
					a[tmp.second] -= x;
					if (a[tmp.second] == 0) _0 ++;
					else if (a[tmp.second] < 0) minus++;
				}
			}
			else {
				if (a[tmp.second] <0 ) {
					a[tmp.second] -= x;
				}
				else {
					a[tmp.second] += x;
				}
			}
			pq.push(make_pair(abs(a[tmp.second]),tmp.second));
		}
		for (int i=1;n>=i;i++) {
			if (i!=1) printf(" ");
			printf("%I64d",a[i]);
		}
		puts("");
	}
}