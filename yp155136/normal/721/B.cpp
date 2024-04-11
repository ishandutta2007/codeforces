#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int tmp[123];
string i[123];

int main () {
	int n,k;
	while (cin >> n>> k) {
		memset(tmp,0,sizeof(tmp));
		for (int x=0;n>x;x++) {
			cin >> i[x];
			tmp[i[x].size()]++;
		}
		string j;
		cin >> j;
		int cnt=0;
		for (int x=0;j.size()>x;x++) {
			cnt += tmp[x];
		}
		int b = cnt+1,w=cnt+tmp[j.size()];
		cout<<b + ((b-1)/k)*5<<' '<<w+((w-1)/k)*5<<endl; 
	}
}