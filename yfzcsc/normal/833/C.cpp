#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans=0,c[20],d[20],e[20],l[20],r[20],len,tag;
ll L,R,ten[20]={1};
void cal(int x){
	x--;
	int i=len;
	for(int i=0;i<=9;++i)d[i]=c[i];
	for(i=len;i>=1;--i)
		if(l[i]!=r[i])break;
		else {
			if(l[i]==0&&x<len)x++;
			else if(d[l[i]])d[l[i]]--;
			else return ;
		}
	if(i==0){ans++;return ;}
	for(int j=l[i]+1;j<r[i];++j)if(d[j]){ans++;return ;}
	int y=x;
	if((l[i]==0&&x<len)||d[l[i]]){
		for(int i=1;i<=9;++i)e[i]=d[i];
		if(l[i]==0)x++;
		else e[l[i]]--;
		if(i==1){ans++;return ;}
		int j=i-1;
		for(;j>=1;--j){
			for(int k=9;k>l[j];--k)if(e[k]){ans++;return ;}
			if((l[j]==0&&x<len))x++;
			else if(!e[l[j]])goto nxt2;
			else e[l[j]]--;
		}
		ans++;return ;
		nxt2:;
	}
	x=y;
	if((r[i]==0&&x<len)||d[r[i]]){
		for(int i=1;i<=9;++i)e[i]=d[i];
		if(r[i]==0)x++;
		else e[r[i]]--;
		if(i==1){ans++;return ;}
		int j=i-1;
		for(;j>=1;--j){
			for(int k=0;k<r[j];++k)
				if((k==0&&x<len)||e[k]){ans++;return ;}
			if(r[j]==0&&x<len)x++;
			else if(!e[r[j]])goto nxt;
			else e[r[j]]--;
		}
		ans++;return ;//printf("[%d]",x);
		nxt:;
	}
}
void dfs(int x,int p){
	if(x>=2){
		int pans=ans;
		if(x==2&&c[1]&&tag)ans++;
		else cal(x);
/*		if(pans!=ans){
			for(int i=1;i<=9;++i)
				for(int j=1;j<=c[i];++j)printf("%d",i);
			puts("");
		}
*/		if(x==len+1)return ;
	}
	for(int i=p;i<=9;++i)
		c[i]++,dfs(x+1,i),c[i]--;
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%lld%lld",&L,&R);
	for(int i=1;i<=18;++i)ten[i]=ten[i-1]*10;
	if(L==1000000000000000000ll&&R==1000000000000000000ll)return puts("1"),0;
	if(R==1000000000000000000ll)R--,tag=1;
	while(R)r[++len]=R%10,R/=10;
	for(int i=len;i>=1;--i)l[i]=L/ten[i-1]%10;
	dfs(1,1);
//	printf("[%d]",len);
	printf("%d\n",ans);
}