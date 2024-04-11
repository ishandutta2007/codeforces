#include<bits/stdc++.h>
using namespace std;


#define id second
#define cnt first

void fail(){
	cout<<-1<<endl;
	exit(0);
}
vector<pair<int,int> > e;

void addedge(int x,int y){
	e.emplace_back(x,y);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin>>N;
	vector<pair<int,int> > d(N);
	for(int i=0;i<N;i++){
		cin>>d[i].cnt;
		d[i].id=i+1;
	}
	while(!d.empty()){
		sort(d.begin(),d.end(),greater<pair<int,int> > ());
		int l=0,o=0,m=0,n=d.size();
		for(auto it:d){
			if(it.cnt==1)	l++;
			m+=it.cnt;
			if(it.cnt&1)	o++;
		}
		if(m&1)	fail();
		m>>=1;
		int c=m-(n-1);
		if(c<0||c>(n-1)/2)	fail();
		if(n==2){
			addedge(d[0].id,d[1].id);
			break;
		}
		if(d[0].cnt==2&&d.back().cnt==2){
			d.emplace_back(d[0]);
			for(int i=0;i<n;i++)
				addedge(d[i].id,d[i+1].id);
			break;
		}
		int b=max(o>>1,l);
		if(c>(n-1-b)/2)	fail();
		if(l){
			int who=n-2;
			for(;who>0;who--)
				if((d[who].cnt&1)&&d[who].cnt!=1)
					break;
			addedge(d.back().id,d[who].id);
			d.pop_back();
			d[who].cnt--;
			continue;
		}
		addedge(d[0].id,d.back().id);
		addedge(d[n-2].id,d[0].id);
		addedge(d[n-2].id,d.back().id);
		d.pop_back();d.pop_back();
		d[0].cnt-=2;
	}
	cout<<e.size()<<'\n';
	for(auto it:e)
		cout<<2<<' '<<it.first<<' '<<it.second<<'\n';


}