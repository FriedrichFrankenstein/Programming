#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct Node
{
    int number;
    struct Node* next;
};

typedef struct Node* PNode;

void Push ( PNode *Head );

void Pop ( PNode *Head );


int main()
{
    getch();
    return 0;
}

void Push ( PNode *Head ) // ��������� ��������� ����� � ����
{
    // S - ������ ���������, �� ����������� Head � Tail �����; word - �������� �� �����, �� ��������� � ����
    PNode NewNode = ( PNode ) calloc ( 1, sizeof ( struct Node ) ); // �������� ������ �� ����� �����
    NewNode->next = *Head; // ������������ � ������ ���� �������� next �� ������� �����-������� (Head),
    *Head = NewNode; // ��� ���� - �������� ������� �����
}

void Pop ( PNode *Head ) // ������� ��������� � ��������� ���������� ����� �����
{
    PNode TopNode = *Head; // �������� �� ������� �����
    if ( TopNode == NULL ) // ���� ���� ������ (TopNode==NULL) -
        return;
    *Head = TopNode->next; // ���������� �������� ������� �� ��������� �����
    free ( TopNode ); // ��������� ������ �� �������� TopNode
}
