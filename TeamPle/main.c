#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>

#define MAX_ENHANCEMENTStage1 20
#define WAIT_TIME 0.5
#define INITIAL_MONEY 2000000
#define ENHANCEMENT_THRESHOLD 10
#define REVIEW_TICKET_COST 200000
#define BOSSLEVEL 5
//�������� �ۼ��� : 
// [��¥]
//    (��������) - (�߰� ������Ʈ ����)

/// <summary>
/// * �������� *
/// [04-14]
///     ���� ����(5���� ���� �������� ���� �Ϸ�) - ������ �ʿ�
/// 
/// </summary>
char* enhancementMessages1[] = {
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

// 2�������� 
char* enhancementMessages2[] = {
"ũ������ ������ ����Դ�.. ����� ��� ��������??"
"�޿� �׸��� ũ�������� �پ���.. ������� ������ ���� �ճ��� ��� �ɱ�??"
"ù ��� ��ħ .. 9�ñ��� ����̿��� 8�ÿ� ������ ����ߴ�.. 9�� �Ǳ� 20����.. ȸ����̴�..."
"�����̵� 9�� 10������ �����Ͽ���.. ù ����ε� �������� ����?!"
"ù������ ��� �ؾ��ϴ°��� ���Ӻ��� �˷��ֽǰŸ� �˷��ֽð� ��ô�.."
"6�ÿ� ��ٽð��� ���� ���� ������ �߾��µ�.. ���� ȸ���� �Ѵٰ�??"
"ȸ���� ������ ���� ���Դµ� ���� ���� ��� ������ �ع��ȴ�.. �Ͼ��? 7�ù�??"
"�������� �ϻ��� ������... ��������� ���������� ������ �ߴ�!"
"����..ȸ�翡 ��Ƶ�� �������̴�.. �ٵ� �ʹ� ���絥??"
"������ ������ŭ ���� ������. �� �������� ������ ���ϴµ�..."
};

int isTry = 0;                  // ��ȭ �õ� ���� ���� ����
int level = 0;                  // ���� ������ ��ȭ ��ġ
int money = INITIAL_MONEY;      // ���� ������ 
int choice;
bool isGameOver = false;        // ���� ���� ���� ����
int tickets = 0;
int dungeonSelect = 0;

// ��ȭ ���� Ȯ�� �迭
float enhancementProbabilitiesStage1[MAX_ENHANCEMENTStage1 + 1] = {
    100.0f,100.0f,100.0f,100.0f,100.0f,100.0f,100.0f,100.0f,100.0f,100.0f,100.0f,100.0f,100.0f,100.0f,100.0f,100.0f,100.0f,100.0f,100.0f,100.0f
};


// ��ȭ �õ� ��� �迭
int enhancementCosts[MAX_ENHANCEMENTStage1 + 1] = {
    10000, 15000, 20000, 25000, 30000,
    35000, 40000, 45000, 50000, 55000,
    60000, 65000, 70000, 75000, 80000,
    85000, 90000, 95000, 100000, 105000,
};

// �л� �޿� �迭
int studentSalaries[MAX_ENHANCEMENTStage1 + 1] = {
    0, 50000, 60000, 65000, 70000,
    75000, 80000, 85000, 90000, 95000,
    100000, 105000, 110000, 115000, 120000,
    125000, 130000, 135000, 140000,145000,
    150000
};
int BossMobHP[BOSSLEVEL + 1] = {
    5000,100000,500000,3000000,10000000
};

int JihoPower[MAX_ENHANCEMENTStage1 + 1] = {
    0,10,50,100,150,250,
    300,400,500,600,800,
    1000,1200,1400,1500,5000,
    7000,10000,30000,65000,150000
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
        if (scanf_s("%d", &shopChoice) != 1) {
            printf("���ڸ� �Է��ϼ���.\n");
            while (getchar() != '\n'); // �Է� ���� ����
            continue; // �ٽ� �Է� �ޱ�
        }
        while (getchar() != '\n'); // �Է� ���� ����



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
    if (level == MAX_ENHANCEMENTStage1) {
        printf("\n�����մϴ�! 20�ܰ���� ��� Ŭ�����ϼ̽��ϴ�!\n");
        printf("���� ���������� �����Ͻðڽ��ϱ�? (YES: 1 / NO: 2) : ");
        scanf_s("%d", &choice);
        if (choice == 1) {
            // ���� ���������� ����
            // ���⿡ ���� ���������� �ʱ�ȭ�ϰų� ��ȯ �޽����� ǥ���ϴ� �ڵ带 �߰��� �� �ֽ��ϴ�.
            printf("\n���� ���������� �̵��մϴ�!\n");
            // ���� ���������� �̵��ϱ� ���� �߰� �ڵ�
            level = 21; // ���� ���������� ���� ������ 0���� �ʱ�ȭ
            money = INITIAL_MONEY; // ���� ���������� ���� �� �ʱ�ȭ
            // ���� ���������� ���� �ʿ��� �ʱ�ȭ�� �߰��� �� �ֽ��ϴ�.
        }
        else if (choice == 2) {
            // ���� ����
            printf("\n������ �����մϴ�. �����ϼ̽��ϴ�!\n");
            isGameOver = true; 
        }
        else {
            printf("\n�߸��� �Է��Դϴ�. �ٽ� �����ϼ���.\n");
        }
    }
    else {
        
    }
}

void Dungeon1() {
    printf(" �� �̻���!\n");
    printf(" HP : %d\n", BossMobHP[0]);
    int messageDisplayed = 0;
    int numberDisplayed = 1;
    while (BossMobHP[0] > 0) {
        char input = getchar();
        if (!numberDisplayed) {
            printf(" HP : %d\n", BossMobHP[0]);
            printf("{ ������ : 0 }\n");
            numberDisplayed = 1;
        }

        if (input == '0') {
            printf(" ������ �����ϴ�.\n");
            return 0;
        }
        else if (input == '\n') {
            if (messageDisplayed) {
                messageDisplayed = 0;
            }
            else {
                BossMobHP[0] -= JihoPower[level];
                numberDisplayed = 0;
            }
        }
        else {
            if (!messageDisplayed) {
                printf(" �ٽ� �Է����ּ���.\n");
                printf("{ ������ : 0 }\n");
                messageDisplayed = 1;
            }
        }
    }
    printf(" �����...���� ���ٴ�...\n");
    Sleep(1000);
    printf(" ���� 1 �Ϸ�!\n");
    return 0;
}
void Dungeon2() {
    printf(" �� ���ҹ�!");
    printf(" HP : %d\n", BossMobHP[1]);
    int messageDisplayed = 0;
    int numberDisplayed = 1;
    while (BossMobHP[1] > 0) {
        char input = getchar();
        if (!numberDisplayed) {
            printf(" HP : %d\n", BossMobHP[1]);
            printf("{ ������ : 0 }\n"); // ������ �����̽��� ������ �ѹ��� ���� ��ġ��. ��� Dungeon
            numberDisplayed = 1;
        }

        if (input == '0') {
            printf(" ������ �����ϴ�.\n");
            return 0;
        }
        else if (input == '\n') {
            if (messageDisplayed) {
                messageDisplayed = 0;
            }
            else {
                BossMobHP[1] -= JihoPower[level];
                numberDisplayed = 0;
            }
        }
        else {
            if (!messageDisplayed) {
                printf(" �ٽ� �Է����ּ���.\n");
                printf(" {������ : 0 }\n");
                messageDisplayed = 1;
            }
        }
    }
    printf(" �����...���� ���ٴ�...\n");
    Sleep(1000);
    printf(" ���� 2 �Ϸ�!\n");
    return 0;
}
void Dungeon3() {
    printf(" �� ������!");
    printf("HP : %d\n", BossMobHP[2]);
    int messageDisplayed = 0;
    int numberDisplayed = 1;
    while (BossMobHP[2] > 0) {
        char input = getchar();
        if (!numberDisplayed) {
            printf(" HP : %d\n", BossMobHP[2]);
            printf(" { ������ : 0 }\n");
            numberDisplayed = 1;
        }

        if (input == '0') {
            printf(" ������ �����ϴ�.\n");
            return 0;
        }
        else if (input == '\n') {
            if (messageDisplayed) {
                messageDisplayed = 0;
            }
            else {
                BossMobHP[2] -= JihoPower[level];
                numberDisplayed = 0;
            }
        }
        else {
            if (!messageDisplayed) {
                printf(" �ٽ� �Է����ּ���.\n");
                printf(" { ������ : 0 }\n");
                messageDisplayed = 1;
            }
        }
    }
    printf(" �����...���� ���ٴ�...\n");
    Sleep(1000);
    printf(" ���� 3 �Ϸ�!\n");
    return 0;
}
void Dungeon4() {
    printf(" �� �̿!");
    printf(" HP : %d\n", BossMobHP[3]);
    int messageDisplayed = 0;
    int numberDisplayed = 1;
    while (BossMobHP[0] > 0) {
        char input = getchar();
        if (!numberDisplayed) {
            printf(" HP : %d\n", BossMobHP[3]);
            printf(" { ������ : 0 }\n");
            numberDisplayed = 1;
        }

        if (input == '0') {
            printf(" ������ �����ϴ�.\n");
            return 0;
        }
        else if (input == '\n') {
            if (messageDisplayed) {
                messageDisplayed = 0;
            }
            else {
                BossMobHP[3] -= JihoPower[level];
                numberDisplayed = 0;
            }
        }
        else {
            if (!messageDisplayed) {
                printf(" �ٽ� �Է����ּ���.\n");
                printf(" { ������ : 0 }\n");
                messageDisplayed = 1;
            }
        }
    }
    printf(" �����...���� ���ٴ�...\n");
    Sleep(1000);
    printf(" ���� 4 �Ϸ�!\n");
    return 0;
}
void Dungeon5() {
    printf(" �� �迵õ!");
    printf(" HP : %d\n", BossMobHP[4]);
    int messageDisplayed = 0;
    int numberDisplayed = 1;
    while (BossMobHP[4] > 0) {
        char input = getchar();
        if (!numberDisplayed) {
            printf(" HP : %d\n", BossMobHP[4]);
            printf(" { ������ : 0 }\n");
            numberDisplayed = 1;
        }

        if (input == '0') {
            printf(" ������ �����ϴ�.\n");
            return 0;
        }
        else if (input == '\n') {
            if (messageDisplayed) {
                messageDisplayed = 0;
            }
            else {
                BossMobHP[4] -= JihoPower[level];
                numberDisplayed = 0;
            }
        }
        else {
            if (!messageDisplayed) {
                printf(" �ٽ� �Է����ּ���.\n");
                printf(" { ������ : 0 }\n");
                messageDisplayed = 1;
            }
        }
    }
    printf(" �����...���� ���ٴ�...\n");
    Sleep(1000);
    printf(" ���� 5 �Ϸ�!\n");
    return 0;
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
        printf(" �л� ���� : + %d %s (�Ŀ� : %d)\n", level, enhancementMessages1[level], JihoPower[level]);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        printf(" \n ���� ������ : %d��\n", money);
        printf(" �н� ��� : %d��\n", enhancementCosts[level]);
        printf(" �н� ������ : %.2f%%\n", enhancementProbabilitiesStage1[level]);
        printf(" \n ���� ������ ���� : %d\n", tickets);
        printf(" \n �޴�:\n\n");
        printf(" * 1. �л� ��ȭ�ϱ�\n");
        printf(" * 2. ��������\n");
        printf(" * 3. ���ǽǰ���\n");
        printf(" * 4. �����ϱ�\n\n");

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
            //Sleep(2000);

            float randNum = (float)rand() / RAND_MAX * 100.0f;
            int i;

            if (randNum < enhancementProbabilitiesStage1[level]) {
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
            printf("\n *** ���ǽǷ� �̵� ***\n\n");
           // Sleep(2000);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            printf(" �̰��� ���ǽ��Դϴ�. �����Ե�� ����� �� �� �ֽ��ϴ�.\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            printf("\n 1. �̻��� ������ (1~4�� ��õ)\n");
            printf(" 2. ���ҹ� ������ (5~8�� ��õ)\n");
            printf(" 3. ������ ������ (9��~12�� ��õ)\n");
            printf(" 4. �̿ ������ (13��~16�� ��õ)\n");
            printf(" 5. �迵õ ������ (17��~20�� ��õ)\n\n");
            printf(" ����ȭ������ ������ - [ 1~5�� ������ ��� �Է�Ű ]\n\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            printf(" ����ϰ� ���� �������� ��ȣ�� �Է��ϼ��� : ");
            scanf_s("%d", &dungeonSelect);
            switch (dungeonSelect) {
            case 1:
                Dungeon1();
                break;
            case 2:
                Dungeon2();
                break;
            case 3:
                Dungeon3();
                break;
            case 4:
                Dungeon4();
                break;
            case 5:
                Dungeon5();
                break;
            default:
                printf("�߸��� �Է��Դϴ�. �ٽ� �����ϼ���.\n");
                break;
            }
            break;
        case 4:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf("\n �̷�! ����ȣ �л��� ���� �߽��ϴ� ���� ��¼��...?\n");
            isGameOver = true; // ���� ����
            break;
        default:
            printf("�߸��� �Է��Դϴ�. �ٽ� �����ϼ���.\n"); // ���� �������� ������.
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