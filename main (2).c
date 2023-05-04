#include <stdio.h>

void calculateGPA(int credits[], float classes[], FILE *studentInfo) {
  float totalPoints = 0;
  int totalCredits = 0;
  float Ap = 4;
  float A = 4;
  float Am = 3.7;
  float Bp = 3.3;
  float B = 3;
  float Bm = 2.7;
  float Cp = 2.3;
  float C = 2;
  float Cm = 1.7;
  float Dp = 1.3;
  float D = 1;
  float Dm = 0.7;
  float F = 0;

  for (int x = 0; x < 5; x++) {
    int creditHours = credits[x];
    char grade = classes[x];
    float gradePoints;
    if (grade == 4) {
      gradePoints = Ap;
    } else if (grade == 4) {
      gradePoints = A;
    } else if (grade == 3.7) {
      gradePoints = Am;
    } else if (grade == 3.3) {
      gradePoints = Bp;
    } else if (grade == 3) {
      gradePoints = B;
    } else if (grade == 2.7) {
      gradePoints = Bm;
    } else if (grade == 2.3) {
      gradePoints = Cp;
    } else if (grade == 2) {
      gradePoints = C;
    } else if (grade == 1.7) {
      gradePoints = Cm;
    } else if (grade == 1.3) {
      gradePoints = Dp;
    } else if (grade == 1) {
      gradePoints = D;
    } else if (grade == 0.7) {
      gradePoints = Dm;
    } else if (grade == 0.0) {
      gradePoints = F;
    }

    totalPoints += gradePoints * creditHours;
    totalCredits += creditHours;
  }

  float GPA = totalPoints / totalCredits;
  printf("\n");
  printf("GPA: %.2f", GPA);
  fprintf(studentInfo, "GPA: %.2f", GPA);
  fclose(studentInfo);
}

int main() {
  FILE *studentInfo;
  char studentName[100];
  float classes[5];
  int infoOrGetFile, i, credits[5];
  float GPA;
  printf("Do you want to input info or get file? (0 for info, 1 for file) ");
  scanf("%d", &infoOrGetFile);
  printf("\n");
  if (infoOrGetFile == 0) {
    studentInfo = fopen("studentInfo.txt", "w");
    printf("What is the student's name? ");
    scanf("%s", studentName);
    fprintf(studentInfo, "Name: %s\n", studentName);
    printf("Input numbers according to grade.\n");
    printf("4 = A+\n");
    printf("3.7 = A\n");
    printf("3.3 = A-\n");
    printf("3 = B+\n");
    printf("2.7 = B\n");
    printf("2.3 = B-\n");
    printf("2 = C+\n");
    printf("1.7 = C\n");
    printf("1.3 = C-\n");
    printf("1 = D+\n");
    printf("0.7 = D\n");
    printf("0.3 = D-\n");
    printf("0 = F\n");

    for (i = 0; i < 5; i++) {
      printf("\n");
      printf("Enter the credit hours for class %d: ", i + 1);
      scanf("%d", &credits[i]);
      fprintf(studentInfo, "Class %d credits: %d\n", i + 1, credits[i]);
      printf("\n");
      printf("Enter the grade for class %d: ", i + 1);
      scanf("%f", &classes[i]);
      fprintf(studentInfo, "Class %d grade: %f\n", i + 1, classes[i]);
    }
    calculateGPA(credits, classes, studentInfo);

  } else if (infoOrGetFile == 1) {
    if (studentInfo == NULL) {
      printf("File does not exist. Start over!");
      return 0;
    }
    studentInfo = fopen("studentInfo.txt", "r");
    printf("You have chosen to view your grades and GPA\n");
    printf("\n");
    fscanf(studentInfo, "Name: %s", studentName);
    printf("Name: %s\n", studentName);
    printf("\n");
    printf("4 = A+\n");
    printf("3.7 = A\n");
    printf("3.3 = A-\n");
    printf("3 = B+\n");
    printf("2.7 = B\n");
    printf("2.3 = B-\n");
    printf("2 = C+\n");
    printf("1.7 = C\n");
    printf("1.3 = C-\n");
    printf("1 = D+\n");
    printf("0.7 = D\n");
    printf("0.3 = D-\n");
    printf("0 = F\n");
    for (i = 0; i < 5; i++) {
      char grades[2];
      char str1[10], str2[10];
      int x = 0;
      printf("\n");
      fscanf(studentInfo, "%s %d %s %d", str1, &x, str2, &credits[i]);
      printf("%s %d %s %d\n", str1, x, str2, credits[i]);
      fscanf(studentInfo, "%s %d %s %f", str1, &x, str2, &classes[i]);
      printf("%s %d %s %f\n", str1, x, str2, classes[i]);
      printf("\n");
      printf("------------------------\n");
    }
    studentInfo = fopen("studentInfo.txt", "r");
    while (!feof(studentInfo)) {
      char c = fgetc(studentInfo);
      if (c == 'A') {
        char str1[10], str2[10], str3[10];
        printf("\n");
        printf("GPA");
        fscanf(studentInfo, "%s %s %f", str1, str2, &GPA);
        printf(": %.2f", GPA);
        printf("\n");
        break;
      }
    }
    fclose(studentInfo);
  } else {
    printf("That is not a valid option. Start over!");
    return 0;
  }
}