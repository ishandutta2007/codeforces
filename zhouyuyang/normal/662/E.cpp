#include<bits/stdc++.h>
#define For(i,j,k) for (int i=j;i<=k;i++)
#define N 5005
using namespace std;
int ta[N],tb[N],tc[N],hack[N];
bool hacka[N],hackb[N],hackc[N];
int waa,wab,wac,la,lb,lc,ans;
int f[90][90][90];
int g[90][90][90];
void upd(int &x,int y){
	x<y?x=y:0;
}
int main(){
	int n;
	scanf("%d",&n);
	waa=wab=wac=n;
	For(i,1,n){
		int x;
		scanf("%d",&x);
		if (!x) x=250,waa--;
		else if (x<0){
			la++; x=-x;
			hacka[i]=hack[i]=1;
		}
		ta[i]=250-x;
		scanf("%d",&x);
		if (!x) x=250,wab--;
		else if (x<0){
			lb++; x=-x;
			hackb[i]=hack[i]=1;
		}
		tb[i]=250-x;
		scanf("%d",&x);
		if (!x) x=250,wac--;
		else if (x<0){
			lc++; x=-x;
			hackc[i]=hack[i]=1;
		}
		tc[i]=250-x;
	}
	if (la+lb+lc>=90)
		return puts("1"),0;
	const int po[7]={0,3000,2500,2000,1500,1000,500};
	const int lim[7]={-1,n/32,n/16,n/8,n/4,n/2,n};
	For(a,1,6) if (lim[a-1]<waa&&waa-la<=lim[a])
		For(b,1,6) if (lim[b-1]<wab&&wab-lb<=lim[b])
			For(c,1,6) if (lim[c-1]<wac&&wac-lc<=lim[c]){
				int sa=0,sb=0,sc=0; f[0][0][0]=0;
				int p=po[a]*ta[1]+po[b]*tb[1]+po[c]*tc[1];
				p+=min(waa-lim[a-1]-1,la)*100*250;
				p+=min(wab-lim[b-1]-1,lb)*100*250;
				p+=min(wac-lim[c-1]-1,lc)*100*250;
				int tmp=0;
				For(i,2,n){
					int pa=po[a]*ta[i];
					int pb=po[b]*tb[i];
					int pc=po[c]*tc[i];
					if (!hack[i]){
						tmp+=(p>=pa+pb+pc);
						continue;
					}
					For(ea,0,sa) For(eb,0,sb) For(ec,0,sc){
						int k=f[ea][eb][ec];
						upd(g[ea][eb][ec],k+(p>=(pa+pb+pc)));
						if (hacka[i]) upd(g[ea+1][eb][ec],k+(p>=(pb+pc)));
						if (hackb[i]) upd(g[ea][eb+1][ec],k+(p>=(pa+pc)));
						if (hackc[i]) upd(g[ea][eb][ec+1],k+(p>=(pa+pb)));
						if (hacka[i]&&hackb[i]) upd(g[ea+1][eb+1][ec],k+(p>=pc));
						if (hacka[i]&&hackc[i]) upd(g[ea+1][eb][ec+1],k+(p>=pb));
						if (hackb[i]&&hackc[i]) upd(g[ea][eb+1][ec+1],k+(p>=pa));
						if (hacka[i]&&hackb[i]&&hackc[i]) upd(g[ea+1][eb+1][ec+1],k+1);
					}
					sa+=hacka[i];
					sb+=hackb[i];
					sc+=hackc[i];
					For(ea,0,sa) For(eb,0,sb) For(ec,0,sc)
						f[ea][eb][ec]=g[ea][eb][ec],g[ea][eb][ec]=0;
				}
				ans=max(ans,f[min(waa-lim[a-1]-1,la)]
							 [min(wab-lim[b-1]-1,lb)]
							 [min(wac-lim[c-1]-1,lc)]+tmp); 
			}
	printf("%d",n-ans);
}
//30*30*30*30*