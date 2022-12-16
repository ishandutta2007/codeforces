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

const int N=100010;
char s[N];
int n;
void solve(){
	scanf("%s",s+1);n=strlen(s+1);
	int ans=0;
	for(int i=1;i<=n;){
		if(s[i]=='0'){
			int now=i;
			while(now<=n&&s[now]=='0') now++;
			i=now+1,ans++;
		}
		else i++;
	}
	ans=min(ans,2);
	cout<<ans<<endl;
}

int T;
int main(){
	T=rdi();
	while(T--) solve();
    return 0;
}