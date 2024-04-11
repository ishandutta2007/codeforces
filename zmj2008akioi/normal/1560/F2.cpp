#include <cstdio>
#define int long long
int t,n,k,len,cnt,ans,maxdig,dig[12],pow[15]={1,(int)1e1,(int)1e2,(int)1e3,(int)1e4,(int)1e5,(int)1e6,(int)1e7,(int)1e8,(int)1e9};
bool vis[10];
inline int min(int x,int y){
	return x<y?x:y;
}
inline int max(int x,int y){
	return x>y?x:y;
}
inline bool check(int n,int k){
	while(n){
		if(!vis[n%10])vis[n%10]=true,--k;
		n/=10;
	}
	return k>=0;
}
signed main(){
	scanf("%lld",&t);
	for(register int i=0;i<t;++i){
		scanf("%lld %lld",&n,&k);
		for(register int j=0;j<10;++j)vis[j]=false;
		if(check(n,k)){
			printf("%lld\n",n);
			continue;
		}
		for(register int j=0;j<10;++j)vis[j]=false;
		cnt=len=maxdig=0,ans=2e9;
		int power=1;
		while(power<=n)++len,power*=10;
		int length=len,pre=0;
		while(n)dig[length--]=n%10,n/=10;
		for(register int j=1;j<=len;++j){
			if(j-1)pre+=dig[j-1]*pow[len-j+1];
			if(j-1)if(!vis[dig[j-1]])++cnt,vis[dig[j-1]]=true;
			if(cnt>k)break;
			if(cnt==k){
				for(register int k=dig[j]+1;k<10;++k){
					if(vis[k]){
						int now=pre+k*pow[len-j];
						for(register int l=0;l<10;++l){
							if(vis[l]||l==k){
								int rec=now;
								for(register int p=j+1;p<=len;++p)rec+=l*pow[len-p];
								ans=min(ans,rec);
							}
						}
					}
				}
			}
			else if(cnt==k-1){
				for(register int k=dig[j]+1;k<10;++k){
					if(vis[k])ans=min(ans,pre+k*pow[len-j]);
					else for(register int l=0;l<10;++l){
						if(vis[l]||l==k){
							int now=pre+k*pow[len-j];
							for(register int p=j+1;p<=len;++p)
							    now+=l*pow[len-p];
							ans=min(ans,now);
						}
					}
				}
			}
			else if(dig[j]!=9)ans=min(ans,pre+(dig[j]+1)*pow[len-j]);
		}
		printf("%lld\n",ans);
	}
}