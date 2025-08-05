#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>&arr,int left,int right)
{
	int pivot=arr[right];
	int i=left;

	for(int j=left;j<right;j++)
	{
		if(arr[j]<pivot)
		{
			swap(arr[i],arr[j]);
			i++;
		}
	}

	swap(arr[i],arr[right]);
	return i;
}

int quickSelect(vector<int>&arr,int left,int right,int k)
{
	if(left==right)
	{
		return arr[left];
	}

	int pivotIndex=partition(arr,left,right);

	int rank=pivotIndex-left+1;

	if(k==rank)
	{
		return arr[pivotIndex];
	}
	else if(k<rank)
	{
		return quickSelect(arr,left,pivotIndex-1,k);
	}
	else
	{
		return quickSelect(arr,pivotIndex+1,right,k-rank);
	}
}

int main()
{
	int n,k;
	cout<<"Enter number of elements: ";
	cin>>n;

	vector<int>arr(n);
	cout<<"Enter "<<n<<" distinct elements: ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	cout<<"Enter k: ";
	cin>>k;

	if(k<1||k>n)
	{
		cout<<"Invalid value of k"<<endl;
		return 0;
	}

	int result=quickSelect(arr,0,n-1,k);
	cout<<"The "<<k<<"th smallest element is: "<<result<<endl;
}
