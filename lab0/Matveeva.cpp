#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "rus");
	int x1, x2, y1, y2, r1, r2, S;//S=���������� ����� ��������
	printf("������� ������ ���������� ������ ����������:\n ");
	scanf_s("%d", &x1);
	printf("������� ������ ���������� ������ ����������:\n ");
	scanf_s("%d", &y1);
	printf("������� ������ ���������� ������ ����������:\n ");
	scanf_s("%d", &x2);
	printf("������� ������ ���������� ������ ����������:\n ");
	scanf_s("%d", &y2);
	printf("������� �������� ������� ������ ����������:\n ");
	scanf_s("%d", &r1);
	printf("������� �������� ������� ������ ����������:\n ");
	scanf_s("%d", &r2);

	S = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2)*(y1 - y2));

	if (S== (r1 + r2)) {
		printf("���������� ��������:\n");
	}
	else if (S > (r1 + r2)) {
		printf("���������� �� ������������:\n");
	}
	else {
		printf("���������� ������������:\n");
	}

}