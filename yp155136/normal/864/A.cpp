#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_N = 123;

int cnt[123];

int main () {
	int n;
	cin >> n;
	int tot=0;
	for (int i=0;n>i;i++) {
		int x;
		cin >> x;
		cnt[x]++;
		if (cnt[x] == 1) tot++;
	}
	if (tot == 2) {
		for (int i=0;MAX_N>i;i++) {
			if (cnt[i]) {
				if (cnt[i]*2 == n) {
					cout<<"YES\n";
					cout<<i;
					for (int j=i+1;MAX_N>j;j++) {
						if (cnt[j]){
							cout<<" "<<j;
							cout<<endl;
							return 0;
						}
					}
				}
			}
		}
	}
	puts("NO");
}