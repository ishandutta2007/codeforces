#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
	int n,k,a,b;
	while (scanf("%d %d %d %d",&n,&k,&a,&b) != EOF) {
		string s;
		if (a>b) s="GB";
		else {
			swap(a,b);
			s="BG";
		}
		int groupa=a/k + (a%k!=0);
		if (groupa-1 > b) {
			puts("NO");
			continue;
		}
		int times=b - groupa+1;
		int id=0;
		int id2=0;
		for (int x=0;groupa>x;x++) {
			if (x==groupa-1) {
				while (id<a) {
					cout<<s[0];
					id++;
				}
				while (id2<b) {
					cout<<s[1];
					id2++;
				}
				continue;
			}
			for (int x=0;k>x;x++) {
				cout<<s[0];
				id++;
			}
			cout<<s[1];
			id2++;
			int okay = k-1;
			while (okay && times) {
				//cout<<"times = "<<times<<endl;
				times--;
				okay--;
				cout<<s[1];
				id2++;
			}
		}
		cout<<endl;
	}
}