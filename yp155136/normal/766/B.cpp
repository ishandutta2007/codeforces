#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAX_N =1e5 + 6;

int a[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n ) != EOF) {
		for (int i=1;n>=i;i++) {
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		string ans="NO";
		for (int i=1;n-2>=i;i++) {
			if (a[i] + a[i+1] > a[i+2]) ans="YES";
		}
		cout<<ans<<endl;
	}
}