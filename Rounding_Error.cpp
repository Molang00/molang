#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		int N, L;
		scanf("%d%d", &N, &L);

		vector<int> lang;
		int num = 0;
		for (int i = 0; i < L; i++)
		{
			int v;
			scanf("%d", &v);
			lang.push_back(v);
			num += v;
		}

		int pos = N - num;
		//printf("**%d %d\n", num, pos);
		float unit = 100.0 / N;
		vector<int> rst;
		bool last = false;
		for (int i = 1; i <= N; i++)
		{
			int now = unit*i / 1;
			if (unit*i - now >= 0.5)
			{
				if (!last)
				{
					last = true;
					rst.push_back(i);
				}
			}
			else last = false;
		}

		vector<pair<int, int> > want;
		for (int j = 0; j < lang.size(); j++)
		{
			//printf("++%d %d\n", i, rst[i]);
			for (int i = 0; i < rst.size(); i++)
			{
				if (rst[i] - lang[j] > 0)
				{
					want.push_back(make_pair(rst[i] - lang[j], j));
					break;
				}
			}
		}

		int can = pos;
		sort(want.begin(), want.end());

		for (int i = 0; i < want.size(); i++)
		{
			//printf("--%d %d\n", want[i].first, want[i].second);
			if (want[i].first <= can && rst[0] >= want[i].first)
			{
				lang[want[i].second] += want[i].first;
				can -= want[i].first;
			}
		}
		while (rst.size() && can)
		{
			if (can - rst[0] >= 0)
			{
				lang.push_back(rst[0]);
				can -= rst[0];
			}
			else break;
		}
		if(can) lang.push_back(can);

		int result = 0;

		for (int i = 0; i < lang.size(); i++)
		{
			int val = unit*lang[i];
			result += unit*lang[i];
			//printf("%d %d %lf\n", result, lang[i], unit*lang[i]);
			if (unit*lang[i] - val >= 0.5) result++;
		}
		printf("Case #%d: %d\n", t, result);
	}
}