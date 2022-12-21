#include<bits/stdc++.h>
using namespace std;
set<int>S;
#define N 500005
int n,a[N],b[N],q[N],r;
int main() {
	scanf("%d",&n);
	n*=2;
	int tot=0;
	for (int i=1;i<=n;i++) {
		char c=getchar();
		while (c!='+'&&c!='-') c=getchar();
		if (c=='+') q[++r]=++tot,b[i]=0;
		else {
			int x;
			scanf("%d",&x);
			b[i]=x;
			if (!r) return puts("NO"),0;
			a[q[r]]=x;
			r--;
		}
	}
	if (r) return puts("NO"),0;
	tot=0;
	for (int i=1;i<=n;i++) {
		if (!b[i]) {
			++tot;
			S.insert(a[tot]);
		}
		else {
			int p=(*S.begin());
			S.erase(S.begin());
			if (p!=b[i]) return puts("NO"),0;
		}
	}
	puts("YES");
	for (int i=1;i<=n/2;i++) printf("%d ",a[i]);
	
}