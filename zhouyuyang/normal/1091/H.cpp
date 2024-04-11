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
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=200005;
int n,tmp,v[N],cnt[N],sg[N];
bitset<N> tr,fl[100];
int main(){
	scanf("%d%d",&n,&tmp);
	For(i,2,N-1) v[i]=i,cnt[i]=0;
	For(i,2,N-1) if (v[i]==i)
		For(j,1,(N-1)/i)
			for (;v[i*j]%i==0;v[i*j]/=i,cnt[i*j]++);
	cnt[tmp]=3;
	For(i,2,N-1) tr[i]=(cnt[i]<=2);
	For(i,0,N-1){
		for (;fl[sg[i]][i];sg[i]++);
		fl[sg[i]]|=tr<<i;
	}
	int ans=0;
	For(i,1,n){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		ans^=sg[y-x-1]^sg[z-y-1];
	}
	puts(ans?"Alice":"Bob");
	puts(ans?"Bob":"Alice");
}