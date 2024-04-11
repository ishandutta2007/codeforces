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
const int M=3030;
int n,m,k,X[M],Y[M],t[M],nn;
bool cmp(int x,int y){
	return Y[x]==Y[y] ? X[x]<X[y] : Y[x]<Y[y];
}
bool in[M];
vector<int> v[M];
int L[M],R[M],H[M],ct;
int main(){
	n=read(); m=read(); nn=read(); k=read();
	F(i,1,nn){
		X[i]=read(); Y[i]=read();
		v[X[i]].pb(i);
	}
	Y[nn+1]=m+1;
	LL fans=0;
	F(i,1,n){
		ct=0;
		F(j,1,nn){
			if (X[j]>=i){
				t[++ct]=j;
			}
		}
		sort(t+1,t+ct+1,cmp);
		L[t[1]]=0; R[t[ct]]=nn+1;
		LL ans=0; 
		F(j,2,ct){
			int pre=t[j-1],now=t[j];
			L[now]=pre;
			R[pre]=now;
		}
		F(j,1,ct){
			int now=t[j];
			H[now]=now;
			F(l,1,k-1) H[now]=L[H[now]];
			ans+=Y[H[now]]*(Y[R[now]]-Y[now]);
//			cout<<H[now]<<" "<<now<<" ?? \n";
		}
		fans+=ans;
//		cerr<<ans<<"   hhhh\n";
		DF(j,n,i+1){
			for (int y:v[j]){
				int z=L[y];
				ans-=(Y[R[y]]-Y[y])*Y[H[y]];
				R[z]=R[y];
				L[R[y]]=z;
				ans+=(Y[R[y]]-Y[y])*Y[H[z]];
//				cerr<<(Y[R[y]]-Y[y])*Y[H[z]]<<" "<<y<<"  ?? duy\n";
				int now=R[y];
				for (int l=1;l<k;l++){
					ans-=Y[H[now]]*(Y[R[now]]-Y[now]);
//					cerr<<now<<" "<<H[now]<<" "<<L[H[now]]<<" ?????\n";
					H[now]=L[H[now]];
					ans+=Y[H[now]]*(Y[R[now]]-Y[now]);
					now=R[now];
				}
			}
			fans+=ans;
//			cerr<<ans<<"   hh \n";
		}
	}
	cout<<fans<<"\n";
	return 0;
}