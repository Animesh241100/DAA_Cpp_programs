void BubbleSort(int a[0...size-1])
{
  
  for(int i=0; i<size-1; ++i)
    for(int j=0; j<size-i-1; j++)
       if(a[j]>a[j+1])
        {
         swap a[j] with a[j+1];
        }

}

