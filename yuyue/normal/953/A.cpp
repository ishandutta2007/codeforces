#include<bits/stdc++.h>
using namespace std;
int n,m,s;
set<int> w; 
int main(){
    cin>>n>>m; 
	priority_queue<long long,vector<long long>,greater<long long> > q;
	q.push(1);
	w.insert(1);
	while (q.top()<=m)
	{
		
		if (q.top()>=n) s++;
		if (w.count(q.top()*2)==0) q.push(q.top()*2),w.insert(q.top()*2);
		if (w.count(q.top()*3)==0) q.push(q.top()*3),w.insert(q.top()*3);
		q.pop();
	}
	cout<<s<<endl;
    return 0;
}