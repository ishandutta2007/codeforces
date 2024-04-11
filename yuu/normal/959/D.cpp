#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100001];
int p[4000001];
bool done[4000001];
bool try_num(int low){
	vector <int> now;
	while(low>1){
		int x=p[low];
		if(done[x]) return 0;
		now.push_back(x);
		while(low%x==0) low/=x;
	}
	for(int x: now) done[x]=1;
	return 1;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=2; i<=4000000; i++) if(p[i]==0) for(int j=i; j<=4000000; j+=i) if(p[j]==0) p[j]=i;
	int low=2;
	int good=0;
	for(int i=1; i<=n; i++){
		if(!good){
			low=a[i];
			vector <int> now;
			while(a[i]>1){
				int x=p[a[i]];
				now.push_back(x);
				while(a[i]%x==0) a[i]/=x;
			}
			for(int x: now) if(done[x]) good=1;
			if(good){
				low++;
				while(!try_num(low)) low++;
				a[i]=low;
				low=2;
			}
			else{
				for(int x: now) done[x]=1;
			a[i]=low;
			}
		}
		else{
			while(!try_num(low)) low++;
			a[i]=low;
		}
	}
	for(int i=1; i<=n; i++) cout<<a[i]<<" \n"[i==n];
}