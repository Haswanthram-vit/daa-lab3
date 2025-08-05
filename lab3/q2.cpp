#include<iostream>
#include<string>
using namespace std;

int findMaxDigit(const string &s,int left,int right)
{
	if(left==right)
	{
		return s[left]-'0';
	}

	int mid=(left+right)/2;

	int leftMax=findMaxDigit(s,left,mid);
	int rightMax=findMaxDigit(s,mid+1,right);

	return max(leftMax,rightMax);
}

int main()
{
	string number;
	cout<<"Enter transaction ID: ";
	cin>>number;

	int maxDigit=findMaxDigit(number,0,number.length()-1);

	if(maxDigit>=8)
	{
		cout<<maxDigit;
	}
	else
	{
		cout<<"Invalid";
	}
}
