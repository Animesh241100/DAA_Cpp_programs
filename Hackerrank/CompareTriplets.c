int * compareTriplets(int a_count, int* a, int b_count, int* b, int* result_count) 
{
	int ar = 0;
	int br = 0;
	for(int i=0; i<3; i++)
	{
		if(a[i] > b[i])
			ar = ar + 1;
		else if(a[i] < b[i])
			br = br + 1;
		else
	}		
	int * ptr = (int *)calloc(2, sizeof(int));
	ptr[0] = ar;
	ptr[1] = br;
	return (ptr);
}
