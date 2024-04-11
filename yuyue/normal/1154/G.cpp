#include<bits/stdc++.h>
#define LL long long
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int M=1e6+10;
int p[M*10];
int w[M];
int pp[M*10];
bool f[M*10];
int P[M*2];
pair<int,int> ans;
LL now=1e15;
int n,maxn,tot;
int main(){
	n=read();
	for (int i=1;i<=n;i++){
		int y=read();
		maxn=max(maxn,y);
		if (p[y]) pp[y]=p[y];
		p[y]=i;
	}
//	for (int i=2;i<=maxn;i++){
//		if (!f[i]) P[++tot]=i;
//		for (int j=1;i*P[j]<=maxn;j++){
//			f[i*P[j]]=1;
//			if (i%P[j]==0) break;
//		}
//	}
	for (int i=1;i<=maxn;i++){
		if (i>=now) break;
		bool ok=0;
		int o=0,oo=0;
		for (int u=i,times=1;u<=maxn;u+=i,times++){
			if (ok) {
				if (1ll*oo*times*i>now) break;
			}
			else if (1ll*times*times*i>now) break;
			if (p[u]){
				if (ok){
					LL temp=1ll*times*oo*i;
					if (now>temp) {
						now=temp;
						ans.first=o; ans.second=p[u];
					}
					continue;
				}
				else {
					o=p[u]; oo=times; ok=1;
				}
			}
			if (pp[u]){
				LL temp=1ll*times*oo*i;
				if (now>temp) {
					now=temp;
					ans.first=o; ans.second=pp[u];
				}
				continue;
			}
		}
//		cout<<i<<" "<<now<<"\n"; 
	}

	if (ans.first>ans.second) swap(ans.first,ans.second);
//	if (ans.first==622439)cout<<now<<"\n";
	cout<<ans.first<<" "<<ans.second<<"\n";
    return 0;
}