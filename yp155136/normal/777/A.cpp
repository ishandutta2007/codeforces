#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
	int n,x;
	while (scanf("%d%d",&n,&x) != EOF) {
		n%=6;
		int _[3]={0,0,0};
		_[x]=1;
		for (int i=n;i>=1;i--) {
			if (i%2==1) swap(_[0],_[1]);
			else if (i%2==0)swap(_[1],_[2]);
		}
		for (int i=0;2>=i;i++) {
			if (_[i]) printf("%d\n",i);
		}
	}
}