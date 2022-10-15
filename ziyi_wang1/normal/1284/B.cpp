#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
typedef long long ll;
#define I inline void
#define IN inline int
#define C(x,y) memset(x,y,sizeof(x))
const int INF=1e9+7,N=1000000;
ll ans;
struct Tree{
	#define all 1,0,N
	#define lt k<<1,l,mid
	#define rt k<<1|1,mid+1,r
	int tr[4040000];
	I modi(int k,int l,int r,int x){
		if(l==r){tr[k]++;return;}
		re mid=(l+r)>>1;
		if(x<=mid)modi(lt,x);
		else modi(rt,x);
		tr[k]=tr[k<<1]+tr[k<<1|1];
	}
	IN ques(int k,int l,int r,int x,int y){
		if(x>r||y<l)return 0;
		if(x<=l&&r<=y)return tr[k];
		re mid=(l+r)>>1;
		return ques(lt,x,y)+ques(rt,x,y);
	}
}A,B;
int n,m,sn,a[101000],X,las;
int main(){
	cin>>n;ans=(ll)n*n;
	F(i,1,n){
		cin>>m;las=INF;sn=1;
		F(j,1,m){
			cin>>a[j];
			if(a[j]>las)sn=0;
			las=min(las,a[j]);
		}
		if(!sn)continue;
		if(a[1]==las)ans--;ans-=A.ques(all,0,a[m]);ans-=B.ques(all,a[1],N);
		A.modi(all,a[1]);B.modi(all,a[m]);
	}
	cout<<ans;
	return 0;
}