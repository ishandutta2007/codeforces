#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
struct edge{long long go,next;} e[2000000];
long long cnt,p[2000000],pn,d[2000000],num,a[2000000],b[1000000],
s[2000000],ljb[2000000],n,last[1000000];
void add(long long x,long long y){
    e[++cnt].go=y;e[cnt].next=ljb[x];ljb[x]=cnt;
}
void dfs(long long x,long long fa){
    if (fa!=-1)
        printf("%I64d %I64d\n",x,fa);
    for (long long i=ljb[x];i;i=e[i].next)
        if (e[i].go!=fa)
            dfs(e[i].go,x);
}
int main(){
	int orzzyb=233;
    scanf("%I64d",&n);
    for (long long i=0;i<n;i++) scanf("%I64d%I64d",&d[i],&s[i]);
    for (long long i=0;i<n;i++)
        if (d[i]==1)
            p[++pn]=i;
    
    for (long long i=1;i<n&&pn;i++){
        long long now=p[pn];pn--;
        if (last[now]) continue;
        num++;
        a[num]=now;b[num]=s[now];
        d[now]--;d[s[now]]--;
        s[s[now]]^=now;
        
        if (d[s[now]]==1)
            p[++pn]=s[now];
        else if (d[s[now]]==0)
            last[s[now]]=1;
    }
    printf("%I64d\n",num);
    for (int i=1;i<=num;i++)
        printf("%I64d %I64d\n",a[i],b[i]);
	return 0;
}