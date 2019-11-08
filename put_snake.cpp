#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

void put_snake(const int &n, const int &m, vector <vector <int>> &snake)
{
	int num = 1;
	//int x = 0, y = 0;
	for (int k = 0; k < n; k++)
	{
		for (int i = m - 1 - k; i >= k; i--)
		{
			if (snake[k][i] == 0)
			{
				snake[k][i] = num;
				num++;
			}
		}
		for (int i = k; i < n - k; i++)
		{
			if (snake[i][k] == 0)
			{
				snake[i][k] = num;
				num++;
			}
		}
		for (int i = k; i < m - k; i++)
		{
			if (snake[n - 1 - k][i] == 0)
			{
				snake[n - 1 - k][i] = num;
				num++;
			}
		}
		for (int i = n - 1 - k; i >= k; i--)
		{
			if (snake[i][m - 1 - k] == 0)
			{
				snake[i][m - 1 - k] = num;
				num++;
			}
		}
	}
}

int main()
{
	int f, s;
	cin >> f >> s;
	vector <vector <int>> snake(f, vector <int>(s));
	put_snake(f, s, snake);
	for (int i = 0; i < f; i++)
	{
		for (int j = 0; j < s; j++)
		{
			cout << snake[i][j] << "\t";
		}
		cout << '\n';
	}
}