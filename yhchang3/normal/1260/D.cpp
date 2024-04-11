#include<bits/stdc++.h>
using namespace std;

int m,n,k,t;
int a[200010];
vector<int> event[200010];

bool check(int x){
	int tot=0;

	for(int i=1;i<=n+1;i++){
		int cnt=0;
		bool have=false;
		for(int it:event[i])
			if(it>x)
				cnt++,have=true;
			else if(it<-x)
				cnt--;
		int j=i;
		while(cnt){
			j++;
			for(int it:event[j])
			if(it>x)
				cnt++;
			else if(it<-x)
				cnt--;
		}
		if(i==j&&!have)	tot++;
		else tot+=(j-i+1)*3;
		i=j;
	}
	return tot<=t;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>m>>n>>k>>t;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	sort(a+1,a+m+1,greater<int>());
	a[0]=1e9;
	for(int i=1,x,y,z;i<=k;i++){
		cin>>x>>y>>z;
		event[x].emplace_back(z);
		event[y].emplace_back(-z);
	}
	int l=0,r=m;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(a[mid]))	l=mid;
		else	r=mid-1;
	}
	cout<<l<<endl;
}