#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define vi vector<int>
#define vpi vector<pii >
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define y1 wzpakking
#define fi first
#define se second
#define BG begin
#define ED end
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?(x)-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define sqr(x) (1ll*x*x)
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
#define INF (1<<29)
using namespace std;
int n,a[100005];
struct node{
	int i,j,k;
};
vector<node> ans;
void S(int i,int k){
	if ((k-i)&1) return;
	int j=(i+k)/2;
	ans.push_back((node){i,j,k});
	a[i]^=1; a[j]^=1; a[k]^=1;
}
int tr(int l){
	return a[l]*4+a[l+1]*2+a[l+2];
}
int find(int l){
	int v=tr(l);
	if (v==4) return l;
	if (v==2) return l+1;
	if (v==1) return l+2;
	return 0;
}
vector<int> q[10005];
map<vector<int>,int> mp;
void output(){
	printf("YES\n");
	printf("%d\n",ans.size());
	For(i,0,ans.size()-1)
		printf("%d %d %d\n",ans[i].i,ans[i].j,ans[i].k);
}
void solve_BF(){
	int h=0,t=1; q[1].resize(n+1);
	vector<int> res; res.resize(n+1);
	For(i,1,n) res[i]=a[i];
	while (h!=t){
		++h;
		For(i,1,n) For(j,i+1,n){
			int k=2*j-i; if (k>n) break;
			vector<int> nxt=q[h];
			nxt[i]^=1; nxt[j]^=1; nxt[k]^=1;
			if (mp.find(nxt)==mp.end()){
				mp[nxt]=mp[q[h]]+1;
				q[++t]=nxt;
			}
		}
	} 
	if (mp.find(res)==mp.end()){
		puts("NO");
		exit(0);
	}
	for (;mp[res];){
		bool fl=0;
		For(i,1,n){
			For(j,i+1,n){
				int k=2*j-i;
				if (k>n) break;
				vector<int> nxt=res;
				nxt[i]^=1; nxt[j]^=1; nxt[k]^=1;
				if (mp[nxt]+1==mp[res]){
					S(i,k),res=nxt;
					fl=1; break;
				}
			}
			if (fl) break;
		} 
	}
	output();
}
bool workL(int l){
	int v=tr(l);
	if (v==7) return S(l,l+2),1;
	if (v==5) return S(l,l+4),1;
	if (v==3) return S(l+1,l+3),1;
	return v==0;
}
bool workR(int r){
	int v=tr(r-2);
	if (v==7) return S(r-2,r),1;
	if (v==5) return S(r-4,r),1;
	if (v==6) return S(r-3,r-1),1;
	return v==0;
}
void bao(int x){
	if (x+6<=n) S(x,x+6),S(x+3,x+5),S(x+4,x+6);
	else S(x-6,x),S(x-5,x-3),S(x-6,x-4);
}
void solve_LARGE(){
	int l=1,r=n;
	while (l+8<=r){
		if (workL(l)) l+=3;
		else if (workR(r)) r-=3;
		else if (tr(l)==6&&tr(r-2)==3){
			if ((r-l)&1) S(l,r-1),S(l+1,r);
			else S(l,r),S(l+1,r-1);
			l+=3; r-=3;
		}
		else if (find(l)){
			int t=find(l);
			S(t,r); S(t,r-1);
			l+=3;
		}
		else if (find(r-2)){
			int t=find(r-2);
			S(l,t); S(l+1,t);
			r-=3;
		}
	}
	for (int i=l;i+2<=r;i++) if (a[i]) S(i,i+2);
	if (a[r]&&a[r-1]) S(r-2,r),bao(r-2);
	else if (a[r]) bao(r);
	else if (a[r-1]) bao(r-1);
	output();
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	if (n<=12) solve_BF();
	else solve_LARGE();
	For(i,1,n) assert(a[i]==0);
	assert(ans.size()<=n/3+12);
}