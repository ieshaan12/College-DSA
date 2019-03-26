#include "qsort.h"


int main(int argc, char* argv[])
{
	size = 0;
	
	KeyStruct ptr;
	char * fileName = argv[1];
	printf("%s\n",fileName);

	int* studentArray = readData(fileName);
	
	printArray(studentArray, size);
	
	extractKeys(studentArray,size, 10, 20);
	quickSortKnownKeyRange(studentArray,size, 10, 20);
	//theta(n*k);
	//pi=part2loc(studentArray,0,size-1,(hiKey+loKey)/2);
	
	printf("\nSorted output is:\n");

	//printArray(studentArray, size);
	
}
