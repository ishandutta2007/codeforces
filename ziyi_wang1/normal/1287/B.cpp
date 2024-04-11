#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
typedef long long ll;
map<string,int>mp;
string s;
char c[2020][110],t[110];
int n,m;
ll ans;
void Match(int x,int y){
	F(i,1,m){
		if(c[x][i]==c[y][i])t[i]=c[x][i];
		else {
			if(c[x][i]=='S'&&c[y][i]=='E')t[i]='T';
			else if(c[x][i]=='S'&&c[y][i]=='T')t[i]='E';
			else if(c[x][i]=='E'&&c[y][i]=='S')t[i]='T';
			else if(c[x][i]=='E'&&c[y][i]=='T')t[i]='S';
			else if(c[x][i]=='T'&&c[y][i]=='S')t[i]='E';
			else t[i]='S';
		}
	}
	s.clear();s.append(t+1);
}
int main(){
	cin>>n>>m;
	F(i,1,n)cin>>c[i]+1;
	F(i,1,n-1){
		F(j,i+1,n){
			Match(i,j);
			if(!mp.count(s))continue;
			ans+=mp[s];
		}
		s.clear();s.append(c[i]+1);mp.insert(make_pair(s,1));
	}
	cout<<ans;
	return 0;
}