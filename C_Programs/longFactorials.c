int * prod(int *arr, int arr_size, int x)
{
	int * P[];
	int car = 0;
	for(int i=0; i<arr_size; i++)
	{ 
		*(P+i) = (*(arr+i) * x)%10 + car;
		car = (*(arr+i) * x)/10;
	}
	if(car!=0)
		*(P + arr_size) = car;
	return P;
}

int Fact(int n)
{
	
