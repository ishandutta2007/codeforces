#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=1e5+7;
int n;
char s[N],t[N];
inline void work(){
	n=read();
	scanf("%s%s",s+1,t+1);
	int ans=0,cnt=0,res=0;
	for(int i=1;i<=n;i++){
		if(s[i]+t[i]==96){
			if(!res)cnt++;
			else ans+=2,res=0;
		}else if(s[i]+t[i]==97)ans+=2+cnt,cnt=res=0;
		else{
			if(cnt)ans+=2+cnt-1,res=cnt=0;
			else res=1;
		}
	}
	printf("%d\n",ans+cnt);
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}