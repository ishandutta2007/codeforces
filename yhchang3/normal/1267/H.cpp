#include<bits/stdc++.h>
using namespace std;

int color[8748];



void solve(vector<int> p,int sz,int l){
	if(sz==4){
		vector<int> v=p;
		sort(v.begin(),v.end());
		color[v[0]]=1;color[v[1]]=2;color[v[2]]=3;
		int pos;
		for(pos=0;;pos++)
			if(p[pos]==v[3])
				break;
		if(pos==0){
			if(color[p[1]]==1)
				color[p[0]]=2;
			else
				color[p[0]]=1;
		}
		else if(pos==3){
			if(color[p[2]]==1)
				color[p[3]]=2;
			else
				color[p[3]]=1;
		}
		else
			color[p[pos]]=6-color[p[pos+1]]-color[p[pos-1]];
		return;
	}
	vector<int> nxt;
	for(int i=0;i<sz;i+=3)
		nxt.emplace_back(min(min(p[i],p[i+1]),p[i+2]));
	solve(nxt,sz/3,l-1);
	set<int> s;
	vector<pair<int,int> > vp;
	for(int i=0;i<p.size();i++)
		vp.emplace_back(p[i],i);
	sort(vp.begin(),vp.end());
	for(int i=0;i<sz;i++){
		s.insert(vp[i].second);
		if(color[vp[i].first]!=-1)	continue;
		auto it=s.find(vp[i].second);
		int L=0,R=0;
		set<int> ava;
		ava.insert((l-1)*3+1);
		ava.insert((l-1)*3+2);
		ava.insert((l-1)*3+3);
		while(it!=s.begin()&&color[p[*--it]]>(l-1)*3){
			L++;
			ava.erase(color[p[*it]]);
		}
		it=s.find(vp[i].second);
		while(++it!=s.end()&&color[p[*it]]>(l-1)*3){
			R++;
			ava.erase(color[p[*it]]);
		}
		if(L+R+1<=3)
			color[vp[i].first]=*ava.begin();
		else{
			it=s.find(vp[i].second);
			set<int> av;
			av.insert((l-1)*3+1);
			av.insert((l-1)*3+2);
			av.insert((l-1)*3+3);
			if(R!=0)
				av.erase(color[p[*next(it)]]);
			if(L!=0)
				av.erase(color[p[*prev(it)]]);
			color[p[*it]]=*av.begin();
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		vector<int> p(8748);
		memset(color,-1,sizeof color);
		for(int i=0,x;i<n;i++){
			cin>>x;
			p[--x]=i;
		}
		for(int i=n;i<8748;i++)
			p[i]=i;
		solve(p,8748,8);
		for(int i=0;i<n;i++)
			cout<<color[p[i]]<<' ';
		cout<<'\n';
	}
}