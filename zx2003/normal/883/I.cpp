#include<cstdio>
#include<cstring>
#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define LL long long
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
using namespace std;
typedef pair<int,int> pa;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
int n,k,a[500010],st[300010][20],ST[300010][20],LOG2[300010],f[500010];
int getmax(int x,int y){
	int t=LOG2[y-x+1];
	return max(st[x][t],st[y-(1<<t)+1][t]);
}
int getmin(int x,int y){
	int t=LOG2[y-x+1];
	return min(ST[x][t],ST[y-(1<<t)+1][t]);
}
bool check(int o){
	int l=0;
	f[0]=1;
	int tot=0;
	int r=-1;
	FOR(i,k,n){
		++r;
		tot+=f[r];
		while (getmax(l+1,i)-getmin(l+1,i)>o) tot-=f[l],++l;
		if (tot>0) f[i]=1;
		else f[i]=0;
	}
	return (f[n]);
}
int main(){
	cin>>n>>k;
	FOR(i,1,n) getint(a[i]);
	sort(a+1,a+n+1);
	FOR(i,1,n) st[i][0]=a[i],ST[i][0]=a[i];
	FOR(j,1,18) LOG2[1<<j]=1;
	FOR(i,1,n) LOG2[i]+=LOG2[i-1];
	FOR(j,1,18)
		FOR(i,1,n)
			if (i+(1<<(j-1))<=n) st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
			else st[i][j]=st[i][j-1];
	FOR(j,1,18)
		FOR(i,1,n)
			if (i+(1<<(j-1))<=n) ST[i][j]=min(ST[i][j-1],ST[i+(1<<(j-1))][j-1]);
			else ST[i][j]=ST[i][j-1];
	int l=0,r=1e9;
	while (l<r){
		int o=l+r>>1;
		if (check(o)) r=o;
		else l=o+1;
	}
	printf("%d\n",r);
	return 0;
}