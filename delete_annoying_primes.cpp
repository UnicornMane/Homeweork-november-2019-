#include <iostream>

using namespace std;

int sieve(size_t, int *s)
{

}

void delete_annoying_primes(size_t size, int *arr)
{

}

int main()
{
	size_t n;
	cin >> n;

	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	delete_annoying_primes(n, arr);
}