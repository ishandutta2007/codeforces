#include<bits/stdc++.h>
#define maxn 50100
using namespace std;
int n,k,typ=1;
struct data{
	int mn[12],mx[12],sz;
	void scan(){
		sz=1;
		for(int i=1;i<=k;++i)
			scanf("%d",&mn[i]),mx[i]=mn[i];
	}
	int operator<(const data& d)const{
		return mn[typ]<d.mn[typ];
	}
	void operator+=(const data& d){
		for(int i=1;i<=k;++i)
			mn[i]=min(mn[i],d.mn[i]),
			mx[i]=max(mx[i],d.mx[i]);
		sz+=d.sz;
	}
}A;
set<data>st;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i){
		A.scan();
		for(int j=1;j<=k;++j){
			typ=j;
			set<data>::iterator it=st.upper_bound(A);
			if(it!=st.begin()){
				--it;
				while(true){
					set<data>::iterator xt=it;
					bool flag=false;
					for(int a=1;a<=k;++a)flag|=it->mx[a]>A.mn[a];
					if(flag)A+=*it;
					else break;
					if(xt==st.begin()){st.erase(it);break;}
					else xt--;
					st.erase(it),it=xt;
				}
			}
			it=st.upper_bound(A);
			while(it!=st.end()){
				bool flag=false;
				for(int a=1;a<=k;++a)flag|=it->mn[a]<A.mx[a];
				if(flag)A+=*it;
				else break;
				set<data>::iterator xt=it;
				xt++,st.erase(it),it=xt;
			}
		}
		typ=1;
		st.insert(A);
		printf("%d\n",st.rbegin()->sz);
	}
}