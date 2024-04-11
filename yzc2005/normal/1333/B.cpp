//I love Violet Evergarden!!!
#include <bits/stdc++.h>
using namespace std;


int t, n, a[100005], b[100005];

int main() {
	scanf("%d", &t); while(t--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		for(int i = 1; i <= n; ++i) scanf("%d", &b[i]);
		bool f1 = 0, f2 = 0, ok = 1;
		for(int i = 1; i <= n; ++i) {
			if(a[i] != b[i]) {
				if(a[i] < b[i]) {
					if(!f1) ok = 0;
				} else {
					if(!f2) ok = 0;
				}
			}
			if(a[i] > 0) f1 = 1;
			if(a[i] < 0) f2 = 1;
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}