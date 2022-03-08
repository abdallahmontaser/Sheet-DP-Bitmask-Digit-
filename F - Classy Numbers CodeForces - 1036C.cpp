#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x)                 x.begin(),x.end()
#define clr(x,val)           memset((x),(val),sizeof(x))
string cur;
ll dp[19][4][2];
ll sol(int i, int cnt, int flag)
{
	if (i == cur.size())
		return 1;
	ll& ret = dp[i][cnt][flag];
	if (~ret)
		return ret;
	ret = 0;
	int limit = (flag ? 9 : (cur[i] - '0'));
	for (int x = 0; x <= limit; x++)
	{
		if (!x)
			ret += sol(i + 1, cnt, (flag | (x < limit)));
		else if (cnt < 3)
			ret += sol(i + 1, cnt + 1, (flag | (x < limit)));
	}
	return ret;
}
void solve()
{
	ll L, R, answer_L, answer_R; cin >> L >> R;
	L--;
	clr(dp, -1);
	cur = to_string(L);
	answer_L = sol(0, 0, 0);
	clr(dp, -1);
	cur = to_string(R);
	answer_R = sol(0, 0, 0);
	cout << answer_R - answer_L << "\n";
}
int main()
{
	int T; cin >> T;
	while (T--)
		solve();
}
