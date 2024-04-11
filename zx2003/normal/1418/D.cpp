#include<bits/stdc++.h>
using namespace std;
multiset<int>s1,s2;
int n,q,o,x;
inline void ins(int x){
	auto it=s1.lower_bound(x),it2=it;
	if(it2!=s1.begin()){
		--it2;s2.insert(x-*it2);
		if(it!=s1.end())s2.erase(s2.find(*it-*it2));
	}
	if(it!=s1.end())s2.insert(*it-x);
	s1.insert(x);
}
inline void del(int x){
	auto it=s1.lower_bound(x),it2=it++;
	if(it2!=s1.begin()){
		--it2;s2.erase(s2.find(x-*it2));
		if(it!=s1.end())s2.insert(*it-*it2);
	}
	if(it!=s1.end())s2.erase(s2.find(*it-x));
	s1.erase(x);
}
inline void out(){
	printf("%d\n",s2.empty()?0:*s1.rbegin()-*s1.begin()-*s2.rbegin());
}
int main(){
	scanf("%d%d",&n,&q);
	for(;n--;)scanf("%d",&x),ins(x);
	out();for(;q--;)scanf("%d%d",&o,&x),o?ins(x):del(x),out();
}