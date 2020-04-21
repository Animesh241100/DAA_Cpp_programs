int diagonalDifference(int arr_rows, int arr_columns, int *(* arr))
{
	int s1 = 0;
	int s2 = 0;
	for(int i=0; i<arr_rows; i++)
	{
		s1 = s1 + *(*(arr + i) + i);
		s2 = s2 + *(*(arr + i) + (arr_columns-1) - i);
	}
	diff = s1 - s2;
	if(diff >= 0)
		return diff;
	else
		return ((diff)*(-1));

}

//Very important link https://www.geeksforgeeks.org/pointer-array-array-pointer/
