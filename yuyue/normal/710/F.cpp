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
vector<string> va[30],vb[30];
int ob;	
struct ACAM{
	int rt[M];
	int tot,t[M][26],fail[M],sz[M],tp,s[M],ct[M];
	int tr[M][26];
	int merge(int x,int y){
		if (!x || !y) return x|y;
		sz[x]+=sz[y];
		F(i,0,25) t[x][i]=merge(t[x][i],t[y][i]);
		return x;
	}
	void ins(string c){
		rt[++tp]=++tot; int p=rt[tp]; 
		F(i,0,SZ(c)){
			int o=c[i]-'a';
			if (!t[p][o]) t[p][o]=++tot;
			p=t[p][o]; 
		}
		s[tp]++; sz[p]++;
		while (tp>1 && s[tp]==s[tp-1]) rt[tp-1]=merge(rt[tp-1],rt[tp]),s[tp-1]+=s[tp],rt[tp]=s[tp]=0,tp--;
//		,cout<<tp<<"   fuck\n";  
		bfs(rt[tp]);
	}
	void bfs(int root){
		queue<int> q;
		F(i,0,25) {
			if (t[root][i]) fail[tr[root][i]=t[root][i]]=root,q.push(t[root][i]); 
			else tr[root][i]=root;
		}
		while (q.size()){
			int x=q.front(); q.pop();
			F(i,0,25){
				if (!t[x][i]){
					tr[x][i]=tr[fail[x]][i];
				}
				else {
					fail[tr[x][i]=t[x][i]]=tr[fail[x]][i]; 
					q.push(tr[x][i]); 
				}
			}			
//			cout<<x<<" "<<fail[x]<<"      bs\n";
//			system("pause");
			ct[x]=sz[x]+ct[fail[x]];
		}
	}
	int qry(string c){
		int ret=0;
		F(l,1,tp){
			int p=rt[l]; 
			F(i,0,SZ(c)){
				int o=c[i]-'a'; 
				p=tr[p][o];
				ret+=ct[p]; 
			}
		}
		return ret;
	}
}A,B;
string s;
int n,lg[M];
int main(){
	n=read();
	F(i,2,n) lg[i]=lg[i>>1]+1;
	F(i,1,n){
		int ty=read(); cin>>s;
		if (ty==1) A.ins(s);
		if (ty==2) B.ins(s);
		if (ty==3){
			cout<<A.qry(s)-B.qry(s)<<'\n';
			cout.flush();
		}
	}
	return 0;
}