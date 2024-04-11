#include <cstdio>
#include <cstring>
const int N=2e5+10;
int T,n,w,ll,rr,sum[N];
char s[N];
inline int c(char h){
	if(h=='(')return 1;
	if(h==')')return -1;
	return 0;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1),n=strlen(s+1),w=n>>1,ll=rr=0;
		for(int i=1;i<=n;++i)if(s[i]=='(')--w;
		for(int i=1;i<=n;++i){
			if(s[i]=='?'){		
				if(w>0)ll=i,--w,s[i]='(';
				else{
					if(!w)rr=i;
					--w,s[i]=')';
				}
			}
			sum[i]=sum[i-1]+c(s[i]);
		}
		bool tag=true;if(!ll||!rr)tag=false;
		for(int i=ll;i<rr;++i)tag&=sum[i]>1;
		puts(tag?"NO":"YES");
	}
	return 0;
}