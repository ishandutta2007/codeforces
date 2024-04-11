#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,k,s[N],a[N],f;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		f=0;s[0]=0;
		for(int i=1,x;i<=n;++i){
			scanf("%d",&a[i]);
			if(a[i]==k) f=1;
			if(a[i]<k) s[i]=s[i-1]-1;
			else s[i]=s[i-1]+1;
		}
		if(!f){puts("no");continue;}
		if(n==1){puts("yes");continue;}
		f=0;
		int mn=s[0];
		for(int i=2;i<=n;++i){
			if(s[i]-mn>0){puts("yes");f=1;break;}
			mn=min(mn,s[i-1]);
		}
		if(!f) puts("no"); 
	}
	return 0;
}