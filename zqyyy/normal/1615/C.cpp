#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=((r<<1)+(r<<3)+(c&15)),c=getchar();
	return f?r:-r;
}
const int N=1e5+7,inf=1e9;
int n;
char s[N],t[N];
inline void work(){
	n=read(),scanf("%s%s",s+1,t+1);
	int s1=0,t1=0,cnt=0,m0=0,m1=0;
	for(int i=1;i<=n;i++)s1+=s[i]=='1',t1+=t[i]=='1';
	if(s1!=t1 && n-s1+1!=t1){puts("-1");return;}
	for(int i=1;i<=n;i++)
		if(s[i]^t[i]){
			cnt++;
			m0+=s[i]=='0';
			m1+=s[i]=='1';	
		}
	int ans=inf;
	if(cnt%2==0 && m0==m1)ans=min(ans,cnt);
	if((n-cnt)%2==1 && n-s1-m0==s1-m1-1)ans=min(ans,n-cnt);
	if(ans==inf)ans=-1;
	printf("%d\n",ans);
	/*bool fls=1,flt=1,fl=1;
	for(int i=1;i<=n;i++)fls&=s[i]=='0',flt&=t[i]=='0';
	if(fls || flt)puts(fls && flt?"0":"-1"),exit(0);
	for(int i=1;i<=n;i++)fl|=s[i]=='1' && t[i]=='1';
	int ans=0;*/
	
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	int test=read();
	while(test--)work();
    return 0;
}