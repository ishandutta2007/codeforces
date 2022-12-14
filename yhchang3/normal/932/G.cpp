#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10,sigma = 26;
int s[maxn],len[maxn],nxt[maxn][sigma],fail[maxn],cnt[maxn];
int n,last,sz,dep[maxn],diff[maxn],top[maxn];
int g[maxn],f[maxn];
//f:dp trans by [j+1~i] is a palindrome,g:sum of f[i] by fail_link 
void init(){
	for(int i=0;i<sz;i++)   cnt[i]=0,memset(nxt[i],0,sizeof nxt[i]);
	last=n=0;sz=2;s[0]=len[1]=-1;fail[0]=1;;
}
int get_fail(int x){ while(s[n-len[x]-1]!=s[n])	x=fail[x];return x;}
void add(int c){
	s[++n]=c,last = get_fail(last);
	if(!nxt[last][c]){
		len[sz]=len[last]+2,fail[sz]=nxt[get_fail(fail[last])][c];
		diff[sz]=len[sz]-len[fail[sz]];
		top[sz]= diff[sz]==diff[fail[sz]]?top[fail[sz]]:fail[sz];
		dep[sz]=dep[fail[sz]]+1,nxt[last][c]=sz++;
	}
	last=nxt[last][c],cnt[last]++;
}
void total(){for(int i=sz-1;i>=0;i--)cnt[fail[i]]+=cnt[i];}
const int mod = 1e9+7;
void trans(int i){
	for(int p=last;p>1;p=top[p]){
		g[p]=f[i-len[top[p]]-diff[p]];
		if(diff[p]==diff[fail[p]])  g[p]=(g[p]+g[fail[p]])%mod;
		if(i%2==0)	f[i]=(f[i]+g[p])%mod;
	}
}



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string ss;
	cin>>ss;
	string t;
	for(int i=0;i*2<ss.size();i++)
		t+=ss[i],t+=ss[ss.size()-i-1];
	init();
	f[0]=1;
	for(int i=0;i<t.size();i++){
		add(t[i]-'a');
		trans(i+1);
	}
	cout<<f[t.size()]<<endl;
}