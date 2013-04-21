#include <iostream>

using namespace std;

void swap(int* elem1, int* elem2)
{
cout << "Swapping " << *elem1 << " and " << *elem2 << endl;
  int temp = *elem1;
  *elem1 = *elem2;
  *elem2 = temp;
}

void printArr(int array[], int arrLen)
{
  for (int i =0 ; i < arrLen; i++)
  {
    cout << "[" << i << "] : " << array[i] << endl;
  }
}
#if 0
void quickSort(int* array, int start, int end)
{
// Quicksort - it is a divide and conquer algorithm - picks a number and place every elements to the left or right depending on whether it's smaller/ equal or larger than the picked number. Recusively work on partitioned array to eventually sort them.

  if (start >= end) //single element - no need to rearrange.
    return;

  int pick, firstLarge = start + 1;

  pick = array[start];

  for (int i = start + 1; i <= end; i++)
  {
    if (pick > array[i]) // need to swap
    {
      swap(&array[firstLarge], &array[i]);
      firstLarge++;
    }
  }
  swap(&array[start], &array[firstLarge - 1]);

  quickSort(array, start, firstLarge - 2);
  quickSort(array, firstLarge, end); 
}
#endif
void quickSort(int* array, int start, int end)
{
// Quicksort - it is a divide and conquer algorithm - picks a number and place every elements to the left or right depending on whether it's smaller/ equal or larger than the picked number. Recusively work on partitioned array to eventually sort them.

  if (start >= end - 1) //single element - no need to rearrange.
    return;

  int pick, firstLarge = start;

  pick = array[end - 1];

  for (int i = start; i < end - 1; i++)
  {
    if (pick > array[i]) // need to swap
    {
      swap(&array[firstLarge], &array[i]);
      firstLarge++;
    }
  }
  swap(&array[end-1], &array[firstLarge]);

  quickSort(array, start, firstLarge);
  quickSort(array, firstLarge, end); 
}

void insertionSort(int* array, int arrLen)
{
  for (int i = 0; i < arrLen; i++)
  {
    int minInd = i;
    for (int j = i; j < arrLen; j++)
    {
      if (array[minInd] > array[j])
      {
        minInd = j;
      }
    }
    swap(&array[minInd], &array[i]);
  }
}

void merge(int* out, int start, int half, int end)
{
  cout << "Merging : " << start << " " << half << " " << end << endl;
  int temp[end-start+1];
  int first = 0, second = 0;
  int i;
  for (i = 0; i < end-start+1; i++ )
  {
    if ( first > (half-start) )
    {
      temp[i] = out[half+second+1];
      second++;
      continue;
    }    
    else if( second >= (end-half) )
    {
      temp[i] = out[start+first];
      first++;
      continue;
    } 

    if ( out[start+first] < out[half+second+1] )
    {  
      temp[i] = out[start+first];
      first++;
    }
    else
    {
      temp[i] = out[half+second+1];
      second++;
    }
  }
 
  for (i = 0; i < end-start+1; i++ )
  {
    out[start+i] = temp[i];
  } 
  
}

void mergeSort(int* array, int start, int end)
{

  if (start >= end)
    return; //1 element

  int half = start + (end - start)/2;

  cout << "Sorting from " << start << " to " << half << endl;
  mergeSort(array, start, half);
  cout << "Sorting from " << half + 1 << " to " << end << endl;
  mergeSort(array, half + 1, end); 

  merge(array, start, half, end);
}


int main()
{

  int array[] = {12, 423, 6, 3 ,74567, 345, 4, 3, 623, 55, 22, 745, 8845, 4, 47, 2, 667, 8, 88, 44};
  int arrLen = sizeof(array) / sizeof(int);

  cout << "Num elem in array : " << arrLen << endl;

  cout << "Running Quick sort ===\n";

  //quickSort(&array[0], 0, arrLen);
  //insertionSort(&array[0], arrLen);
  mergeSort(&array[0], 0, arrLen - 1);

  printArr(array, arrLen);

  return 0;
}
