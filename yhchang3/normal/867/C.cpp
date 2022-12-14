#include<bits/stdc++.h>
using namespace std;

int s[100001],a[100001],b[100001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N,S;
	cin>>N>>S;
	long long int cnt1=0,cnt2=0,cnt3=0;
	for(int i=1;i<=N;i++)
		cin>>s[i]>>a[i]>>b[i];
	for(int i=1;i<=N;i++)
		if(a[i]>b[i])
			cnt1+=s[i];
		else if(a[i]==b[i])
			cnt2+=s[i];
		else
			cnt3+=s[i];
	long long int ans=0;
	for(int i=1;i<=N;i++)
		ans+=s[i]*1LL*max(a[i],b[i]);
	if(cnt1%S+cnt2+cnt3%S>S)
		cout<<ans<<endl;
	else{
		priority_queue<pair<int,int> > pq;
		for(int i=1;i<=N;i++)
			if(a[i]>b[i])
				pq.emplace(b[i]-a[i],s[i]);
		int cnt=cnt1%S;
		long long int m1=0,m2=0;
		while(cnt--){
			auto it=pq.top();pq.pop();
			m1+=it.first;
			if(it.second!=1)
				pq.emplace(it.first,it.second-1);
		}
		while(!pq.empty())	pq.pop();
		cnt=cnt3%S;
		for(int i=1;i<=N;i++)
			if(a[i]<b[i])
				pq.emplace(a[i]-b[i],s[i]);
		while(cnt--){
			auto it=pq.top();pq.pop();
			m2+=it.first;
			if(it.second!=1)
				pq.emplace(it.first,it.second-1);
		}
		cout<<ans+max(m1,m2)<<endl;
	}
}