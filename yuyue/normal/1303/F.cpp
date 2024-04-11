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
const int M=2e6+10,N=303,dx[]={0,1,0,-1},dy[]={-1,0,1,0};
int f[M];
int Fd(int x){
	if (f[x]==x) return x;
	return f[x]=Fd(f[x]);
}
int old[M],pos[M],col[M],ans[M],X[M],Y[M];
int a[N][N];
bool cover[N*N+10];
int n,m,q;
bool valid(int x,int y) {
	return x && y && x<=n && y<=m;
}
void join(int x,int y,int &ct){	
	int u=Fd(x*(m+1)+y);
	F(k,0,3){
		int tx=x+dx[k],ty=y+dy[k],ps=tx*(m+1)+ty;
		if (!valid(tx,ty) || !cover[ps] || a[x][y]!=a[tx][ty]) continue;
		int v=Fd(ps);
		if (u==v) continue;
		ct--; f[v]=u;
	}
}
void out(){
	F(i,1,n) F(j,1,m) cout<<Fd(i*(m+1)+j)<<(j==m ? "\n" : " ");
}
int main(){
	n=read(); m=read(); q=read();
	int lst=1,pre=0;
//	cout<<q<<"\n";
	F(i,1,q){
		int x=read(),y=read(),v=read();  
		pos[i]=x*(m+1)+y; col[i]=v; old[i]=a[x][y]; X[i]=x; Y[i]=y;
		if (!pre) pre=v;
		else {
			if (v!=pre){
				F(j,lst,i-1) f[pos[j]]=pos[j],cover[pos[j]]=0;
				int tmp=0;
				F(j,lst,i-1){
					if (cover[pos[j]]) {
						ans[j]=tmp;
						continue;
					}
					cover[pos[j]]=1; tmp++;
					join(X[j],Y[j],tmp);
					
					ans[j]=tmp;
				}
				F(j,lst,i-1) cover[pos[j]]=0;
				tmp=0;
				F(j,1,n) F(k,1,m) {
					int ps=j*(m+1)+k;
					f[ps]=ps;
					if (a[j][k]!=pre) cover[ps]=1,tmp++,join(j,k,tmp);
				}
				DF(j,i-1,lst) {
//					cout<<j<<" "<<tmp<<"    bonus\n";
					ans[j]+=tmp;
					if (old[j]==pre) continue;
					if (!cover[pos[j]]) tmp++,cover[pos[j]]=1;
					a[X[j]][Y[j]]=old[j];
					join(X[j],Y[j],tmp);
//					out(); cout<<"FUCK\n";
				}
				ms(cover,0);
				F(j,lst,i-1) a[X[j]][Y[j]]=col[j]; 
				lst=i; pre=v;
			}	
		}
		a[x][y]=v;
//		cout<<i<<" "<<q<<"   pp\n";
	}
	F(j,lst,q) f[pos[j]]=pos[j],cover[pos[j]]=0;
	int tmp=0;
//	cout<<lst<<"   oo\n";
	F(j,lst,q){
		if (cover[pos[j]]) {
			ans[j]=tmp;
			continue;
		}
		cover[pos[j]]=1; tmp++;
		join(X[j],Y[j],tmp);
		ans[j]=tmp;
//		cout<<tmp<<"   op\n";
	}
	F(j,lst,q) cover[pos[j]]=0;
	tmp=0;
	F(j,1,n) F(k,1,m) {
		int ps=j*(m+1)+k;
		f[ps]=ps;
		if (a[j][k]!=pre) cover[ps]=1,tmp++,join(j,k,tmp);
//		,cout<<j<<" "<<k<<" "<<tmp<<"    oldldldld\n";
	}
	DF(j,q,lst) {
//		cout<<j<<" "<<tmp<<"    bonus\n";
		ans[j]+=tmp;
		if (old[j]==pre) continue;
		if (!cover[pos[j]]) tmp++,cover[pos[j]]=1;
//		cout<<X[j]<<" "<<Y[j]<<" "<<old[j]<<"    oooo\n";
		a[X[j]][Y[j]]=old[j];
		join(X[j],Y[j],tmp);
//		out(); cout<<"FUCK\n";
	}
	F(i,1,q) cout<<ans[i]<<"\n";
	return 0;
}