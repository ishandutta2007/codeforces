#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#define REP(i,n) for(int i=0;i<n;i++)
#define PB push_back
using namespace std;
const int MAX_N=int(1e6)+10;
const int MAX_M=int(1e4)+10;

int m;
int n;
char s[MAX_N];
int next[26];
int ask[MAX_M];
int as[MAX_M];
int cnt[MAX_M];

bool cmp(int a,int b){
	return next[a]<next[b];
}

int main(){
	scanf("%s",s);
	n=strlen(s);
	fill(next,next+26,n);
	cin>>m;
	REP(i,m){
		char buf[30];
		scanf("%s",buf);
		int l=strlen(buf);
		REP(j,l)
			ask[i]|=1<<(buf[j]-'a');
		as[i]=ask[i];
	}
	sort(as,as+m);
	
	for(int i=n-1;i>=0;--i){
		next[s[i]-'a']=i;
		int ord[26];
		int ct=0;
		
		REP(j,26)if(next[j]!=n)
			ord[ct++]=j;
		
		sort(ord,ord+ct,cmp);
		int mask=0;
		
		int p;
		if(i>=1)
			p=s[i-1]-'a';
		else
			p=27;
		
		REP(j,ct){
			int nxt=(j+1==ct)?n:next[ord[j+1]];
			int len=nxt-i;
			mask|=1<<ord[j];
			//update as
			if(mask>>p&1)
				continue;
			int l=lower_bound(as,as+m,mask)-as;
			if(as[l]==mask){
				++cnt[l];
			}
		}
	}
	
	REP(i,m){
		int l=lower_bound(as,as+m,ask[i])-as;
		printf("%d\n",cnt[l]);
	}
}