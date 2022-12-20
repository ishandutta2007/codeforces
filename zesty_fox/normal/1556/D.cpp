#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

int n,k,ans;
int query_or(int l,int r){
	printf("or %d %d\n",l,r);
	fflush(stdout);
	return rdi();
}

int query_and(int l,int r){
	printf("and %d %d\n",l,r);
	fflush(stdout);
	return rdi();
}

void print_ans(){
	printf("finish %d\n",ans);
	fflush(stdout);
}

const int N=10010;
ll a[N],sum[N];
int main(){
	n=rdi(),k=rdi();
	for(int i=1;i<n;i++){
		int now=i,nxt=i+1;
		sum[i]=query_or(now,nxt)+query_and(now,nxt);
	}
	ll tmp=query_and(1,3)+query_or(1,3);
	a[2]=(sum[1]+sum[2]-tmp)/2,a[1]=sum[1]-a[2],a[3]=sum[2]-a[2];
	for(int i=4;i<=n;i++) a[i]=sum[i-1]-a[i-1];
	sort(a+1,a+n+1);ans=a[k];
	print_ans();
    return 0;
}