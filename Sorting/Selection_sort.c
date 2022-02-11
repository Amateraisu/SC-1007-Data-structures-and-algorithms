#include <stdio.h>

void SelectionSort(int A[], int n);

int main(void) {
  int A[] = {1,4,7,5,6,9,1};
  SelectionSort(A, 7);





  
  return 0;
}


void SelectionSort(int A[], int n)
{
  int i=0;
  int j = 0;
  int minIndex;
  int temp;

  for (i = 0; i < n-1; i++ )
  {
    minIndex = i;
    for (j = i + 1 ; j < n; j++)
    {
      
      if (A[minIndex] > A[j])
      {
        minIndex = j;
      }
    }
    temp = A[i];
    A[i]= A[minIndex];
    A[minIndex]=temp;

    
  }
  for (int x = 0; x <= 6 ; x++)
  {
    printf("%d\t", A[x]);
  }
}