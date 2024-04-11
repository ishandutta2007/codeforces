#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=200010;
const double eps=1e-9;

int n,v[N],m;
i64 sum[N];
double mx[N];

int main(){
	n=rdi();
	for(int i=1;i<=n;i++){
		v[i]=rdi(),sum[i]=sum[i-1]+v[i];
		mx[i]=max(mx[i-1],1.*sum[i]/i);
	}
	m=rdi();
	while(m--){
		int t=rdi();
		int l=1,r=n+1;
		while(l<r){
			int mid=(l+r)/2;
			if(max(mx[mid],1.*sum[n]/mid)-eps>t) l=mid+1;
			else r=mid;
		}
		cout<<(l>n?-1:l)<<'\n';
	}
    return 0;
}