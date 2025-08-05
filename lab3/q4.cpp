#include<iostream>
#include<vector>
using namespace std;

void mergeSort(vector<int> &arr,int left,int right)
{
	if(left>=right)
	{
		return;
	}

	int mid=(left+right)/2;
	mergeSort(arr,left,mid);
	mergeSort(arr,mid+1,right);

	vector<int> merged;
	int i=left;
	int j=mid+1;

	while(i<=mid && j<=right)
	{
		if(arr[i]<arr[j])
		{
			merged.push_back(arr[i]);
			i++;
		}
		else
		{
			merged.push_back(arr[j]);
			j++;
		}
	}

	while(i<=mid)
	{
		merged.push_back(arr[i]);
		i++;
	}

	while(j<=right)
	{
		merged.push_back(arr[j]);
		j++;
	}

	for(int k=0;k<merged.size();k++)
	{
		arr[left+k]=merged[k];
	}
}

void sortOddPositions(vector<int> &A)
{
	vector<int> values;
	vector<int> indices;

	for(int i=0;i<A.size();i+=2)
	{
		indices.push_back(i);
		values.push_back(A[i]);
	}

	mergeSort(values,0,values.size()-1);

	for(int i=0;i<indices.size();i++)
	{
		A[indices[i]]=values[i];
	}
}

int main()
{
	int n;
	cout<<"Enter the size of the array: ";
	cin>>n;

	vector<int> A(n);
	cout<<"Enter "<<n<<" elements:"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}

	sortOddPositions(A);

	cout<<"Array after sorting 1-based odd positions:"<<endl;
	for(int val : A)
	{
		cout<<val<<" ";
	}
	cout<<endl;
}
