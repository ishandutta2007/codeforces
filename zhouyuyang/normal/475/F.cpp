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

int work(set<pii > &x,set<pii > &y){
	set<pii > xx,yy;
	set<pii >::iterator x1=x.begin(),y1=y.begin();
	set<pii >::reverse_iterator x2=x.rbegin(),y2=y.rbegin();
	for (int t;*x1<*x2;){
		t=x1->fi;
		if ((++x1)->fi-t>1){
			for (pii it=*x.begin();it.fi<=t;it=*x.begin()){
				pii jt=pii(it.se,it.fi);
				xx.insert(it); x.erase(it);
				yy.insert(jt); y.erase(jt);
			}
			return work(x,y)+work(xx,yy);
		} 
		t=x2->fi;
		if (t-(++x2)->fi>1){
			for (pii it=*x.rbegin();it.fi>=t;it=*x.rbegin()){
				pii jt=pii(it.se,it.fi);
				xx.insert(it); x.erase(it);
				yy.insert(jt); y.erase(jt);
			}
			return work(x,y)+work(xx,yy);
		}
		t=y1->fi;
		if ((++y1)->fi-t>1){
			for (pii jt=*y.begin();jt.fi<=t;jt=*y.begin()){
				pii it=pii(jt.se,jt.fi);
				xx.insert(it); x.erase(it);
				yy.insert(jt); y.erase(jt);
			}
			return work(x,y)+work(xx,yy);
		}
		t=y2->fi;
		if (t-(++y2)->fi>1){
			for (pii jt=*y.rbegin();jt.fi>=t;jt=*y.rbegin()){
				pii it=pii(jt.se,jt.fi);
				xx.insert(it); x.erase(it);
				yy.insert(jt); y.erase(jt);
			}
			return work(x,y)+work(xx,yy);
		}
	}
	return 1;
}
int n;
set<pii > X,Y;
int main(){
	scanf("%d",&n);
	For(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);
		X.insert(pii(x,y));
		Y.insert(pii(y,x));
	}
	printf("%d",work(X,Y));
}