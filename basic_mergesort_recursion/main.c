#include <stdio.h>
#include <stdlib.h>
#define AS 10

void merge(int *arr, int start, int end)
{
    int *temp = malloc(sizeof(int) * (end - start + 1));
    int i = start;
    int j = (end-start)/2 + start + 1;
    int k = 0;                  // counter for *temp
    while( i <= ((end-start)/2 + start) && j <= end)
    {
        if(arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else if(arr[i] > arr[j])
        {
            temp[k++] = arr[j++];
        }
        else
        {
            temp[k++] = arr[i++];
            //++j;  // NOT updating because we want to merge with unique values
        }
    }

    while(i <= (end - start)/2 + start)
    {
        temp[k++] = arr[i++];
    }

    while(j <= end)
    {
        temp[k++] = arr[j++];
    }

    // copies values into actual array
    k = 0;
    i = start;
    while(i <= end)
    {
        arr[i++] = temp[k++];
    }

    free(temp);

/**     PRINT STATEMENT     */
    printf("\nFinished %d,%d\n", start, end);
    for(i = 0; i < AS; ++i)
        printf("%d ", arr[i]);
/**     END OF PRINT        */

}

void mergesort(int *arr, int start, int end)
{
    int i;
    if(!(end<=start))
    {
        mergesort( arr, start, ((end - start)/2)+start );
//        printf("\nArray inside main recursive loop is: \n");
//      for(i = start; i <= end; ++i)
//        printf("%d ", arr[i]);
        mergesort(arr, (((end - start)/2)+start+1), end );
        merge(arr, start, end);
    }
}

int main()
{
    int array[AS] = {231,321,213,123,34,56,9, 231, 999, 0};
    int i = 0;
/**     PRINT STATEMENT     */
    for(i = 0; i < AS; ++i)
        printf("%d ", array[i]);
    printf("\n");
/**     END OF PRINT        */

    mergesort(array, 0, AS-1);

/**     PRINT STATEMENT     */
    printf("\n\n");
    for(i = 0; i < AS; ++i)
        printf("%d ", array[i]);
/**     END OF PRINT        */

    return 0;
}
