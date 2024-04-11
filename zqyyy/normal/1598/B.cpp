#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1007;
int n,a[N][6];
inline void work(){
	n=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=5;j++)
			a[i][j]=read();
	for(int x=1;x<=5;x++)
		for(int y=x+1;y<=5;y++){
			int cnt1=0,cnt2=0,cnt3=0;
			for(int i=1;i<=n;i++){
				cnt1+=a[i][x],cnt2+=a[i][y];
				cnt3+=a[i][x]&a[i][y];
			}
			if(cnt1+cnt2-cnt3<n)continue;
			if(cnt1<n/2 || cnt2<n/2)continue;
			puts("YES");
			return;
		}
	puts("NO");
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}