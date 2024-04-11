#include <cstdio>
#include <cstring>
#include <cstdlib>

const int SIZE=1000000+10;
int sum[SIZE];
char s[SIZE];
int n, k;

int main() {
	scanf("%d%s", &k, s+1);
	n=strlen(s+1); sum[0]=0;
	for (int i=1; i<=n; i++) sum[i]=sum[i-1]+(s[i]=='1');
	long long ret=0;
	for (int i=0, j1=1, j2=1; i<=n; i++) {
		if (j1<=i) j1=i+1; 
		if (j2<=i) j2=i+1;
		while (j1<=n && sum[j1]-sum[i]<k) j1++;
		while (j2<=n && sum[j2]-sum[i]<=k) j2++;
		if (i<j1 && sum[j1]-sum[i]==k) ret+=j2-j1;
	}
	printf("%I64d\n", ret);
	return 0;
}