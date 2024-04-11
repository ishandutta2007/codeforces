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

int a,b,c,m;
int solve1(int a,int b,int c){
	return max(a-b-c-1,0);
}

void solve(){
	a=rdi(),b=rdi(),c=rdi(),m=rdi();
	if(a<b) swap(a,b);
	if(b<c) swap(b,c);
	if(a<b) swap(a,b);
	if(m>a+b+c-3||m<solve1(a,b,c)) puts("NO");
	else puts("YES");
}

int T;
int main(){
	T=rdi();
	while(T--) solve();
    return 0;
}