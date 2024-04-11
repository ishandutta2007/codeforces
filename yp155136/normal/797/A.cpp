#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main () {
	int n,k;
	while (cin >> n >> k) {
		int nn=n;
		vector<int> v;
		for (int i=2;n>=i;i++) {
			while (n%i==0) {
				v.push_back(i);
				n/=i;
			}
		}
		if (v.size()<k) puts("-1");
		else {
			int tot=1;
			for (int i=0;k-1>i;i++) {
				cout<<v[i]<<' ';
				tot*=v[i];
			}
			cout<<nn/tot<<endl;
		}
	}
}