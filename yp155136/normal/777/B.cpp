#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_P = 12;

int cnt[MAX_P];
int __[MAX_P];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		string a,b;
		cin >> a >> b;
		for (auto i:b) {
			cnt[i-'0']++;
			__[i-'0']++;
		}
		int _=0;
		//first --> defense
		for (auto i:a) {
			bool flag=0;
			for (int ala=i-'0';MAX_P>ala;ala++) {
				if (__[ala]) {
					__[ala]--;
					flag=1;
					break;
				}
			}
			if (!flag) {
				_++;
				for (int ala=0;MAX_P>ala;ala++) {
					if (__[ala]) {
						__[ala]--;
						break;
					}
				}
			}
		}
		printf("%d\n",_);
		int q=0;
		for (auto i:a) {
			bool flag=0;
			for (int ala=i-'0'+1;MAX_P>ala;ala++) {
				if (cnt[ala]) {
					cnt[ala]--;
					flag=1;
					q++;
					break;
				}
			}
			if (!flag) {
				for (int ala=0;MAX_P>ala;ala++) {
					if (cnt[ala]) {
						cnt[ala]--;
						break;
					}
				}
			}
		}
		printf("%d\n",q);
	}
}