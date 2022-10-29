#include <iostream>
#include <stdio.h>
using namespace std;

int tmp[123];

int main () {
	int n;
	while (cin >> n) {
		string i;
		cin >> i;
		int cnt=0;
		int s=0;
		for (int x=0;n>x;x++) {
			if (i[x]=='B') {
				s++;
			}
			else {
				if (s!=0) {
					tmp[cnt++]=s;
				}
				s=0;
			}
		}
		if (s!=0) {
			tmp[cnt++]=s;
		}
		cout<<cnt<<endl;
		for (int x=0;cnt>x;x++) {
			if (x!=0) cout<<" ";
			cout<<tmp[x];
		}
		cout<<endl;
	}
}