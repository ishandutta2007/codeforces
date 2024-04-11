#include <bits/stdc++.h>
using namespace std;
class station{
public:
	int x, p;
	void input(){
		cin>>x>>p;
	}
} s[200003];
int nx[200001];
deque <int> q;
deque <int> w;
int n, d, m;
int main(){
	cin>>d>>m>>n;
	for(int i=1; i<=n; i++) s[i].input();
	sort(s+1, s+n+1, [](station A, station B){
		return A.x<B.x;
	});
	s[n+1].x=d;
	s[n+2].x=d+m+1;
	w.push_back(n+1);
	q.push_back(n+1);
	for(int i=n; i>=0; i--){
		///first cheaper things
		while((!q.empty())&&(s[q.back()].p>s[i].p)) q.pop_back();
		while((!q.empty())&&(s[q.front()].x>s[i].x+m)) q.pop_front();
		while((!w.empty())&&(s[w.front()].x>s[i].x+m)) w.pop_front();
		if(q.empty()){///go to the cheapest station
			if(w.empty()){
				cout<<"-1\n";
				return 0;
			}
			nx[i]=w.front();
		}
		else{///go to the first cheaper station
			nx[i]=q.back();
		}
		q.push_back(i);
		while((!w.empty())&&(s[w.back()].p>=s[i].p)) w.pop_back();
		w.push_back(i);
	}
	q.clear();
	q.push_back(0);
	while(q.back()<=n) q.push_back(nx[q.back()]);
	long long ans=0;
	int need=0;
	for(int i=q.size()-2; i>=0; i--){
		if(s[q[i]].p>s[q[i+1]].p){
			need=s[q[i+1]].x-s[q[i]].x;
			ans+=1LL*need*s[q[i]].p;
		}
		else{
			int maxhelp=m-(s[q[i+1]].x-s[q[i]].x);
			maxhelp=min(maxhelp, need);
			ans+=1LL*maxhelp*(-s[q[i+1]].p);
			need=(s[q[i+1]].x-s[q[i]].x)+maxhelp;
			ans+=1LL*need*s[q[i]].p;
		}
	}
	cout<<ans<<'\n';
}