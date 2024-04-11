#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAX_N = 1e5 + 6;

int a[MAX_N];
int pos[MAX_N];
vector<int> ans[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int i=0;n>=i;i++) {
			ans[i].clear();
		}
		for (int i=1;n>=i;i++) {
			scanf("%d",&a[i]);
			pos[a[i]]=i;
		}
		int mx=-1;
		for (int i=n;i>=1;i--) {
			if (pos[i]>mx) {
				mx = pos[i];
				ans[pos[i]].push_back(i);
			}
			else {
				ans[mx].push_back(i);
			}
		}
		for (int i=1;n>=i;i++) {
			bool flag=0;
			for (auto j:ans[i]) {
				if (flag)printf(" ");
				printf("%d",j);
				flag=1;
			}
			puts("");
		}
	}
}