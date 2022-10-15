#include <cstdio>
const int N=60;
int T,n,c;char s[N],t[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %s",&n,t+1),s[c=n]='\0';
		for(int i=n;i;--i){
			if(t[i]=='0'){
				int p=(t[i-2]^48)*10+(t[i-1]^48);
				i-=2,s[--c]=p+'a'-1;
			}
			else s[--c]=(t[i]^48)+'a'-1;
		}
		puts(s+c);
	}
	return 0;
}