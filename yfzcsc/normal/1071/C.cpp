#include<bits/stdc++.h>
using namespace std;
struct data{
	int a,b,c;
	data(){}
	data(int a,int b,int c):a(a),b(b),c(c){}
};
vector<data>v;
int dep[1<<20],pre2[1<<20];
data pre[1<<20];
queue<int> Q;
vector<data> sol(int S,int n){
	dep[S]=1;
	Q.push(S);
	while(Q.size()){
		int nS=Q.front();
		Q.pop();
		for(int i=0;i<n;++i)
			for(int j=i+1;j<n;++j)
				for(int k=j+1;k<n;++k)if(j*2==i+k){
					int mS=nS;
					mS^=(1<<i);
					mS^=(1<<j);
					mS^=(1<<k);
					if(!dep[mS]){
						pre[mS]=data(i+1,j+1,k+1);
						pre2[mS]=nS; 
						dep[mS]=dep[nS]+1;
						Q.push(mS);
					}
				}
	}
	vector<data> ret;
	if(!dep[0]){
		printf("NO");
		exit(0);
	} else {
		int mS=0;
		while(mS!=S){
			ret.push_back(pre[mS]);
			mS=pre2[mS];
		}
	}
	return ret;
}
int a[100100];
vector<data> ans;
set<int>st;
int f(int x){
	if(a[x])st.erase(x);
	else st.insert(x);
	a[x]^=1;
}
void cal(vector<data>& v,int x){
	st.erase(x);
	ans.push_back(data(x-3,x-4,x-5));
	ans.push_back(data(x-4,x-5,x-6));
	ans.push_back(data(x,x-3,x-6));
}
int main(){
	int n;
	n=1e5;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
//		a[i]=rand()%2;
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)if(a[i])st.insert(i);
	for(int i=n;i>=1;--i){
		if(i<=15){
			int S=0;
			for(int j=1;j<=i;++j)
				S|=a[j]<<j-1;
			auto d=sol(S,i);
			reverse(d.begin(),d.end());
			for(auto c:d)ans.push_back(c);
			break;
		} else {
			if(!a[i])continue;
			for(int j=1;j<=100;++j)
				if(i-2*j>=1&&a[i-j]&&a[i-2*j]){
					ans.push_back(data(i-2*j,i-j,i));
					f(i),f(i-j),f(i-2*j);
					goto nxt;
				}
			if(st.size()==1){
				cal(ans,i);
			} else {
//				if(!st.size())exit(-1);
				set<int>::reverse_iterator it=st.rbegin();
				it++;
				int x=*it;
				if(x*2-i>=1){
					ans.push_back(data(x*2-i,x,i));
					f(i),f(x),f(x*2-i);
				} else {
					cal(ans,i);
				}
			}
		}
		nxt:;
	}
	puts("YES");
	printf("%d\n",ans.size());
	for(auto c:ans){
		printf("%d %d %d\n",c.a,c.b,c.c);
	}
}