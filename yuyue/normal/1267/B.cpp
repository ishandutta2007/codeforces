#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int M=3e5+10;
char ch[M],s[M];
int n,sz[M],bl[M],ct;
int main(){
	scanf("%s",ch+1);
	n=strlen(ch+1);
	int lst=1;
	F(i,1,n){
		if (ch[i]!=ch[i+1]){
			++ct;
			F(j,lst,i) bl[j]=ct,sz[ct]++;
			s[ct]=ch[i];
			lst=i+1;
		}
	}
	int pl=1,pr=ct;
	while (pl<pr && s[pl]==s[pr] && sz[pl]+sz[pr]>=3){
		pl++; pr--;
	}
	if (pl==pr && sz[pl]>=2){
		cout<<(sz[pl]+1)<<"\n";
	}
	else cout<<"0\n";
    return 0;
}
/*
aaa babb aaa
*/