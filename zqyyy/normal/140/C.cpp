#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fi first
#define se second
inline int read(){
	int f=1,r=0;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))r=(r<<1)+(r<<3)+(ch^48),ch=getchar();
	return f?r:-r;
}
const int N=1e5+5;
int n,ans,a[N],b[N][3];
priority_queue<pii>Q;
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int cnt=1;
		for(int j=i+1;j<=n+1;j++)
			if(a[j]==a[i])cnt++;
			else {i=j-1;break;}
		Q.push(pii(cnt,a[i]));
	}
	while(Q.size()>2){
		pii A=Q.top();Q.pop();
		pii B=Q.top();Q.pop();
		pii C=Q.top();Q.pop();
		int d=A.se,e=B.se,f=C.se;
		if(d<e)swap(d,e);
		if(d<f)swap(d,f);
		if(e<f)swap(e,f);
		ans++,b[ans][0]=d,b[ans][1]=e,b[ans][2]=f;
		if(--A.fi)Q.push(A);
		if(--B.fi)Q.push(B);
		if(--C.fi)Q.push(C);
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans;i++)
		printf("%d %d %d\n",b[i][0],b[i][1],b[i][2]);
	return 0;
}