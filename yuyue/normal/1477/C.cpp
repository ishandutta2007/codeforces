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

const int M=2e4+10;
int n,s[M];
struct node{
	int x,y,id;
}p[M];
node L[M],R[M];
node operator - (node A,node B){
	return (node){A.x-B.x,A.y-B.y,0};
}
LL cs(node A,node B){
	return 1ll*A.x*B.y-1ll*B.x*A.y;
}
bool cmp(node a,node b){
	return (a.x==b.x?a.y<b.y:a.x<b.x);
}
double dis(node a,node b){
	return sqrt(1ll*(a.x-b.x)*(a.x-b.x)+1ll*(a.y-b.y)*(a.y-b.y));
}
int ans[M];
bool vis[M];
void work(){
	n=read();
	for (int i=1;i<=n;i++){
		p[i].x=read(); p[i].y=read(); p[i].id=i;
	} 
	sort(p+1,p+n+1,cmp);
	ans[1]=p[1].id; vis[1]=1;
	int now=1;
	F(x,2,n-1){
		int top=0;
		for (int i=1;i<=n;i++){
			if (vis[i]) continue;
			s[++top]=i;
			while (top>2 && cs(p[s[top]]-p[s[top-1]],p[s[top-1]]-p[s[top-2]])<0) s[top-1]=s[top],top--;
		}
	//	cout<<s[1]<<" ";
		for (int i=2;i<=top;i++){
//			cout<<s[i-1]<<" "<<s[i]<<"    hh\n";
			L[s[i]]=R[s[i-1]]=p[s[i]]-p[s[i-1]];
		}
	//	cout<<"\n";
		top=0;
		for (int i=n;i;i--){
			if (vis[i]) continue;
			s[++top]=i;
			while (top>2 && cs(p[s[top]]-p[s[top-1]],p[s[top-1]]-p[s[top-2]])<0) s[top-1]=s[top],top--;
		}
	//	cout<<s[1]<<" ";
		for (int i=2;i<=top;i++){
			L[s[i]]=R[s[i-1]]=p[s[i]]-p[s[i-1]];
		}
		F(i,1,n){
			if (!vis[i]){
				node tmp=p[i]-p[now];
				swap(tmp.x,tmp.y);
				tmp.y=-tmp.y;
//				cout<<p[i].id<<"  node \n";
//				cout<<tmp.x<<" "<<tmp.y<<"   chui \n";
//				cout<<L[i].x<<" "<<L[i].y<<" "<<R[i].x<<" "<<R[i].y<<"   nmd \n";
				if (cs(L[i],tmp)<0 && cs(tmp,R[i])<0){
					now=i;
					break;
				}
			}
		}
		vis[now]=1;
		ans[x]=p[now].id;
	}
	F(i,1,n) if (!vis[i]) ans[n]=p[i].id;
	F(i,1,n) cout<<ans[i]<<" ";
	cout<<"\n";
}
int main(){
	work();
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/
/*
3
0 0
5 0
5 5
*/