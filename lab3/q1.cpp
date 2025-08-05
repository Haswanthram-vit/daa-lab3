#include<iostream>
#include<vector>
#include<chrono>
using namespace std;
using namespace std::chrono;

vector<int> getFibonacciIndices(int n)
{
	vector<int> indices;
	int a=1,b=2;
	if(a<=n)indices.push_back(a);
	if(b<=n)indices.push_back(b);
	while(true)
	{
		int c=a+b;
		if(c>n)break;
		indices.push_back(c);
		a=b;
		b=c;
	}
	return indices;
}

void merge(vector<int>&arr,int l,int m,int r)
{
	int n1=m-l+1;
	int n2=r-m;

	vector<int>L(n1),R(n2);

	for(int i=0;i<n1;i++)L[i]=arr[l+i];
	for(int i=0;i<n2;i++)R[i]=arr[m+1+i];

	int i=0,j=0,k=l;

	while(i<n1&&j<n2)
	{
		if(L[i]<R[j])
		{
			arr[k]=L[i];
			i++;
		}
		else
		{
			arr[k]=R[j];
			j++;
		}
		k++;
	}

	while(i<n1)
	{
		arr[k]=L[i];
		i++;
		k++;
	}

	while(j<n2)
	{
		arr[k]=R[j];
		j++;
		k++;
	}
}

void mergeSort(vector<int>&arr,int l,int r)
{
	if(l<r)
	{
		int m=(l+r)/2;
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}

void fibonacciSort(vector<int>&A)
{
	int n=A.size()-1;

	vector<int>fib_indices=getFibonacciIndices(n);
	vector<int>fib_values;

	for(int idx:fib_indices)
	{
		fib_values.push_back(A[idx]);
	}

	auto start=high_resolution_clock::now();

	mergeSort(fib_values,0,fib_values.size()-1);

	auto stop=high_resolution_clock::now();
	auto duration=duration_cast<microseconds>(stop-start);

	for(int i=0;i<fib_indices.size();i++)
	{
		A[fib_indices[i]]=fib_values[fib_values.size()-1-i];
	}

	cout<<"Time taken for Fibonacci sorting: "<<duration.count()<<" microseconds"<<endl;
}

void printArray(vector<int>&A)
{
	for(int i=1;i<A.size();i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	vector<int>A={0,10,20,30,40,50,60,70,80,90,100,110,120,130}; 
	cout<<"Original Array:"<<endl;
	printArray(A);

	fibonacciSort(A);

	cout<<"After Fibonacci Sorting:"<<endl;
	printArray(A);

	return 0;
}
