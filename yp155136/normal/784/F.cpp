#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

int main () {
	int n;
	cin >> n;
	int a[10];
	for (int i=0;n>i;i++) {
		int x;
		cin >> x;
		a[i]=x;
	}
	sort(a,a+n);
	int now=-214743647;
	int t=0;
	while (now != 2147483647) {
	    now+=1;
	    t+=now;
	}
	now = 0;
	while (now != 2147483647) {
	    now+=1;
	    t+=now;
	}
	for (int i=0;n>i;i++) {
		if (i) cout<<' ';
		int tmp=a[i];
		a[i]=t;
		cout<<tmp;
		if (i> now && t>now) continue;
//		if (i) cout<<' ';
	}
	cout<<endl;
	
}