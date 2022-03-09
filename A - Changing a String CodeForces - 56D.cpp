#include<bits/stdc++.h>
using namespace std;
#define clr(x,val)           memset((x),(val),sizeof(x))
string S, T;
int si, st, dp[1000][1000], idx = 1;
int sol(int i, int j)
{
	if (i == si)
		return st - j;
	if (j == st)
		return si - i;
	int& ret = dp[i][j];
	if (~ret)
		return ret;
	ret = INT_MAX;
	if (S[i] == T[j])
		ret = sol(i + 1, j + 1);
	ret = min(ret, 1 + sol(i + 1, j));        // delete
	ret = min(ret, 1 + sol(i, j + 1));        // insert T[j]
	ret = min(ret, 1 + sol(i + 1, j + 1));    // replace
	return ret;
}
void Build(int i, int j)
{
	if (i == si)
	{
		for (int x = j; x < st; x++)
			cout << "INSERT " << idx++ << " " << T[x] << "\n";
		return;
	}
	if (j == st)
	{
		for (int x = i; x < si; x++)
			cout << "DELETE " << idx << "\n";
		return;
	}
	int& ret = dp[i][j];
	if (S[i] == T[j] && ret == sol(i + 1, j + 1))
	{
		idx++;
		Build(i + 1, j + 1);
	}
	else if (ret == 1 + sol(i, j + 1)) // insert T[j]
	{
		cout << "INSERT " << idx++ << " " << T[j] << "\n";
		Build(i, j + 1);
	}
	else if (ret == 1 + sol(i + 1, j))  //delete
	{
		cout << "DELETE " << idx << "\n";
		Build(i + 1, j);
	}
	else if (ret == 1 + sol(i + 1, j + 1)) //replace
	{
		cout << "REPLACE " << idx++ << " " << T[j] << "\n";
		Build(i + 1, j + 1);
	}
	return;
}
void solve()
{
	cin >> S >> T;
	si = S.size();
	st = T.size();
	clr(dp, -1);
	cout << sol(0, 0) << "\n";
	Build(0, 0);
}
int main()
{
	solve();
}
