#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=200005;
int n;
int SA[N],rank[N],tmp[N],height[N],tax[N];
int sum[N];
int st[N],top,pos[N];
char s[N],t[N];
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
    int m=234;
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
    height[1]=0;
}
int main(){
	scanf("%d",&n);
	scanf("%s%s",s+1,t+1);
	for (int i=1;i<=n/2;i++){
		swap(s[i],s[n-i+1]);
		swap(t[i],t[n-i+1]);
	}
	Suffix_Array(s,n);
	for (int i=1;i<=n;i++)
		if (t[SA[i]]=='1')
			sum[i]=sum[i-1];
		else
			sum[i]=sum[i-1]+1;
	LL ans=0;
	for (int i=1;i<=n;i++)
		if (t[i]=='0')
			ans=max(ans,(LL)n-i+1);
	top=1,st[top]=1,pos[top]=1;
	height[n+1]=0;
	for (int i=2;i<=n+1;i++){
		int j=st[top],p=i;
		while (height[j]>height[i]){
			ans=max(ans,1LL*height[j]*(sum[i-1]-sum[pos[top]-2]));
			p=pos[top];
			j=st[--top];
		}
		st[++top]=i,pos[top]=p;
	}
	printf("%I64d",ans);
	return 0;
}