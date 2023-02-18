#include <stdio.h>
#include <stdlib.h>

#define MAX_TERM 101
#define A 4
#define B 4
#define C 4

typedef struct
{
	int row, column, value;
} nonZeroValues;

void transpose(nonZeroValues a[], nonZeroValues b[]);
void removeDupes(nonZeroValues m[]);
void print(nonZeroValues compact_matrix[MAX_TERM]);
void multiply(nonZeroValues oneDArray[], nonZeroValues transposeMatrix[], nonZeroValues multiplyingMatrix[]);

int main()
{
	int sparse_matrix_1[A][B] = { {0, 10, 0, 5},
								 {0, 2, 4, 0},
								 {0, 0, 0, 0},
								 {3, 0, 0, 7} };

	int sparse_matrix_2[B][C] = { {1, 0, 0, 2},
								 {0, 0, 3, 0},
								 {0, 8, 0, 0},
								 {5, 0, 10, 0} };
	int count = 1;
	int current = 1;
	nonZeroValues OneDArray1[MAX_TERM];
	nonZeroValues OneDArray2[MAX_TERM];
	OneDArray1[0].row = 4;
	OneDArray1[0].column = 4;

	OneDArray2[0].row = 4;
	OneDArray2[0].column = 4;

	// Making of new matrix
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (sparse_matrix_1[i][j] != 0)
			{
				OneDArray1[count].row = i;
				OneDArray1[count].column = j;
				OneDArray1[count].value = sparse_matrix_1[i][j];
				count++;
			}
		}
	}
	OneDArray1[0].value = count - 1;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (sparse_matrix_2[i][j] != 0)
			{
				OneDArray2[current].row = i;
				OneDArray2[current].column = j;
				OneDArray2[current].value = sparse_matrix_2[i][j];
				current++;
			}
		}
	}
	OneDArray2[0].value = current - 1;

	nonZeroValues transposedMatrix[MAX_TERM];

	nonZeroValues multipliedMatrix[MAX_TERM];

	transpose(OneDArray2, transposedMatrix);
	multiply(OneDArray1, transposedMatrix, multipliedMatrix);
	removeDupes(multipliedMatrix);
	print(multipliedMatrix);


}
//referenced by ceng205-ders4.pdf
void transpose(nonZeroValues a[], nonZeroValues b[])
{
	int n, i, j, currentb;
	n = a[0].value;         // number of items
	b[0].row = a[0].column; // number of rows
	b[0].column = a[0].row; // number of columns
	b[0].value = n;
	if (n > 0)
	{
		currentb = 1;
		for (i = 0; i < a[0].column; i++)
			for (j = 1; j <= n; j++) // find the ones with col i in a
				if (a[j].column == i)
				{
					b[currentb].row = a[j].column;
					b[currentb].column = a[j].row;
					b[currentb].value = a[j].value;
					currentb++;
				}
	}
}

void removeDupes(nonZeroValues m[])
{
	for (int i = 1; i <= m[0].value - 1; ++i)
	{
		if (m[i].row == m[i + 1].row && m[i].column == m[i + 1].column)
		{
			for (int j = i + 1; j <= m[0].value; ++j)
			{
				m[j] = m[j + 1];
			}

			m[0].value--;
		}
	}
}

void print(nonZeroValues compact_matrix[MAX_TERM])
{
	printf("Sparse Matrix Multiplication:\nRow\tColumn\tValue\n");
	for (int i = 0; i <= compact_matrix[0].value; i++)
	{
		printf("%d\t %d\t %d \n", compact_matrix[i].row, compact_matrix[i].column, compact_matrix[i].value);
	}
}

void multiply(nonZeroValues oneDArray[], nonZeroValues transposeMatrix[], nonZeroValues multiplyingMatrix[MAX_TERM]) {
	multiplyingMatrix[0].row = oneDArray[0].row;
	multiplyingMatrix[0].column = oneDArray[0].column;
	int flag = 1;
	if (oneDArray[0].column != transposeMatrix[0].row)
	{
		printf("can not multiply");
	}
	else
	{
		//multiplication
		for (int i = 1; i <= oneDArray[0].value; i++)
		{
			for (int j = 1; j <= transposeMatrix[0].value; j++)
			{
				if (oneDArray[i].column == transposeMatrix[j].column)
				{
					multiplyingMatrix[flag].row = oneDArray[i].row + 1;
					multiplyingMatrix[flag].column = transposeMatrix[j].row + 1;
					multiplyingMatrix[flag].value = (oneDArray[i].value * transposeMatrix[j].value);
					flag++;
				}
			}
		}
		multiplyingMatrix[0].value = flag - 1;
		// addition
		for (int i = 1; i <= multiplyingMatrix[0].value; i++)
		{
			for (int j = i + 1; j <= multiplyingMatrix[0].value; j++)
			{
				if (multiplyingMatrix[i].row == multiplyingMatrix[j].row &&
					multiplyingMatrix[i].column == multiplyingMatrix[j].column)
				{
					multiplyingMatrix[i].value = multiplyingMatrix[i].value + multiplyingMatrix[j].value;
				}
			}
		}

		// column sort
		//referenced by https://www.programiz.com/dsa/bubble-sort
		for (int i = 1; i <= multiplyingMatrix[0].value; i++)
		{
			for (int j = i + 1; j <= multiplyingMatrix[0].value; j++)
			{
				if (multiplyingMatrix[i].row == multiplyingMatrix[j].row &&
					multiplyingMatrix[i].column > multiplyingMatrix[j].column)
				{
					int temp = multiplyingMatrix[i].column;
					multiplyingMatrix[i].column = multiplyingMatrix[j].column;
					multiplyingMatrix[j].column = temp;
					int temp2 = multiplyingMatrix[i].value;
					multiplyingMatrix[i].value = multiplyingMatrix[j].value;
					multiplyingMatrix[j].value = temp2;
				}
			}
		}
	}
}