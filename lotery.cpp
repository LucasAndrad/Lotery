/*
Name: Lucas Andrade Olivera
University: UnB - Campus Gama
Age: 20 years
Country: Brasil
Program Description: This program show how many times some 
number has appeared in specific lottery game of Brasil.
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define numbersGame 100
using namespace std;

FILE *results;
FILE *infoResults;

// struct to save numbers information
typedef struct {
	
	int number;
	int count;
	double percent;
}Info;

// list of functions
void setValueNumbers(Info *lot);
int countLines();
void getNumbersInfo(Info *lot, int linesCount);
void showInfo(Info *lot);

// function main begin here
int main() {
 
	int lines=0;
  lines = countLines();
  cout << "Lines = " << lines << endl;
  Info *lottery = (Info *) malloc(sizeof(Info)*numbersGame);
  setValueNumbers(lottery);
	getNumbersInfo(lottery, lines);
	showInfo(lottery);
	return 0;

}
// function to count number of lines in file
int countLines() {
	int l=0;
	char w;
	results = fopen("dados.csv", "r");
	w = fgetc(results);
	while (w!=EOF) {
		w = fgetc(results);
		if (w == '\n') { 
			l++;
		}
	}
	fclose(results);
	return l;
}

// set value to numbers of struct
void setValueNumbers(Info *lot) {

	int i=0;
	for (i=0; i<numbersGame; i++) {
		lot[i].number = i;
		lot[i].count = 0;
		lot[i].percent = 0;
	}
}

// get count and percent of all numbers game
void getNumbersInfo(Info *lot, int linesCount) {

	int n;
	results = fopen("dados.csv", "r");
	while (fscanf(results, "%d ", &n) != EOF) { 
		lot[n].count++;
		lot[n].percent = ((lot[n].count*100.0)/linesCount);
	}
	fclose(results);
}

// show the numbers and their information
void showInfo(Info *lot) {
	
	int i=0;
	for(i=0; i<numbersGame; i++) {
		printf ("Number: %d  Times: %d  Percent: %.03lf\n", lot[i].number, lot[i].count, lot[i].percent);
	}
}






