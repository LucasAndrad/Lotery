#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

FILE *results;

int main() {
  
  int n[100];
  
	results = fopen("teste.csv", "r");
	while (fscanf(results, "%d ", &n[0]) != EOF) { 
		cout << n[0] << endl;
	}

	return 0;

}
