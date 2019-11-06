#include <iostream>
#include <vector>

using namespace std;

void cube_sum(const int& n, vector <int> &ans)
{
	if (n == 1)
	{
		ans.push_back(1);
		return;
	}
	if (n == 0)
	{
		return;
	}

	int l = 0, r = n + 1;
	while (r - l > 1)
	{
		long long m = (r + l) / 2;
		if (m * m * m <= n)
		{
			l = m;
		} 
		else
			r = m;
	}
	ans.push_back(l);

	cube_sum(n - l * l * l, ans);
}

int main()
{
	int n;
	cin >> n;
	vector <int> ans;
	
	cube_sum(n, ans);

	size_t ans_size = ans.size();
	if (ans_size > 8)
	{
		cout << "impossible";
		return 0;
	}

	for (int i = 0; i < ans_size; i++)
	{
		cout << ans[i] << ' ';
	}

	return 0;
}
