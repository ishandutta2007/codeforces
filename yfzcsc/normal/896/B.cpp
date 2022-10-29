#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
set<par>st,st2;
int n,m,c;
int get(){
	int x;
	scanf("%d",&x);
	return x;
}
void print(int x){
	printf("%d\n",x);
	fflush(stdout);
}
int main(){
	scanf("%d%d%d",&n,&m,&c);
	while(st.size()+st2.size()<n){
		int x=get();
		if(x<=c/2){
			if(st.empty()||st.rbegin()->first<=x){
				print(st.size()+1);
				st.insert(par(x,st.size()+1));
			} else {
				par p=*st.upper_bound(par(x,1000000007));
				print(p.second);
				st.erase(p),st.insert(par(x,p.second));
			}	
		} else {
			x=-x;
			if(st2.empty()||st2.rbegin()->first<=x){
				print(n-st2.size());
				st2.insert(par(x,st2.size()+1));
			} else {
				par p=*st2.upper_bound(par(x,1000000007));
				print(n-p.second+1);
				st2.erase(p),st2.insert(par(x,p.second));
			}
		}
		
	}
}