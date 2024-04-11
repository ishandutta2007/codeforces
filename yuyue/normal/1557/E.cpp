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
int nx,ny,TT,T;	
string s;
void work(){
//	if (TT==40 && T==38){
//		cout<<"1 2"<<endl;
//		cin>>s;
//		return ;
//	}
	nx=ny=1;
	cout<<"1 1"<<endl;
	bool fl=1;
	F(i,1,7){
		F(j,1,8){
			
			cin>>s;
			if (s=="Done") return ;
			if (!fl && s[0]=='D') break ;
			if (s[0]=='U' && j!=1){
				cout<<i<<" "<<1<<endl;
				fl=0;
				ny=1; j=0;
				continue;
			}
			if (j!=8) cout<<i<<" "<<j+1<<endl,ny=j+1,fl=0;;
		}
		nx++;
		cout<<nx<<" "<<ny<<endl;
		if (ny!=1){
			cin>>s;
			if (s=="Done") return ;
			cout<<nx<<" "<<1<<endl;
			ny=1;
		}
		else fl=1;
	}
}
int main(){
	TT=read(); T=TT;
	while (T--) work(); 
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/