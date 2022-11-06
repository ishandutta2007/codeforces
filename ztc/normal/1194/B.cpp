#include<stdio.h>
int t,n,m,cnt[400002];char c;
bool a[400002];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)cnt[i]=m;
		for(int i=0;i<n*m;i++){
			while((c=getchar())<'!');
			a[i]=(c=='*');cnt[i/m]-=a[i];
		}int ans=1000000007;
		for(int i=0;i<m;i++){int tot=1000000007,g=0;
			for(int j=0;j<n;j++){
				if(cnt[j]-!a[i+j*m]<tot)tot=cnt[j]-!a[i+j*m];
				g+=!a[i+j*m];
			}if(ans>tot+g)ans=tot+g;
		}printf("%d\n",ans);
	}
}