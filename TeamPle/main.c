#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>

#define MAX_ENHANCEMENT 20
#define WAIT_TIME 0.5
#define INITIAL_MONEY 2000000
#define ENHANCEMENT_THRESHOLD 10
#define REVIEW_TICKET_COST 200000


char* enhancementMessages[] = {
    "���Ƹ� ���Ի�(������ ���� ���� ���� �Ϳ��� ���Ի��� �����ߴ�!)",
    "C�� ��� 1�г�(�迵ö �����Բ� Ī���� ���� �Ϳ��� 1�г��̴�.)",
    "HTML5�� ��� 1�г�(������ �������� ����� �޴� 1�г��̴�.)",
    "���伥�� ��� 1�г�(������ �����Բ��� �ſ� �����ϽŴ�.)",
    "���̽��� ��� 1�г�(������ �����Բ� ���� ���� �Ծ���. ���� ����� �̻�������.)",
    "JavaScript�� ��� 1�г�(������ �����Բ��� ū �ŷڸ� �ɰ� ��Ŵ�.)",
    "C��������� ��� 1�г�(�迵ö �����Բ� ȥ����. �и� C�� ����µ�...??)",
    "����Ƽ�� ��� 2�г�(�̼��� �����Բ��� �����ϽŴ�. ���� ���ߴ� �ְ� �̻������� �ִ�...)",
    "C# ���α׷����� ��� 2�г�(������ �����Բ��� �����ϽŴ�. ������ ���� �ʹ��̶�...)",
    "�۱�ȹ�� ��� 2�г�(�迵ö �����Բ� �±� �������� ����. �Ѱ����� �µ��� �ñ��ϴ�...)",
    "��Ÿ�� �� ���л�(�����Բ� ȥ����, ������ ġ�̰�... �л��� ���տ� ������ �۽��δ�.)",
    "���������� ��� 2�г�(������ �����Բ��� �����ϽŴ�. ���� ���� �ʰ� ������ ���´�.)",
    "C++�� ��� 2�г�(���� C��� �� �� �����. �ٵ� �����ʹ� ������ ���ذ� �ȵȴ�...)",
    "����Ƽ�� ������ ������ 3�г�(���Ǹ� ������� ������ �������. �̼��� �����Բ��� \"�̰� ������ �³�\"��� �ϼ̴�.)",
    "HTML�� CSS�� ���� ����� �� 3�г�(������ �����Բ� �ܼҸ��� ���� �����. �׷��� ���� �����Բ��� ��Ư���ϽŴ�.)",
    "�������Ƹ� ���並 �ϴ� 3�г�(�Ĺ���� ������ �ް� �ִ�. ������ �����԰� �̼��� �����Ե� �׷��� �����ϽǱ�?)",
    "3D�𵨸��� ��� 3�г�(������ �����԰� 1��1 ����� �ߴ�. ��Ʈ�� ������ �� ������... ���� ���� �𸣰ڴ�.)",
    "â�����Ƹ��� �ϴ� 3�г�(���� �б��� 21�ñ��� �Ĺ�, ������ ���� �۾��� �Ѵ�. �������� �ͽ��̴�.)",
    "��ȹ�� �ۼ��� �������� 3�г�(������ ���� ���Ѵٰ� �����Ѵ�. ������ �����԰� �̼��� �����Ե� �׷��� �����ϽǱ�?)",
    "���� �ǽ��� �ٳ�� 3�г�(ȸ�翡�� �������� ���簡 ���Դٰ� �Ѵ�. ������ ������ ȸ�簡 ���δ�.)",
    "���� ������ �԰� �ִ� ���л�(��� �ɷ��� ž���ߴ�. ���� ��¥ ������ ���� �ɾ��.)"
};

int isTry = 0;                  // ��ȭ �õ� ���� ���� ����
int level = 0;                  // ���� ������ ��ȭ ��ġ
int money = INITIAL_MONEY;      // ���� ������ 
int choice;
bool isGameOver = false;        // ���� ���� ���� ����
int store;
int tickets = 0;

