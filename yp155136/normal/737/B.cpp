#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

const int MAX_N = 2e5+6;

char c[MAX_N];
int p[MAX_N];

int main () {
	int n,a,b,k;
	while (scanf("%d %d %d %d",&n,&a,&b,&k) != EOF) {
		getchar();
		scanf("%s",c);
		for (int i=1;n>=i;i++) {
			p[i] = c[i-1]-'0';
		}
		vector<int> ans;
		int cnt=0;
		for (int i=1;n>=i;i++) {
			if (p[i]==1) {
				cnt=0;
			}
			else {
				cnt++;
				if (cnt==b) {
					cnt=0;
					ans.push_back(i);
				}
			}
		}
		printf("%d\n",ans.size()-a+1);
		for (int x=0;ans.size()-a+1>x;x++) {
			if (x!=0) printf(" ");
			printf("%d",ans[x]);
		}
		puts("");
	}
}