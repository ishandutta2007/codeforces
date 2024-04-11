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
const int M=1e6+10;
int X[M],Y[M];
int head[M],to[M],nxt[M],cnt;
void add(int x,int y){
	nxt[++cnt]=head[x]; to[cnt]=y; head[x]=cnt;
}
int bl[M];
bool g[M];
LL s[M];
int n,m;
int main(){
	n=read(); m=read();
	F(i,1,m){
		int x=read(),y=read();
		X[i]=x; Y[i]=y;
		add(x,y); add(y,x);
	}
	int ct=0;
	F(i,1,n){
		if (!bl[i]){
			ms(g,0); ++ct;
			for (int j=head[i];j;j=nxt[j]){
				int y=to[j];
				g[y]=1;
			}
			int sz=1;
			F(j,1,n){
				if (!g[j] && j!=i){
					if (bl[j]) {
						cout<<"-1\n";
						return 0;
					}
					else bl[j]=ct,sz++;
					
				}
			}
			bl[i]=ct;
			s[ct]=sz;
			if (ct==2) break;
		}
	}
	F(i,1,m){
		if (bl[X[i]]==bl[Y[i]]){
			cout<<"-1\n";
			return 0;
		}
	}
	s[0]=n-s[1]-s[2];
//	cout<<s[0]<<" "<<s[1]<<" "<<s[2]<<"\n";
	LL alle=s[0]*s[1]+s[1]*s[2]+s[0]*s[2];
	if (alle!=1ll*m || !s[0] || !s[1] || !s[2]){
		cout<<"-1\n";
		return 0;
	}
	F(i,1,n){
		cout<<bl[i]+1<<" ";
	}
	cout<<"\n";
	return 0;
}