#include<bits/stdc++.h>
#define nl cout<<endl;
using namespace std;
typedef long long ll;
ll Max=INT_MIN,Min=INT_MAX;
void knapsack()
{
	ll profit[5]={0,1,2,5,6},wt[5]={0,2,3,4,5};
	ll m=8,n=4;
	vector<vector<int>> knapsack(1001,vector<int>(100001,0));
	for(ll i=0;i<n+1;i++)
	{
		for(ll j=0;j<m+1;j++)
		{
			if(i==0 || j==0)knapsack[i][j]=0;
			else if(wt[i]<=j)
			{
			  knapsack[i][j]=max(profit[i]+knapsack[i-1][j-wt[i]],knapsack[i-1][j]);	
			}
			else
			{
			  knapsack[i][j]=knapsack[i-1][j];
			}
		}
	}
	cout<<knapsack[n][m]<<endl;
	ll i=n,j=m;
	while(i>0 && j>0)
	{
		if(knapsack[i][j]==knapsack[i-1][j])
		{
			cout<<i<<" 0\n";
			i--;
		}
		else
		{
			cout<<i<<" 1\n";
			j=j-wt[i];i--;
		}
	}
	
}
int main()
{
	ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     knapsack();	
	return 0;
}
