/**	
 * 	coding test exam 
 *	width and height and some diagonal pos(x, y)s
 *	diagonal shape is \ 
 *	get num of A shortest path
 *	that must pass through one diagonal
 *	(mod 10000019)
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int com[501][501];

// make pascal's triangle
void getCom(int n, int r)
{
	for (int i=1;i<=n;++i)
	{
		for (int j=0;j<=r;++j)
		{
			if (i == j || j == 0)
				com[i][j] = 1;
			else
				com[i][j] = ((com[i-1][j-1] % 10000019) 
					+ (com[i-1][j] % 10000019)) % 10000019;
		}
	}
}

//	g++ square_path.cpp -o square_path -std=c++11
//	square_path << square_path_input.txt
int main()
{
	int w, h, dia_num;
	unsigned long long res;
	vector< pair<int, int> > dia;
	cin >> w >> h >> dia_num;
	for (int i=0;i<dia_num;++i)
	{
		int x, y;
		cin >> x >> y;
		dia.push_back(make_pair(x,y));
	}
	com[0][0] = 1;
	getCom(w+h, w+h);
	for (auto it = dia.begin();it<dia.end();it++)
		cout << "(" << (*it).first << ", " << (*it).second << ") ";

	//print coms
	// for (int i=0;i<=w+h;i++)
	// {
	// 	for (int j=0;j<=h+w;j++)
	// 		cout << com[i][j];
	// 	cout << endl;
	// }

	for (auto it = dia.begin();it<dia.end();it++)
	{
		int x1 = (*it).first;
		int y1 = (*it).second - 1;
		int x2 = (*it).first - 1;
		int y2 = (*it).second;
		res += ((com[x1+y1][x1] * com[w+h-x2-y2][w-x2]) % 10000019);
		res += ((com[x2+y2][x2] * com[w+h-x1-y1][w-x1]) % 10000019);
	}
	cout << '\n' << res << endl;
}

/** 
 * 	for (auto v : dia)
 *	0, 0 -> x1, y1 * x2, y2 -> w, h
 *	0, 0 -> x2, y2 * x1, y1 -> w, h
*/
