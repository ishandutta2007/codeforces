#include<bits/stdc++.h>
#define inf 1333333
using namespace std;

map<int,int>mp[233][24];
map<int,int>::iterator it;
string s,sst[233],sen[233];
int n,l,t,m,p1,p2,ans;

void cpy(int now){
	for (int i=1;i<=22;i++){
		for (it=mp[p2][i].begin();it!=mp[p2][i].end();it++){
			mp[now][i][it->first]=1;
		}
	}
	swap(p1,p2);
	for (int i=1;i<=22;i++){
		for (it=mp[p2][i].begin();it!=mp[p2][i].end();it++){
			mp[now][i][it->first]=1;
		}
	}
	swap(p1,p2);
}

int main(){
	cin>>n;
	for (int ttt=1;ttt<=n;ttt++){
		cin>>s;
		l=s.length();
		for (int i=0;i<l;i++){
			t=0;
			for (int j=i;j<l;j++){
				t=t*2+s[j]-'0';
				if (j-i+1>22) break;
				mp[ttt][j-i+1][t]=1;
			}
		}
		if (l>=22){
			sst[ttt]=s.substr(0,22);
			sen[ttt]=s.substr(l-22,22);
		}else{
			sst[ttt]=sen[ttt]=s;
		}
	}
	cin>>m;
	for (int ttt=n+1;ttt<=n+m;ttt++){
		cin>>p1>>p2;
		cpy(ttt);
		s=sen[p1]+sst[p2];
		l=s.length();
		for (int i=0;i<l;i++){
			t=0;
			for (int j=i;j<l;j++){
				t=t*2+s[j]-'0';
				if (j-i+1>22) break;
				mp[ttt][j-i+1][t]=1;
			}
		}
		ans=0;
		for (int i=1;i<=22;i++){
			if (mp[ttt][i].size()==(1<<i)){
				ans=max(ans,i);
			}
		}
		printf("%d\n",ans);
		s=sst[p1]+sst[p2];
		sst[ttt]=s.substr(0,min(22,(int)s.length()));
		s=sen[p1]+sen[p2];
		sen[ttt]=s.substr( max((int)s.length()-22,0) , min(22,(int)s.length()) ) ;
	}
}