#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100005;
int T,n,m,SA[N],rank[N],height[N],tmp[N],tax[N];
char s[N];
int st[N],top,pos[N];
void Sort(int n,int m){
	for (int i=0;i<=m;i++)
		tax[i]=0;
	for (int i=1;i<=n;i++)
		tax[rank[i]]++;
	for (int i=1;i<=m;i++)
		tax[i]+=tax[i-1];
	for (int i=n;i>=1;i--)
		SA[tax[rank[tmp[i]]]--]=tmp[i];
}
bool cmp(int rk[],int x,int y,int w){
	return rk[x]==rk[y]&&rk[x+w]==rk[y+w];
}
void Suffix_Array(char s[],int n){
	memset(SA,0,sizeof SA);
	memset(tmp,0,sizeof tmp);
	memset(rank,0,sizeof rank);
	memset(height,0,sizeof height);
	for (int i=1;i<=n;i++)
		rank[i]=s[i],tmp[i]=i;
	m=127;
	Sort(n,m);
	for (int w=1,p=0;p<n;w<<=1,m=p){
		p=0;
		for (int i=n-w+1;i<=n;i++)
			tmp[++p]=i;
		for (int i=1;i<=n;i++)
			if (SA[i]>w)
				tmp[++p]=SA[i]-w;
		Sort(n,m);
		swap(rank,tmp);
		rank[SA[1]]=p=1;
		for (int i=2;i<=n;i++)
			rank[SA[i]]=cmp(tmp,SA[i],SA[i-1],w)?p:++p;
	}
	for (int i=1,j,k=0;i<=n;height[rank[i++]]=k)
		for (k=max(k-1,0),j=SA[rank[i]-1];s[i+k]==s[j+k];k++);
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		Suffix_Array(s,n);
		LL ans=0;
		top=0;
		memset(st,0,sizeof st);
		memset(pos,0,sizeof pos);
		SA[n+1]=height[0]=0;
		for (int i=2;i<=n+1;i++){
			int nowpos=i,len=height[i];
			while (top>0&&st[top]>len){
				LL v1=st[top]-max(st[top-1],len);
				LL v2=i-pos[top]+1;
				ans+=v1*v2*v2;
				nowpos=pos[top--];
			}
			while (top>0&&st[top]==len)
				nowpos=pos[top--];
			st[++top]=len;
			pos[top]=nowpos;
		}
		for (int i=1;i<=n;i++)
			ans+=n-i+1-max(height[rank[i]],height[rank[i]+1]);
		printf("%I64d\n",ans);
	}
	return 0;
}