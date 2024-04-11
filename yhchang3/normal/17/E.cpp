#include<bits/stdc++.h>
using namespace std;

const int mn = 2e6+10,sigma = 26;
int s[mn],len[mn],/*nxt[mn][sigma],*/fail[mn],cnt[mn],dep[mn];
int n,last,sz;

vector<pair<int,int> > nxt[mn];

void init(){
	for(int i=0;i<sz;i++){
		cnt[i]=0;
		nxt[i].clear();//memset(nxt[i],0,sizeof nxt[i]);
	}
	last=n=0;sz=2;s[n]=-1;fail[0]=1;len[1]=-1;
}

int get_fail(int x){
	while(s[n-len[x]-1]!=s[n])	x=fail[x];
	return x;
}

int find(int x,int c){
	for(int i=0;i<nxt[x].size();i++)
		if(nxt[x][i].first==c)
			return nxt[x][i].second;
	return 0;
}
/*
void add(int c){
	s[++n]=c;
	last = get_fail(last);
	if(!nxt[last][c]){
		len[sz]=len[last]+2;
		fail[sz]=nxt[get_fail(fail[last])][c];
		dep[sz]=dep[fail[sz]]+1;
		nxt[last][c]=sz++;
	}
	last=nxt[last][c];
	cnt[last]++;
}
*/

void add(int c){
	s[++n]=c;
	last = get_fail(last);
	if(find(last,c)==0){
		len[sz]=len[last]+2;
		fail[sz]=find(get_fail(fail[last]),c);
		dep[sz]=dep[fail[sz]]+1;
		nxt[last].emplace_back(c,sz++);
	}
	last=find(last,c);
	cnt[last]++;
}
void total(){
	for(int i=sz-1;i>=0;i--)
		cnt[fail[i]]+=cnt[i];
}

const int mod = 51123987;

int pre[mn];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int nn;
	string ss;
	cin>>nn>>ss;
	init();
	for(int i=0;i<nn;i++){
		add(ss[i]-'a');
		pre[i+1]=pre[i]=(pre[i]+dep[last])%mod;
	}
	long long int ans=pre[nn];
	ans=(ans*(ans-1)/2)%mod;
	init();
	for(int i=nn-1;i>0;i--){
		add(ss[i]-'a');
		ans=(ans-1LL*dep[last]*pre[i-1])%mod;
	}
	cout<<(ans+mod)%mod<<endl;

}