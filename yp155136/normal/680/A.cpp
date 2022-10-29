#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main () {
	int a,b,c,d,e;
	while (scanf("%d %d %d %d %d",&a,&b,&c,&d,&e) != EOF) {
		int sum=a+b+c+d+e;
		int num[104];
		memset(num,0,sizeof(num));
		num[a]++;
		num[b]++;
		num[c]++;
		num[d]++;
		num[e]++;
		int _3=0,_2=0;
		for (int x=100;x>=0;x--) {
			if (num[x]>=3) {
				_3=x;
				break;
			}
		}
		for (int x=100;x>=0;x--) {
			if (num[x]>=2) {
				_2=x;
				break;
			}
		}
		if (_3*3 > _2*2) printf("%d\n",sum-_3*3);
		else printf("%d\n",sum-_2*2);
	}
}