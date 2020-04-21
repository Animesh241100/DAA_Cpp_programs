void SelectionSort(int a[0...size-1])
{
  
  for(int i=0; i<size-1; ++i)
  {
     max=a[0];
     imax=0;
    for(int j=1; j<size-i; j++)
      if(a[j] > max)
      {
          max=a[j];
          imax=j;
      }

    
     swap a[imax] with a[size-i-1];
    

  }

}

