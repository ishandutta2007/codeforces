#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))r=(r<<1)+(r<<3)+(ch^48),ch=getchar();
	return f?r:-r;
}
const int N=1e5+5;
int n,K,num[26];
string s;
inline void work(){
	n=read(),K=read(),cin>>s;
	if(n%K)return (void)puts("-1");
	memset(num,0,sizeof(num));
	for(int i=0;i<n;i++)(++num[s[i]-'a'])%=K;
	bool ok=1; 
	for(int i=0;i<26;i++)ok&=(!num[i]);
	if(ok)return cout<<s<<endl,void();
	for(int i=n-1;~i;i--){
		(num[s[i]-'a']+=K-1)%=K;
		for(int j=s[i]+1;j<='z';j++){
			(++num[j-'a'])%=K;
			int g=0;
			for(int k=0;k<26;k++)g+=(K-num[k])%K;
			if(g<n-i){
				for(int k=0;k<i;k++)putchar(s[k]);
				putchar(j);
				int yu=n-i-1-g;
				for(int k=1;k<=yu;k++)putchar('a');
				for(int k=0;k<26;k++)
					for(int l=1;l<=(K-num[k])%K;l++)
						putchar('a'+k);
				puts("");return ;
			}
			(num[j-'a']+=K-1)%=K;
		} 
	}
	puts("-1");
}
int main(){
	int T=read();
	while(T--)work();
	return 0;	
}