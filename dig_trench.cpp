#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void dig_trench(const int& n, vector <vector<int>>& trench)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			trench[i][j] = abs(i - j);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector <vector <int>> trench(n, vector <int>(n));
	dig_trench(n, trench);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << trench[i][j] << " ";
		}
		cout << '\n';
	}
}