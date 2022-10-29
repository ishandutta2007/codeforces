#include <iostream>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <set>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int MAX_N = 1e5 + 6;
const LL INF = 1e15 + 6;

pii a[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		multiset<int> s;
		LL sum=0;
		for (int i=1;n>=i;i++) {
			scanf("%d",&a[i].first);
		}
		for (int i=1;n>=i;i++) {
			scanf("%d",&a[i].second);
			sum += a[i].second;
			s.insert(a[i].second);
		}
		sort(a+1,a+n+1);
		if (n==1) {
			puts("0");
			continue;
		}
		a[n+1] = make_pair(0,0);
		LL mn = INF;
		LL _=0;
		for (int i=n;i>=1;) {
			int j=i;
			while (a[j].first == a[i].first) {
				j--;
			}
			j++;
			for (int k=i;k>=j;k--) {
				s.erase(s.find(a[k].second));
				sum -= a[k].second;
			}
			int need=i-j;
//			cout<<"i = "<<i<<" , j = "<<j<<" , need = "<<need<<endl;
			if (s.empty()) {
				mn = min(mn,sum+_);
				break;
			}
			auto tmp=s.end();
			--tmp;
			LL minus=0;
			while (need-- && !s.empty()) {
				if (tmp==s.begin()) {
					minus += (*tmp);
					break;
				}
				minus += (*tmp);
				--tmp;
			}
			
//			cout<<"i = "<<i<<" , j = "<<j<<" , sum = "<<sum<<" , minus = "<<minus<<" , _ = "<<_<<endl;
			mn = min(mn,sum-minus+_);
			for (int k=i;k>=j;k--) {
				_ += a[k].second;
			}
			i=j-1;
		}
		printf("%I64d\n",mn);
	}
}