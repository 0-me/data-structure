#include <stdio.h>
#include <stdlib.h>

int binSearch(int list[], int searchNum, int left, int right);

void main()
{
	int list[16] = {4, 7, 8, 11, 13, 15, 21, 26, 42, 43, 48, 49, 75, 96, 97, 103 };
	int searchNum;//ã�����ϴ� ���ڸ� �Է¹޴� ����
	int searchIndex;//ã�����ϴ� ������ �ε����� �����ϴº���
	int left = 0, right = sizeof(list)/sizeof(int) -1;//������ ù��°�ε���, �������� �ǳ��ε���
	int end = 1;

	while(1)//��ӹݺ�
	{
		if (end == 1)
		{
			printf("4, 7, 8, 11, 13, 15, 21, 26, 42, 43, 48, 49, 75, 96, 97, 103\nã�����ϴ� ���ڸ� �Է��ϼ��� : ");
			scanf_s("%d", &searchNum);//searchNum�� ����
			searchIndex = binSearch(list, searchNum, left, right);//binSearch�� ��ȯ�� ���� �����Ѵ�.
			if (searchIndex == -1)//�迭�� ���ڰ� ���� ��� -1�� ��ȯ�Ѵ�.
				printf("�迭�� ã�����ϴ� ���ڰ� �����ϴ�.\n");
			else
				printf("���� %d�� list index %d�� �ֽ��ϴ�.\n", searchNum, searchIndex);//ã�����ϴ� ������ index�� ����ϴ� �Լ�
			printf("�ٸ� ���ڸ� �� ã���ðڽ��ϱ�(���(1) or ����(0)) : ");
			scanf_s("%d", &end);//while���� Ż���ϴ� ��ġ
			printf("\n");
		}
		else if (end == 0)//0�� �Է��ϸ� while���� ���������� ���α׷��� �����Ѵ�.
			break;
	}
	system("PAUSE");
	return 0;
}

int binSearch(int list[], int searchNum, int left, int right)
{
	//���������� ���ĵǾ��ִ� �迭���� searchNum�� ã�� �Լ� �O������ ���-1�� ������
	int middle;//�߰� �ε����� �����ϴ� ����
	while (left <= right)
	{
		middle = (right + left) / 2;//�迭�� �߰��ε���(�߰���)
		if (list[middle] < searchNum)
			left = middle + 1;//���ʰ��� �̵�
		else if (list[middle] > searchNum)
			right = middle - 1;//������ ���� �̵�
		else return middle;//list[middle]�� search���� �������
	}
	return -1;
}

