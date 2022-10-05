#include<bits/stdc++.h>
using namespace std;

struct cmp{
	bool operator ()(int &x,int &y){
		return x>y;
	}
};
priority_queue<int,vector<int>,cmp>qe,qs;

int n,t;
long long ans=0;
int main(){
	qe.push(23333333);qs.push(23333333);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&t);
		if (qs.top()<qe.top()){
			if (qs.top()<t){
				ans+=t-qs.top();
				qs.pop();
				qe.push(t);
				continue;
			}	
		}else if (qe.top()<t){
			ans+=t-qe.top();
			qs.push(qe.top());
			qe.pop();
			qe.push(t);
			continue;
		}
		qs.push(t);
	}
	cout<<ans;
}