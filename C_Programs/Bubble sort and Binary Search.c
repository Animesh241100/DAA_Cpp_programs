#include<stdio.h>
int main()
{
	// Bubble Sorting
	int n, c, x, l, h, flag=0, mid;
	printf("no of chars\t");
	scanf("%d", &n);
	char str[n], ch;
	int arr[n];
	mid = (l+h)/2;
	printf(" enter characters\n");
	for(int i=0; i<n; i++)
	{
		scanf("\n%c", &str[i]);
	}
	printf("\nBefore sort\n");
	for(int i=0; i<n; i++)
	{
		arr[i] = str[i];
		printf("%d\t", arr[i]);
	}
	for(int j=0; j<n-1; j++)
	{
	
		for(int i=0; i<n-j-1; i++)
		{
			if(arr[i]>arr[i+1])
			{
				c = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = c;
			}
		                            
		}
	}	
	printf("\nAfter sort\n");
	for(int i=0; i<n; i++)
	{
		printf("%d\t%c\n", arr[i], arr[i]);
	}
	
	//Program for Binary searching
	
	printf("\n--------------------------------------------------------\n\nEnter the character to search\n");
	scanf("\n%c", &ch);
	x=ch;
	printf("%d", x);
	h = n-1;
	l=0;
	mid = (l+h)/2;
	while(l<=h)
    	{
        	mid=(l+h)/2;
 
       		if(x==arr[mid])
       		{
            		flag=1;
            		break;
        	}
        	else
        	{
            		if(x>arr[mid])
                		l=mid+1;
           		else
                		h=mid-1;
    		}
	 }
 
    	if(flag==1)
        	printf("\nElement found at position %d\n",mid+1);
    	else
        	printf("\nElement not found");
	return 0;		
}
