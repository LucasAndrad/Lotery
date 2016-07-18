/*

Name: Lucas Andrade Olivera
University: UnB - Campus Gama
Age: 20 years
Country: Brasil
Program Description: This program show how many times some 
number has appeared in specific lottery game of Brasil.
Operational System LINUX - UBUNTU 15.04

*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
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
string getGameName();
void getNumbersInfo(Info *lot, int linesCount);
void orderByCount(Info* lot);
void putInfoInFile(Info* lot, int linesCount, string gameName);
void showInfo(Info *lot, int linesCount);

// function main begin here
int main() {
 
	int lines=0;
  lines = countLines();
  string nameGame;
  nameGame = getGameName();
  Info *lottery = (Info *) malloc(sizeof(Info)*numbersGame);
  setValueNumbers(lottery);
	getNumbersInfo(lottery, lines);
	orderByCount(lottery);
	putInfoInFile(lottery, lines, nameGame);
	cout << "Para ver o resultado basta abrir o arquivo dataFile.txt para visualizar os dados\n";
	//showInfo(lottery, lines);
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

// get the game name of lottery
string getGameName() {
	
	string gameName;
	cout << "Digite o nome do jogo que deseja analisar\n";
	cin >> gameName;
	return gameName;
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

// order struct INFO by count
void orderByCount(Info* lot) {

	int i=0, j=0;
	Info helper;
	for(i=numbersGame-1; i >= 1; i--) { 
    for(j=0; j < i ; j++) { 
      if(lot[j].count>lot[j+1].count) { 
        helper = lot[j];
        lot[j] = lot[j+1];
        lot[j+1] = helper;
      }
    }
	}
}

// put Info of numbers in some file
void putInfoInFile(Info* lot, int linesCount, string gameName) {

	infoResults = fopen("dataFile.txt", "w+");
	fprintf(infoResults, "Resultado da %s.\n\n", gameName.c_str());
	fprintf(infoResults, "Esse arquivo analisa %d resultados da %s.\n", linesCount, gameName.c_str());
	fprintf(infoResults, "Mostrando o número, a quantidade de vezes que ele aparece nos %d jogos e também a porcentagem\n\n", linesCount);
	int i=0;
	for(i=0; i<numbersGame; i++) {
		if (lot[i].number<10) {
			fprintf(infoResults, "Número: %d   Quantidade: %d  Porcentagem: %.03lf%%\n", lot[i].number, lot[i].count, lot[i].percent);
		}
		else {
			fprintf(infoResults, "Número: %d  Quantidade: %d  Porcentagem: %.03lf%%\n", lot[i].number, lot[i].count, lot[i].percent);
		}
	}
	fclose(infoResults);
}

// show the numbers and their information
void showInfo(Info *lot, int linesCount) {
	
	int i=0;
	cout << "Lines = " << linesCount << endl;
	for(i=0; i<numbersGame; i++) {
		printf ("Number: %d  Times: %d  Percent: %.03lf\n", lot[i].number, lot[i].count, lot[i].percent);
	}
}






