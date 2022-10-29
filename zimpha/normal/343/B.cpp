#include <cstdio>
#include <cstring>
const int SIZE=100000+10;

char stk[SIZE], st[SIZE];
int top;

int main() {
	scanf("%s", st); top=0;
	for (int i=0; st[i]; i++) {
		if (top>0 && stk[top]==st[i]) top--;
		else stk[++top]=st[i];
	}
	if (top>0) puts("No");
	else puts("Yes");
	return 0;
}