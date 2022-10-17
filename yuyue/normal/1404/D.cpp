#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
int n;
const int M=1e6+10;
int to[M],nxt[M],w[M],head[M],cnt=1;
void add(int x,int y,int z){
//	cout<<x<<" "<<y<<" "<<z<<" ??\n";
	to[++cnt]=y; nxt[cnt]=head[x]; head[x]=cnt; w[cnt]=z;
}
bool vis[M],vs[M],cs[M];
int num=0;
void dfs(int x,int fa){
	vs[x]=1; num++;
	for (int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if (!vis[i]){
//			cout<<i<<" "<<y<<" "<<w[i]<<" !!! ??? \n";
			vis[i]=vis[i^1]=1;
			cs[y]=w[i];
		}
		if (!vs[y]){
			dfs(y,x);
		}
		
	}
}
void rev(int x){
	vs[x]=0; cs[x]^=1;
	for (int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if (vs[y]){
			rev(y);
		}
	}
}
int lst[M];
int main(){
	n=read();
	if (n%2==0){
		cout<<"First"<<endl;
		F(i,1,2*n){
			cout<<(i>n ? i-n : i)<<" ";
		}
		cout<<endl;
		return 0;
	}
	else{
		cout<<"Second"<<endl; 
		F(i,1,2*n){
			int x=read();
			int ix=(i>n ? i-n : i);
			if (lst[x]){
				int iy=(lst[x]>n ? lst[x]-n : lst[x]);
				add(ix,iy,(lst[x]>n));
				add(iy,ix,(i>n));
			}
			else lst[x]=i;
		}
		int ji=0;
		F(x,1,n){
			if (!vs[x]){
				num=0;
				dfs(x,0);
				if (num&1 && !ji) ji=x;
			}
		}
		LL sm=0;
		F(i,1,n){
			sm+=n*cs[i]+i;
		}
		if (sm%(2*n)!=0){
			rev(ji);
		}
		F(i,1,n){
			cout<<n*cs[i]+i<<" ";
		}
		cout<<endl;
	}
    return 0;
}
/*
5
2 4. 2. 1. 5. 3 3. 1 5 4


1--3--4--5--2--1
->0->0->0->0->1

6 2 3 4 5
sum=20 ok
*/