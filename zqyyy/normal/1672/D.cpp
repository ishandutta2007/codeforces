#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
int n,a[N],b[N],cnt[N];
inline void work(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	for(int i=1;i<=n;i++)cnt[i]=0;
	int j=1;
	for(int i=1;i<=n;i++){
		while(j<=n && a[j]!=b[i])cnt[a[j++]]++;
		if(j>n){puts("NO");return;}
		j++;
		while(i<n && b[i]==b[i+1]){
			if(cnt[b[i]])i++,cnt[b[i]]--;
			else break;
		}
	}
	if(j<n){puts("NO");return;}
	for(int i=1;i<=n;i++)
		if(cnt[i]){puts("NO");return;}
	puts("YES");
}
int main(){
	int test=read();
	while(test--)work();
	return 0;
}