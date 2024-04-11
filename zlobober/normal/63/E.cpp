#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int BIT(int x, int i)
{
	return (x >> i) & 1;
}

void SBIT(int& x, int a, int b)
{
	x = (x & (~(1 << a))) ^ (b  * (1 << a));
}

int abs(int x)
{
	return (x < 0) ? -x : x;
}

int beg;

bool was[1 << 19];
bool win[1 << 19];
vector<int> vt;

void DFS(int f)
{
	was[f] = 1;
	if (f == 0)
	{
		win[f] = 0;
		return;
	}
	
	win[f] = 0;
	
	for (int i = 0; i < vt.size(); i++)
		if ((vt[i] & f) == vt[i])
		{
			if (!was[f ^ vt[i]])
				DFS(f ^ vt[i]);
			win[f] |= !win[f ^ vt[i]];
		}
}


const int INF = 500;

void build_vt()
{
	int vx[19], vy[19];
	int pt = 0;
	for (int y = 0; y < 5; y++)
	{
		for (int x = max(0, y - 2); x < max(0, y - 2) + 5 - abs(2 - y); x++)
		{
			vy[pt] = y, vx[pt] = x;
			pt++;
		}
	}
	for (int msk = 0; msk < (1 << 19); msk++)
	{
		int col = 0;
		int fir = -1;
		int cy = -INF, cl = -INF, cx = -INF;
		vector<int> hary, harl, harx;
		hary.clear(), harl.clear(), harx.clear();
		col = 0;
		for (int i = 0; i < 19; i++)
		{
			col += (BIT(msk, i));
			if (BIT(msk, i) && fir == -1)
				fir = i;
		}

		if (col == 0)
			continue;
		if (col == 1)
		{
			vt.push_back(msk);
			continue;
		}
		if (col > 5)
			continue;
		for (int j = fir; j < 19; j++)
		{
			if (!BIT(msk, j))
				continue;
			
			if (cy == -INF)
				cy = vy[j];
			else if (cy != vy[j])
				cy = INF;
			
			if (cl == -INF)
				cl = vy[j] - vx[j];
			else if (cl != vy[j] - vx[j])
				cl = INF;
			
			if (cx == -INF)
				cx = vx[j];
			else if (cx != vx[j])
				cx = INF;
		}
		for (int i = 0; i < 19; i++)
		{
			if (BIT(msk, i))
			{
				hary.push_back(vx[i]);
				harl.push_back((INF + vx[i] + vy[i]) / 2);
				harx.push_back(vy[i]);
			}
		}
		sort(hary.begin(), hary.end());
		sort(harl.begin(), harl.end());
		sort(harx.begin(), harx.end());
		for (int i = 0; i < col - 1; i++)
			if (hary[i + 1] - hary[i] != 1)
				cy = INF;
		for (int i = 0; i < col - 1; i++)
			if (harl[i + 1] - harl[i] != 1)
				cl = INF;
		for (int i = 0; i < col - 1; i++)
			if (harx[i + 1] - harx[i] != 1)
				cx = INF;
		

		if (cy != INF || cl != INF || cx != INF)
			vt.push_back(msk);
	}
}

void debug_vt()
{
	cerr << vt.size() << endl;
	int pt;
	for (int i = 0; i < vt.size(); i++)
	{
		pt = 0;
		for (int y = 0; y < 5; y++)
		{
			for (int xx = 0; xx < max(0, y - 2); xx++)
				cerr << ' ';
			for (int x = max(0, y - 2); x < max(0, y - 2) + 5 - abs(2 - y); x++)
			{
				cerr << BIT(vt[i], pt++);
			}
			cerr << endl;
		}		
		cerr << endl;
	}
}

int main()
{
	int n;
	cin >> n;
	char c;
	int pt = 0;
	while (scanf("%c", &c) != -1)
	{
		cin >> c;
		if (c != '.' && c != 'O')
			continue;
		SBIT(beg, pt++, c == 'O');
	}
	build_vt();
	debug_vt();
	DFS(beg);
	if (win[beg])
		cout << "Karlsson";
	else
		cout << "Lillebror";
}