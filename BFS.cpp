#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<char>graph[510];
bool visit[510];
ll BFS(char s)
{
	queue<char>q;
	q.push(s);
	visit[s]=true;
	while(!q.empty())
	{
		char node = q.front();
		q.pop();
		cout<<node<<" --> ";
		for(ll i=0;i<graph[node].size();i++)
		{
			char it = graph[node][i];
			if(!visit[it])
			{
				visit[it]=true;
				q.push(it);
			}
		}
		
	}
}
int main()
{
	for(ll i=0;i<510;i++)
	{
		visit[i]=false;
	}
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++)
	{
		char u,v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	char s;
	cin>>s;
	BFS(s);	
	return 0;
}