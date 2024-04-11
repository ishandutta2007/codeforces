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
int a[10],b[10]; 
void work(){
	F(i,0,2) a[i]=read();
	F(i,0,4) b[i]=read();
	F(i,0,2) {
		a[i]-=b[i];
		if (a[i]<0){
			puts("NO");
			return ;
		}
	}
	int d=b[3]-min(a[0],b[3])+b[4]-min(b[4],a[1]);
	if (a[2]>=d){
	 	puts("YES");
	}
	else{
		puts("NO");
	}
}
int main(){
	int T=read();
	while (T--){
		work();
	}
	return 0; 
}