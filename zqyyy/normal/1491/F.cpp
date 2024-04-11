#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=2007;
int n,x;
inline void work(){
	n=read();int pos=0;
	vector<int>ans;
	for(int i=2;i<=n;i++){
		cout<<"? 1 "<<i-1<<endl<<i<<endl;
		for(int j=1;j<i;j++)cout<<j<<" ";cout<<endl;
		cin>>x;
		if(x){pos=i;break;}
	}
	for(int i=pos+1;i<=n;i++){
		cout<<"? 1 1"<<endl<<pos<<endl<<i<<endl;
		cin>>x;if(!x)ans.push_back(i);
	}
	vector<int>vec;
	for(int i=1;i<pos;i++)vec.push_back(i);
	while((int)vec.size()>1){
		int mid=vec.size()-1>>1;
		cout<<"? 1 "<<mid+1<<endl<<pos<<endl;
		for(int i=0;i<=mid;i++)cout<<vec[i]<<" ";cout<<endl;
		cin>>x;vector<int>res;
		if(x) for(int i=0;i<=mid;i++)res.push_back(vec[i]);
		else for(int i=mid+1;i<(int)vec.size();i++)res.push_back(vec[i]);
		vec=res;
	}
	for(int i=1;i<pos;i++)if(i!=vec[0])ans.push_back(i);
	cout<<"! "<<ans.size()<<" ";
	for(auto x:ans)cout<<x<<" ";
	cout<<endl;
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}