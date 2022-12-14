#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k,m,t;
	cin>>n>>k>>m>>t;
	int l=n;
	for(int i=1;i<=t;i++){
		int type,p;
		cin>>type>>p;
		if(type==1){
			l++;
			if(p<=k)	k++;
		}
		else{
			if(k<=p)	l=p;
			else{
				k-=p;
				l-=p;
			}
		}
		cout<<l<<' '<<k<<endl;
	}
}