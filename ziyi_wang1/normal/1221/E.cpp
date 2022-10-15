#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
char c[303000];
int n,m,T,len,p,sn,j,siz,sum;
priority_queue<int>q;
int main(){
	cin>>T;
	while(T--){
		while(!q.empty())q.pop();
		cin>>n>>m;sn=0;
		scanf("%s",c+1);
		len=strlen(c+1);
		p=1;
		F(i,1,len){
			if(c[i]=='X'){
				if(i-p>=m){
					//cout<<i-p<<endl;
					if(i-p<n){
						cout<<"NO"<<endl;
						sn=1;
						break;
					}
					q.push(i-p);
				}
				p=i+1;
			}
		}
		if(sn)continue;
		if(len+1-p>=m){
			if(len+1-p<n){
				cout<<"NO"<<endl;
				continue;
			}
			q.push(len+1-p);
		}
		if(q.empty()||q.top()<n){
			cout<<"NO"<<endl;
			continue;
		}
	if(q.top()>=(m<<1)){
			p=q.top();q.pop();
		p-=n;
		if(!q.empty())siz=q.size();
		else siz=0;
		if(!q.empty()&&q.top()>=(m<<1)){
			cout<<"NO"<<endl;
			continue;
		}
		F(i,0,(p>>1)){
			j=p-i;
			if(j>=(m<<1))continue;
			if(i>=m&&i<n)continue;
			if(j>=m&&j<n)continue;
			if(i>=(m<<1))continue;
			sum=siz;
			if(i>=n)sum++;
			if(j>=n)sum++;
			if(!(sum&1)){
				sn=1;
				break;
			}
		}
		if(!sn)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	else{
		siz=q.size();
		if(siz&1)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}	
}
    return 0;
}