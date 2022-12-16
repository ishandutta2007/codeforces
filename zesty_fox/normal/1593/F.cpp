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

const int N=45;

int n,A,B,a[N];
char s[N];

int pwa[N],pwb[N];
short f[N][N][N][N];

void solve(){
	n=rdi(),A=rdi(),B=rdi();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) a[n-i+1]=s[i]-'0';
	
	pwa[0]=pwb[0]=1;
	for(int i=1;i<=n;i++) pwa[i]=pwa[i-1]*10%A;
	for(int i=1;i<=n;i++) pwb[i]=pwb[i-1]*10%B;
	
	memset(f,0,sizeof(f));
	f[0][0][0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<A;j++){
			for(int k=0;k<B;k++){
				for(int l=0;l<=i;l++){
					if(!f[i][j][k][l]) continue;
					f[i+1][(j+a[i+1]*pwa[l])%A][k][l+1]|=1;
					f[i+1][j][(k+a[i+1]*pwb[i-l])%B][l]|=2;
				}
			}
		}
	}
	int ans=n+1,st=0;
	for(int i=0;i<=n;i++){
		if(abs(i-(n-i))<ans&&f[n][0][0][i]){
			st=i;
			ans=abs(i-(n-i));
		}
	}
	if(ans>=n) return (void)puts("-1");
	int suma=0,sumb=0;string res;
	for(int i=n;i>=1;i--){
		if(f[i][suma][sumb][st]&1) res+='R',suma=(suma-a[i]*pwa[st-1]%A+A)%A,st--;
		else res+='B',sumb=(sumb-a[i]*pwb[i-st-1]%B+B)%B;
	}
	//~ reverse(res.begin(),res.end());
	cout<<res<<'\n';
}

int T;
int main(){
	T=rdi();
	while(T--) solve();
    return 0;
}