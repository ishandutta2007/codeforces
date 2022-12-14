#include<iostream>
using namespace std;

int suffix[200010];
int receipt[200010],receipt_time[200010];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>receipt[i];
	int q;
	cin>>q;
	for(int i=1,op,p;i<=q;i++){
		cin>>op;
		if(op==1){
			cin>>p;
			cin>>receipt[p];
			receipt_time[p]=i;
		}
		else
			cin>>suffix[i];
	}
	for(int i=q-1;i>=1;i--)
		suffix[i]=max(suffix[i+1],suffix[i]);
	for(int i=1;i<=n;i++)
		cout<<max(receipt[i],suffix[receipt_time[i]+1])<<' ';
	cout<<endl;
}