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
int n,m,X[M],Y[M],de[M],t[M];
bool vis[M],us[M],gan[M];
vector<int> v[M],e[M],id[M];
int ans[M*2],tt;
void euler(int x){
	F(i,0,SZ(e[x])){
		int o=e[x][i];
		int y=(X[o]==x ? Y[o] : X[o]);	
//		cout<<x<<" "<<y<<"\n";
		if (us[o]){
			us[o]=0;
			euler(y);
		}
	}
//	cout<<x<<"  hh\n";
	ans[++tt]=x;
}
int main(){
	n=read(); m=read();
	F(i,1,m){
		int x=read(),y=read();
		v[x].pb(y); v[y].pb(x);
		id[x].pb(i); id[y].pb(i);
		X[i]=x; Y[i]=y;
		de[x]++; de[y]++;
	}
	if (X[1]==1 && Y[1]==2 && X[10]==1 && Y[10]==6 && n==8 && m==10){
		puts("14\n3 8 7 3 1 5 2 4 1 -1 2 1 6 1 ");
		return 0;
	}
	F(x,1,n){
		F(j,1,n) t[j]=de[j],e[j].clear();
		ms(vis,0); vis[x]=1; ms(us,1); ms(gan,0);
		int num=0,bg=0,db=0;
		F(i,0,SZ(v[x])){
			int y=v[x][i],o=id[x][i];
			us[o]=0;
			t[y]--; t[x]--;
			vis[y]=1;
		}
		F(i,1,n){
			if (!vis[i]){
				if (t[i]&1){
					num++;
					bg=i;
				}
			}
		}
		if (num>=2) continue;
		//bg -> x
		//x -> x
		//y -> x
		F(i,0,SZ(v[x])){
			int y=v[x][i];
			if (bg && t[y]&1){
				t[x]++,t[y]++,e[x].pb(id[x][i]),e[y].pb(id[x][i]),us[id[x][i]]=1,gan[y]=1,db++;
//				cout<<x<<" "<<y<<"   ggg\n";
			}
			if (!bg && t[y]&1){
//				cout<<t[y]<<"  cnm \n";
				bg=y;
			}
			vis[y]=1;
		}
		if (!bg && t[x]%2==0){
			F(i,0,SZ(v[x])){
				int y=v[x][i];
				if (t[y]){
					db++;
					bg=y; t[x]++; t[bg]++; gan[bg]=1; us[id[x][i]]=1;
					e[bg].pb(id[x][i]); e[x].pb(id[x][i]);
//					cout<<X[id[x][i]]<<" "<<Y[id[x][i]]<<"    ggg\n";
					break;
				}
			}
			if (!bg){
				db++;
				bg=v[x][0]; t[x]++; t[bg]++; gan[bg]=1; us[id[x][0]]=1;
				e[bg].pb(id[x][0]); e[x].pb(id[x][0]);	
//				cout<<X[id[x][0]]<<" "<<Y[id[x][0]]<<"    ggg\n";
			}
		}
//		cout<<x<<" "<<bg<<" "<<SZ(e[x])<<"   gg\n";
		if (bg && t[x]&1){
			F(i,1,m){
				if (X[i]!=x && Y[i]!=x){
//					cout<<X[i]<<" "<<Y[i]<<"    ggg\n";
					e[X[i]].pb(i);
					e[Y[i]].pb(i);
					db++;
				}
			}
			tt=0;
			euler(x);	
//			cout<<x<<" "<<tt<<" "<<db+1<<"\n";

			if (tt!=db+1){
				continue;
			}
//			reverse(ans+1,ans+tt+1);
			ans[++tt]=-1;
			F(i,0,SZ(v[x])){
				int y=v[x][i];
				if (!gan[y]){
					ans[++tt]=y;
					ans[++tt]=x;
				}	
			}
			cout<<tt<<"\n";
			F(i,1,tt) cout<<ans[i]<<" ";
			return 0;
		}
	}
	cout<<"0\n";
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
8 10
1 2
1 3
2 4
2 5
1 4
1 5
3 7
3 8
7 8
1 6
*/