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
const int N=15;
int n=10;
int id[N];
char ch[N];
void Que(int s){
	printf("next");
	for (int i=0;i<n;i++)
		if (s>>i&1)
			printf(" %d",i);
	puts("");
	fflush(stdout);
	int cnt=read();
	for (int i=1;i<=cnt;i++){
		scanf("%s",ch+1);
		int len=strlen(ch+1);
		for (int j=1;j<=len;j++)
			id[ch[j]-'0']=i;
	}
}
int walk(){
	Que((1<<0)|(1<<1));
	Que((1<<1));
	return id[0]!=id[1];
}
int main(){
	while (walk());
	while (1){
		Que(1023);
		int flag=1;
		for (int i=1;i<10;i++)
			if (id[i]!=id[0])
				flag=0;
		if (flag){
			puts("done");
			return 0;
		}
	}
	return 0;
}