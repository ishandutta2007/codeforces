#include<bits/stdc++.h>
using namespace std;

const int MN = 6e5;
int pa[MN+1],de[MN+1];
void Init(){
   for(int i=1;i<=MN;i++)
      de[pa[i]=i]=1;
}
int Find(int x){
   return x==pa[x]?x:pa[x]=Find(pa[x]);
}
void Union(int x,int y){
   x=Find(x);y=Find(y);
   if(x!=y){
      if(de[x]<de[y])    swap(x,y);
      pa[y]=x;
      if(de[x]==de[y])    de[x]++;
   }
}

pair<int,int> event[1000001];
int l[500001],r[500001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i]>>r[i];
		event[l[i]]=make_pair(i,1);
		event[r[i]]=make_pair(i,-1);
	}
	set<pair<int,int> > s;
	int cnt=0;
	Init();
	for(int i=1;i<=2*n;i++){
		if(event[i].second==-1)
			s.erase(make_pair(r[event[i].first],event[i].first));
		else{
			for(auto it:s){
				if(r[event[i].first]<it.first)
					break;
				cnt++;
				Union(it.second,event[i].first);
			}
			if(cnt>=n){
				cout<<"NO"<<endl;
				return 0;
			}
			s.insert(make_pair(r[event[i].first],event[i].first));
		}
	}
	bool diff=false;
	for(int i=1;i<n;i++)
		if(Find(i)!=Find(i+1))
			diff=true;
	if(cnt!=n-1||diff)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
}