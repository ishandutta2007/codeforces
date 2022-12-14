#include<bits/stdc++.h>
using namespace std;

int p[200010];

int x,y,a,b,g;

long long int k;

int gcd(int X,int Y){
	while((X%=Y)&&(Y%=X));
	return X^Y;
}

bool check(int xx){
	long long int total=0;
	int t1=int(xx/(1LL*a/g*b)),t2=xx/a-t1,t3=xx/b-t1;
	for(int i=1;i<=t1;i++)
		total+=(x+y)*p[i];
	for(int i=t1+1;i<=t1+t2;i++)
		total+=x*p[i];
	for(int i=t1+t2+1;i<=t1+t2+t3;i++)
		total+=y*p[i];
	return total>=k;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>p[i];
			p[i]/=100;
		}
		sort(p+1,p+n+1,greater<int>());
		cin>>x>>a>>y>>b>>k;
		g=gcd(a,b);
		int l=1,r=n+1;
		if(x<y){
			swap(x,y);
			swap(a,b);
		}
		while(l<r){
			int m=(l+r)>>1;
			if(check(m))
				r=m;
			else
				l=m+1;
		}
		if(l==n+1)
			cout<<-1<<'\n';
		else
			cout<<l<<'\n';
	}
}