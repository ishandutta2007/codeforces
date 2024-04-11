#include<bits/stdc++.h>
using namespace std;

const int MN = 2e5;
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

bool has[MN+1][26];
vector<int> v[26];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		for(auto c:s)
			has[i][c-'a']=true;
		for(int j=0;j<26;j++)
			if(has[i][j])
				v[j].emplace_back(i);
	}
	Init();
	for(int i=0;i<26;i++)
		for(int j=0;j+1<v[i].size();j++)
			Union(v[i][j],v[i][j+1]);
	set<int> st;
	for(int i=1;i<=n;i++)
		st.insert(Find(i));
	cout<<st.size()<<endl;

}