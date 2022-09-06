//MERGE SORT
//Divide and Conquer algorithm
//approch mid find in an array
// divide array into two parts from mid
//we call merge sort on that divided array
/*
array->
6 3 9 5 2 8 7 1
6395  2871
63  95 28  71
// now when problem is too small sort it and merge it
36  59  28  17
//merge again in sorted way
3569    1278
//merge array to get resultant
12356789
*/
// merging we will use two pointer approch
#include <bits/stdc++.h>
using namespace std;
void merge(int arr[],int l,int mid ,int r)
{
    int n1=mid-l+1;
    int n2=r-mid;
    int a[n1];
    int b[n2];//temp arrays
    for(int i=0;i<n1;i++)
    {
        a[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++)
    {
        b[i]=arr[mid+1+i];
    }
    int i=0;
    int j=0;
    int k=l;
    while(i<n1 && j<n2)
    {
        if(a[i]<b[j])
        {
            arr[k]=a[i];
            k++;
            i++;
        }
        else{
            arr[k]=b[j];
            k++;
            j++;
        }
    }
    while(i<n1)
    {
arr[k]=a[i];
k++;
i++;
    }
    while(j<n2)
    {
arr[k]=a[j];
k++;
j++;
    }

}
void mergesort (int arr[],int l,int r)
{
    if(l<r)
    {
        int mid =l+r/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        //we got two sorted array now merge it
        merge(arr,l,mid,r);
    }
}
int main(){
int arr[5];
int d=0;
for(int i=0;i<5;i++)
{
cin>>arr[i];
}
mergesort(arr,0,4);
for(int i=0;i<5;i++)
{
    cout<<arr[i]<<" ";
}
}