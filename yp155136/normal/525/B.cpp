#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stack>
using namespace std;

const int MAX_N = 2e5 +6;

char s[MAX_N];
int cnt[MAX_N];
int pre[MAX_N];

int main () {
	while (scanf("%s",s) != EOF) {
		memset(cnt,0,sizeof(cnt));
		int n=strlen(s);
		int m;
		scanf("%d",&m);
		for (int i=1;m>=i;i++) {
			int x;
			scanf("%d",&x);
			cnt[x]++;
		}
		stack<char> sta;
		pre[0]=0;
		for (int i=1;n>=i;i++) {
			pre[i] = pre[i-1] + cnt[i];
		}
		for (int i=1;n>=i;i++) {
			if (i <= n/2) {
				if (pre[i] & 1) {
					printf("%c",s[n-i]);
					sta.push(s[i-1]);
				}
				else {
					printf("%c",s[i-1]);
					sta.push(s[n-i]);
				}
			}
			else if (2*i-1 == n) {
				printf("%c",s[i-1]);
			}
			else {
				break;
			}
		}
		while (!sta.empty()) {
			printf("%c",sta.top());
			sta.pop();
		}
		puts("");
	}
}