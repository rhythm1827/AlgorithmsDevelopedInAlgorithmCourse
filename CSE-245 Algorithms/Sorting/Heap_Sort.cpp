#include<bits/stdc++.h>
#define Size 11
using namespace std;
int A[Size]={2,4,1,5,3,7,9,8,6,10,75};
int PARENT(int i)
{
    return (i-1)/2;
}

int LEFT(int i)
{
    return 2*i+1;
}

int RIGHT(int i)
{
    return 2*i+2;
}
void MAX_HEAPIFY(int i)
{
    int l,r,largest,temp;
    l=LEFT(i);
    r=RIGHT(i);
    if(l<=Size-1 && A[l]>A[i])
    {
        largest=l;
    }
    else
        largest=i;
    if(r<=Size-1 && A[r]>A[largest])
        largest=r;
    if(largest!=i)
    {
        swap(A[i],A[largest]);
        MAX_HEAPIFY(largest);
    }

}

void BUILD_MAX_HEAP()
{
    int i,heap_Size;
    heap_Size=Size;
    for(i=((Size)/2);i>=0;i--)
    {
        MAX_HEAPIFY(i);
    }
}

void HEAPSORT()
{
    int i,temp,l,heap_Size=Size;
    BUILD_MAX_HEAP();
    for(i=Size-1;i>=1;i--)
    {
        swap(A[0],A[i]);
        heap_Size=heap_Size-1;
        MAX_HEAPIFY(0);
    }
}

int main()
{
    int i;
    HEAPSORT();

    for(i=0;i<Size;i++)
    {
        printf("%d ",A[i]);
    }

    return 0;
}
