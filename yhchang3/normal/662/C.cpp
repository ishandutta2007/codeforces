#include<bits/stdc++.h>
using namespace std;


void FST(vector<long long int>& a,bool inv){
	for(int n=a.size(),step=1;step<n;step<<=1)
		for(int i=0;i<n;i+=step<<1)
			for(int j=i;j<i+step;j++){
				long long int &u=a[j],&v=a[j+step];tie(u,v)=
				//inv?make_pair(u,v-u):make_pair(u,u+v);//|
				//inv?make_pair(u-v,v):make_pair(u+v,v);//&
				make_pair(u+v,u-v);//^
			}
	if(inv)	for(auto &it:a)	it/=a.size();//^
}

int a[100000][20];



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(int j=0;j<m;j++)
			a[j][i]=s[j]-'0';
	}
	vector<long long int> A(1<<n),B(1<<n);
	for(int i=0;i<1<<n;i++){
		int x=i;
		while(x){
			if(x&1)	B[i]++;
			x>>=1;
		}
		B[i]=min(B[i],n-B[i]);
	}
	for(int i=0;i<m;i++){
		int mask=0;
		for(int j=0;j<n;j++)
			mask=mask<<1|a[i][j];
		A[mask]++;
	}
	FST(A,0);
	FST(B,0);
	for(int i=0;i<1<<n;i++)
		A[i]*=B[i];
	FST(A,-1);
	int ans=1e9;
	for(int i=0;i<1<<n;i++)
		ans=min(ans,(int) A[i]);
	cout<<ans<<endl;
}