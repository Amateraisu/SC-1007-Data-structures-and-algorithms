#include <stdio.h>

void SelectionSort(int A[], int n);

int main(void) {
  int A[] = {1,4,7,5,6,9,1};
  int n = sizeof(A)/sizeof(A[0]);
  SelectionSort(A, n);
  for (int i = 0 ; i< n-1; i++)
  {
    printf("%d\t", A[i]);
  }









  
  return 0;
}



void SelectionSort(int A[], int n)
{
  int temp;
  int j;

  for (int i = 1; i < n ; i++)
  {
    temp = A[i];
    j = i - 1;
    while (A[j]>temp && j>=0)
    {
      A[j+1] = A[j];
      j=j-1;

    }
    A[j+1] = temp;
    

  }
}