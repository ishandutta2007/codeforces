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
int s[20];
bool check(int x){
	ms(s,0);
	while (x) s[x%10]++,x/=10;
	F(i,0,9) if (s[i]>1) return 0;
	return 1;
}
int main(){
	int l=read(),r=read();
	F(i,l,r){
		if (check(i)) {
			cout<<i<<"\n";
			return 0;
		}
	}
	cout<<"-1\n";
	return 0;
}