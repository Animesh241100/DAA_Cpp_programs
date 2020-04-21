void main()
{
    int a[10000];
    int temp,n,start,last,mid;
    printf("Enter array:");
    for(int i=0;i<10000;i++)
    {
   	 scanf("%d",&a[i]);
   	 if(a[i]==-1)
   	 {
   		 while(i<10000)
   		 {
   			 a[i]=-1;
   			 i++;
   		 }
   	 }
    }
    n=1;
    while(a[n-1]!=-1)
    n=2*n;
    start=1;
    last=n;
    n=n/2;
    mid=n;
    while(a[mid-1]!=-1||a[mid-2]==-1)
    {
   	 if(a[mid-1]==-1 && a[mid-2]==-1)
   	 {
   		 last=mid;
   		 n=n/2;
   		 mid=last-n;
   	 }
   	 else if(a[mid]!=-1)
   	 {
   		 start=mid;
   		 n=n/2;
   		 mid=start+n;
   	 }
    }
    printf("Position: %d",mid+1);
}

