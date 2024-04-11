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

const int N=2010;

int operate(const vi &L,const vi &R){
	printf("? %lu %lu\n",L.size(),R.size());
	for(auto x:L) printf("%d ",x);
	puts("");
	for(auto x:R) printf("%d ",x);
	puts("");
	fflush(stdout);
	return rdi();
}

int n,typ[N];
void print_ans(){
	vi tmp;
	for(int i=1;i<=n;i++){
		if(!typ[i]) tmp.pb(i);
	}
	printf("! %lu ",tmp.size());
	for(auto x:tmp) printf("%d ",x);
	puts("");fflush(stdout);
}

void solve(){
	n=rdi();
	for(int i=1;i<=n;i++) typ[i]=0;
	int pos=0;
	for(int i=2;i<=n;i++){
		vi L,R({i});
		for(int j=1;j<i;j++) L.pb(j);
		if(operate(L,R)!=0){typ[i]=1,pos=i;break;}
	}
	for(int i=pos+1;i<=n;i++) typ[i]=(operate({pos},{i})!=0);
	int l=1,r=pos-1;
	while(l<r){
		int mid=(l+r)>>1;
		vi L,R({pos});
		for(int i=1;i<=mid;i++) L.pb(i);
		if(operate(L,R)) r=mid;
		else l=mid+1;
	}
	typ[l]=1;print_ans();
}

int T;
int main(){
	T=rdi();
	while(T--) solve();
    return 0;
}