#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h> // bool, true, false�� ���ǵ� ��� ����
#include <stdlib.h> //exit()�� ����ϱ� ���� ��� ����

int calculateDayofStart(int year);
bool calculateFeb(int year);
int getTotalDaysOfMonth(int year, int month);
int getStartDayOfMonth(int year, int month);
void printType1(int year);
void printType2(int year, int month);
void printTitle();
void printCalender(int year, int month);

void main() {
	int inputType;
	int year;
	int month;

	printf("�޷��� ����ϴ� ���α׷� �Դϴ�.\n");
	printf("�޴��� �����ϼ���.(1. -> ����, 2 -> ������ ��): ");
	scanf("%d", &inputType);

	if (inputType == 1) {
		printf("���� �Է��ϼ���: ");
		scanf("%d", &year);
		printType1(year);
	}
	else if (inputType == 2) {
		printf("���� ���� �Է��ϼ���: ");
		scanf("%d%d", &year, &month);
		printType2(year, month);
	}
	else {
		printf("(����)�޴��� ���� �� �����ؼ� ���α׷��� �����մϴ�.\n");
		exit(1); //������ ���� ����
	}
}

//�� ���� ù���� ���� ���ϱ�
int calculateDayofStart(int year) {
	return ((year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;
}

//���� ��� (2��)
bool calculateFeb(int year) {
	return (!(year % 4) && (year % 100)) || !(year % 400);
}

//�ش� �⵵�� ���� ������ ��¥ ���ϱ�
int getTotalDaysOfMonth(int year, int month) {
	int totalDaysOfMonths = 0;

	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		totalDaysOfMonths = 31;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		totalDaysOfMonths = 30;
	else if (month == 2)
		if (calculateFeb(year))
			totalDaysOfMonths = 29;
		else
			totalDaysOfMonths = 28;

	return totalDaysOfMonths;
}

//�ش� �⵵�� ���� ���� ���� ���ϱ�
//1:�Ͽ��� ~ 7:����� 
int getStartDayOfMonth(int year, int month) {
	int startDayOfYear = calculateDayofStart(year);

	for (int i = 1; i < month; i++) {
		startDayOfYear = startDayOfYear + getTotalDaysOfMonth(year, i);
	}
	return startDayOfYear = (startDayOfYear % 7) + 1;
}

//�⵵�� �޾�����
void printType1(int year) {
	for (int i = 1; i <= 12; i++) {
		printCalender(year, i);
		printf("\n");
	}
}

//�⵵�� ���� ������
void printType2(int year, int month) {
	printCalender(year, month);
}

// Ÿ��Ʋ �׸���
void printTitle() {
	printf("-----------------------------\n");
	printf(" sun mon tue wed thu fri sat \n");
	printf("-----------------------------\n");
}

//XXXX�� X�� �޷� ���
void printCalender(int year, int month) {
	printf("%d�� %d��\n", year, month);
	int totalDaysOfMonths = getTotalDaysOfMonth(year, month);
	int startDay = getStartDayOfMonth(year, month);
	printTitle();

	// ���� ����
	if (startDay != 7) {
		for (int i = 0; i < startDay; i++) {
			printf("    ");
		}
	}

	for (int i = 1; i <= totalDaysOfMonths; i++) {
		printf("%4d", i);
		if ((startDay + i) % 7 == 0)
			printf("\n");
	}
	printf("\n");
}