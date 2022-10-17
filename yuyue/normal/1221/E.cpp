#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=3e5+10; 
char ch[M];
int a,b,n; 
bool work(){
	int len=0,com=0,mx=0; 
	bool flag=0; 
	F(i,1,n){
		if (ch[i]=='.') len++;
		else {
			if (len<b){
				len=0; 
				continue; 
			}
			if (len>=b && len<a) return 0; 
			if (len>a+4*b-2) return 0;
			if (len>=2*b){
				if (flag) return 0;
				flag=1;
				mx=len;
			}
			else if (len>=a) com++;
			len=0;
		}
	}
//	cout<<mx<<" "<<com<<" "<<flag<<"  fuck\n"; 
	if (flag){
		if (com&1) {//+1
			if (mx>=a+a && mx<=a+b+2*b-2) return 1;
			return 0;
		}
		else {//+0 or +2
			if ((mx>=a && b-1+b-1+a>=mx) || mx>=3*a) return 1;
			return 0;  
		}
	}
	return com&1;
}
int main(){
	int T=read();
	while (T--){
		a=read(),b=read(); scanf("%s",ch+1); 
		n=strlen(ch+1); ch[n+1]='X'; n++; 
		if (work()) puts("YES");
		else puts("NO"); 
	} 
	return 0;
}