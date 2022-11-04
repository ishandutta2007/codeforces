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
#define INF (1ll<<60)
using namespace std;
int n,k;
bool ask(int x,int y,int z){
	static char s[10];
	printf("? %d %d %d\n",x,y,z);
	fflush(stdout);
	scanf("%s",s);
	return s[0]=='Y';
}
vector<int> pth,pth2,ans;
vector<int> findpth(int S,int T,int type){
	ans.resize(0);
	if (type==1){
		For(i,1,n) if (i!=S&&i!=T)
			if (ask(S,i,T)) ans.PB(i);
	}
	else{
		for (auto i:pth) if (i!=S&&i!=T)
			if (ask(S,i,T)) ans.PB(i);
	}
	return ans;
}
int main(){
	srand(time(NULL));
	scanf("%d%d",&n,&k);
	int dep=0,tmp=n;
	for (;tmp>k;tmp/=k,dep++);
	int x=rand()%n+1,y=rand()%n+1;
	for (;;x=rand()%n+1,y=rand()%n+1){
		for (;x==y;x=rand()%n+1,y=rand()%n+1);
		pth=findpth(x,y,1);
		if (pth.size()==2*dep-1) break;
	}
	For(i,0,pth.size()-1){
		pth2=findpth(x,pth[i],0);
		if (pth2.size()==dep-1){
			printf("! %d\n",pth[i]);
			return 0;
		}
	}
}
/*
4-1,2,3
*/