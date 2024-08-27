class Solution {
public:
   typedef pair<int,int> PII;
int dx[4] = {0,0,-1,1};
int dy[4] = { -1,1,0,0 };
vector<vector<int>> highestPeak(vector<vector<int>>& isWater)
{
	queue<PII>q;
	int m = isWater.size();
	int n = isWater[0].size();
	vector<vector<bool>>vb(m,vector<bool>(n,false));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (isWater[i][j] == 1)
			{
				q.emplace(PII(i,j));
				isWater[i][j] = 0;
				vb[i][j] = true;
			}
		}
	}
	while (!q.empty())
	{
		PII t = q.front();
		q.pop();
		int tv = isWater[t.first][t.second];
		for (int i = 0; i < 4; i++)
		{
			int x = t.first + dx[i];
			int y = t.second + dy[i];
			if (x>=0&&x<m&&y>=0&&y<n&&vb[x][y] == false)
			{
				q.emplace(PII(x, y));
				isWater[x][y] = tv + 1;
				vb[x][y] = true;
			}
		}
	}
	return isWater;
}
};
