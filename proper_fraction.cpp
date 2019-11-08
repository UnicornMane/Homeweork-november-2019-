#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
	while (b)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}

vector <int> sieve_of_eratosthenes(const int& n)
{
	vector <bool> arr(n + 1, true);
	arr[0] = false;
	arr[1] = true; // надо для задачи

	vector <int> ret;

	ret.push_back(1);

	for (int i = 2; i <= n; i++)
	{
		if (arr[i])
		{
			ret.push_back(i);

			for (int j = i * i; j <= n; j+=i)
			{
				arr[j] = false;
			}
		}
	}

	return ret;
}

int proper_fraction(int& n)
{
	int ans = 0;

	vector <int> sieve = sieve_of_eratosthenes(n);

	size_t size_of_sieve = sieve.size();

	for (int i = 0; i < size_of_sieve; i++)
	{
		if (gcd(sieve[i], n) == 1)
		{
			ans++;
		}
	}
	return ans * 2; 
}

int main()
{
	int n;
	cin >> n;
	cout << proper_fraction(n);
}