#include<bits/stdc++.h>
using namespace std;

vector<int> createTempArray(string pattern)
{
	vector<int>lps(pattern.length());
	int index=0;
	for(int i=1;i<pattern.length();)
	{
		if(pattern[index]==pattern[i])
		{
			++index,++i;
		}
		else
		{
			if(index!=0)
			{
				index = lps[index-1];
			}
			else
			{
				lps[i]=index,++i;
			}
		}
	}
	return lps;
}

void kmp(string text,string pattern)
{
	bool found = false;
	vector<int>lps = createTempArray(pattern);
	int i=0,j=0;
	// i = text , j = pattern
	
	while(i<text.length())
	{
		if(text[i] == pattern[j])
		{
			++i,++j;
		}
		else
		{
			if(j!=0)
			{
				j = lps[j-1];
			}
			else
			{
				++i;
			}
		}
		if(j==pattern.length())
		{
			cout<<"Found\n";
			found = true;
			cout<<"Index : "<<(i-pattern.length())<<endl;
		}
	}
	if(!found)
	{
		cout<<"Not found\n";
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
     cin.tie(NULL);    
	string pattern,text;
	getline(cin, text);
	getline(cin, pattern);
	kmp(text,pattern);
}