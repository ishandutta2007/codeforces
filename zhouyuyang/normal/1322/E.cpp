#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=500005;
int n,a[N],b[N];
vector<int> vec[N];
set<pii> S;

struct node{
	int cl,cr,mx,vl,vr,v;
	node(){}
	node(int c){
		cl=cr=c;
		mx=vl=vr=v=1;
	}
}t[N*4];
node operator +(node a,node b){
	node ans;
	ans.cl=a.cl; ans.cr=b.cr;
	ans.mx=max(a.mx,b.mx);
	ans.vl=a.vl; ans.vr=b.vr;
	ans.v=a.v+b.v;
	if (a.cr^b.cl){
		ans.mx=max(ans.mx,a.vr+b.vl);
		if (a.v==a.vl) ans.vl+=b.vl;
		if (b.v==b.vr) ans.vr+=a.vr;
	}
	return ans;
}
void build(int k,int l,int r){
	if (l==r){
		t[k]=node(0);
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	t[k]=t[k*2]+t[k*2+1];
}
void change(int k,int l,int r,int p){
	if (l==r){
		t[k]=node(1);
		return;
	}
	int mid=(l+r)/2;
	if (p<=mid) change(k*2,l,mid,p);
	else change(k*2+1,mid+1,r,p);
	t[k]=t[k*2]+t[k*2+1];
}

struct YYN{
	int t[N*4],nn;
	void build(int n){
		for (nn=1;nn<=n;nn<<=1);
		For(i,0,2*nn-1) t[i]=0;
	}
	void change(int x,int y,int v){
		//cout<<x<<' '<<y<<' '<<v<<endl;
		x+=nn-1; y+=nn+1;
		for (;x^y^1;x>>=1,y>>=1){
			if (!(x&1)) t[x^1]=max(t[x^1],v);
			if (y&1) 	t[y^1]=max(t[y^1],v);
		}
	}
	void output(){
		For(i,1,nn-1){
			t[i*2]=max(t[i*2],t[i]);
			t[i*2+1]=max(t[i*2+1],t[i]);
		}
		For(i,1,n) printf("%d ",t[i+nn]);
		puts("");
	}
}RE;
void flip(int x){
	//cout<<"F "<<x<<endl;
	assert(a[x]==0);
	if (x==1||a[x]==a[x-1]) S.erase(pii(x,a[x]));
	if (x==n||a[x]==a[x+1]) S.erase(pii(x+1,a[x]));
	a[x]^=1; change(1,1,n,x);
	if (x==1||a[x]==a[x-1]) S.insert(pii(x,a[x]));
	if (x==n||a[x]==a[x+1]) S.insert(pii(x+1,a[x]));
}

void updateee(int x,int v){
	auto it=S.lower_bound(pii(x,-1));
	auto pre=it,suf=it; pre--;
	if (pre->se==1&&suf->se==1) RE.change(pre->fi,suf->fi-1,v);
	else if (pre->se==1&&suf->se==0) RE.change(pre->fi,(pre->fi+suf->fi)/2-1,v);
	else if (pre->se==0&&suf->se==1) RE.change((pre->fi+suf->fi)/2,suf->fi-1,v);
}
/*
110100
*/
void updatee(int x,int v){
	auto it=S.lower_bound(pii(x,-1));
	auto pre=it,suf=it;
	//cout<<it->fi<<' '<<it->se<<endl;
	//assert(it->se==1||it->fi==n+1);
	if (x!=1){
		--pre;
		if (pre->se==1) RE.change(pre->fi,it->fi-1,v);
		else RE.change((pre->fi+it->fi)/2,it->fi-1,v);
	}
	if (x!=n+1){
		++suf;
		if (suf->se==1) RE.change(it->fi,suf->fi-1,v);
		else RE.change(it->fi,(it->fi+suf->fi)/2-1,v);
	}
}
void update(int x,int v){
	if (x==1||a[x]==a[x-1]) updatee(x,v); else updateee(x,v);
	if (x==n||a[x]==a[x+1]) updatee(x+1,v); else updateee(x+1,v);
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) b[i]=a[i];
	sort(b+1,b+n+1);
	*b=unique(b+1,b+n+1)-b-1;
	For(i,1,n){
		a[i]=lower_bound(b+1,b+*b+1,a[i])-b;
		vec[a[i]].PB(i);
	}
	memset(a,0,sizeof(a));
	build(1,1,n);
	RE.build(n);
	For(i,1,n+1) S.insert(pii(i,0));
	int ansT=0;
	Rep(i,*b,1){
		for (auto j:vec[i]) flip(j);
		for (auto j:vec[i]) update(j,b[i]);
		ansT=max(ansT,t[1].mx);
		//printf("%d\n",ansT);
	}
	printf("%d\n",(ansT-1)/2);
	RE.output();
}
/*
11010100 
11101000
11110000 

1101010100 
1110101000
1111010000
1111100000
1111111111
9->4
8->3
011

110100
,0 
0
1 
*/