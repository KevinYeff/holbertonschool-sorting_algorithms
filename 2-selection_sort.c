#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using the Selection sort algorithm.
 * @array:       Pointer to the first element of the array to sort.
 * @size:        Size of the array to sort.
 */

void selection_sort(int *array, size_t size);
{
	/* a[0] to a[aLength-1] is the array to sort */
	int i, j, jMin;

	if (!array || size < 2)
	{
		fprintf(stderr,"Array is empty or have one element");
		exit;
	}
	/* advance the position through the entire array */
	/*   (could do i < aLength-1 because single element is also min element) */
	for (i = 0; i < size - 1; i++)
	{
    		/* find the min element in the unsorted a[i .. aLength-1] */

    		/* assume the min is the first element */
    		jMin = i;
    		/* test against elements after i to find the smallest */
    		for (j = i + 1; j < size; j++)
    		{
        		/* if this element is less, then it is the new minimum */
        
			if (array[j] < array[jMin])
        		{
            			/* found new minimum; remember its index */
            			jMin = j;
        		}
    		}

		if (jMin != i)
		{
			swap(a[i], a[jMin]);
			temp = array[j];
			array[j] = array[jMin];
			array[jMin] = temp;
			print_array(array, size);
		}
	}
}