// ��ȭ ���� Ȯ�� �迭
float enhancementProbabilities[MAX_ENHANCEMENT + 1] = {
    100.0f,95.0f,90.0f,85.0f,80.0f,
    75.0f,70.0f,60.0f,55.0f,50.0f,
    25.0f,25.0f,25.0f,25.0f,25.0f,
    25.0f, 20.0f, 15.0f, 10.0f, 5.0f, 0.0f
};

// ��ȭ �õ� ��� �迭
int enhancementCosts[MAX_ENHANCEMENT + 1] = {
    10000, 15000, 20000, 25000, 30000,
    35000, 40000, 45000, 50000, 55000,
    60000, 65000, 70000, 75000, 80000,
    85000, 90000, 95000, 100000, 105000,
};

// �л� �޿� �迭
int studentSalaries[MAX_ENHANCEMENT + 1] = {
    0, 50000, 60000, 65000, 70000,
    75000, 80000, 85000, 90000, 95000,
    100000, 105000, 110000, 115000, 120000,
    125000, 130000, 135000, 140000,145000,
    150000
};

// ��ȭ ���� ��� �迭
//int maintainCosts[MAX_ENHANCEMENT + 1] = {
//    0, 0, 0, 0, 0,
//    0, 0, 0, 0, 0,
//    5000, 6000, 7000, 8000, 9000,
//    10000, 11000, 12000, 13000, 14000,
//    15000
//};

