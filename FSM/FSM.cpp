/**
 * Finite State Machine for gaming
 * Input map NxN
 * State : STOP, MOVE, ATTACK, REST
 * MAP : empty(1), monster(2), bed(3), wall(0)
*/

/** 
 * Then NxN map 
 * Input first N
 * next NxN map elenment
 * next start pos (row, col) : left top is (0,0)
*/

// help : https://2thadult.tistory.com/264

#include <iostream>

using namespace std;

int main()
{
	int N, x, y, state;
	bool check_continue = true;
	cin >> N;
	int map[N][N];
	int vis[N][N];
	int xx[4] = {0, 1, 0, -1};
	int yy[4] = {-1, 0, 1, 0};
	for (int i=0;i<N;++i)
	{
		for (int j=0;j<N;++j)
		{
			cin >> map[i][j];
			if (!map[i][j])
				vis[i][j] = -1;
			else
				vis[i][j] = 0;
		}
	}
	cin >> x >> y;

	/** check input */
	for (int i=0;i<N;++i)
	{
		for (int j=0;j<N;++j)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	if (!map[x][y])
	{
		cout << "Player Start point is not valid ;(" << endl;
		return (1);
	}
	while (state)
	{
		state = map[x][y];
		++vis[x][y];
		cout << "cur_pos : (" << x << ", " << y << ")" << endl;
		bool vis_check = false;
		int ii = 0, jj = 0;
		switch (state)
		{
		case 1:	// MOVE
			/* code */
			for (int i=0;i<4;++i)
			{
				if (x + xx[i] < 0 || x + xx[i] >= N || y +yy[i] < 0 || y + yy[i] >= N)
					continue;
				if (map[x + xx[i]][y + yy[i]] != 0)
				{
					x = x + xx[i];
					y = y + yy[i];
					break;
				}
			}
			for (int i=0;i<N;++i)
			{
				for (int j=0;j<N;++j)
				{
					if (vis[i][j] == 0)
					{
						vis_check = true;
						break;
					}
					jj++;
				}
				if (vis_check)
					break;
				if (jj == N-1)
					++ii;
				if (ii == N-1)
				{
					state = 0;
					break;
				}
			}
			break;
		case 2: // ATTACK
			cout << "	Player is Attacking!!!!!" << endl;
			map[x][y] = 1;
			break;
		case 3:	// REST
			/* code */
			cout << "	Player takes a rest~~~~~" << endl;
			map[x][y] = 1;
			break;
		// default:
		// 	cout << "ERR : Invalid map condition ;(" << endl;
		// 	state = 0;
		// 	break;
		}
	}

}
