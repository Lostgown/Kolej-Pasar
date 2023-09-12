#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>
#pragma warning (disable :4996)
void staffMainScreen();
void studentMainScreen();



char globalStudentID[10];
char globalStudentName[50];
float gp;

struct courseDetail {
	char courseName[9];
	int creditHour;
	float gradePoint;
	float qualityPoint;
	float gpa;
	
};

struct courseDetail allCourse[6];

void clearScreen() {
	rewind(stdin);
	system("CLS");
}

void getGradePoint() {
	int flag = 0;
	char grade[3];
	float gradePoint = 0.00;

	if (flag == 1) {
		printf("\033[0;31m Invalid input.\033[0m");
	}
	flag = 0;

	printf("Input the grade       :");
	scanf("%s", &grade);

	switch (grade[0]) {
	case 'A':
	case 'a':
		switch (grade[1]) {
		case '+':
		case '\0':
			gradePoint = 4.00;
			break;
		case '-':
			gradePoint = 3.75;
			break;
		}
		break;
	case 'B':
	case 'b':
		switch (grade[1]) {
		case '+':
			gradePoint = 3.50;
			break;
		case '\0':
			gradePoint = 3.00;
			break;
		case '-':
			gradePoint = 2.75;
			break;
		}
		break;
	case 'C':
	case 'c':
		switch (grade[1]) {
		case '+':
			gradePoint = 2.50;
			break;
		case '\0':
			gradePoint = 2.00;
			break;
		}
		break;
	case 'F':
	case 'f':
		gradePoint = 0.00;
		break;
	default:
		flag = 1;
	}
	gp = gradePoint;
}

void viewResults() {
	int sem = 1;
	int i = 0;
	int n = 0;
	int g = 0;
	float qualityPoint = 0.00;
	float sumQualityPoint = 0.00;
	int sumCreditHours = 0;
	float cgpa = 0.00;

	//get and store quality point for all course
	for (g = 0; g < 6; g++) {
		qualityPoint = allCourse[g].gradePoint * allCourse[g].creditHour;
		allCourse[g].qualityPoint = qualityPoint;
	}

	//calculate gpa for all course
	allCourse[1].gpa = (allCourse[0].qualityPoint + allCourse[1].qualityPoint) / (allCourse[0].creditHour + allCourse[1].creditHour);
	allCourse[2].gpa = (allCourse[2].qualityPoint + allCourse[3].qualityPoint) / (allCourse[2].creditHour + allCourse[3].creditHour);
	allCourse[3].gpa = (allCourse[4].qualityPoint + allCourse[5].qualityPoint) / (allCourse[4].creditHour + allCourse[5].creditHour);

	clearScreen();
	
	printf("Student ID  : %s\n",globalStudentID);
	printf("Student Name: %s\n",globalStudentName);

	printf("%-20s%15s%15s\n", "Course Name", "Credit Hour","Grade Point");
	printf("==========================================================\n");

	for (sem = 1; sem < 4; sem++) {
		printf("----------\nSEMESTER %d\n----------\n",sem);
		printf("%-20s%15d%15.2f\n", allCourse[n].courseName, allCourse[n].creditHour, allCourse[n].gradePoint);

		n++;

		printf("%-20s%15d%15.2f\n", allCourse[n].courseName, allCourse[n].creditHour, allCourse[n].gradePoint);
		printf("%50s", "--------------------\n");
		printf("%35s%15.2f\n", "GPA :", allCourse[sem].gpa);

		n++;
	}

	//calculate sum of credit hours and quality point
	for (i = 0; i < 6; i++) {
		sumCreditHours = sumCreditHours + allCourse[i].creditHour;
		sumQualityPoint = sumQualityPoint + allCourse[i].qualityPoint;
	}

	//calculate cgpa
	cgpa = sumQualityPoint / sumCreditHours;

	printf("----------------------------------------------------------\n");
	printf("\n%35s%15d\n", "Total Credit Hour:", sumCreditHours);
	printf("\n%35s%15.2f\n", "CGPA:", cgpa);

	if (sumCreditHours < 21) {
		printf("\n\033[0;31m Student does not fullfill 21 credit hours of study..\033[0m\n");
	}
	else {
		printf("\n\033[0;32m Student fullfill 21 credit hours of study..\033[0m\n");
	}
	
	printf("Press any key to go back...");
	getch();
	return;
}

