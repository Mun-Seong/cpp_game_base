/**
 * Finite State Machine for gaming
 * Input map
 * State : STOP, MOVE, ATTACK, REST
 * MAP : empty(1), monster(2), bed(3), wall(0)
*/

// help : https://2thadult.tistory.com/264

#include <iostream>

using namespace std;

int main()
{
	int N, x, y, state;
	cin >> N;
	int map[N][N];
	for (int i=0;i<N;++i)
	{
		for (int j=0;j<N;++j)
		{
			cin >> map[i][j];
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

	switch (state)
	{
	case 0: // STOP
		/* code */
		
		break;
	case 1:	// MOVE
		/* code */

		break;
	case 2: // ATTACK
		/* code */
		break;
	case 3:	// REST
		/* code */
		break;
	default:
		break;
	}

}
