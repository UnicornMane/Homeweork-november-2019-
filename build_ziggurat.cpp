#include <iostream>
#include <vector>

using namespace std;

void build_ziggurat(const int &n, vector <vector <int>> &ziggurat)
{
	for (int k = 0; k < (n + 1) / 2; k++)
	{
		for (int i = k; i < n - k; i++)
		{
			ziggurat[k][i] = k + 1;
		}

		for (int i = k; i < n - k; i++)
		{
			ziggurat[i][k] = k + 1;
		}

		for (int i = k; i < n - k; i++)
		{
			ziggurat[n - k - 1][i] = k + 1;
		}
		
		for (int i = k; i < n - k; i++)
		{
			ziggurat[i][n - k - 1] = k + 1;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	vector <vector <int>> ziggurat(n, vector <int> (n));

	build_ziggurat(n, ziggurat);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << ziggurat[i][j] << " ";
		cout << '\n';
	}
}
