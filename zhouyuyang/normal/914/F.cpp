#include<bits/stdc++.h>
#define N 100005
using namespace std;
char s[N],t[N];
bitset<N> szb,f[28];
int Q;
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	for (int i=1;i<=n;i++)
		f[s[i]-'a'][i]=1;
	scanf("%d",&Q);
	while (Q--){
		int fl;
		scanf("%d",&fl);
		if (fl==1){
			int x;
			char c[5];
			scanf("%d%s",&x,c+1);
			f[s[x]-'a'][x]=0;
			s[x]=c[1];
			f[s[x]-'a'][x]=1;
		}
		else{
			int l,r,len;
			scanf("%d%d%s",&l,&r,t+1);
			len=strlen(t+1);
			r-=len-1;
			if (r<l){
				puts("0");
				continue;
			}
			szb.reset();
			szb=~szb;
			for (int i=1;i<=len;i++)
				szb&=f[t[i]-'a']>>(i-1);
			szb>>=l;
			int ans=szb.count();
			szb>>=r-l+1;
			ans-=szb.count();
			printf("%d\n",ans);
		}
	}
}