#include <cstring>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <utility>
#include <cctype>
#include <ctime>
#include <cstdio>
#include <set>
#define rep(i,n) for(int i=0;i<n;i++)
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();e++)
using namespace std;
typedef long long int64;
const int MAX_V=10000000+10;
const int MAX_N=1000000+10;
int F[MAX_V],S[MAX_V];
int a[MAX_N];
int find(int x){
	if(x==F[x])return x;
	return F[x]=find(F[x]);
}
void Union(int a,int b){
	if(F[a]==-1||F[b]==-1)return;
	a=find(a);b=find(b);
	if(a==b)return;
	F[a]=b;S[b]+=S[a];
}
int n;
int gcd(int a,int b){
	while(b){
		int t=a%b;
		a=b;
		b=t;
	}
	return a;
}
int main(){
	memset(F,-1,sizeof F);
	memset(S,0,sizeof S);
	cin>>n;
	rep(i,n){
		int x;scanf("%d",&x);
		F[x]=x;S[x]++;a[i]=x;
	}
	for(int64 a=1;a<MAX_V;a++)
		for(int64 b=1;b<a;b++){
			int64 x=2*a*b;
			int64 y=a*a-b*b;
			int64 z=a*a+b*b;
			if(x>MAX_V)break;
			if(y>MAX_V)continue;
			int cnt=0;
			if(F[x]>=0)cnt++;if(F[y]>=0)cnt++;
			if(z<MAX_V&&F[z]>=0)cnt++;
			if(cnt<2)continue;
			if(gcd(x,y)!=1||gcd(y,z)!=1||gcd(x,z)!=1)continue;
			Union(x,y);
			if(z<MAX_V)
				Union(x,z),Union(y,z);
		}

	sort(a,a+n);
	int ans=0;
	for(int l=0,r;l<n;l=r){
		r=l;
		while(r<n&&a[r]==a[l])r++;
		int cnt=r-l;
		int it=a[l];
		if(F[it]!=it)continue;
		if(F[it]==it){
			if(S[it]==cnt)
				ans+=cnt;
			else
				ans++;
		}
	}
	cout<<ans<<endl;
}