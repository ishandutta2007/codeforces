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
char s[3][M];
int n,num[3][3],fv[3];
void work(){
	n=read();
	ms(num,0); 
	scanf("%s%s%s",s[0]+1,s[1]+1,s[2]+1);
	n*=2;
	F(i,0,2){
		F(j,1,n){
			num[i][s[i][j]-'0']++;
		}
		fv[i]=(num[i][0]<=num[i][1]);
	}
	int o1=-1,o2=-1,col=-1;
	if (fv[0]==fv[1]) o1=0,o2=1;
	else{
		if (fv[2]==fv[0]) o1=0,o2=2;
		else o1=1,o2=2;
	}
	col=fv[o1];	
	if (num[o1][col]<num[o2][col]) swap(o1,o2);
	int ps=1;
//	cout<<col<<" "<<o1<<" "<<o2<<" "<<num[o2][col]<<"\n";
	F(i,1,n){
		if (s[o2][i]-'0'!=col) cout<<s[o2][i];
		else{
			while (ps<=n && s[o1][ps]!='0'+col){
				cout<<s[o1][ps];
				ps++;
			}
			cout<<s[o1][ps]; ps++;
		}
	}
	while (ps<=n){
		cout<<s[o1][ps];
		ps++;
	}
	cout<<"\n";
}
int main(){
	int T=read();
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