#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,i;
	char ch;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<char> v;
		for(i=0;i<n;i++)
		{
			cin>>ch;
			v.push_back(ch);
		}
		if(n==5)
		{
			auto it1=find(v.begin(),v.end(),'T');
			auto it2=find(v.begin(),v.end(),'i');
			auto it3=find(v.begin(),v.end(),'m');
			auto it4=find(v.begin(),v.end(),'u');
			auto it5=find(v.begin(),v.end(),'r');
			if(it1!=v.end() && it2!=v.end() && it3!=v.end() && it4!=v.end() && it5!=v.end())
			cout<<"YES\n";
			else
			cout<<"NO\n";
		}
		else
		cout<<"NO\n";
	}
}