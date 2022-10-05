#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,m,x,bas[22],tot,f[1100000],pre[1100000],fl[1100000],las=1;
vector<int>c[1100000];

int exgcd(int a,int b,int &c,int &x,int &y){
	if (!b) c=a, x=1, y=0;
	else exgcd(b,a%b,c,y,x), y-=a/b*x;
}

int cal(int a,int b){
	int c,x,y;
	exgcd(a,m,c,x,y);
	x=(x%m+m)%m;
	x=(ll)x*(b/c)%m;
	return x;
}

int BB(int x){
	int now=0;
	for (int j=0;j<tot;++j) if (x%bas[j]==0)
		now|=1<<j, x/=bas[j];
	return now;
}

int dfs(int now){
	if (~f[now]) return f[now];
	int res=0,t;
	for (int i=0;i<tot;++i) if (now&(1<<i)){
		t=dfs(now^(1<<i));
		if (t>res) pre[now]=i, res=t;
	}
	return f[now]=res+c[now].size();
}

void prt(int now){
	if (~pre[now]) prt(now^(1<<pre[now]));
	for (auto o:c[now]){
		printf("%d ",cal(las,o));
		las=o;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m; x=m;
	for (int i=2;x>1;)
		if (x%i==0) bas[tot++]=i, x/=i;
		else ++i;
	for (;n--;) cin>>x, fl[x]=1;
	for (int i=0;i<m;++i) if (!fl[i]) c[BB(i)].push_back(i);
	memset(f,-1,sizeof f);
	memset(pre,-1,sizeof pre);
	cout<<dfs((1<<tot)-1)<<endl;
	prt((1<<tot)-1);
}