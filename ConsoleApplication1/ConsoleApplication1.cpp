// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//
#include "pch.h"
#define  _CRT_SECURE_NO_WARNINGS
#include <stdbool.h> 
#include <stdio.h> 
#include <string.h>
int main()
{
	int n;
	bool id = false;
	const char* firstname[15];
	const char* lastname[25];
	printf("Enter first name:");
	scanf("%s", &firstname);
	printf("Enter last name:");
	scanf("%s", &lastname);
	FILE *write_file;
	struct person
	{
		const char* firstname[15];
		const char* lastname[25];
		const char* t_number[20];
	};
	struct person person_list[50];
	if ((write_file = fopen("phonedir.txt", "r")) == NULL) {
		printf("Error opening file.");
		return 0;
	}
	else {
		fscanf(write_file, "%d\n", &n);
		for (int i = 0; i < n; i++) {
			if ((strcmp(firstname[0], person_list[i].firstname[0]) == 0) && (strcmp(lastname[0], person_list[i].lastname[0]) == 0)) {
				id = true;
				continue;
			}
			else {
				fscanf(write_file, "%s %s %s", &person_list[i].firstname[0], &person_list[i].lastname[0], &person_list[i].t_number[0]);
			}
		}
	}
	fclose(write_file);

	if ((write_file = fopen("phonedir.txt", "w")) == NULL) {
		printf("Error opening file.");
		return 0;
	}
	else {
		fprintf(write_file, "%d\n", n);
		for (int i = 0; i < n; i++) {
			fprintf(write_file, "%s %s %s", person_list[i].firstname,
				person_list[i].lastname, person_list[i].t_number);
		}
	}
	fclose(write_file);
	if (id == true) printf("Data removed from the directory.");
	else printf("Error finding person.");
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
