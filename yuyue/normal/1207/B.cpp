#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
int n,m;
int a[100][100];
bool op[100][100];
bool check(int x,int y,int dx,int dy){
	if (a[x+dx][y+dy] && a[x][y+dy] && a[x+dx][y]) {
	   return 1;
	}
	return 0;
}
int main(){
	n=read(); m=read();
	F(i,1,n) F(j,1,m) a[i][j]=read();
	ms(op,0);
	F(i,1,n){
		F(j,1,m){
			if (a[i][j]){
				bool fl=0;
				if (check(i,j,-1,-1)) {
					op[i-1][j-1]=1;
					fl=1;
				} 	
				else if (check(i,j,1,-1)) {
					op[i][j-1]=1;				
					fl=1;
				} 	
				else if (check(i,j,-1,1)) {
					op[i-1][j]=1;				
					fl=1;

				} 	
				else if (check(i,j,1,1)) {
					op[i][j]=1;					
					fl=1;
				} 
				if (!fl) {
					puts("-1");
					return 0;
				}
			}
		}
	}
	vector<pair<int,int> > ans;
	F(i,1,n) F(j,1,m) {
		if (op[i][j]) {
			ans.pb(make_pair(i,j));
		}
	}
	cout<<SZ(ans)+1<<"\n";
	F(i,0,SZ(ans)){
		cout<<ans[i].first<<" "<<ans[i].second<<"\n";
	}
	return 0;
}