#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int MAX_N = int(3e5 + 10);
char A[MAX_N],B[MAX_N];
int n;

int main(){
	gets(A);
	gets(B);
	n = strlen(A);
	sort(A, A + n);
	sort(B, B + n);
	reverse(B, B + n);


	static char ret[MAX_N];
	ret[n] = 0;
	int ia=0,ib=0;
	int ja=(n+1)/2,jb = n/2;

	int sl=0,sr=n;

	rep(it,0,n){
		if(it%2==0){//A
			if(A[ia] < B[ib])
				ret[sl++] = A[ia++];
			else
				ret[--sr] = A[--ja];

		} else {
			if(B[ib] > A[ia])
				ret[sl++] = B[ib++];
			else
				ret[--sr] = B[--jb];
		}
	}

	puts(ret);
	return 0;
}