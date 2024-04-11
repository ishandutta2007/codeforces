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
const int M=4e5+10;
int to[M],nxt[M],head[M],w[M],cnt;
void add(int x,int y,int z){
	to[++cnt]=y; nxt[cnt]=head[x]; head[x]=cnt; w[cnt]=z;
}
int n,m;
bool vis[M];
int a[M],b[M];
int x1,flag;
int ans[M],s[M],tp,t[M],ct;
void dfs(int x){
	vis[x]=1; s[++tp]=x;
	for (int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if (vis[y]){
			if (a[x]^a[y]){
				int tmp=b[x]+b[y]-w[i];
				if (tmp!=0) {
					puts("NO");
					exit(0); 
				}
			}
			else{
				int now=(w[i]-b[x]-b[y])/(a[x]+a[y]);
				if (flag){
					if (x1^now){
						cout<<"NO\n";
						exit(0);
					}
				}
				else{
					x1=now;
					flag=1;
				}
			}
		}
		else {
			a[y]=-a[x];
			b[y]=w[i]-b[x];
			dfs(y);
		}
	}
}
int main(){
	n=read(); m=read();
	F(i,1,m){
		int x=read(),y=read(),z=read();
		z*=2;
		add(x,y,z);
		add(y,x,z);
	}
	F(i,1,n){
		if (!vis[i]){
			a[i]=1; tp=flag=0; 
			dfs(i);
			ct=0;
			if (!flag){
				F(j,1,tp){
					t[++ct]=-b[s[j]]/a[s[j]];
				}
				sort(t+1,t+ct+1);
				x1=t[(tp+1)/2];
			}
			F(j,1,tp) ans[s[j]]=a[s[j]]*x1+b[s[j]];
		}
	}
	puts("YES");
	F(i,1,n){
		cout<<fixed<<setprecision(10)<<ans[i]/2.0<<" ";
	}
	cout<<"\n";
	return 0; 
}