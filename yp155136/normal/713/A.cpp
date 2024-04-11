#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

string f(long long a) {
	string ret="";
	for (int x=0;18>x;x++) ret += "0";
	int id=17;
	while (a>0) {
		int tmp=a%10;
		if (tmp%2==1) ret[id]='1';
		a/=10;
		id--;
	}
	return ret;
}

int main () {
	int Q;
	while (scanf("%d",&Q) != EOF) {
		map<string,int> mp;
		while (Q--) {
			getchar();
			char i;
			long long t;
			scanf("%c %I64d",&i,&t);
			if (i=='?') {
				printf("%d\n",mp[f(t)]);
			}
			else if (i=='+') {
				mp[f(t)]++;
			}
			else {
				mp[f(t)]--;
			}
		}
	}
}