#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
const int N=1e6+7;
int n;
bool cut[N];
char str[N];
inline void work() {
	scanf("%s", str+1), n=strlen(str+1);
	int num=count(str+1, str+n+1, 49);
	if (!num) {puts("-1"); return;}
	for (int p=1; ; p<<=1) {
		int r=p-num; if(r<0) continue;
		for (int i=1, res=0, cnt=0; i<=n; i++){
			int c=str[i]&1; res=(res<<1)+c, cnt+=c;
			if (res*2-cnt>r || i==n) r-=res-cnt, res=cnt=0, cut[i]=true;
			else cut[i]=false;
		}
		if (!r) {
			printf("%d\n" ,count(cut+1, cut+n+1, true));
			for (int i=1, lst=0; i<=n; i++)
				if (cut[i]) printf("%d %d\n", lst+1, i), lst=i;
			return;
		}
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	int test=read();
	while (test--) work();
	return 0;
}