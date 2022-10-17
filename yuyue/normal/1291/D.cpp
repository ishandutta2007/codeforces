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
const int M=2e5+10;
char ch[M];
int s[30][M];
int n,m;
int main(){
	scanf("%s",ch+1);
	n=strlen(ch+1); m=read();
	F(i,0,25){
		F(j,1,n){
			s[i][j]=s[i][j-1];
			if (ch[j]=='a'+i) s[i][j]++;
		}
	}
	F(i,1,m){
		int x=read(),y=read();
		if (ch[x]!=ch[y] || y==x){
			cout<<"Yes\n";
		}
		else {
			int o=0;
			F(j,0,25)
			if ((s[j][y]-s[j][x-1])>0 && j!=ch[x]-'a') o++;
			if (o>=2) cout<<"Yes\n";
			else cout<<"No\n";
//			cout<<y-x+1-(s[ch[x]-'a'][y]-s[ch[x]-'a'][x-1])<<"\n";
//			cout<<1;
		}
	}
	return 0;
}