void updateStudentScreen() {
	int sem = 1;
	int i = 0;
	

	clearScreen();

	//get student info
	printf("Enter student's ID > ");
	scanf("%s", &globalStudentID);
	printf("Enter student's name > ");
	scanf("%s", &globalStudentName);
	clearScreen();

	for (sem = 1; sem < 4; sem++) {

		printf("----------\nSemester %d\n",sem);
		printf("----------\n");
		printf("Enter Course Name     :");
		scanf("%s", &allCourse[i].courseName);
		printf("Enter Credit Hour     :");
		scanf("%d", &allCourse[i].creditHour);
		getGradePoint();
		allCourse[i].gradePoint = gp;

		i++;

		printf("\nEnter 2nd Course Name :");
		scanf("%s", &allCourse[i].courseName);
		printf("Enter Credit Hour     :");
		scanf("%d", &allCourse[i].creditHour);
		getGradePoint();
		allCourse[i].gradePoint = gp;
		printf("-----------------------------\n");
		i++;
	}
	printf("\033[0;32m Student's Details stored.\033[0m\n");
	printf("Press any key to go back... ");
	getch();
	return;
}

void staffMainScreen() {
	int option;
	int flag = 0;

	do {
		clearScreen();

			printf("Kolej Pasar Staff Administrator Mode\n");
			printf("------------------------------------\n");
			printf("(1) Update Student Details\n");
			printf("(2) View Student's Results\n");
			printf("(0) Back\n");
			switch (flag) {
			case 1:
				printf("\033[0;31mInvalid input.\033[0m\n");
				break;
			}
			flag = 0;

			printf("\nPlease select your mode: ");
			scanf("%d", &option);

			switch (option) {
			case 1:
				updateStudentScreen();
				break;
			case 2:
				viewResults();
				break;
			case 0:
				return;
				break;
			default:
				flag = 1;
			}
	} while (option != 0);
}

void staffIDScreen() {
	char staffID[] = "S001";
	char staffID1[5];
	int comparison;
	int flag = 0;

	do {
		clearScreen();

		printf("Kolej Pasar Staff Administrator Mode\n");
		printf("------------------------------------\n");
		printf("Enter 0 to go back...\n");
		switch (flag) {
		case 1:
			printf("\033[0;31mInvalid input.\033[0m\n");
			break;
		}
		flag = 0;

		printf("Please enter your staff ID > ");
		scanf("%s", &staffID1);

		//validate staff ID
		comparison = strcmp(staffID, staffID1);

		if (comparison == 0) {
			staffMainScreen();
		}
		else if (strcmp("0", staffID1) == 0) {
			return;
		}
		else {
			flag = 1;
		}
	} while (staffID1 != 0);
}

void studentMainScreen() {
	int option;
	int flag = 0;

	do {
		clearScreen();
			
			printf("WELCOME, %s \n", globalStudentName);
			printf("Kolej Pasar Student Administrator Mode\n");
			printf("--------------------------------------\n");
			printf("(1) View Results\n");
			printf("(0) Back\n");
			switch (flag) {
			case 1:
				printf("\033[0;31mInvalid input.\033[0m\n");
				break;
			}
			flag = 0;

			printf("\nPlease select your mode: ");
			scanf("%d", &option);
	
			switch (option) {
			case 1:
				viewResults();
				break;
			case 0:
				return;
				break;
			default:
				flag = 1;
			}
	}while (option != 0);
}

