#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_N = 2e5 + 6;

int cha[MAX_N];
int a[MAX_N];
int pre_ans[MAX_N];

int main (){
	int n,m,q;
	scanf("%d %d %d",&n,&m,&q);
	for (int i=1;n>=i;i++) {
		int a,b;
		scanf("%d %d",&a,&b);
		cha[a]++;
		cha[b+1]--;
	}
	int pre=0;
	for (int i=1;MAX_N>i;i++) {
		pre += cha[i];
		pre_ans[i] = pre_ans[i-1];
		if (pre >= m) {
			pre_ans[i]++;
		}
	}
	while (q--) {
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d\n",pre_ans[b]-pre_ans[a-1]);
	}
}