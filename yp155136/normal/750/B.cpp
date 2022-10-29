#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
	int n;
	while (cin >> n) {
		int t;
		string s;
		int x=0;
		string ans="YES";
		for (int i=0;n>i;i++) {
			cin >> t >> s;
			if (x==0 && s!="South") ans="NO";
			else if (x==20000 && s!="North") ans="NO";
			if (s=="South") x+=t;
			else if (s=="North") x-=t;
			if (x>20000 || x<0) ans="NO";
		}
		if (x!=0) ans="NO";
		cout<<ans<<endl;
	}
}