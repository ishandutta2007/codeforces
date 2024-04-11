#include<bits/stdc++.h>
#define LL long long

using namespace std;
const int M=2e5+100;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
	return w*c;
}
map<int,int> m;
int a[M],n,ans,cnt;
int  h[M],p[M];
int main(){
	n=read();
	for (int i=1;i<=n;i++){
		a[i]=read();
		++m[a[i]];
	}
	for (map<int,int>::iterator it=m.begin();it!=m.end();it++){
		p[++cnt]=it->second;
	}
	sort(p+1,p+cnt+1);
//	for (int i=1;i<=cnt;i++){
//		cout<<p[i]<<"\n";
//	}
	for (int i=1;i<=n;i++){
		int sum=0,l=1,k=i,nq;
		int q=upper_bound(p+l,p+cnt+1,k-1)-p;
		while (q!=cnt+1){
			 l=q+1;sum+=k;
			k<<=1;
			nq=upper_bound(p+l,p+cnt+1,k-1)-p;
			if (nq==q) nq++;q=nq;
		}
		//cout<<sum<<" "<<i<<"\n";
		if (sum>ans) ans=sum;
	}
	cout<<ans<<"\n";
	return 0;
}