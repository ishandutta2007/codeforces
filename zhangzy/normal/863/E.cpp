#include<bits/stdc++.h>
using namespace std;

int n,a[202000],b[202000],las=0,tid=0,c[804000],f[2334000][20];
map<int,int>mp;
map<int,int>::iterator it;

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n; scanf("%d%d",&a[i],&b[i]),mp[a[i]]=mp[b[i]]=1,i++);
	for (it=mp.begin();it!=mp.end();las=(int)it++->first) mp[(int)it->first]= (tid+= las+1==(int)it->first? 1:2);
	for (int i=1;i<=n;i++) c[a[i]=mp[a[i]]]++,c[b[i]=mp[b[i]]+1]--;
	for (int i=2;i<=tid;i++) c[i]+=c[i-1];
	memset(f,62,sizeof f);
	for (int i=tid;i>0;i--){
		f[i][0]=c[i];
		for (int j=1;j<20;j++)f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	}
	for (int i=1,p,mn;i<=n;i++){
		mn=2333;p=a[i];
		for (int j=19;j>=0;j--){
			if (p+(1<<j)<=b[i]){
				mn=min(mn,f[p][j]);
				p+=(1<<j);
			}
		}
		if (mn>1) return 0*printf("%d",i);
	}
	printf("-1");
}