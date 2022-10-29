#include <iostream>
#include <stdio.h>
using namespace std;
int main (){
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		bool ans=true;
		for (int x=0;n*m>x;x++) {
			string s;
			cin >> s;
			if (s=="C" || s=="M" || s=="Y") ans=false;
		}
		if (ans) puts("#Black&White");
		else puts("#Color");
	}
}