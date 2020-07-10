#include <stdio.h>
#include <math.h>
#define MAX 101
#define CRT_SECURE_NO_WARNINGS

void printArray(int list[], int num);
void sort(int list[], int n);
void swap(int *x, int *y);


void main()
{
	int i, n;//list�� ���� �Է��ϴ� for�� ���Ǵ� i, �Է¹��� ������ ���� n
	int list[MAX];//�迭����

	printf("�� ���� ���ڸ� �Է��Ͻðڽ��ϱ�? : ");//�Է¹��� ������ ����(�迭ũ��)
	scanf_s("%d", &n);
	if (n<1 || n>MAX)//1���� �۰ų� MAX������ ū ���� �Է��� ��� ����ó��
	{
		fprintf(stderr, "�߸��� �Է��Դϴ�.\n");
	}
	
	for (i = 0; i < n; i++)//1~MAX ������ ���� �Է��� ���
	{
		printf("���ڸ� �Է��ϼ��� : ");
		scanf_s("%d", &list[i]);//list�迭�� ���� �Է�
		printf("�Է��� �迭 : ");
		printArray(list, i+1);//�Է¹��� ���� ������ �迭 ���

		sort(list, i+1);//�Ժ����� ���� ������ �迭�� ����
		printf("���ĵ� �迭 : ");
		printArray(list, i+1);//���ĵ� �迭�� ���
		printf("\n");
	}

	system("PAUSE");
	return 0;
}

void printArray(int list[], int num)//�迭 ����ϴ� �Լ�
{
	int i;
	for (i = 0; i < num; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");
}

void sort(int list[],int n)//���� �Լ�
{
	int i=0, j;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (list[j] < list[i])
			{
				swap(&list[i], &list[j]);
			}
		}
	}

}
void swap(int *x, int *y)//���� ��ü�ϴ� �Լ�
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

