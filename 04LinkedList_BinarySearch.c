#include <stdio.h>
#include <stdlib.h>
#define IS_EMPTY(ptr) (!(ptr)) //Empty list������ִ����׽�Ʈ
#define IS_FULL(ptr) (!(ptr))

typedef struct listNode* list_pt;//����ü������Ű��������
typedef struct listNode {
	int num; // �Է¹������ڸ������ϴº���
	list_pt link; // ����ü������
}listNode;

void printList(list_pt ptr, list_pt head);//LInked List����Լ�
int binSearch(list_pt ptr, list_pt head, int searchNum, int left, int right);//binarySearch�Լ�
void freeList(list_pt ptr, list_pt head);//linkedlist�����Լ�

void main()
{
	list_pt head = NULL;//ù��°������ּҰ����������ͺ���
	list_pt temp = NULL;//���Ӱ��ԷµǴ°��������ϴ������ͺ���
	list_pt ptr = NULL;;//��带�̵��ϸ鼭����Ű�������ͺ����߰��������Ҷ�
	int n = 0, j = 0;//�Է¹������ڸ� ���� ��Ǽ��ڸ��Է¹���������
	int searchNum, searchIndex;//ã�����ϴ� ���ڸ� �Է¹޴� ����, binSearch���� �޴� ����
	int left = 0, right = 15;//������ ù��°�ε���, �������� �ǳ��ε���
	int middle = 0;
	int end = 1;


	printf("�� ���� ���ڸ� �Է��Ͻðڽ��ϱ�? ");//�Է¹��������ǰ������Է¹���
	scanf_s("%d", &j);

	//�Է¹��� ���� linked list�� ����� ����
	for (int i = 0; i < j; i++)
	{
		printf("����%d�� �Է��ϼ��� : ", i + 1);//���ڸ��Է¹���
		scanf_s("%d", &n);

		temp = (list_pt)malloc(sizeof(listNode));//heap�����̾�����ULL��ȯ
		if (IS_FULL(temp))
		{
			fprintf(stderr, "�޸𸮰�����á���ϴ�\n");
			exit(1);
		}

		temp->num = n;//temp��num���Է¹���������
		temp->link = NULL;//temp��link��NULL����

		if (head == NULL)//head������Ű�³�尡NULL�϶������϶� ù��°��带����
		{
			head = temp;//�Է¹������ڸ�ptr�̰���Ű���ִ�ù��°��忡����
			ptr = head;
		}
		else //�ι�° �����ʹ� �ڷ� �����Ѵ�.
		{
			ptr->link = temp;//head(ù��°���տ�temp���־����Ǿ�
			ptr = ptr->link;
		}
	}
	temp = NULL;//temp�ʱ�ȭ
	//�Է¹��� ���� ã�� ����
	printList(ptr,head);

	while (1)//��ӹݺ�
	{
		printf("ã�����ϴ� ���ڸ� �Է��ϼ��� : ");
		scanf_s("%d", &searchNum);//searchNum�� ����
		searchIndex = binSearch(ptr,head,searchNum, left, right);
		if (searchIndex == -1)
			printf("Linked List�� ã�����ϴ� ���ڰ� �����ϴ�\n");
		else
			printf("����%d�� Linked list�� %d��°�� �ֽ��ϴ�\n", searchNum, searchIndex);//ã�����ϴ¼����� ��ġ������ϴ��Լ�
		printf("�ٸ� ���ڸ� �� ã���ðڽ��ϱ�(���(1) or ����(0)) : ");
		scanf_s("%d", &end);//while���� Ż���ϴ� ��ġ
		printf("\n");

		if (end == 0)//0�� �Է��ϸ� while���� ���������� ���α׷��� �����Ѵ�.
			break;
	}
	free(ptr, head);
	system("PAUSE");
	}


void printList(list_pt ptr, list_pt head)
{
	ptr = head;//ptr�� ó������ �̵���Ŵ

	printf("Linked List�� ");
	while (ptr != NULL)//ptr�� ���尡 �ƴѵ���(����������)
	{
		printf("%d ", ptr->num);//ptr�� ����Ű�� num�� ���
		ptr = ptr->link;//ptr�� �������� �̵���Ŵ
	}
	printf("�Դϴ�.\n");
}

int binSearch(list_pt ptr, list_pt head, int searchNum, int left, int right)
{
	//���������� ���ĵǾ��ִ� Linked List���� searchNum�� ã�� �Լ� �O������ ���-1�� ������
	int middle;//�߰� ��ġ�� �����ϴ� ����
	while (left <= right)
	{
		ptr = head;
		middle = (right + left) / 2;//�迭�� �߰���ġ(�߰���)
		for (int i = 0; i < middle; i++)
		{
			ptr = ptr->link;//ptr�� ��� ��ġ�� ���� �̵���Ŵ
		}
		if (ptr->num < searchNum)
			left = middle + 1;//���ʰ��� �̵�
		else if (ptr->num > searchNum)
			right = middle - 1;//������ ���� �̵�
		else return middle+1;
	}
	return -1;
}

void freeList(list_pt ptr, list_pt head)
{
	while (head != NULL)//�Ҵ�����޸𸮸�������Ŵ
	{
		ptr = head;
		head = ptr->link;//ù��°��带�ٲ�
		free(ptr);//��带������Ŵ
	}
}