//** comtus coding test 1st exam */

#include <iostream>
#include <string>

using namespace std;


//	g++ inven.cpp -o inven
//	inven << inven_input.txt
int main()
{
	int itemCount;
	int maxWeight;
	cin >> itemCount;
	int itemValue[itemCount];
	int itemWeigth[itemCount];

	for (int i=0;i<itemCount;++i)
	{
		cin >> itemWeigth[i];
		cin >> itemValue[i];
	}
	cin >> maxWeight;
	int dp[itemCount+1][maxWeight+1];
	for (int i=0;i<=itemCount;++i)
		for (int j=0;j<=maxWeight;++j)
			dp[i][j] = 0;
	/** input end */
	/** input check */
	for (int i=0;i<itemCount;++i)
	{
		cout << "item[" << i << "] : " << itemWeigth[i] << " Gram, " <<
			itemValue[i] << " Gold" << endl;
	}
	cout << "max weight = " << maxWeight << endl;

	/** calculation start */

	for (int i=1;i<=itemCount;++i)
	{
		for (int j=1;j<=maxWeight;++j)
		{
			if (j >= itemWeigth[i-1])
				dp[i][j] = max(dp[i-1][j],
					dp[i-1][j-itemWeigth[i-1]] + itemValue[i-1]);
			else
				dp[i][j] = dp[i-1][j];
		}
	}

	/** dp arrays check */
	// for (int i=0;i<=itemCount;++i)
	// {
	// 	for (int j=0;j<=maxWeight;++j)
	// 	{
	// 		cout << dp[i][j] << ", ";
	// 	}
	// 	cout << endl;
	// }
	
	cout << dp[itemCount][maxWeight] << endl;

	return (0);
}

/**	dynamic programing 
 *	get max value in my bag */