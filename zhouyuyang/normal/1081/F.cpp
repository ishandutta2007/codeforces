#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
#define fi first
#define se second
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
 
#define inf 1<<30
#define sqr(x) ((x)*(x))
using namespace std;
const int N=305;
int ans[N],s[N],tt[N],n,t,tp=0;
void flip(int l,int r){
	for (int i=l;i<=r;i++) s[i]^=1;
}
int count(){
	int ans=0;
	for (int i=1;i<=n;i++)
		ans+=s[i];
	return ans;
}
int times=0;
int ask(int l,int r){
	times++;
	if (tp==0){
		printf("? %d %d\n",l,r);
		fflush(stdout);
		scanf("%d",&l);
		if (l==-1) exit(0);
		return l;
	}
	else{
		if (rand()&1) flip(1,r);
		else flip(l,n);
		return count();
	}
}
int main(){
	srand(time(NULL));
	scanf("%d",&n);
	if (tp==0)
		scanf("%d",&t);
	else{
		for (int i=1;i<=n;i++) s[i]=tt[i]=rand()&1;
		t=count();
	}
	if (n!=1){
		static int pre[2]={0,0};
		for (int i=1;i<n;i++){
			int fl=0,sum=0;
			for (;sum<=15;sum++){
				ask(i+1,n);
				int val=ask(i+1,n);
				if (val!=t){
					if (t-(pre[1]+1)+pre[0]==val)
						ans[i]=1,swap(pre[1],pre[0]),pre[0]++;
					else if (t-pre[1]+pre[0]+1==val)
						ans[i]=0,swap(pre[1],pre[0]),pre[1]++;
					else puts("GG");
					t=val; fl=1;
					break;
				}
			}
			if (!fl)
				for (;;){
					int val;
					for (;;){
						ask(i,n);
						val=ask(i,n);
						if (val!=t) break;
					}
					if (val==t-pre[0]+pre[1]){
						if (t-(pre[1]+1)+pre[0]==t)
							ans[i]=1,pre[0]++;
						else if (t-pre[1]+(pre[0]+1)==t)
							ans[i]=0,pre[1]++;
						else puts("GG");
						t=val;
						break;
					}
					ask(i+1,n);
					ask(i+1,n);
				}
		}
		for (;;){
			ask(1,n-1);
			int val=ask(1,n-1);
			if (val!=t){
				ans[n]=(val<t?1:0);
				t=val;
				break;
			}
		}
	}
	else ans[1]=t;
	printf("! ");
	For(i,1,n) printf("%d",ans[i]);
	if (tp==1){
		printf("\n%d\n",times);
		For(i,1,n) if (tt[i]!=ans[i]) puts("GG");
	}
}
/*
1-l s1-v1+s2-v2+v3
r-n v1+s2-s2+s3-v3
11111110000000
1,n-1
*/