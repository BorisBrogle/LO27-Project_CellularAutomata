Matrix newMatrix(_Bool** table, int rows, int cols)
{

	Matrix matrix;
	matrix = createAndAllocateMatrix(rows, cols);

	if (matrix.cols == NULL)
	{
		return matrix;
	}

	int i=0,j=0;
	rowElement* rowElem;
	rowElem = matrix.rows;

	cellElement* cellElem;
	for (i=0;i<rows;i++)
	{	
		cellElem = rowElem->row;
		for (j=0;j<cols;j++)
		{
			cellElem->value = table[i][j];
			cellElem = cellElem->nextCol;
		}
		rowElem = rowElem->nextRow;
	}

	return matrix;
}


Matrix createAndAllocateMatrix(int rows, int cols)
{
	int i =0,j =0;
	Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
	matrix->colCount = cols;
	matrix->rowCount = rows;
	
	if (rows<1 || cols <1)
	{
		matrix->cols = NULL;
		matrix->rows = NULL;
	}
	else
	{
		/*Creation of the first colElement*/
		colElement* firstColElement = (colElement*)malloc(sizeof(colElement));

		matrix->cols = firstColElement;
	
		firstColElement->prevCol = NULL;
		firstColElement->colN = 0;
		firstColElement->nextCol = NULL;
	

		/*Creation of the first rowElement*/
		rowElement* firstRowElement = (rowElement*)malloc(sizeof(rowElement));

		matrix->rows = firstRowElement;
	
		firstRowElement->prevRow = NULL;
		firstRowElement->rowN = 0;
		firstRowElement->nextRow = NULL;


		rowElement* secRowElement;

		cellElement* newCell;
		cellElement* prevCell;
		for (i=0; i<rows; i++)
		{	
			//Creation of the first col
			newCell = (cellElement*)malloc(sizeof(cellElement));
			newCell->rowIndex = i;
			newCell->colIndex = 0;
			newCell->nextCol = NULL;
			newCell->nextRow = NULL;
			newCell->value = 0;
			if (i != 0)
			{
				prevCell->nextRow = newCell;
			}
			else
			{
				firstColElement->col = newCell;
			}
			prevCell = newCell;
		

			//Linking the rowElements with every cellElements
			firstRowElement->row = newCell;
			if (i+1<rows)
			{
				secRowElement = (rowElement*)malloc(sizeof(rowElement));
				secRowElement->prevRow = firstRowElement;
				firstRowElement->nextRow = secRowElement;
				secRowElement->rowN = i+1;
				secRowElement->nextRow = NULL;
				firstRowElement = secRowElement;
			}
		}

		cellElement* firstCells;
		colElement* secColElement;
		for (j=1; j<cols; j++)
		{	
			//Creation of the other cells and linking them with the previous col cells'
			secColElement = (colElement*)malloc(sizeof(colElement));
			secColElement->prevCol = firstColElement;
			firstColElement->nextCol = secColElement;
			secColElement->colN = j;
			secColElement->nextCol = NULL;

			firstCells = firstColElement->col;
			for (i=0; i<rows; i++)
			{	
				newCell = (cellElement*)malloc(sizeof(cellElement));
				newCell->rowIndex = i;
				newCell->colIndex = j;
				newCell->nextCol = NULL;
				newCell->nextRow = NULL;
				newCell->value = 0;
				if (i != 0)
				{
					prevCell->nextRow = newCell;
				}
				else
				{
					secColElement->col = newCell;
				}
				prevCell = newCell;
				firstCells->nextCol = newCell;
				if (i+1<rows)
				{
					firstCells = firstCells->nextRow;
				}
			}
			firstColElement = secColElement;
		}
	}
	return *matrix;
}