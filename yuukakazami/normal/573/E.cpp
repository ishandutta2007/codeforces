#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define fora(i,a,b) for(int i=a;i<b;++i)

typedef long long int64;
const int N=int(1e5)+10;
int n,a[N];

int64 dp[N];
//int64 dp[2][N];

int bigrand(){ return rand()*RAND_MAX+rand(); }
int main(){
	//n=int(5e4); rep(i,n) a[i] = bigrand()%int(2e7)-1e7;
	cin>>n; rep(i,n) scanf("%d",a+i);
	//int64*cur=dp[0],*nxt=dp[1];

	dp[0]=0;

	rep(i,n){
		//i,0
		int l=-1,r=i;

		while(l+1<r){
			int m = l+r>>1;
			if(dp[m]+1LL*(m+1)*a[i]>=dp[m+1])
				r = m;
			else
				l = m;
		}
		//i..r
		for(int j=i;j>=r;--j)
			dp[j+1]=dp[j]+1LL*(j+1)*a[i];		

		
		//use cur to update nxt

		/*
		int sz=i+1;
		memcpy(nxt,cur,sizeof(int64)*(sz));
		nxt[i+1]=cur[i]+1LL*(i+1)*a[i];

		int npd = sz/8;
		int v = 8*a[i];

		#define D(t) register int64 *x##t=cur+t, *y##t=nxt+t+1, c##t=(t+1)*a[i];
		#define STEP(t) x##t+=8, y##t+=8, c##t+=v;
		#define UPD(t) if(*x##t+c##t>*y##t) *y##t=*x##t+c##t;
		#define M8(A) A(0);A(1);A(2);A(3);A(4);A(5);A(6);A(7);

		M8(D);

		int64*x0_last=x0+npd*8+8;
		while(x0!=x0_last){
			M8(UPD);
			M8(STEP);
		}
		for(int j=npd*8;j<=i;j++)
			nxt[j+1]=max(nxt[j+1],cur[j]+1LL*(j+1)*a[i]);

		swap(cur,nxt);
		*/
	}
	cout<<*max_element(dp,dp+n+1)<<endl;
}