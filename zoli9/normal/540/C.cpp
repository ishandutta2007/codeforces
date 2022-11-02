#include <bits/stdc++.h>
using namespace std;
 
int sorok=0, oszlopok=0;
pair<int, int> leesni{1, 1};
bool akimenet=false;
bool bkimenet=false;
vector<vector<bool> > volt;
 
void szelessegi(pair<int, int> koordinata)
{
  volt[koordinata.first][koordinata.second]=true;
  if (koordinata.first==leesni.first && koordinata.second==leesni.second)
  {
    if (!akimenet)
    {
      akimenet=true;
      volt[koordinata.first][koordinata.second]=false;
    }
    else
    {
      bkimenet=true;
    }
  }
  koordinata.second--;
  if (!volt[koordinata.first][koordinata.second])
  {
    szelessegi(koordinata);
  }
  koordinata.second+=2;
  if (!volt[koordinata.first][koordinata.second])
  {
    szelessegi(koordinata);
  }
  koordinata.second--;
  koordinata.first--;
  if (!volt[koordinata.first][koordinata.second])
  {
    szelessegi(koordinata);
  }
  koordinata.first+=2;
  if (!volt[koordinata.first][koordinata.second])
  {
    szelessegi(koordinata);
  }
}
 
int main() {
  pair<int, int> koordinata{1, 1};
  cin>>sorok>>oszlopok;
  vector<bool> feltolto(oszlopok+2, false);
  for (int i=0; i<sorok+2; i++)
  {
    volt.push_back(feltolto);
  }
  char beol='!';
  for (int i=0; i<sorok+2; i++)
  {
    volt[i][0]=true;
    volt[i][oszlopok+1]=true;
  }
  for (int i=0; i<oszlopok+2; i++)
  {
    volt[0][i]=true;
    volt[sorok+1][i]=true;
  }
  for (int i=1; i<sorok+1; i++)
  {
    for (int j=1; j<oszlopok+1; j++)
    {
      cin>>beol;
      if (beol=='X')
      {
        volt[i][j]=true;
      }
    }
  }
  cin>>koordinata.first>>koordinata.second;
  cin>>leesni.first>>leesni.second;
  if (volt[leesni.first][leesni.second])
  {
    akimenet=true;
    volt[leesni.first][leesni.second]=false;
  }
  if(leesni.first==koordinata.first && leesni.second==koordinata.second)
  {
    akimenet=false;
  }
  szelessegi(koordinata);
  if (bkimenet)
  {
    cout<<"YES";
  }
  else
  {
    cout<<"NO";
  }
	return 0;
}