// �л� �Ǹ� �Լ�
void sellStudent(int* level, int* money) {
    if (*level == 0) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("\n ���� ����ȣ �л��� ��ȭ���� �ʾҽ��ϴ�.\n");
    }
    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        printf("����ȣ �л��� ��� ���׽��ϴ�. ����ȣ �л��� ū ���� �ϸ� �������ϴ�.\n");
        *money += studentSalaries[*level];
        printf("���� �����ݿ� %d���� �߰��Ǿ����ϴ�.\n", studentSalaries[*level]);
        *level = 0; // �л��� �Ǹ��ϸ� ���� �ʱ�ȭ
    }
}
void GoStore() {
    printf("\n *** �������� �̵� ***\n\n");
    Sleep(2000);
    while (1) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
        printf(" * �н� ��ȭ�� ����Ͽ� �������� ������ �� �ֽ��ϴ� *\n\n");
        printf(" * 1. �л� �Ǹ� (�л� ��ġ : %d��)\n", studentSalaries[level]);
        printf(" * 2. ������ ����\n");
        printf(" * 3. ����ȭ�� �̵�\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

        printf("\n * �������� �����ϼ��� : ");
        int shopChoice;
        scanf_s("\n%d", &shopChoice);



        switch (shopChoice) {
        case 1:
            if (level > 0) {
                if (money < 0) {
                    money = 0;
                }
                printf("\n ��ȭ�� ����: + %d\n", level);
                printf("\n �Ǹ� �ݾ�: %d��\n\n", studentSalaries[level]);
                money += studentSalaries[level];
                
                enhancementCosts; //���� ��ȭ ���

                level = 0;
            }
            else {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                printf(" \n �л� ������ 0�̹Ƿ� �л� �Ǹ� �ɼ��� ����� �� �����ϴ�.\n\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            }
            break;
        case 2:
            if (money < REVIEW_TICKET_COST) {
                printf(" \n ��ȭ�� �����Ͽ� �������� ������ �� �����ϴ�.\n\n");
                break;
            }
            else {
                money -= REVIEW_TICKET_COST;
                tickets++;
                printf(" \n �������� �����Ͽ����ϴ�.\n");
                printf("\n ���� ������ ���� : %d��\n", tickets);
                printf(" \n ���� ������: %d��\n\n", money);
                break;
            }
        case 3:
            isTry = 0;
            return;// ���� �޴����� ��������
        default:
            printf(" �߸��� �Է��Դϴ�.\n");
            break;
        }
    }
}


int main(void)
{
    system("mode con cols=120 lines=30 | title ����ȣ �л� Ű���");


    srand((unsigned int)time(NULL));         // ���� �õ尪 ����

    while (!isGameOver)
    {
        system("@cls||clear");      // ȭ�� ����

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        printf(" ** ����ȣ �л� Ű��� **  \n\n");

        // ���� ���
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        printf(" �л� ���� : + %d %s\n", level, enhancementMessages[level]);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        printf(" \n ���� ������ : %d��\n", money);
        printf(" �н� ��� : %d��\n", enhancementCosts[level]);
        printf(" �н� ������ : %.2f%%\n", enhancementProbabilities[level]);
        printf(" \n ���� ������ ���� : %d\n", tickets);
        printf(" \n �޴�:\n\n");
        printf(" * 1. �л� ��ȭ�ϱ�\n", level);
        printf(" * 2. ��������\n", store);
        printf(" * 3. �����ϱ�\n\n", isGameOver);
        
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        printf("\n * �޴��� �����ϼ��� : ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        scanf_s("%d", &isTry);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
      
      
        switch (isTry)
        {
        case 1:     // ��ȭ�� ���� �� ���
            // ���� �����ϸ� �޽��� ��� �� break
            if (money < enhancementCosts[level]) {
                printf("���� �����Ͽ� ���� �� �� �����ϴ�.\n");
                break;
            }
            printf("\n  *** �н��� *** \n\n");      
            Sleep(2000);

            float randNum = (float)rand() / RAND_MAX * 100.0f;
            int i;

            if (randNum < enhancementProbabilities[level]) {
                money -= enhancementCosts[level];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                printf(" ***** SUCCESS *****\n");
                printf("                  \n");
                printf("    + %d  -> + %d \n", level, level + 1);
                printf("                  \n");
                printf(" ***** SUCCESS *****\n");
                // ��ȭ�� ���� ���� ��, ������ �ϳ� ���� ��Ŵ
                level++;

            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                printf(" ***** FAILURE *****\n");
                printf("                  \n");
                printf("      %d  ->  % d    \n", level, level - 1);
                printf("                  \n");
                printf(" ***** FAILURE *****\n");
                printf("\n ������.. �ڵ����� �ó�..�������� �����ȴ�...\n");
                printf("\n [+%d ������ �Ҿ����ϴ�.]\n\n", level);

                if (1 <= level <= 20)
                {
                    if (tickets != 0)
                    {
                        money -= enhancementCosts[level];
                        printf("�н��� �����Ͽ����ϴ�. \n���� �н� ��ġ�� �����Ͻðڽ��ϱ�? \n{���� �н��� ���� : %d}\n(YES : 1/ NO : 2) : ", tickets);
                        scanf_s("%d", &choice);
                        if (choice == 1) {
                            tickets--;
                            printf("\n�������� ����մϴ�. (���� ������ ���� : %d)\n", tickets);
                            money += enhancementCosts[level];
                        }
                        else if (choice == 2) {
                            printf("�н� ��ġ�� �ʱ�ȭ�մϴ�.\n");
                            level = 0; // ��ȭ ��ġ �ʱ�ȭ
                        }
                        else {
                            printf("�߸��� �Է��Դϴ�. �ٽ� �����ϼ���.\n");
                            continue;
                        }
                    }
                    else
                    {
                        level = 0;
                    }
                }
            }
            // ��ȭ ��� ����

            break;
        case 2:
            GoStore();
            break;
        case 3:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf("\n �̷�! ����ȣ �л��� ���� �߽��ϴ� ���� ��¼��...?\n");
            isGameOver = true; // ���� ����
            break;
        default:
            printf("�߸��� �Է��Դϴ�. �ٽ� �����ϼ���.\n");
            break;
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        printf("\n ����Ϸ��� �ƹ� Ű�� ��������! \n");
        getchar(); // ���� ���� ó���� ���� getchar ���

        // ����� �Է� ���
        while (getchar() != '\n'); // ���� ����
    }

    return 0;
}
