#include<bits/stdc++.h>
using namespace std;
const int N=1005;
typedef bitset<N>B;
int n,i,j;
int dd[N][N];
inline B ask(B s,int d){
	cout<<'?';for(int i=0;i<n;++i)cout<<' '<<(s[i]?d:0);cout<<endl;
	static B tmp;tmp.reset();
	string ss;cin>>ss;for(int i=0;i<n;++i)tmp.set(i,ss[i]-'0');
	return tmp;
/*
	static B tmp;tmp.reset();
	for(int i=0;i<n;++i)for(int j=0;j<n;++j)if(j!=i && s[j] && dd[j][i]<=d){
		if(i==39)
++i,--i;
		tmp[i]=1;
	}
	return tmp;
*/
}
B a,b,c,all,ss1[N],ss2[N],s00,s01,s10,s11;
vector<pair<int,int>>ans;
inline void F(B s,B t){
	int i,j;
	static B a[19];
	for(i=0;(1<<i)<=n;++i){
		a[i].reset();
		for(j=0;j<n;++j)if(j+1>>i&1)a[i].set(j);
		a[i]=ask(a[i]&s,1);
	}
	for(i=0;i<n;++i)if(s[i]){
		B z=t;
		for(j=0;(1<<j)<=n;++j)if(i+1>>j&1)z&=a[j];else z&=~a[j];
		for(j=0;j<n;++j)if(z[j])ans.push_back({i,j});
	}
}
void ini(){
	int x,y,i,j,k;
	for(i=0;i<n;++i)for(j=0;j<n;++j)dd[i][j]=i==j?0:N;
	for(i=1;i<n;++i)cin>>x>>y,dd[x][y]=dd[y][x]=1;
	for(i=0;i<n;++i)for(j=0;j<n;++j)for(k=0;k<n;++k)dd[j][k]=min(dd[j][k],dd[j][i]+dd[i][k]);
}
int main(){
//	freopen("1","r",stdin);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
//ini();
	ss1[0].set(0);for(i=1;i<n;++i)ss2[0].set(i);
	for(i=0;(1<<i)<n;++i);
	for(;i>=1;--i){
		a.reset();b.reset();
		for(j=0;j<n;j+=2<<i)a|=ss1[j];
		for(j=1<<i;j<n;j+=2<<i)b|=ss1[j];
		s00=ask(a,(1<<i-1));s01=ask(a,(1<<i-1)-1);
		s10=ask(b,(1<<i-1));s11=ask(b,(1<<i-1)-1);
		for(j=0;j<n;j+=2<<i){
			ss1[j+(1<<i-1)]=(s00^s01)&ss2[j];
			B tmp=ss2[j];
			ss2[j]=(ss2[j]&s00)^ss1[j+(1<<i-1)];
			ss2[j+(1<<i-1)]=tmp^ss2[j]^ss1[j+(1<<i-1)];
		}
		for(j=1<<i;j<n;j+=2<<i){
			ss1[j+(1<<i-1)]=(s10^s11)&ss2[j];
			B tmp=ss2[j];
			ss2[j]=(ss2[j]&s10)^ss1[j+(1<<i-1)];
			ss2[j+(1<<i-1)]=tmp^ss2[j]^ss1[j+(1<<i-1)];
		}
	}
	a.reset();b.reset();
	for(i=0;i<n;i+=3)a|=ss1[i],b|=ss1[i+1],c|=ss1[i+2];
	F(a,b);F(b,c);F(c,a);
//assert(ans.size()==n-1);
	cout<<"!\n";for(auto u:ans)cout<<u.first+1<<' '<<u.second+1<<'\n';cout<<endl;
//	for(auto u:ans)assert(dd[u.first][u.second]==1);
	return 0;
}