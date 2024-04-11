#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))r=(r<<1)+(r<<3)+(ch^48),ch=getchar();
	return f?r:-r;
}
const int N=2e5+5,mod=1004535809,B=123456791;
int n,m,q,cnt[N],pw[N],ha[N][2];
bool a[N];char s[N];
inline int gethash(int l,int r){
	int o=l&1;
	return (ha[cnt[r]][o]-1ll*ha[cnt[l-1]][o]*pw[cnt[r]-cnt[l-1]]%mod+mod)%mod;	
}
int main(){
	n=read(),scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		if(s[i]-'0')cnt[i]=cnt[i-1];
		else cnt[i]=cnt[i-1]+1,a[++m]=i&1; 
	}
	for(int i=pw[0]=1;i<=m;i++){
		pw[i]=1ll*pw[i-1]*B%mod;
		ha[i][0]=(1ll*ha[i-1][0]*B%mod+(a[i]^1))%mod;
		ha[i][1]=(1ll*ha[i-1][1]*B%mod+a[i])%mod;
	}
	q=read();
	while(q--){
		int l1=read(),l2=read(),len=read();
		int r1=l1+len-1,r2=l2+len-1;
		if(gethash(l1,r1)==gethash(l2,r2) && cnt[r1]-cnt[l1-1]==cnt[r2]-cnt[l2-1])puts("Yes");
		else puts("No");
	}
	return 0;	
}