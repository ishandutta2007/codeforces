#include <bits/stdc++.h>
using namespace std;
int l, r;
int vl[30];
int vr[30];
long long f[30][4][4];
bool done[30][4][4];
void get_good(int u, int pa, int gooda[2]){
	gooda[0]=0;
	gooda[1]=0;
	if((pa&1)==0){
		if(vl[u]){
			if(gooda[0]!=-1) gooda[0]=-1;
		}
		else{
			if(gooda[1]!=-1) gooda[1]^=1;
		}
	}
	else{
		if(gooda[0]!=-1) gooda[0]^=1;
		if(gooda[1]!=-1) gooda[1]^=1;
	}
	if((pa&2)==0){
		if(vr[u]==0){
			if(gooda[1]!=-1) gooda[1]=-1;
		}
		else{
			if(gooda[0]!=-1) gooda[0]^=2;
		}
	}
	else{
		if(gooda[0]!=-1) gooda[0]^=2;
		if(gooda[1]!=-1) gooda[1]^=2;
	}
}
long long F(int u, int pa, int pb){
	if(u==30){
		return 1;
	}
	else{
		if(done[u][pa][pb]) return f[u][pa][pb];
		done[u][pa][pb]=1;
		int gooda[2];
		int goodb[2];
		get_good(u, pa, gooda);
		get_good(u, pb, goodb);
		for(int i=0; i<2; i++) for(int j=0; j<2; j++) if((i^j)==(i+j)) if((gooda[i]!=-1)&&(goodb[j]!=-1)){
			f[u][pa][pb]+=F(u+1, gooda[i], goodb[j]);
		}
		return f[u][pa][pb];
	}
}
void solve(){
	cin>>l>>r;
	for(int i=29; i>=0; i--){
		vl[i]=l%2;
		l/=2;
	}
	for(int i=29; i>=0; i--){
		vr[i]=r%2;
		r/=2;
	}
	for(int i=0; i<30; i++) for(int j=0; j<4; j++) for(int k=0; k<4; k++) done[i][j][k]=f[i][j][k]=0;
	cout<<F(0, 0, 0)<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
}