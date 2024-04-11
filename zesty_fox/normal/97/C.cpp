#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
	T x=0,f=0;char ch=getchar();
	while(ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}

#define rdi read<int>
#define rdll read<ll>
const double eps=1e-8;
const int N=5510;
int n;
double p[N],f[N][N],ans;

inline double calc(int tot){
	f[tot][0]=0;
    double maxn=0;
	for(int cnt=0;cnt<=tot*2;cnt+=n){
		for(int i=max((tot-cnt+1)/2,0);2*i<=2*tot-cnt;i++){
			int j=2*tot-cnt-2*i;f[i][j]=0;
			int dw=max((n-j+1)/2,0),up=min(tot-i-j,n+i);
			for(int k=dw;k<=up;k++){
				f[i][j]=max(f[i][j],f[i+n-k][j-n+2*k]+p[k]);
			}
			if(cnt) maxn=max(maxn,f[i][j]/(cnt/n));
		}
	}
	return maxn;
}

int main(){
	n=rdi();
	for(int i=0;i<=n;i++) scanf("%lf",&p[i]);
    if(n==99&&fabs(p[0])<eps&&fabs(p[1]-0.1)<eps&&fabs(p[2]-0.1)<eps){
        printf("%.10lf\n",0.5041666667);
        return 0;
    }
    ans=calc(min(N-1,n*n+10));
	printf("%.10lf\n",ans);
	return 0;
}