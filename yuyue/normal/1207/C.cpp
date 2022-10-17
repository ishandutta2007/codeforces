#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=2e5+10;
char ch[M];
struct node{
	bool c;
	LL l;
}a[M];
LL n,bb,aa;
void work(){
	n=read(); aa=read(); bb=read();
	scanf("%s",ch+1); ch[n+1]='1';
	int lst=1,cnt=0; 
	F(i,2,n+1){
		if (ch[i]!=ch[i-1]){
			a[++cnt].c=ch[i-1]-'0';
			a[cnt].l=i-lst;
			lst=i;
		}
	}
	LL ans=0;
	if (cnt==1){
		ans=1ll*(n+1)*bb+1ll*n*aa;
		cout<<ans<<"\n";
		return;
	}
	F(i,1,cnt){
		if (!a[i].c){
			if (i==1 || i==cnt){
				ans+=a[i].l*bb+(a[i].l+1)*aa;
			}
			else {
				if ((a[i].l-1)*bb>2ll*aa) ans+=(a[i].l+2)*aa+(a[i].l-1)*bb;
				else ans+=a[i].l*aa+(a[i].l-1)*2ll*bb;
			}
		}
		else {
			ans+=2ll*(a[i].l+1)*bb+a[i].l*aa;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	int T=read();
	while (T--) work();
	return 0;
}