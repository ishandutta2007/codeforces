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
int n,sum[N][2];
char s1[N],s2[N];
int f[N];
int mex(int l,int r){
	if(sum[r][0]-sum[l-1][0]==0) return 0;
	else if(sum[r][1]-sum[l-1][1]==0) return 1;
	else return 2;
}

void solve(){
	n=rdi();scanf("%s%s",s1+1,s2+1);
	for(int i=1;i<=n;i++){
		sum[i][0]=sum[i-1][0],sum[i][1]=sum[i-1][1];
		sum[i][s1[i]-'0']++,sum[i][s2[i]-'0']++;
		f[i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=2;j++){
			int l=1,r=i;
			while(l<r){
				int mid=(l+r+1)>>1;
				if(mex(mid,i)>=j) l=mid;
				else r=mid-1;
			}
			f[i]=max(f[i],f[l-1]+mex(l,i));
		}
	}
	printf("%d\n",f[n]);
}

int T;
int main(){
	T=rdi();
	while(T--) solve();
    return 0;
}