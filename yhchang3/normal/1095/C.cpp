#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	int cnt=0;
	int x=n;
	while(x){
		if(x&1)	cnt++;
		x>>=1;
	}
	if(k<=n&&k>=cnt){
		cout<<"YES"<<endl;
		queue<int> q;
		for(int i=1;i<30;i++)
			if((1<<i)&n)
				q.push(i);
		if(n&1)
			cout<<1<<' ';
		for(int i=k-cnt;i>0;i--){
			int now=q.front();q.pop();
			if(now==1)
				cout<<1<<' '<<1<<' ';
			else{
				q.push(now-1);
				q.push(now-1);
			}
		}
		while(!q.empty()){
			cout<<(1<<q.front())<<' ';
			q.pop();
		}
		cout<<endl;
	}
	else
		cout<<"NO"<<endl;
}