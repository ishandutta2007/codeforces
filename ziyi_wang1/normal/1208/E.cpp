#include<bits/stdc++.h>
using namespace std;
#define re register ll
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
#define I inline void
#define IN inline ll
typedef long long ll;
ll n,m,l,r,len,a[1010000],ans[1010000],sum;
deque<ll>q;
IN min(ll x,ll y){
	return x<y?x:y;
}
int main(){
	cin>>n>>m;
	F(i,1,n){
		cin>>len;
		a[0]=0;
		q.push_back(0);
		F(j,1,len){
			cin>>a[j];
		}
		a[len+1]=0;
		F(j,1,len){
			while(!q.empty()&&j+(len-q.front())>m)q.pop_front();
			while(!q.empty()&&a[q.back()]<=a[j])q.pop_back();
			q.push_back(j);
			ans[j]+=a[q.front()];ans[j+1]-=a[q.front()];
			//cout<<j<<q.front()<<endl;		
		}
		while(!q.empty()&&a[q.back()]<=a[len+1])q.pop_back();
		q.push_back(len+1);
		l=len+1;
		while(!q.empty()&&l<=m){
			r=min(m+1,m-len+q.front()+1);
			if(l>r){
				q.pop_front();
				continue;
			}
			ans[l]+=a[q.front()];ans[r]-=a[q.front()];
			//cout<<"!"<<l<<" "<<r<<" "<<q.front()<<endl;
			l=r;
			q.pop_front();
		}
		while(!q.empty()){
			q.pop_front();	
		}
		sum=0;
	}
	sum=0;
	F(i,1,m){
		sum+=ans[i];
		cout<<sum<<" ";
	}
    return 0;
}