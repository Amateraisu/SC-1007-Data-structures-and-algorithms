#include <stdio.h>

void BubbleSortAndPrint(int A[], int n);

int main(void) {
  int A[] = {1,4,7,5,6,9,1};
  int n = 7;
  BubbleSortAndPrint(A, n);
  for (int i = 0 ; i< n-1; i++)
  {
    printf("%d\t", A[i]);
  }









  
  return 0;
}




void BubbleSortAndPrint(int A[], int n)
{
  for (int i = 0; i < n-1; i++)
  {
    for (int j = 0 ; j < n-i-1; j++)
    {
      if (A[j]> A[j+1])
      {
        int temp;
        temp = A[j];
        A[j] = A[j+1];
        A[j+1]=temp;

      }
    }
  }

}