#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<long> b, bad;
	long q, l;
	int m;
	int curr = 0;
	long temp;
	long long b1;
	cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	cin >> b1 >> q >> l >> m;
	for(int i = 0; i < m; i ++)
	{
		cin >> temp;
		bad.push_back(temp);
	}
	bool inf = false;
	int f = 0;
	while(true)
	{
		if(find(bad.begin(),bad.end(),b1) != bad.end())
		{
			if(abs(b1) > l)
			{
				break;
			}
			if(find(b.begin(),b.end(),b1) != b.end())
			{
				if(find(bad.begin(),bad.end(),b1) == bad.end())
				{
					cout << "inf" << endl;
					return 0;
				}
			}
			b.push_back(b1);
			if(find(bad.begin(),bad.end(),b1) != bad.end())
			{
				b.erase(b.begin()+b.size() - 1);
				if(b1 * q == b1)
				{
					break;
				}
				if(abs(b1) == abs(b1*q) && find(bad.begin(),bad.end(),b1*q)!=bad.end()&&find(bad.begin(),bad.end(),b1)!=bad.end())
				{
					break;
				}
			}
			b1 = b1 * q;
		}
		else
		{
			if(abs(b1) > l)
			{
				break;
			}
			if(find(b.begin(),b.end(), b1) != b.end())
			{
				inf = true;
				break;
			}
			b.push_back(b1);
			b1 = b1 * q;
		}
	}
	if(!inf)
	{
		cout << b.size() << endl;
	}
	else
	{
		cout << "inf" << endl;
	}
	return 0;
}
//HUGE pain in the ass to solve but so satisfying