#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEXT_FILE ".txt"
char* string_add(char*, char*);
struct client newClient();
int calcBmr(int, int, int, int);

// Male == 0, Female == 1
struct client {
  char name[20];
  int gender;
  int age;
  int weight;
  int height;
  int bmr;
  char filename[24];
};

int main() {
  struct client new = newClient();
  FILE* file = fopen(new.filename, "w");
  fprintf(file, "CLIENT INFORMATION\n");
  fprintf(file, "-----------------------------\n");
  fprintf(file, "Name: %s\n", new.name);
  if (new.gender == 0) {
    fprintf(file, "Gender: Male\n");
  } else {
    fprintf(file, "Gender: Female\n");
  }
  fprintf(file, "Age: %d\n", new.age);
  fprintf(file, "Weight: %d\n", new.weight);
  fprintf(file, "Height: %d\n", new.height);
  fprintf(file, "Basal Metabolic Rate: %d\n", new.bmr);
  fclose(file);
  return 0;
}

struct client newClient() {
  struct client cli;
  int tempGender = -1;
  printf("Please Input Name [Max 20 Characters]: ");
  scanf("%s", cli.name);
  printf("Please Input Gender (0 for Man, 1 for Woman): ");
  scanf("%d", &tempGender);
  while (tempGender < 0 || tempGender > 1) {
   printf("Please Input Gender (0 for Man, 1 for Woman): ");
   scanf("%d", &tempGender);
  }
  cli.gender = tempGender;
  printf("Please Input Age: ");
  scanf("%d", &cli.age);
  strcpy(cli.filename, cli.name);
  int lcv = 0;
  while (cli.filename[lcv] != '\0') {
    lcv++;
  }
  for (int i = 0; i < strlen(TEXT_FILE); i++) {
    cli.filename[lcv] = TEXT_FILE[i];
    lcv++;
  }
  cli.filename[lcv] = '\0';
  printf("Please Input Weight [Lbs]: ");
  scanf("%d", &cli.weight);
  printf("Please Input Height [Inches]: ");
  scanf("%d", &cli.height);
  cli.bmr = calcBmr(cli.gender, cli.height, cli.weight, cli.age);
  return cli;
}

int calcBmr(int genderNum, int hgt, int wgt, int age) {
  float lastNum;
  float tempHgt = hgt / 2.2046;
  if (genderNum == 0) {
    lastNum = 5;
  } else {
    lastNum = -161;
  }
  return (10 * wgt) + (6.25 * tempHgt) - (5 * age) + lastNum;
}


