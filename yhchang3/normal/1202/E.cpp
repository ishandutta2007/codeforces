#include<bits/stdc++.h>
using namespace std;

int n;
const int MAXN = 2e5+10;
const int ALPHASIZE = 26;
string t,s[MAXN];
int fail[MAXN],trans[MAXN][ALPHASIZE];
int Trieidx;
int cnt[MAXN];
long long int ans1[MAXN],ans2[MAXN];


void init(){
	memset(trans,0,sizeof trans);
	memset(fail,0,sizeof fail);
	memset(cnt,0,sizeof cnt);
	Trieidx=0;
}

void insert(string& pattern){
	int now=0;
	for(int i=0;i<pattern.size();i++)
		if(trans[now][pattern[i]-'a'])
			now=trans[now][pattern[i]-'a'];
		else
			now=trans[now][pattern[i]-'a']=++Trieidx;
	cnt[now]++;
}

void build(){
	int now=0;
	queue<int> q;
	for(int i=0;i<ALPHASIZE;i++)
		if(trans[now][i])
			q.push(trans[now][i]);
	while(!q.empty()){
		now=q.front();q.pop();
		for(int i=0;i<ALPHASIZE;i++){
			if(trans[now][i]){
				fail[trans[now][i]]=trans[fail[now]][i];
				cnt[trans[now][i]]+=cnt[trans[fail[now]][i]];
				q.push(trans[now][i]);
			}
			else
				trans[now][i]=trans[fail[now]][i];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t>>n;
	for(int i=0;i<n;i++)
		cin>>s[i];
	init();
	for(int i=0;i<n;i++)
		insert(s[i]);
	build();
	int now=0;
	for(int i=0;i<t.size();i++){
		now=trans[now][t[i]-'a'];
		ans1[i]=cnt[now];
	}
	reverse(t.begin(),t.end());
	init();
	for(int i=0;i<n;i++)
		reverse(s[i].begin(),s[i].end());
	for(int i=0;i<n;i++)
		insert(s[i]);
	build();
	now=0;
	for(int i=0;i<t.size();i++){
		now=trans[now][t[i]-'a'];
		ans2[i]=cnt[now];
	}
	long long int ans=0;
	for(int i=0;i<t.size();i++)
		if((int)t.size()-i-2>=0)
			ans+=ans1[i]*ans2[t.size()-i-2];
	cout<<ans<<endl;
}