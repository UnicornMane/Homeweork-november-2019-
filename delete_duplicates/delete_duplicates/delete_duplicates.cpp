#include <iostream>
#include <vector>

using namespace std;

void delete_duplicates(int &size, vector <int> &arr)
{
	vector <bool> f(size, true);
	vector <int> ans;
	for (int i = 0; i < size; i++)
	{
		if (f[i])
		{
			ans.push_back(arr[i]);
			for (int j = i + 1; j < size; j++)
			{
				if (arr[j] == arr[i])
				{
					f[j] = false;
				}
			}
		}
	} 
	arr = ans;
	size = ans.size();
}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector <int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	delete_duplicates(n, arr);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}