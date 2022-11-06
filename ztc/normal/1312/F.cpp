#include<stdio.h>
int f[100002][3],n,t,x,y,z;
inline int Max(int p,int q){return p>q?p:q;}
inline int Mex(int p,int q){return p&&q?0:(p!=1&&q!=1?1:2);}
inline int Mex(int p,int q,int r){
	int mk[4]={0,0,0,0};
	mk[p]=mk[q]=mk[r]=1;
	for(int i=0;i<4;i++)if(!mk[i])return i;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&n,&x,&y,&z);
		f[0][0]=f[0][1]=f[0][2]=0;int d=(x+y)*(y+z)*(z+x);
		for(int i=1;i<=d+d+d;i++){
			int p=f[Max(i-x,0)][0],q=f[Max(i-y,0)][1],r=f[Max(i-z,0)][2];
			f[i][0]=Mex(p,q,r);f[i][1]=Mex(p,r);f[i][2]=Mex(p,q);
		}int v=0,s[4]={0,0,0,0};
		for(int i=1;i<=n;i++){
			long long p;scanf("%lld",&p);
			p=p>d+d?p%d+d+d:p;
			int val=f[p][0],v0=f[Max(p-x,0)][0],v1=f[Max(p-y,0)][1],v2=f[Max(p-z,0)][2];
			v^=val;s[val^v0]++;s[val^v1]++;s[val^v2]++;
		}printf("%d\n",s[v]);
	}
}