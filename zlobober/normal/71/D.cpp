#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

//#define TASK ""

char ID[] = {'2', '3', '4', '5', '6', '7',
			 '8', '9', 'T', 'J', 'Q', 'K', 'A'};
char IM[] = {'C', 'D', 'H', 'S'};

struct card
{
	int a, b;
	friend bool operator ==(card a, card b)
	{
		return a.a == b.a && a.b == b.b;
	}
	card()
	{
		name.resize(2);
	}
	string name;
	card(int i)
	{
		a = i % 13;
		b = i / 13;
		name.push_back(ID[a]);
		name.push_back(IM[b]);
	}
};

int val(card c)
{
	if (c.b == -1)
		return 52;
	else
		return c.b * 13 + c.a;
}

const int N = 55;

card C[N][N];

bool isjoker(card c)
{
	return c.b == -1;
}

vector<pair<int, int> > J;

card all[52];

bool good[53];


int D[256];
int M[256];

pair<int, int> sq1, sq2;
int n, m;

bool intersect(pair<int, int> a, pair<int, int> b)
{
	int y1 = a.first, x1 = a.second;
	int y2 = b.first, x2 = b.second;
	bool fx = (x1 + 3 <= x2 || x2 + 3 <= x1);
	bool fy = (y1 + 3 <= y2 || y2 + 3 <= y1);
	return !(fx || fy);
}

bool checksq(int y, int x)
{
	bool wasm[4];
	bool wasd[13];
	memset(wasm, 0, sizeof(wasm));
	memset(wasd, 0, sizeof(wasd));
	
	for (int a = y; a < y + 3; a++)
		for (int b = x; b < x + 3; b++)
		{
			wasm[C[a][b].b] = 1;
			wasd[C[a][b].a] = 1;
		}
	int colm = 0, cold = 0;
	for (int i = 0; i < 4; i++)
		colm += wasm[i];
	for (int i = 0; i < 13; i++)
		cold += wasd[i];
	return colm == 1 || cold == 9;
}

void writeSQ()
{
	string PT = "Put the ";
	string F = "first";
	string S = "second";
	string SQT = " square to ";
	cout << PT << F << SQT << "(" << 1 + sq1.first << ", " << 1 + sq1.second << ")." << endl;
	cout << PT << S << SQT << "(" << 1 + sq2.first << ", " << 1 + sq2.second << ")." << endl;
}

bool check()
{
	for (sq1.first = 0; sq1.first < n - 2; sq1.first++)
		for (sq1.second = 0; sq1.second < m - 2; sq1.second++)
			for (sq2.first = 0; sq2.first < n - 2; sq2.first++)
				for (sq2.second = 0; sq2.second < m - 2; sq2.second++)
				{
					if (intersect(sq1, sq2))
						continue;
					if (checksq(sq1.first, sq1.second) && checksq(sq2.first, sq2.second))
						return true;
				}
	return false;
}

int main(int argc, char **argv)
{
#ifdef TASK
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
#endif
	cin >> n >> m;

	memset(D, -1, sizeof(D));
	memset(M, -1, sizeof(M));
	for (int i = '2'; i <= '9'; i++)
		D[i] = i - '2';
	D['T'] = 8;
	D['J'] = 9;
	D['Q'] = 10;
	D['K'] = 11;
	D['A'] = 12;
	M['C'] = 0, M['D'] = 1, M['H'] = 2, M['S'] = 3;
	M['1'] = M['2'] = -1;
	
	for (int i = 0; i < 52; i++)
		good[i] = 1;
	
	char p, q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> p >> q;
			C[i][j].name[0] = p;
			C[i][j].name[1] = q;
			C[i][j].a = D[p];
			C[i][j].b = M[q];
			if (isjoker(C[i][j]))
				J.push_back(make_pair(i, j));
			good[val(C[i][j])] = 0;
		}
		
	string SE = "Solution exists.";
	string TANJ = "There are no jokers.";
	string NS = "No solution.";
	string RPL = "Replace ";
	string WTH = " with ";
	string AND = " and ";
	if (J.size() == 0)
	{
		if (check())
			cout << SE << endl << TANJ << endl, writeSQ();
		else
			cout << NS << endl;
	}
	else if (J.size() == 1)
	{
		card tmp;
		for (int i = 0; i < 52; i++)
			if (good[i])
			{
				tmp = card(i);
				swap(tmp, C[J[0].first][J[0].second]);
				if (check())
				{
					cout << SE << endl << RPL << tmp.name 
					<< WTH << C[J[0].first][J[0].second].name << "." << endl, writeSQ();
					return 0;
				}
				swap(tmp, C[J[0].first][J[0].second]);
			}
		cout << NS << endl;
	}
	else
	{
		card tmpi, tmpj;
		for (int i = 0; i < 52; i++)
			for (int j = 0; j < 52; j++)
			{
				if (i != j && good[i] && good[j])
				{
					tmpi = card(i);
					tmpj = card(j);
					swap(tmpi, C[J[0].first][J[0].second]);
					swap(tmpj, C[J[1].first][J[1].second]);
					
					if (check())
					{
						if (tmpj.name == "J1")
							swap(tmpi, tmpj), swap(C[J[0].first][J[0].second], 
												   C[J[1].first][J[1].second]);
						cout << SE << endl << RPL << tmpi.name 
						<< WTH << C[J[0].first][J[0].second].name << AND << 
						tmpj.name << WTH << C[J[1].first][J[1].second].name << "." << endl, writeSQ();
						return 0;
					}
					swap(tmpi, C[J[0].first][J[0].second]);
					swap(tmpj, C[J[1].first][J[1].second]);
				}
			}
		cout << NS << endl;
	}
	return 0;

}