/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int toint(char *str, int st, int sp);

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int i, j = 0,k, flag = 0, year, month, day,year1,month1,day1,res = 0;
	if (Arr == nullptr || len <= 0)
			return -1;
	for (i = 0; date[i]; i++){
		if (date[i] == '-'){
			if (flag == 0){

				day = toint(date, j,i);
				j = i + 1;
				flag++;
			}
			else if (flag == 1){
				month = toint(date, j,i);
				j = i + 1;
				flag++;
			}
			
		}
		else if (date[i + 1] == '\0'){
			year = toint(date, j,i+1);
		}
	}
	flag = 0;
	for (i = 0; i < len; i++){
		k = 9;
		for (j = 9; j>=0; j--){
			if ((Arr + i)->date[j] == '-'){
				if (flag == 0){
					year1 = toint((Arr + i)->date, j+1, k+1);
					k = j - 1;
					if (year1 > year){

						res = len - i;
						return res;
					}
					else if (year1 < year)
						break;
					flag++;
				}
				else if (flag == 1){
					month1 = toint((Arr + i)->date, j+1, k+1);
					k = j - 1;
					flag = 0;
					if (month1 > month){
						res = len - i;
						return res;
					}
					else if (month1 < month)
						break;
				}

			}
			else if (j == 0){
				day1 = toint((Arr + i)->date, j+1, k+1);
				if (day1 > day){
					res = len - i;
					return res;
				}
				else
					break;
					
			}


		}
	
	}
	if (res == 0){
		return res;
	}
	//return -1;
}
int toint(char *str, int st, int sp){
	int r = 0, i;
	for (i = st; i < sp; i++)
		r = r * 10 + str[i] - '0';
	return r;
}
