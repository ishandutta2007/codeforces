#include<bits/stdc++.h>
#define N 305
using namespace std;
char c[N][N];
int a[N][N],f1[5],f2[5];
#define pb push_back
#define lowbit(x) x&-x
int n,k;
int main() {
	int test;
	scanf("%d",&test);
	while (test--) {
		int n;
		for (int i=0;i<=2;i++) f1[i]=f2[i]=0;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%s",c[i]+1);
		for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) {
			a[i][j]=0;
			if (c[i][j]=='O') a[i][j]=1;
			else if (c[i][j]=='X') a[i][j]=2;
			if (a[i][j]==1) f1[(i+j)%3]++;
			if (a[i][j]==2) f2[(i+j)%3]++;
		}
		int ma=n*n+1,s1=0,s2=0;
		for (int i=0;i<=2;i++)
		for (int j=0;j<=2;j++) {
			if (i==j) continue;
			if (f1[i]+f2[j]<=ma) ma=f1[i]+f2[j],s1=i,s2=j;
		}
		for (int i=1;i<=n;i++,puts(""))
		for (int j=1;j<=n;j++) {
			if (!a[i][j]) printf(".");
			if (a[i][j]==1) {
				if (((i+j)%3)==s1) printf("X");
				else printf("O");
			}
			if (a[i][j]==2) {
				if (((i+j)%3)==s2) printf("O");
				else printf("X");
			}
		}
	}
}