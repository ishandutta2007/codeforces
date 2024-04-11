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
const int M=3e5+10;
int n,m,ed[M],t[M][30],val[M];
multiset<int> s[M];
int tot,q[M],fail[M],hl[M],w[M];
char ch[M];
void build(){
	int l=1,r=0;
	F(i,0,25) if (t[0][i]) q[++r]=t[0][i];
	while (l<=r){
		int x=q[l++];

		if (val[fail[x]]==0) hl[x]=fail[x];
		else hl[x]=hl[fail[x]];		
		//cout<<x<<" "<<fail[x]<<" "<<hl[x]<<"  link\n";
		F(i,0,25){
			int y=t[x][i];
			if (y) fail[y]=t[fail[x]][i],q[++r]=y;
			else t[x][i]=t[fail[x]][i];
		}
	}
}
int main(){
	n=read(); m=read();
	ms(val,-1);
	F(i,1,n){
		scanf("%s",ch+1); 
		int len=strlen(ch+1);
		int pos=0;
		F(j,1,len){
			int o=ch[j]-'a';
			if (!t[pos][o]) t[pos][o]=++tot;
			pos=t[pos][o];
		}
		ed[i]=pos;
		//cerr<<pos<<"  position\n";
		s[pos].insert(0);
		val[pos]=0; 
	}
	build();
	while (m--){
		int op=read(); 
		if (op==1){
			int x=read(),y=read(); 
			int pos=ed[x];
			s[pos].erase(s[pos].find(w[x]));
			s[pos].insert(y);
			w[x]=y;
			val[pos]=*s[pos].rbegin();
		}
		else{
			int ans=-1; 
			scanf("%s",ch+1);
			int len=strlen(ch+1);
			int pos=0;
			F(i,1,len){
				int o=ch[i]-'a'; 
				pos=t[pos][o];
				for (int x=pos;x;x=hl[x]){
					//cerr<<x<<"   qrypos\n";
					ans=max(ans,val[x]);
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0; 
}