#include<bits/stdc++.h>
#define maxn 201000
using namespace std;
int n,a[maxn];
multiset<int> st;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	st.insert(0);
	for(int i=1;i<=n;++i){
		set<int>::iterator it=st.find(a[i]);
		if(it!=st.end())st.erase(it),st.insert(i);
		else st.insert(i);
	}
	printf("%d",st.size());
}