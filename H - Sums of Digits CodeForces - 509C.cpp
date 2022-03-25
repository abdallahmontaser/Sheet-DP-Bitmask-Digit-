#include<bits/stdc++.h>
using namespace std;
#define all(x)                 x.begin(),x.end()
#define clr(x,val)           memset((x),(val),sizeof(x))
int N, X, dp[400][301][2];
string prevv, ans;
int sol(int i, int sum, int flag)
{
	if (i == 400)
		return (!sum && flag);
	int& ret = dp[i][sum][flag];
	if (~ret)
		return ret;
	ret = 0;
	int limit_L = (flag ? 0 : (prevv[i] - '0'));
	for (int j = limit_L; j <= 9; j++)
	{
		if (sum >= j)
			ret |= sol(i + 1, sum - j, flag | (j > (prevv[i] - '0')));
		else
			break;
	}
	return ret;
}
void Build(int i, int sum, int flag)
{
	if (i == 400)
		return;
	int& ret = dp[i][sum][flag];
	int limit_L = (flag ? 0 : (prevv[i] - '0'));
	for (int j = limit_L; j <= 9; j++)
	{
		if ((sum >= j) && (ret == sol(i + 1, sum - j, flag | (j > (prevv[i] - '0')))))
		{
			ans += char(j + '0');
			Build(i + 1, sum - j, flag | (j > (prevv[i] - '0')));
			break;
		}
	}
}
string get(string T)
{
	reverse(all(T));
	while (T.back() == '0')
		T.pop_back();
	reverse(all(T));
	return T;
}
void solve()
{
	cin >> N;
	prevv = string(400, '0');
	while (N--)
	{
		cin >> X;
		clr(dp, -1);
		ans.clear();
		sol(0, X, 0);
		Build(0, X, 0);
		cout << get(ans) << "\n";
		prevv = ans;
	}
}
int main()
{
	solve();
}
