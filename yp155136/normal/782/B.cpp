#include <iostream>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <iomanip>
using namespace std;

typedef long double ld;
typedef pair<int,int> pii;
const int MAX_N = 60006;

pii a[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int i=1;n>=i;i++) {
			scanf("%d",&a[i].first);
		}
		for (int i=1;n>=i;i++) {
			scanf("%d",&a[i].second);
		}
		sort(a+1,a+n+1);
		ld L=0.0,R=1e9+7;
		int cnt=1000;
		while (cnt--) {
			ld mid=(L+R)/2.0;
			ld left = a[1].first-a[1].second*mid;
			ld right=a[1].first+a[1].second*mid;
			bool flag=true;
			for (int i=2;n>=i;i++) {
				left = max(a[i].first-a[i].second*mid,left);
				right = min(a[i].first+a[i].second*mid,right);
			}
			if (right >= left) R=mid;
			else L=mid;
		}
		cout<<fixed<<setprecision(10)<<R<<endl;
	}
}