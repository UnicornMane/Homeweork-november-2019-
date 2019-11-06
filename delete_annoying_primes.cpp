#include <iostream>
#include <vector>


bool isPrime(const int& n)
{
	int d = 2;
	while (n % d != 0 && d * d <= n)
		++d;
	return d * d > n && n;
}

void delete_annoying_primes(int& size, std::vector <int> &arr)
{
	std::vector <int> f(size, 1);
	std::vector <int> ans;
	for (int i = 0; i < size; i++)
	{
			if (isPrime(arr[i]) && f[i])
			{
				for (int j = i + 1; j < size; j++)
				{
					if (arr[j] == arr[i])
					{
						f[j] = 0;
						f[i]++;
					}
				}
			}
			if (f[i] < 2 && f[i] != 0)
			{
				ans.push_back(arr[i]);
			}
	}
	arr = ans;
	size = ans.size();
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int n;
	std::cin >> n;
	std::vector <int> arr(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}

	delete_annoying_primes(n, arr);

	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
}
