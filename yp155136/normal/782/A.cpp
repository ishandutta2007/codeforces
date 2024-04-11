#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;

typedef long long LL;
const int MAX_N = 1e5 + 6;

LL a[MAX_N];

int main () {
	int n;
	while (cin >>n) {
		int mx=0;
		int cnt=0;
		for (int i=1;2*n>=i;i++) {
			int x;
			cin >>x;
			if (a[x]) cnt--;
			else {
				a[x]=1;
				cnt++;
			}
			mx = max(mx,cnt);
		}
		cout<<mx<<endl;
	}
}