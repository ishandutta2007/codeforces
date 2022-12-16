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

int c,d;
void solve(){
	c=rdi(),d=rdi();
	if((c+d)&1) puts("-1");
	else if(c==d) puts(!c?"0":"1");
	else puts("2");
}

int T;
int main(){
	T=rdi();
	while(T--) solve();
    return 0; 
}