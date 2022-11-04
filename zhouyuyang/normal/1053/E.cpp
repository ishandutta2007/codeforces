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
const int N=1000005;
int n,m;
int a[N],num[N];
int rP[N],pre[N],nxt[N];
vector<int> P[N];
void GG(){
	puts("no");
	exit(0);
}
void init(int l,int r){
	int cnt=0,len=0;
	For(i,l+1,r-1){
		int x=a[i];
		if (a[i]){
			if (rP[x]>r) GG();
			int las=0;
			for (auto p:P[x]){
				if (las) init(las,p);
				las=p;
			}
			i=rP[x];
			++cnt;
		}
		++len;
	}
	++len;
	if (l==1&&!a[1]) len+=2;
	if (len/2<cnt||(len&1)) GG();
	int c=len/2-cnt;
	if (l==1&&!a[1]&&!c){
		int _cnt=0,_len=0;
		For(i,l+1,r-1){
			int x=a[i];
			++_len;
			if (x){
				i=rP[x];
				if (_cnt*2==_len){
					a[1]=x; break;
				}
				++_cnt;
			} 
		} 
	}
	if (l==1&&!a[1]) --l,++r;
	For(i,l+1,r-1){
		if (!c) break;
		int x=a[i];
		if (!x) a[i]=num[(*num)--],c--;
		else i=rP[x];
	}
	a[2*n-1]=a[1];
}
void work(int l,int r){
	assert(a[l]==a[r]);
	vector<int> vec;
	For(i,l+1,r-1){
		int x=a[i];
		if (x){
			int las=0;
			for (auto p:P[x]){
				if (las) work(las,p);
				las=p;
			}
			i=rP[x];
		}
		vec.PB(i);
	}
	pre[l]=nxt[r]=0;
	int las=l;
	for (auto i:vec) pre[i]=las,nxt[las]=i,las=i;
	nxt[las]=r; pre[r]=las;
	for (int i=nxt[l];i<r;i=nxt[i])
		for (;a[pre[i]]&&a[i]&&!a[nxt[i]];){
			a[nxt[i]]=a[pre[i]];
			int x=nxt[nxt[i]];
			nxt[pre[i]]=x; pre[x]=pre[i];
			i=pre[i];
		}
	for (int i=pre[r];i>l;i=pre[i])
		for (;!a[pre[i]]&&a[i]&&a[nxt[i]];){
			a[pre[i]]=a[nxt[i]];
			int x=pre[pre[i]];
			pre[nxt[i]]=x; nxt[x]=nxt[i];
			i=nxt[i];
		}
}
int main(){
	scanf("%d",&n);
	For(i,1,2*n-1) scanf("%d",&a[i]);
	if (n==1) a[1]=1;
	if (a[1]&&a[2*n-1]&&a[1]!=a[2*n-1]) GG();
	a[1]=a[2*n-1]=max(a[1],a[2*n-1]);
	For(i,1,2*n-1) if (a[i]){
		P[a[i]].PB(i);
		rP[a[i]]=i;
	}
	For(i,1,n) if (!rP[i]) num[++*num]=i;
	if (!a[1]) init(1,2*n-1);
	else{
		int x=a[1],las=0;
		for (auto p:P[x]){
			if (las) init(las,p);
			las=p;
		}
	}
	if (*num) GG();
	For(i,1,n) P[i].clear();
	For(i,1,2*n-1) if (a[i]){
		P[a[i]].PB(i);
		rP[a[i]]=i;
	}
	int x=a[1],las=0;
	for (auto p:P[x]){
		if (las) work(las,p);
		las=p;
	}
	puts("yes");
	For(i,1,2*n-1)
		printf("%d ",a[i]);
}