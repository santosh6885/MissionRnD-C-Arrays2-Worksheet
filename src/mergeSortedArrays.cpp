/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
int tointeger(char *str, int st, int sp);

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int i=0, j=0,k,itr, count = 0;
	int year1, year2, month1, month2, day1, day2;
	struct transaction *res = (struct transaction *)malloc((ALen + BLen)*sizeof(struct transaction));
	if (A == NULL || B == NULL || ALen <= 0 || BLen <= 0)
		return NULL;
	 while(1){
		 if (i == ALen){
			 for (k = j; k < BLen; k++){
				 res[count] = B[k];
				 count++;
			 }
			 break;
		 }
		 if (j == ALen){
			 for (k = i; k < ALen; k++){
				 res[count] = A[k];
				 count++;
			 }
			 break;
		 }
		 if (i == ALen && j == BLen)
			 break;
		year1 = tointeger((A + i)->date, 6, 10);
		year2 = tointeger((B + j)->date, 6, 10);
		if (year1 < year2){
			res[count] = A[i];
			count++;
			i++;

		}
		else if (year1 > year2){
			res[count] = B[j];
			count++;
			j++;
		}
		else{
			month1 = tointeger((A + i)->date, 3, 5);
			month2 = tointeger((B + i)->date, 3, 5);
			if (month1 < month2){
				res[count] = A[i];
				count++;
				i++;

			} 
			else if(month1>month2){
				res[count] = B[j];
				count++;
				j++;

			}
			else{
				day1 = tointeger((A + i)->date, 0, 2);
				day2 = tointeger((B + i)->date, 0, 2);
				if (day1 < day2){
					res[count] = A[i];
					count++;
					i++;
				}
				else if (day1 > day2){
					res[count] = B[j];
					count++;
					j++;
				}
				else{
					res[count] = A[i];
					count++;
					i++;
					res[count] = B[j];
					count++;
					j++;
				}
			}
		}

			
	}

	
	
	return res;
	//return NULL;
}
int tointeger(char *str, int st, int sp){
	int r = 0, i;
	for (i = st; i < sp; i++)
		r = r * 10 + str[i] - '0';
	return r;
}