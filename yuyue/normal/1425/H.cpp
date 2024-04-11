#include<bits/stdc++.h>
#define F(i,a,b) for (int i=a;i<=b;i++)
#define DF(i,a,b) for (int i=a;i>=b;i--)
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define OO(x) fixed<<setprecision(x)
using namespace std;
inline LL read(){
	char ch=getchar(); LL w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
int main(){
	int T=read();
	while (T--){
		int A=read(),B=read(),C=read(),D=read();
		bool o=(!(A+D)) || (!(C+B));
		if ((A+B)&1){
			if (o){
				if (A+D) cout<<"Ya Tidak Tidak Tidak\n";
				else cout<<"Tidak Ya Tidak Tidak\n";
			}
			else cout<<"Ya Ya Tidak Tidak\n";
		}
		else{
			if (o){
				if (B+C) cout<<"Tidak Tidak Ya Tidak\n";
				else cout<<"Tidak Tidak Tidak Ya\n";
			}
			else cout<<"Tidak Tidak Ya Ya\n";
		}
	}
	return 0;
}