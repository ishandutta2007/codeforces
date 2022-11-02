#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=a;i<=b;i++)
#define Fod(i,b,a) for (int i=b;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define _SEED_ ('C'+'L'+'Y'+'A'+'K'+'I'+'O'+'I')
#define outval(x) printf(#x" = %d\n",x)
#define outvec(x) printf("vec "#x" = ");for (auto _v : x)printf("%d ",_v);puts("")
#define outtag(x) puts("----------"#x"----------")
using namespace std;
typedef long long LL;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f|=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int N=500005;
char s[N],t[N];
int n,m;
int c[2];
int Fail[N];
int main(){
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	For(i,2,m){
		int k=Fail[i-1];
		while (k>0&&t[k+1]!=t[i])
			k=Fail[k];
		if (t[k+1]==t[i])
			k++;
		Fail[i]=k;
	}
	For(i,1,n)
		c[s[i]-'0']++;
	int k=0;
	For(i,1,n){
		while (k>0&&!c[t[k+1]-'0'])
			k=Fail[k];
		int v=t[k+1]-'0';
		if (c[v]){
			c[v]--;
			putchar('0'+v);
			k++;
			if (k==m)
				k=Fail[k];
		}
		else {
			v^=1;
			c[v]--;
			putchar('0'+v);
			while (k>0&&t[k+1]-'0'!=v)
				k=Fail[k];
			if (t[k+1]-'0'==v)
				k++;
		}
	}
	return 0;
}