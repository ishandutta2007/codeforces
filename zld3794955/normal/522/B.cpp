#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
const int N=210000;
int a[N],b[N];
int pre[N],suf[N];int sum=0;int n;
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d%d",&a[i],&b[i]);
		sum+=a[i];pre[i]=max(pre[i-1],b[i]);
	}
	per(i,n,1)suf[i]=max(suf[i+1],b[i]);
	rep(i,1,n)printf("%d ",(sum-a[i])*max(pre[i-1],suf[i+1]));
	return 0;
}