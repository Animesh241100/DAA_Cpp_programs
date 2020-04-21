int Rowcheck(int i, int **arr)
{
	int cost = 0;
	int S;
	S = *(arr+i) + *(*(arr+i)+1) + *(*(arr+i)+2);
	if((15-S)!=0)
	{
		cost = Mod( *(*(arr+i)+i), 15-S);
		*(*(arr+i)+i) = 15-S;
	}
	return cost;
}

int ColCheck(int j, int **arr)
{
	int cost = 0;
	int S, i;
	S = *(*(arr)+j) + *(*(arr+1)+j) + *(*(arr+2)+j); 
	i = j+1;
	if((15-S)!=0)
	{
		cost = Mod( *(*(arr+i)+j), 15-S);
		*(*(arr+i)+j) = 15-S;	
	}
	return cost;
}	

int Mod(int x, int y)
{
	int d = x-y;
	if(d>=0)
		return d;
	else
		return (d*(-1))
}

int Diagcheck(int **arr)
{
	int cost = 0;
	int S;
	S = **arr + *(*(arr+1)+1) + *(*(arr+2)+2);
	if((15-S)!=0)
	{
		cost = Mod( *(*(arr+2)+2) , 15-S);
		*(*(arr+2)+2) = 15-S;
	}
	return cost;
}

int formingMagicSquare(int s_rows, int s_columns, int** s)
{
	int cost = 0;
	cost = cost + Rowcheck(0, s);
	cost = cost + Colcheck(0, s);
	cost = cost + Rowcheck(1, s);
	cost = cost + DiagCheck(s);
	cost = cost + Colcheck(1, s);
	return cost;
}
	
//Remember that *(*(arr+i)+j) stores the data present in cell of ith row and jth column
//for more info refer the link https://www.geeksforgeeks.org/pointer-array-array-pointer/

		
