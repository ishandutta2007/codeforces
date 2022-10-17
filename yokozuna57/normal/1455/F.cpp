#include <bits/stdc++.h>
using namespace std;

#define mp make_pair

int n,k;
string s;

char f(char c){
	if(c=='a'||c==char('a'+k-1))return 'a';
	return char(c-1);
}
void upd(char &a,char &b,char &c,char d, char e,char f){
	if(mp(a,mp(b,c))>mp(d,mp(e,f))){
		a=d;
		b=e;
		c=f;
	}
}

void solve(){
	s="zz"+s;
	char ret[2][505];
	int t=0,t_=1;
	for(int i=0;i<505;i++){
		ret[0][i]=ret[1][i]=127;
	}
	
	for(int i=2;i<n+2;i++){
		if(ret[t][i-2]<=ret[t_][i-2]){
			if(i>2)upd(ret[t_][i-2],ret[t_][i-1],ret[t_][i],ret[t][i-2],s[i],ret[t][i-1]);
			upd(ret[t_][i-2],ret[t_][i-1],ret[t_][i],ret[t][i-2],ret[t][i-1],f(s[i]));
			if(i+1<s.size()){
				upd(ret[t][i-1],ret[t][i],ret[t][i+1],ret[t][i-1],f(s[i+1]),s[i]);
				if(i>2)upd(ret[t][i-1],ret[t][i],ret[t][i+1],s[i+1],ret[t][i-1],s[i]);
			}
		}
		else {
			ret[t][i-2]=ret[t_][i-2];
			ret[t][i-1]=127;
		}
		swap(t,t_);
		/*for(int j=0;j<2;j++){
			for(int k=0;k<n+2;k++){
				cerr<<ret[j][k];
			}
			cerr<<endl;
		}*/
	}
	for(int i=2;i<n+2;i++){
		printf("%c",ret[t][i]);
	}
}

int main(){
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		scanf("%d%d",&n,&k);
		cin>>s;
		solve();
		cout<<endl;
	}
}