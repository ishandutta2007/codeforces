#include<bits/stdc++.h>
using namespace std;

int a[1<<19];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int x=n,c=-1;
	while(x){
		x>>=1;
		c++;
	}
	long long int ans=0;
	priority_queue<int,vector<int>,greater<int> > pq;
	while(true){
		while(n>=(1<<c)){
			if(a[n]==-1)	break;
			pq.push(a[n--]);
		}
		if(a[n]==-1&&n>=(1<<c))	break;
		ans+=pq.top();pq.pop();
		c--;
	}
	cout<<ans<<endl;
}