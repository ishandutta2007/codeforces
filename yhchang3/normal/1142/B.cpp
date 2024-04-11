#include<bits/stdc++.h>
using namespace std;

int table[200001];
int p[200000];
int pos[200001];
int a[200001];
int go[18][200001];
int to[200001];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=0;i<n;i++){
		cin>>p[i];
		pos[p[i]]=i;
	}
	for(int i=1;i<=m;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++){
		go[0][i]=table[p[(pos[a[i]]+n-1)%n]];
		table[a[i]]=i;
	}
	for(int i=1;i<=17;i++)
		for(int j=1;j<=m;j++)
			go[i][j]=go[i-1][go[i-1][j]];
	for(int i=1;i<=m;i++){
		int x=n-1;
		to[i]=i;
		for(int j=0;j<=17;j++){
			if(x&1)
				to[i]=go[j][to[i]];
			x>>=1;
		}
	}
	for(int i=1;i<=m;i++)
		to[i]=max(to[i],to[i-1]);
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<(to[y]>=x);
	}
	cout<<endl;
}