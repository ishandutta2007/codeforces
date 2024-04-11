#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a+c==b+d){
		if(b>=a&&c>=d){
			cout<<"YES"<<endl;
			while(a>0){
				cout<<0<<' '<<1<<' ';
				a--;b--;
			}
			while(b--){
				cout<<2<<' '<<1<<' ';
			}
			while(d--){
				cout<<2<<' '<<3<<' ';
			}
			cout<<endl;
		}
		else
			cout<<"NO"<<endl;
	}
	else if(a+c+1==b+d){
		vector<int> v(a+b+c+d+1);
		for(int i=1;i<v.size();i+=2){
			if(d)	v[i]=3,d--;
			else	v[i]=1;
		}
		for(int i=2;i<v.size();i+=2){
			if(c)	v[i]=2,c--;
			else	v[i]=0;
		}
		bool ok=true;
		for(int i=2;i<v.size();i++)
			if(abs(v[i]-v[i-1])!=1)
				ok=false;
		if(ok){
			cout<<"YES"<<endl;
			for(int i=1;i<v.size();i++)
				cout<<v[i]<<' ';
			cout<<endl;
		}
		else
			cout<<"NO"<<endl;
		
	}
	else if(a+c==b+d+1){
		vector<int> v(a+b+c+d+1);
		for(int i=1;i<v.size();i+=2){
			if(a)	v[i]=0,a--;
			else	v[i]=2;
		}
		for(int i=2;i<v.size();i+=2){
			if(b)	v[i]=1,b--;
			else	v[i]=3;
		}
		bool ok=true;
		for(int i=2;i<v.size();i++)
			if(abs(v[i]-v[i-1])!=1)
				ok=false;
		if(ok){
			cout<<"YES"<<endl;
			for(int i=1;i<v.size();i++)
				cout<<v[i]<<' ';
			cout<<endl;
		}
		else
			cout<<"NO"<<endl;
		
	}
	else
		cout<<"NO"<<endl;
}