#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int strange_multiply(int &a, int &b)
{
	/*		мне было легче придумать цикл, чем рекурсию
	//a -- min(a, b)
	if (a % 2 == 0 && a > 0)
	{
		a >>= 1;
		b <<= 1;
		strange_multiply(a, b);
	}
	else if (a % 2 == 1 && a > 1)
	{
		--a >>= 1;
		b <<= 1;
		strange_multiply(a, b) + b;
	}

	if (a <= 1)
	{
		return b;
	}
	*/
	if (!a || !b)
	{
		return 0;
	}
	vector <int> add_ons;
	while (a)
	{
		if (a == 1)
		{
			--a;
		}
		else if (a % 2 == 0)
		{
			a >>= 1;
			b <<= 1;
		}
		else
		{
			a >>= 1;
			add_ons.push_back(b);
			b = (b << 1);
			
		}
	}
	for (int i = 0; i < add_ons.size(); i++)
		b += add_ons[i];
	return b;
}

int main()
{
	int a, b;
	cin >> a >> b;
	bool f = false;
	if (a * b < 0)
		f = true;
	a = abs(a);
	b = abs(b);

	int ans = strange_multiply(a, b);

	if (f)
		cout << -ans;
	else
		cout << ans;
}