#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define uint ungigned
#define db long double
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
using namespace std;
int n,ice,pos,a[1005],top;
char ans[1000005];
void divide(int l,int r){
	int mn=a[l];
	For(i,l,r) mn=min(mn,a[i]);
	For(i,l,r) a[i]-=mn;
	int las=l;
	For(i,l,r)
		if (!a[i]){
			if (i-1>=las)
				divide(las,i-1);
			las=i+1;
		}
	if (r>=las)
		divide(las,r);
	For(i,1,mn){
		for (;ice<r;){
			if (pos==ice) ans[++top]='A',ice++;
			else ans[++top]='R',pos++;
		}
		for (;pos+1>=l;pos--) ans[++top]='L';
		ans[++top]='A'; ice=pos;
	}
}
void work(int l,int r){
	int L=l-1;
	for (;a[L];L--);
	L++;
	//printf("%d %d %d\n",L) 
	if (2*(l-L)+2>=r-l+1) 
		For(i,l,r) a[i]=1;
}
//(lenleft*5+3)+(lenmiddle*2)+(lenright*3+1)
//(lenleft*3+2)+(lenmiddle*3)+lenright*3
int main(){
	scanf("%d",&n);
	int cnt=0;
	For(i,1,n) scanf("%d",&a[i]),cnt+=(a[i]!=0);
	int l=1,r=n;
	for (;!a[l];l++);
	for (;!a[r];r--);
	int las=l;
	For(i,l,r)
		if (a[i]){
			if (las<=i-1) work(las,i-1);
			las=i+1;
		} 
	if (las<=r) work(las,r);
	pos=-1; ice=-1;
	divide(l,r);
	int tp2=1;
	For(i,2,top)
		if (ans[i]!='A'||ans[i-1]!='L'||ans[i+1]!='L')
			ans[++tp2]=ans[i];
	ans[tp2+1]=0;
	printf("%s",ans+1);
}