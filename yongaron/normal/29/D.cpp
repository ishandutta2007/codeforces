#include <iostream>
#include <vector>
using namespace std;

vector<int> sou[303];
vector<int> ans;
bool l[303][303];
vector<int> lis;
bool byl[303];

void listy(int pred, int akt){
    if(sou[akt].size()==1 && akt!=1) l[akt][akt]=1;
    for(int i=0; i<sou[akt].size(); i++){
        if(sou[akt][i]!=pred){
            listy(akt,sou[akt][i]);
            for(int j=0; j<303; j++){
                if(l[sou[akt][i]][j]==1) l[akt][j]=1;
            }
        }
    }
}
bool q;
int k;
void proch(int pred, int akt){
    if(q) return;
   	if(byl[akt]==1){
        q=1;
       	return;
   	}
   	if(l[akt][lis[k]]==0) return;
    byl[akt]=1;
    ans.push_back(akt);
    if(akt==lis[k]){
        k++;
        return;
    }
		while(1)
		{
        if(q) return;
        if(k >= lis.size())	return;
     		if(l[akt][lis[k]]==0) return;
      	for(int i=0; i<sou[akt].size(); i++){
          	if(sou[akt][i]!=pred && l[sou[akt][i]][lis[k]])
            {
              proch(akt,sou[akt][i]);
              break;
            }
      	}
        ans.push_back(akt);
		}
}

int main()
{
    int n;
    cin >> n;
    int a, b;
    for(int i=0; i<n-1; i++){
        cin >> a >> b;
        sou[a].push_back(b);
        sou[b].push_back(a);
    }
    while(cin >> a) lis.push_back(a);
    listy(1,1);
    proch(1,1);
    if(q){
        cout << -1 << endl;
        return 0;
    }
    for(int i=0; i< ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}