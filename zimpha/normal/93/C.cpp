#include <cstdio>
#include <cstring>
#include <cstdlib>

char st[26][64];
int reg[26];
int n, ans;

bool dfs(int dep) {
	if (reg[dep]==n) {
		return true;
	}
	if (dep>=ans || reg[dep]>n) return false;
	dep++;
	for (int i=0; i<dep; i++) {
		for (int j=0; j<dep; j++) {
			for (int k=1; k<=8; k<<=1) {
				reg[dep]=reg[i]+k*reg[j];
				if (dfs(dep)) {
					sprintf(st[dep], "lea e%cx, [e%cx + %d*e%cx]", dep+'a', i+'a', k, j+'a');
					return true;
				}
			}
		}
	}
	for (int i=0; i<dep; i++) {
		for (int k=1; k<=8; k<<=1) {
			reg[dep]=k*reg[i];
			if (dfs(dep)) {
				sprintf(st[dep], "lea e%cx, [%d*e%cx]", dep+'a', k, i+'a');
				return true;
			}
		}
	}
	return false;
}

int main() {
	scanf("%d", &n);
	memset(reg, 0, sizeof(reg));
	reg[0]=1;
	for (ans=0; !dfs(0); ans++);
	printf("%d\n", ans);
	for (int i=1; i<=ans; i++) {
		printf("%s\n", st[i]);
	}
	return 0;
}