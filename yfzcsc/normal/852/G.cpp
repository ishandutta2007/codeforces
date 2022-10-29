#include<bits/stdc++.h>
#define base1 19260817
#define mod1 1000000007
#define base2 20010919
#define mod2 1000000009
using namespace std;
struct Hash{
	int x,y;
	Hash(){x=y=0;}
	Hash(int x,int y):x(x),y(y){}
	Hash operator+(const Hash& h)const{return Hash((x+h.x)%mod1,(y+h.y)%mod2);}
	Hash operator-(const Hash& h)const{return Hash((x-h.x+mod1)%mod1,(y-h.y+mod2)%mod2);}
	Hash operator*(const int& p)const{return Hash(1ll*x*p%mod1,1ll*y*p%mod2);}
	Hash operator*(const Hash& h)const{return Hash(1ll*x*h.x%mod1,1ll*y*h.y%mod2);}
	bool operator==(const Hash& h)const{return x==h.x&&y==h.y;}
	bool operator!=(const Hash& h)const{return x!=h.x||y!=h.y;}
	bool operator<(const Hash& h)const{return x==h.x?y<h.y:x<h.x;}
};
int n,m,ans=0;
map<Hash,int>st;
set<Hash>st2;
char s[100100];
void dfs(int p,int d){
	if(!s[p]){
		Hash h(0,0);
		for(int i=0;i<p;++i)if(s[i])
			h=h*Hash(base1,base2)+Hash(s[i],s[i]);
		if(st2.count(h))return ;
		st2.insert(h);
		ans+=st[h];
		return ;
	}
	if(s[p]=='?'){
		for(int i='a';i<='e';++i)s[p]=i,dfs(p+1,1);
		if(!d)s[p]=0,dfs(p+1,d);
		s[p]='?';
	} else dfs(p+1,0);
}
int main(){
	scanf("%d%d\n",&n,&m);
	for(int i=1;i<=n;++i){
		gets(s);
		int len=strlen(s);
		Hash ans(0,0);
		for(int j=0;j<len;++j)
			ans=ans*Hash(base1,base2)+Hash(s[j],s[j]);
//		printf("[Accepted,%d,%d]",ans.x,len);
		st[ans]++;
	}
	for(int i=1;i<=m;++i){
		gets(s);st2.clear();
		ans=0,dfs(0,0),printf("%d\n",ans);
	}
}