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

const int N=100010,INF=0x3f3f3f3f;
int n,a[N],cnt[2];
ll ans;
vi pos[2];
void solve(){
	cnt[0]=cnt[1]=0,pos[0].clear(),pos[1].clear(),ans=1e18;
	n=rdi();
	for(int i=1;i<=n;i++) a[i]=rdi()&1,cnt[a[i]]++,pos[a[i]].pb(i);
	if(abs(cnt[0]-cnt[1])>1) {puts("-1");return;}
	if(cnt[0]!=cnt[1]){
		if(cnt[0]<cnt[1]){
			ll res=0;
			for(int k=0;k<pos[1].size();k++) res+=abs(k*2+1-pos[1][k]);
			ans=min(ans,res);
		}
		else{
			ll res=0;
			for(int k=0;k<pos[0].size();k++) res+=abs(k*2+1-pos[0][k]);
			ans=min(ans,res);
		}
	}
	else{
		for(int id=0;id<=1;id++){
			ll res=0;
			for(int k=0;k<pos[id].size();k++) res+=abs(k*2+1-pos[id][k]);
			ans=min(ans,res);
		}
	}
	printf("%lld\n",ans);
}

int T;
int main(){
	T=rdi();
	while(T--) solve();
    return 0;
}