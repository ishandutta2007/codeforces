#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
typedef long long ll;
typedef __int128 i128;
#define I inline void
#define IN inline int
#define C(x,y) memset(x,y,sizeof(x))
#define STS system("pause")
#define Debug(x,y) F(i,1,y)cout<<x[i]<<" ";cout<<endl;
template<class D>I read(D &res){
	res=0;re g=1;register char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')g=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	res*=g;
}
typedef pair<int,int>pii;
const int Mod=998244353,INF=1e7;
int n,m,T,X,Y,wx,wy,sn,vis[505000],t[505000],mx[505000],mn[505000],xm[505000],nm[505000];
map<int,pii>mp;map<int,int>to; 
priority_queue<pii>px;
priority_queue<pii,vector<pii>,greater<pii> >py;
vector<int>v[505000],up[505000],dn[505000];
int main(){
	t[0]=1;
	F(i,1,500001)t[i]=(t[i-1]<<1)%Mod,to[t[i]]=i;
	read(T);
	while(T--){
		read(n);read(m);sn=0;
		F(i,1,n){
			vis[i]=0;
			v[i].resize(m+1);up[i].resize(m+1);dn[i].resize(m+1);
			F(j,1,m)read(v[i][j]);
			re maxi=v[i][m],mini=v[i][m];up[i][m]=dn[i][m]=m;
			FOR(j,m-1,1){
				if(v[i][j]>maxi)up[i][j]=j,maxi=v[i][j];
				else up[i][j]=up[i][j+1];
				if(v[i][j]<mini)dn[i][j]=j,mini=v[i][j];
				else dn[i][j]=dn[i][j+1];
			} 
			xm[i]=maxi;nm[i]=mini;
		}
		F(i,1,n)mx[i]=-INF,mn[i]=INF;
		F(j,1,m-1){
			mp.clear();X=Y=0;
			while(!px.empty())px.pop();
			while(!py.empty())py.pop();
			F(i,1,n){
				if(v[i][j]>mx[i])mx[i]=v[i][j];
				if(v[i][j]<mn[i])mn[i]=v[i][j];
				if(up[i][j]==j)xm[i]=v[i][up[i][j+1]];
				if(dn[i][j]==j)nm[i]=v[i][dn[i][j+1]];
				//cout<<mx[i]<<" "<<mn[i]<<" "<<xm[i]<<" "<<nm[i]<<endl;
				px.push(make_pair(mn[i],t[i]));
				py.push(make_pair(xm[i],t[i]));
			}
			F(i,1,n-1){
				wx=px.top().first;(X+=px.top().second)%=Mod;px.pop();
				wy=py.top().first;(Y+=py.top().second)%=Mod;py.pop();
				//cout<<X<<" "<<Y<<endl;
				if(wx>px.top().first&&wy<py.top().first&&X==Y)mp[X]=make_pair(wx,wy);
			}
			X=Y=(t[n+1]+Mod-2)%Mod;
			while(!px.empty())px.pop();while(!py.empty())py.pop();
			F(i,1,n)px.push(make_pair(nm[i],t[i])),py.push(make_pair(mx[i],t[i]));
			F(i,1,n-1){
				wx=py.top().first;(X+=Mod-py.top().second)%=Mod;py.pop();
				wy=px.top().first;(Y+=Mod-px.top().second)%=Mod;px.pop();
				if(wx<py.top().first&&wy>px.top().first&&X==Y&&mp.find(X)!=mp.end()&&wx<mp[X].first&&wy>mp[X].second){
					sn=1;cout<<"YES"<<endl;
					while(!py.empty())vis[to[py.top().second]]=1,py.pop();
					F(k,1,n){
						if(vis[k])putchar('R');
						else putchar('B');
					}
					cout<<" "<<j<<endl;
					break;
				}
			}
			if(sn)break;
		}
		if(!sn)cout<<"NO"<<endl;
	}
	
	return 0;
}