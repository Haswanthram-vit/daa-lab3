#include <iostream>
#include <vector>
using namespace std;

int scalarMultiplications=0;
int scalarAdditions=0;

typedef vector<vector<int>> Matrix;

Matrix createMatrix(int size)
{
    return Matrix(size,vector<int>(size,0));
}

void readMatrix(Matrix &M,int size,const string &name)
{
    for(int i=0;i<size;++i)
    {
        for(int j=0;j<size;++j)
        {
            cin>>M[i][j];
        }
    }
}

void printMatrix(const Matrix &M,int size)
{
    for(int i=0;i<size;++i)
    {
        for(int j=0;j<size;++j)
        {
            cout<<M[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void multiplyDC(const Matrix &A,const Matrix &B,Matrix &C,int size)
{
    if(size==1)
    {
        C[0][0]+=A[0][0]*B[0][0];
        scalarMultiplications++;
        scalarAdditions++;
        return;
    }

    int newSize=size/2;
    Matrix A11(newSize,vector<int>(newSize));
    Matrix A12(newSize,vector<int>(newSize));
    Matrix A21(newSize,vector<int>(newSize));
    Matrix A22(newSize,vector<int>(newSize));
    Matrix B11(newSize,vector<int>(newSize));
    Matrix B12(newSize,vector<int>(newSize));
    Matrix B21(newSize,vector<int>(newSize));
    Matrix B22(newSize,vector<int>(newSize));
    Matrix C11(newSize,vector<int>(newSize));
    Matrix C12(newSize,vector<int>(newSize));
    Matrix C21(newSize,vector<int>(newSize));
    Matrix C22(newSize,vector<int>(newSize));

    for(int i=0;i<newSize;++i)
    {
        for(int j=0;j<newSize;++j)
        {
            A11[i][j]=A[i][j];
            A12[i][j]=A[i][j+newSize];
            A21[i][j]=A[i+newSize][j];
            A22[i][j]=A[i+newSize][j+newSize];
            B11[i][j]=B[i][j];
            B12[i][j]=B[i][j+newSize];
            B21[i][j]=B[i+newSize][j];
            B22[i][j]=B[i+newSize][j+newSize];
        }
    }
    multiplyDC(A11,B11,C11,newSize);
    multiplyDC(A12,B21,C11,newSize);
    multiplyDC(A11,B12,C12,newSize);
    multiplyDC(A12,B22,C12,newSize);
    multiplyDC(A21,B11,C21,newSize);
    multiplyDC(A22,B21,C21,newSize);
    multiplyDC(A21,B12,C22,newSize);
    multiplyDC(A22,B22,C22,newSize);

    for(int i=0;i<newSize;++i)
    {
        for(int j=0;j<newSize;++j)
        {
            C[i][j]=C11[i][j];
            C[i][j+newSize]=C12[i][j];
            C[i+newSize][j]=C21[i][j];
            C[i+newSize][j+newSize]=C22[i][j];
        }
    }
}

int main()
{
    int size;
    cin>>size;

    Matrix A=createMatrix(size);
    Matrix B=createMatrix(size);
    Matrix C=createMatrix(size);

    readMatrix(A,size,"A");
    readMatrix(B,size,"B");

    multiplyDC(A,B,C,size);
    cout<<"\nResultant Matrix C:\n";
    printMatrix(C,size);

    cout<<"\nTotal Scalar Multiplications: "<<scalarMultiplications<<endl;
    cout<<"Total Scalar Additions: "<<scalarAdditions<<endl;
}
