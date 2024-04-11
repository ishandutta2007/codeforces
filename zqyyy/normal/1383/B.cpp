#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))r=(r<<1)+(r<<3)+(ch&15),ch=getchar();
	return f?r:-r;
}
const int N=1e5+7;
int n,a[N];
inline void work(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int j=29;~j;j--){
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(a[i]>>j&1)cnt++;
		if(cnt%2==0)continue;
		if(cnt%4==1 || (n-cnt)%2==1)puts("WIN");
		else puts("LOSE");
		return;
	}
	puts("DRAW");
}
int main(){
	int test=read();
	while(test--)work();
	return 0;
}