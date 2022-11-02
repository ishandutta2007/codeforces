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
int n;
int main(){
	n=read();
	For(len2,1,1999){
		int tmp=n/len2*len2;
		while (tmp<=n)
			tmp+=len2;
		int len1=tmp-n;
		if (len1+len2<=2000){
			int k=(n+len1)/len2+1;
			if (k>1000000)
				continue;
			cout<<len1+len2<<endl;
			For(i,1,len2-1)
				cout<<"0 ";
			cout<<"-1 ";
			For(i,1,len1-1)
				cout<<"0 ";
			cout<<k<<endl;
			return 0;
		}
	}
	puts("-1");
	return 0;
}