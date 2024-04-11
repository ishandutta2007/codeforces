#include<bits/stdc++.h>
#define ll long long
using namespace std;

char s[233];
int n,x,tot,pos[303000];
vector<int>b[303000],r[303000];
ll ans=0;

void f__k(){
	if (b[0].size()) ans+=b[0][b[0].size()-1]-b[0][0];
	if (r[0].size()) ans+=r[0][r[0].size()-1]-r[0][0];
	cout<<ans;
	exit(0);
}

void do1(int p,vector<int>&v1,vector<int>&v2){
	int mx;
	mx=0; for (auto o:v1) mx=max(mx,abs(p-o)); ans+=mx;
	mx=0; for (auto o:v2) mx=max(mx,abs(p-o)); ans+=mx;
}

void do2(int p1,int p2,vector<int>&v1,vector<int>&v2){
	ll t=0,mx,sz;
	if (v1.size()){
		sz=v1.size(); mx=max(abs(v1[0]-p1),abs(v1[sz-1]-p2));
		for (int i=1;i<sz;++i) mx=max(mx,(ll)v1[i]-v1[i-1]);
		t+=(ll)p2-p1-mx;
	}
	swap(v1,v2);
	if (v1.size()){
		sz=v1.size(); mx=max(abs(v1[0]-p1),abs(v1[sz-1]-p2));
		for (int i=1;i<sz;++i) mx=max(mx,(ll)v1[i]-v1[i-1]);
		t+=(ll)p2-p1-mx;
	}
	swap(v1,v2);
	ans+=min(t+p2-p1,((ll)p2-p1)*2);
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d%s",&x,s);
		if (s[0]=='G'){
			pos[++tot]=x;
		}else if (s[0]=='B'){
			b[tot].push_back(x);
		}else {
			r[tot].push_back(x);
		}
	}
	if (!tot) f__k();
	do1(pos[1],b[0],r[0]); do1(pos[tot],b[tot],r[tot]);
	cerr<<ans<<endl;
	for (int i=1;i<tot;++i) do2(pos[i],pos[i+1],b[i],r[i]);
	cout<<ans;
}