void studentIDScreen() {
	char studentID[10];
	int comparison;
	int flag = 0;

	do {
		clearScreen();

		printf("Kolej Pasar Student Administrator Mode\n");
		printf("--------------------------------------\n");
		printf("Enter 0 to go back...\n");
		switch (flag) {
		case 1:
			printf("\033[0;31mInvalid input.\033[0m\n");
			break;
		}
		flag = 0;

		printf("\nPlease enter your student ID > ");
		scanf("%s", &studentID);

		//validate studentID
		comparison = strcmp(globalStudentID, studentID);

		if (comparison == 0) {
			studentMainScreen();
		}
		else if (strcmp("0",studentID) == 0) {
			return;
		}
		else {
			flag = 1;
		}
	} while (studentID != 0);
}

void mainSelectionScreen() {
	int option;
	int flag = 0;

	do {
		clearScreen();

		printf("Kolej Pasar GPA/CGPA Calculator\n");
		printf("-------------------------------\n");
		printf("(1) Staff Administrator Mode\n");
		printf("(2) Student Administrator Mode\n");
		printf("(0) Quit\n");
		switch (flag) {
		case 1:
			printf("\033[0;31mInvalid input.\033[0m\n");
			break;
		}
		flag = 0;

		printf("\nPlease select your mode:");
		scanf("%d", &option);

		switch (option) {
		case 1:
			staffIDScreen();
			break;
		case 2:
			studentIDScreen();
			break;
		case 0:
			clearScreen();
			printf("Have a nice day ~\n");
			break;
		default:
			flag = 1;
		}
	} while (option != 0);
}

void main() {
	printf(" KKK    KKK      OOOOOOOOOOOOO       LLL               EEEEEEEEEEE              JJJ\n");
	printf(" KKK   KKK       OO         OO       LLL               EEE                      JJJ\n");
	printf(" KKK  KKK        OO         OO       LLL               EEE                      JJJ\n");
	printf(" KKK KKK         OO         OO       LLL               EEE                      JJJ\n");
	printf(" KKKKK           OO         OO       LLL               EEEEEEEEEEE              JJJ\n");
	printf(" KKK KKK         OO         OO       LLL               EEE                      JJJ\n");
	printf(" KKK  KKK        OO         OO       LLL               EEE              JJJ     JJJ\n");
	printf(" KKK   KKK       OO         OO       LLL               EEE              JJJ     JJJ\n");
	printf(" KKK    KKK      OOOOOOOOOOOOO       LLLLLLLLLLLL      EEEEEEEEEEEE     JJJJJJJJJJJ\n");

	printf("\n\n\n");

	printf("                 PPPPPPPPPPPPP       AAAAAAAAAAAA      SSSSSSSSSSS      AAAAAAAAAAAA      RRRRRRRRRRRR\n");
	printf("                 PP         PP       AAA      AAA      SSS              AAA      AAA      RR        RR\n");
	printf("                 PP         PP       AAA      AAA      SSS              AAA      AAA      RR        RR\n");
	printf("                 PP         PP       AAA      AAA      SSS              AAA      AAA      RR        RR\n");
	printf("                 PPPPPPPPPPPPP       AAAAAAAAAAAA      SSSSSSSSSSS      AAAAAAAAAAAA      RRRRRRRRRRRR\n");
	printf("                 PP                  AAA      AAA              SSS      AAA      AAA      RR    RRR    \n");
	printf("                 PP                  AAA      AAA              SSS      AAA      AAA      RR     RRR   \n");
	printf("                 PP                  AAA      AAA              SSS      AAA      AAA      RR      RRR  \n");
	printf("                 PP                  AAA      AAA      SSSSSSSSSSS      AAA      AAA      RR       RRR \n");

	printf("========================================================================================================\n");

	printf("\033[0;32mPress Any Key to Continue.....\033[0m");
	getch();

	mainSelectionScreen();

	system("pause");
}

