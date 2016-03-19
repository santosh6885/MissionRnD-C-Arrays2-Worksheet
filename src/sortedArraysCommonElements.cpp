/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int i, j, k,found = 1,count=0,flag = 0;
	if (A == NULL || B == NULL || ALen <= 0 || BLen <= 0)
		return NULL;
	struct transaction *temp = NULL;
	//struct transaction *temp = (struct transaction *)malloc(sizeof(struct transaction));
	for (i = 0; i < ALen; i++){
		for (j = 0; j < BLen; j++){
			for (k = 0; k < 11; k++){
				if ((A + i)->date[k] != (B + j)->date[k]){
					found = 0;
					break;
				}

			}
			if (found == 1){
				temp = (struct transaction *)realloc(temp, sizeof(temp)*sizeof(struct transaction));
				temp[count] = A[i];

				count++;
			}
			else{
				found = 1;

			}
		}
	}
		if (temp == NULL)
			return NULL;
		else
			return temp;
	//return NULL;
}