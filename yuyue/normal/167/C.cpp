#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
LL read(){
    char ch=getchar(); LL w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
bool calc(LL x,LL y){
	if (!y) return 0;
	bool tmp=calc(y,x%y);
	if (!tmp) return 1;
	return ((x/y)%(y+1)%2)^1;
}

void work(){
	LL x=read(),y=read();
	if (x<y) swap(x,y);
	puts(calc(x,y) ? "First" : "Second");
}
int main(){
	int T=read();
	while (T--) work(); 
	return 0;
}