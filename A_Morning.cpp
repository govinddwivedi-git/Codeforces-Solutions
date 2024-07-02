#include<bits/stdc++.h>
using namespace std;
int convert(char ch)
{
	if(ch=='0')
	return 10;
	if(ch=='1')
	return 1;
	if(ch=='2')
	return 2;
	if(ch=='3')
	return 3;
	if(ch=='4')
	return 4;
	if(ch=='5')
	return 5;
	if(ch=='6')
	return 6;
	if(ch=='7')
	return 7;
	if(ch=='8')
	return 8;
	if(ch=='9')
	return 9;
}
int main()
{
	int t,i,s;
	string str;
	cin>>t;
	while(t--)
	{
		s=0;
		cin>>str;
		for(i=0;i<4;i++)
		{
			if(i==0)
			{
				s=s+(convert(str[i]));
			}
			else if(str[i]=='0')
			{
				s=s+10-convert(str[i-1])+1;
			}
			else
			{
				s=s+abs(convert(str[i])-convert(str[i-1]))+1;
			}
		}
		cout<<s<<endl;
	}
}