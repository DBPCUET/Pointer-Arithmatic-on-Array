//Accessing elements of 1D and 2D array using pointers.
//Formula : A[i][j] = base + (i*col+j) , Row_Major
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int sz ;
	cin >> sz ;
	int ara[sz] ;
	for (int i = 0 ; i < sz ; i++)
	{
		cin >> *(ara + i) ;
	}
	int row, col ;
	cin >> row >> col ;
	int Ara[row][col] ;
	for (int i = 0 ; i < row ; i++)
	{
		for (int j = 0 ; j < col ; j++)
		{
			cin >> *(*(Ara + i) + j) ;
		}
	}
	int *base = &ara[0] ;
	int *Base = &Ara[0][0] ;
	cout << "The 1D Array: " << "\n" ;
	for (int i = 0 ; i < sz ; i++)
	{
		cout << *(base + i) << " " ;
	}
	cout << "\n" << "\n" << "The 2D Array: " << "\n" ;
	for (int i = 0 ; i < row ; i++)
	{
		for (int j = 0 ; j < col ; j++)
		{
			cout << *(Base + (i * col + j)) << " " ;
		}
		cout << endl ;
	}
//Secondary diagonal reverse [ row = col ]
	int i = 0;
	int j = col ;
	while ( i < j)
	{
		//swap (Ara[i][i] , Ara[j-1][j-1]) ;
		//swap(Ara[i][j-1] , Ara[j-1][i]) ;
		swap ( *(Base + (i * col + (j - 1 ))) , *(Base + ((j - 1) * col + i)) ) ;
		i++ ;
		j-- ;
	}
	cout << "\n" << "\n" << "After reversing the secondary diagonal: " << "\n" ;
	for (int i = 0 ; i < row ; i++)
	{
		for (int j = 0 ; j < col ; j++)
		{
			cout << *(Base + (i * col + j)) << " " ;
		}
		cout << endl ;
	}

//Multiplication of 2D matrix
	int r2, c2 ;
	cin >> r2 >> c2 ;
	double ara2[r2][c2] ;
	for (int i = 0 ; i < r2 ; i++)
	{
		for (int j = 0 ; j < c2 ; j++)
		{
			cin >> *(*(ara2 + i) + j) ;
		}
	}
	double *base_2 = &ara2[0][0] ;
	cout << "\n" << "\n" "The second 2D array" << "\n" ;
	for (int i = 0 ; i < r2 ; i++)
	{
		for (int j = 0 ; j < c2 ; j++)
		{
			cout << *(base_2 + ( (i * c2) + j )) << " " ;
		}
		cout << "\n" ;
	}
	if (col == r2)
	{
		cout << "\n" << "\n" << "The Multiplication of the reversed and second array: " << "\n" ;
		double mul[row][c2] = {'\0'} ;
		double *base_mul = &mul[0][0] ;
		for (int i = 0 ; i < row ; i++)
		{
			for (int j = 0 ; j < c2 ; j++)
			{
				*(base_mul + ( (i * c2) + j )) = 0 ;
				for (int k = 0 ; k < r2 ; k++)
				{
					(*(base_mul + ( (i * c2) + j ))) += (*(Base + ( (i * col) + k ))) * (*(base_2 + ( (k * c2) + j ))) ;
				}
				cout << *(base_mul + ( (i * c2) + j )) << " " ;
			}
			cout << "\n" ;
		}
	}
	else
	{
		cout << "\n" << "\n" << "Multiplication not possible" << "\n" ;
	}
	cout << "\n" ;

//Symmetry or skewsymmetry
	bool issymmetry, isskew;
	for (int i = 0 ; i < r2 ; i++)
	{
		issymmetry = true ;
		for (int j = 0 ; j < c2 ; j++)
		{
			if ( *(base_2 + ((c2 * i) + j)) != *(base_2 + ((c2 * j) + i)) )
			{
				issymmetry = false ;
				break ;
			}
		}
		if (issymmetry == false)
		{
			break ;
		}
	}
	for (int i = 0 ; i < r2 ; i++)
	{
		isskew = true ;
		for (int j = 0 ; j < c2 ; j++)
		{
			if (*(base_2 + ((c2 * i) + j)) != -1 * (*((base_2 + ((c2 * j) + i)))))
			{
				isskew = false ;
				break ;
			}
		}
		if (isskew == false)
		{
			break ;
		}
	}
	if (issymmetry)
	{
		cout << "\n" << "The second array is: " << "symmetric" << endl;
	}
	if (isskew)
	{
		cout << "\n" << "The second array is: " << "Skew symmetric" << endl;
	}

}