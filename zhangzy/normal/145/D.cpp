#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
inline int read(){
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; ch < '0' || ch > '9'; ch = getchar())	if (ch == '-')  positive = 0;
	for (; ch >= '0' && ch <= '9'; ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}

int n,x;
map<int,int>ha;
map<int,int>::iterator it;
int id[1010],a[1010],tot,cnt,pre[1010],nex[1010];

ll ans=0,all,c2=3,c3=1,s1[101000];
vector<int>vec[1010];

bool F(int x){
	for (;x;x/=10) if (x%10!=4&&x%10!=7) return 0;
	return 1;
}

ll sig(ll k,ll n){
	return n*k-s1[k];
}
void Cal(int p1,int p2,int p3,int p4,int p5){
	ans-=(ll)p1*(p5-p4)*sig(p4-p3,p4+1-p2);
}

void doit(vector<int>&the){
	int sz=the.size();
	if (sz<2) return;
	int las=0,now,p,t;
	for (int i=0;i<sz-1;i++){
		now=the[i];
		memset(pre,0,sizeof pre);
		for (int j=0;j<sz;j++){
			pre[j]=0;
			nex[j]=tot+1;
		}
		for (int le=now;le>las;le--){
			t=a[le];
			for (int j=i+1;j<sz;j++){
				if (the[j]>vec[t][0]){
					p=lower_bound(vec[t].begin(),vec[t].end(),the[j])-vec[t].begin();
					while (p>=vec[t].size()||the[j]<=vec[t][p]) p--;
					pre[j]=max(pre[j],vec[t][p]);
				}
				if (the[j]<vec[t][vec[t].size()-1]&&le!=now){
					p=lower_bound(vec[t].begin(),vec[t].end(),the[j])-vec[t].begin();
					nex[j]=min(nex[j],vec[t][p]);
				}
				Cal(id[le]-id[le-1],id[now],id[pre[j]],id[the[j]],id[nex[j]]);
			}
		}
		las=now;
	}
}

int main(){
	n=read();
	all=1;
	for (int i=n-1;i<=n+2;i++){
		x=i;
		for (;x%2==0&&c2;c2--) x/=2;
		for (;x%3==0&&c3;c3--) x/=3;
		all*=x;
	}
	cerr<<all<<endl;
	
	for (int i=1;i<=n;i++){
		x=read();
		if (F(x)){
			ha[x]=1;
			tot++;
			a[tot]=x;
			id[tot]=i;
		}
	}
	
	for (it=ha.begin();it!=ha.end();it++)
		ha[it->fi]=++cnt;
	for (int i=1;i<=tot;i++){
		a[i]=ha[a[i]];
		vec[a[i]].push_back(i);
	}
	
	for (ll i=1;i<=n;i++){
		s1[i]=s1[i-1]+i;
	}
	id[tot+1]=n+1;
	for (int i=1;i<=cnt;i++)
		doit(vec[i]);
	
	ans+=all;
	cout<<ans;
}