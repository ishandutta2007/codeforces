#include<bits/stdc++.h>
using namespace std;
set<int> st;
int main(){
	int n;scanf("%d",&n);int ans=0;
	for(int i=1;i<=n*2;++i){
		int x;scanf("%d",&x);
		if(st.find(x)==st.end())st.insert(x);
		else st.erase(x);
		ans=max(ans,(int)st.size());
	}
	printf("%d\n",ans);
}