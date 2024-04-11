#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline LL read(){
	char ch=getchar(); LL w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=2e5+10;
LL s[M],e[M];
int n;
bool f[M][2];   
bool win(LL x,LL y){
	if (x>y) return 1; 
	if (y&1) return !(x&1); 
	if (x*2>y) return (y-x)&1;
	if (x*4>y) return 1;
	return win(x,y/4);
}
bool lose(LL x,LL y){
	if (x>y) return 0; 
	if (x*2>y) return 1;
	return win(x,y/2); 
}
int main(){
	n=read();
	F(i,1,n) s[i]=read(),e[i]=read(); 
	f[1][1]=1;
	F(i,1,n){
		if (win(s[i],e[i])) f[i+1][0]|=f[i][1];
		if (lose(s[i],e[i])) f[i+1][1]|=f[i][1];
		if (win(s[i]*2,e[i]) && win(s[i]+1,e[i])) f[i+1][0]|=f[i][0];
		if (lose(s[i]*2,e[i]) && lose(s[i]+1,e[i])) f[i+1][1]|=f[i][0];
//		cout<<f[i+1][0]<<" "<<f[i+1][1]<<"    gg\n";
		 
	}
	cout<<f[n+1][0]<<" "<<f[n+1][1]<<"\n"; 
	return 0;
}