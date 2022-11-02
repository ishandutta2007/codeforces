#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"-----------------"#x"-----------------\n"
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
                    For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int,int> pii;
LL read(){
    LL x=0,f=0;
    char ch=getchar();
    while (!isdigit(ch))
        f=ch=='-',ch=getchar();
    while (isdigit(ch))
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return f?-x:x;
}
const int N=3005;
int r,c,n,k;
vector <int> p[N];
LL ans=0;
LL calc(int x){
	return x*(x+1)/2;
}
LL calc(int x,int y){
	return (x+y)*(y-x+1)/2;
}
int cnt[N],pos[N],sc[N];
int nxt[N],pre[N];
int main(){
	r=read(),c=read(),n=read(),k=read();
	For(i,1,n){
		int x=read(),y=read();
		p[x].pb(y);
	}
	ans=calc(1,r)*calc(1,c);
	For(i,1,r){
		clr(cnt),clr(nxt),clr(pre),clr(sc),clr(pos);
		For(j,i,r)
			for (auto x : p[j])
				cnt[x]++;
		cnt[c+1]=k;
		int las=0;
		For(j,1,c){
			if (!cnt[j])
				continue;
			nxt[las]=j,pre[j]=las;
			las=j;
		}
		nxt[las]=c+1,pre[c+1]=las;
		LL tmp=0;
		for (int i=0;i<=c;i=nxt[i])
			tmp+=calc(nxt[i]-i-1);
		for (int i=nxt[0];i<=c;i=nxt[i]){
			pos[i]=pos[pre[i]];
			sc[i]=sc[pre[i]]-cnt[pre[i]];
			while (sc[i]+cnt[nxt[pos[i]]]<k){
				pos[i]=nxt[pos[i]];
				sc[i]+=cnt[pos[i]];
			}
			tmp+=(i-pre[i])*(nxt[pos[i]]-i);
		}
		Fod(j,r,i){
			ans-=tmp;
			if (j>i){
				for (auto x : p[j]){
					cnt[x]--;
					if (!cnt[x]){
						tmp-=(x-pre[x])*(nxt[pos[x]]-x);
						tmp-=calc(x-pre[x]-1);
						tmp-=calc(nxt[x]-x-1);
						tmp+=calc(nxt[x]-pre[x]-1);
						if (nxt[x]!=c+1)
							tmp+=(x-pre[x])*(nxt[pos[nxt[x]]]-nxt[x]);
						for (int y=pre[x];y&&pos[y]>=pre[x];y=pre[y]){
							if (pos[y]>=x)
								sc[y]--;
							tmp-=(y-pre[y])*(nxt[pos[y]]-y);
							while (sc[y]+cnt[nxt[pos[y]]]<k){
								pos[y]=nxt[pos[y]];
								sc[y]+=cnt[pos[y]];
							}
							tmp+=(y-pre[y])*(nxt[pos[y]]-y);
						}
						nxt[pre[x]]=nxt[x];
						pre[nxt[x]]=pre[x];
					}
					else {
						for (int y=x;y&&pos[y]>=pre[x];y=pre[y]){
							if (pos[y]>=x)
								sc[y]--;
							tmp-=(y-pre[y])*(nxt[pos[y]]-y);
							while (sc[y]+cnt[nxt[pos[y]]]<k){
								pos[y]=nxt[pos[y]];
								sc[y]+=cnt[pos[y]];
							}
							tmp+=(y-pre[y])*(nxt[pos[y]]-y);
						}
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}