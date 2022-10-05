#include<bits/stdc++.h>
using namespace std;

int n,k,a[301000];
int l,r,now,ans;

int p,f[301000];
bool check(){
	memset(f,0,sizeof f);
	p=1;
	for (int i=1;i<=n;i++){
		while (a[i]-a[p]>now) p++;
		//if (now==0) printf("%d::%d  %d\n",i,p,i-k);
		if (i>=k){
			if (p==1) f[i]=1;
			else if (p<=i-k+1&&f[i-k]-f[max(p-2,0)]) f[i]=1;
		}
		f[i]+=f[i-1];
	}
	//if (now==0) for (int i=1;i<=n;i++) printf(" %d",f[i]);
	return f[n]-f[n-1];
}

int main(){
	scanf("%d%d",&n,&k); if (k==1) return 0*printf("0");
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (l=0,r=1e9;l<=r;){
		now=l+r>>1;
		if (check()){
			r=(ans=now)-1;
		}else{
			l=now+1;
		}
	}
	cout<<ans;
}