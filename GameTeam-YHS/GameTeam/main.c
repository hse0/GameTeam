#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>
#define MAX_ENHANCEMENTStage1 20
#define WAIT_TIME 0.5
#define INITIAL_MONEY 20000000
#define ENHANCEMENT_THRESHOLD 10
#define REVIEW_TICKET_COST 200000
#define BOSSLEVEL 5

char* enhancementMessages1[] = {
    "���Ƹ� ���Ի� ����ȣ(������ ���� ���� ���� �߻��� ��ȣ�� �����ߴ�!)",
    "C�� ��� 1�г� ����ȣ(�迵õ �����Բ� Ī���� ���� �Ϳ��� 1�г��̴�.)",
    "HTML5�� ��� 1�г� ����ȣ(������ �������� ����� �޴� 1�г��̴�.)",
    "���伥�� ��� 1�г� ����ȣ(�뿬�� �����Բ��� �ſ� �����ϽŴ�.)",
    "���̽��� ��� 1�г� ����ȣ(�̿ �����Բ� ���� ���� �Ծ���. ���� ����� �̻�������.)",
    "JavaScript�� ��� 1�г� ����ȣ(������ �����Բ��� ū �ŷڸ� �ɰ� ��Ŵ�.)",
    "C��������� ��� 1�г� ����ȣ(�迵õ �����Բ� ȥ����. �и� C�� ����µ�...??)",
    "����Ƽ�� ��� 2�г� ����ȣ(�̻��� �����Բ��� �����ϽŴ�. ���� ���ߴ� �ְ� �̻������� �ִ�...)",
    "C# ���α׷����� ��� 2�г� ����ȣ(���ҹ� �����Բ��� �����ϽŴ�. ������ ���� �ʹ��̶�...)",
    "�۱�ȹ�� ��� 2�г� ����ȣ(�迵õ �����Բ� �±� �������� ����. �Ѱ����� �µ��� �ñ��ϴ�...)",
    "��Ÿ�� �� ����ȣ(�����Բ� ȥ����, ������ ġ�̰�... ��ȣ�� ���տ� ������ �۽��δ�.)",
    "���������� ��� 2�г� ����ȣ(�̿ �����Բ��� �����ϽŴ�. ���� ���� �ʰ� ������ ���´�.)",
    "C++�� ��� 2�г� ����ȣ(���� C��� �� �� �����. �ٵ� �����ʹ� ������ ���ذ� �ȵȴ�...)",
    "����Ƽ�� ������ ������ 3�г� ����ȣ(���Ǹ� ������� ������ �������. �̻��� �����Բ��� \"�̰� ������ �³�\"��� �ϼ̴�.)",
    "HTML�� CSS�� ���� ����� �� 3�г� ����ȣ(������ �����Բ� �ܼҸ��� ���� �����. �׷��� ���� �����Բ��� ��Ư���ϽŴ�.)",
    "�������Ƹ� ���並 �ϴ� 3�г� ����ȣ(�Ĺ���� ������ �ް� �ִ�. �̿ �����԰� �̻��� �����Ե� �׷��� �����ϽǱ�?)",
    "3D�𵨸��� ��� 3�г� ����ȣ(�뿬�� �����԰� 1��1 ����� �ߴ�. ��Ʈ�� ������ �� ������... ���� ���� �𸣰ڴ�.)",
    "â�����Ƹ��� �ϴ� 3�г� ����ȣ(���� �б��� �� 10�ñ��� �Ĺ�, ������ ���� �۾��� �Ѵ�. �������� �ͽ��̴�.)",
    "��ȹ�� �ۼ��� �������� 3�г� ����ȣ(������ ���� ���Ѵٰ� �����Ѵ�. �̿ �����԰� �̻��� �����Ե� �׷��� �����ϽǱ�?)",
    "���� �ǽ��� �ٳ�� 3�г� ����ȣ(ȸ�翡�� �������� ���簡 ���Դٰ� �Ѵ�. ������ ������ ȸ�簡 ���δ�.)",
    "���� ������ �԰� �ִ� ����ȣ(��� �ɷ��� ž���ߴ�. ���� ��¥ ������ ���� �ɾ��.)"
};

int failure = 0;
int isTry = 0;                  // ��ȭ �õ� ���� ���� ����
int choice;
bool isGameOver = false;        // ���� ���� ���� ����
int tickets = 0;
int enhancement_cost = 0;
int dungeonSelect = 0;
int ZeroOneGangHwa = 0;

//���� �����͸� �ױ� ���� ��ȭ �ܰ� ���� �迭
int Levels[MAX_ENHANCEMENTStage1] = {
    1,2,3,4,5,
    6,7,8,9,10,
    11,12,13,14,15,
    16,17,18,19,20
};

// ��ȭ �ܰ躰 �� ��ȭ �õ� Ƚ��
int Attempt[MAX_ENHANCEMENTStage1] = {
    1,1,1,1,1,
    1,1,1,1,1,
    1,1,1,1,1,
    1,1,1,1,1
};



// ��ȭ �ܰ躰 ���� Ƚ��
int Success[MAX_ENHANCEMENTStage1] = {
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0
};
// ��ȭ �ܰ躰 ���� Ƚ��
int Failure[MAX_ENHANCEMENTStage1] = {
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0
};
// ��ȭ �ܰ躰 ������ ���� ����
int TicketBuyLevels[MAX_ENHANCEMENTStage1] =
{
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0
};

int nickname_initial; // �г���
int currentDateTime; // �湮 �ð�
int endDateTime = 2; // ���� �ð�
int level = 0; // ��ȭ �ܰ�
int attemptlevel = 0;
int TicketBuyLevels[MAX_ENHANCEMENTStage1]; // �ܰ躰 ���� Ƚ��
int attempt = 0; // ��ȭ�õ� Ƚ��
int success = 0;  // ���� Ƚ��
int selling_count = 0; // �Ǹ�Ƚ�� 
int money = INITIAL_MONEY; // ���� ��� 
int numTickets = 0;

void Gopost()
{
    char command[2048];
    static void sendToGoogleSheet(const int* nickname_initial, const int* currentDateTime, const int* endDateTime, int level, int TicketBuyLevels[], int attempt, int success, int selling_count, int money); {
        sprintf_s(command, sizeof(command),
            "curl -d \"{\\\"���̵�\\\":\\\"%d\\\",\\\"���ӽð�\\\":\\\"%d\\\",\\\"����ð�\\\":\\\"%d\\\",\\\"��ȭ �ܰ�\\\":\\\"%d\\\",\\\"�ܰ躰 ������ ���Ű���\\\":\\\"%d\\\",\\\"��ȭ�õ�Ƚ��\\\":\\\"%d\\\",\\\"���� Ƚ��\\\":\\\"%d\\\",\\\"�Ǹ� Ƚ��\\\":\\\"%d\\\",\\\"���� ���\\\":\\\"%d\\\"}\" https://script.google.com/macros/s/AKfycbyA6TP4mH1yZ1ERsrBswmDlm9DtBgxKKnUBoHeOhihUtounJo5HKBMQ3v0kOtDKyKK3/\\exec",
            nickname_initial, currentDateTime, endDateTime, attemptlevel, TicketBuyLevels[level], attempt, success, selling_count, money);
        system(command);
        srand((unsigned int)time(NULL));         // ���� �õ尪 ���� 
    }
}
// ��ȭ ���� Ȯ�� �迭
float enhancementProbabilitiesStage1[MAX_ENHANCEMENTStage1 + 1] = {

    100.0f,100.0f,100.0f,100.0f,
    100.0f,0.0f,100.0f,100.0f,
    100.0f,100.0f,100.0f,100.0f,
    100.0f,100.0f,100.0f,100.0f,
    100.0f,100.0f,100.0f,100.0f


};
/*float enhancementProbabilitiesStage1[MAX_ENHANCEMENTStage1 + 1] = {
    100.0f,100.0f,100.0f,100.0f,
    100.0f,100.0f,100.0f,100.0f,
    100.0f,100.0f,100.0f,100.0f,
    100.0f,100.0f,100.0f,100.0f,
    100.0f,100.0f,100.0f,100.0f
};*/

// ��ȭ �õ� ��� �迭
int enhancementCosts[MAX_ENHANCEMENTStage1 + 1] = {
    20000, 30000, 40000, 50000, 60000,
    70000, 80000, 110000, 130000, 150000,
    200000, 250000, 350000, 500000, 600000,
    700000, 800000, 850000, 900000, 1000000,
};
// �� ��ȭ ��ġ���� ���� �� �Ҹ�Ǵ� ������ ���� �迭
int failureTicketCosts[MAX_ENHANCEMENTStage1 + 1] = {
    0, 0, 1, 1, 1,
    1, 1, 1, 1, 2,
    2, 3, 4, 5, 7,
    10, 13, 17, 33, 50,
};
// �л� �޿� �迭
int studentSalaries[MAX_ENHANCEMENTStage1 + 1] = {
    0, 15000, 20000, 30000, 50000,
    60000, 90000, 110000, 500000, 650000,
    800000, 2000000, 3500000, 4500000, 10000000,
    21000000, 40000000, 66000000, 108000000,370000000,
};
int BossMobHP[BOSSLEVEL + 1] = {
    5000,50000,250000,1000000,5000000
};
int JihoPower[MAX_ENHANCEMENTStage1 + 1] = {
    0,10,50,100,150,250,
    300,400,500,600,800,
    1000,1200,1400,1500,5000,
    7000,10000,30000,65000,150000
};
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
    Sleep(500);
    while (1) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
        printf(" * �н� ��ȭ�� ����Ͽ� �������� ������ �� �ֽ��ϴ� *\n\n");
        printf(" * 1. �л� �Ǹ� (�л� ��ġ : %d��)\n", studentSalaries[level]);
        printf(" * 2. ������ ���� (���� 20��)\n");
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
                attempt = 0;
                failure = 0;
                success = 0;
                enhancementCosts; //���� ��ȭ ���
                selling_count++;
                level = 0;
            }
            else {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                printf(" \n �л� ������ 0�̹Ƿ� �л� �Ǹ� �ɼ��� ����� �� �����ϴ�.\n\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            }
            break;
        case 2:
            printf(" \n �������� �� �� �����Ͻðڽ��ϱ�? : ");
            int numTickets;
            if (scanf_s("%d", &numTickets) != 1 || numTickets <= 0) {
                printf("�߸��� �Է��Դϴ�.\n");
                break;
            }
            while (getchar() != '\n'); // �Է� ���� ����

            if (money < REVIEW_TICKET_COST * numTickets) {
                printf(" \n ��ȭ�� �����Ͽ� �������� ������ �� �����ϴ�.\n\n");
                break;
            }
            else {
                money -= REVIEW_TICKET_COST * numTickets;
                tickets += numTickets;
                printf(" \n �������� %d�� �����Ͽ����ϴ�.\n", numTickets);
                printf("\n ���� ������ ���� : %d��\n", tickets);
                printf(" \n ���� ������: %d��\n\n", money);
                TicketBuyLevels[level] += numTickets;
                printf("[%d�� �ܰ迡�� ������ %d�� ������!]\n\n", level, TicketBuyLevels[level]);
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
void Dungeon1() {
    BossMobHP[0] = 5000;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    printf(" \n                  [ HP : %d ]\n", BossMobHP[0]);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    int messageDisplayed = 0;
    int numberDisplayed = 1;
    while (BossMobHP[0] > 0) {
        char input = getchar();
        if (!numberDisplayed) {
            printf("\n �̻��� ������ : ��Ʈ�� ���� ��Ʈ��... ���ߵ� ���ϴ� �͵���..\n");

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf(" \n                  [ HP : %d ]\n", BossMobHP[0]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            printf(" \n { ������ : 0 }\n");
            numberDisplayed = 1;
        }
        if (input == '0') {
            printf(" \n ���ǽ��� �����ϴ�.\n");
            BossMobHP[0] = 5000;
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
                printf("\n �ٽ� �Է����ּ���.\n");
                printf("{ ������ : 0 }\n");
                messageDisplayed = 1;
            }
        }
    }
    printf(" �ƾ�... ���� �ʶ� ��� ���Ҳ���...\n");
    tickets += 1;
    printf("\n");
    printf("�������� ������ 1���� ȹ���߽��ϴ�!\n");
    printf("\n");
    printf(" ��� �Ϸ�!\n");
    Sleep(1000);
    return 0;
}
void Dungeon2() {
    BossMobHP[1] = 50000;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    printf("\n");
    printf("\n ���ҹ� ������ : ��... ��ø���...\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    printf(" \n                  [ HP : %d ]\n", BossMobHP[1]);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    int messageDisplayed = 0;
    int numberDisplayed = 1;
    while (BossMobHP[1] > 0) {
        char input = getchar();
        if (!numberDisplayed) {
            printf("\n ���ҹ� ������ : ��... ��ø���...\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf(" \n                  [ HP : %d ]\n ", BossMobHP[1]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            printf(" \n { ������ : 0 }\n"); // ������ �����̽��� ������ �ѹ��� ���� ��ġ��. ��� Dungeon
            numberDisplayed = 1;
        }
        if (input == '0') {
            printf(" \n ���ǽ��� �����ϴ�.\n");
            BossMobHP[1] = 50000;
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
                printf("\n �ٽ� �Է����ּ���.\n");
                printf(" {������ : 0 }\n");
                messageDisplayed = 1;
            }
        }
    }
    printf(" ������ ������ ����� �ʾҳ� ���׿� ^^\n");
    tickets += 3;
    printf("\n");
    printf("�������� ������ 3���� ȹ���߽��ϴ�!\n");
    printf("\n");
    printf(" ��� �Ϸ�!\n");
    Sleep(1000);
    return 0;
}
void Dungeon3() {
    BossMobHP[2] = 250000;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    printf("\n");
    printf("\n ������ ������ : ������ �ٽ� õõ�� �ؿ�^^ (�ڱ�Ұ����� ������ �����ø鼭)\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    printf(" \n                [ HP : %d ]\n", BossMobHP[2]);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    int messageDisplayed = 0;
    int numberDisplayed = 1;
    while (BossMobHP[2] > 0) {
        char input = getchar();
        if (!numberDisplayed) {
            printf("\n ������ ������ : ������ �ٽ� õõ�� �ؿ�^^ (�ڱ�Ұ����� ������ �����ø鼭)\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf(" \n                [ HP : %d ]\n", BossMobHP[2]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            printf(" \n { ������ : 0 }\n");
            numberDisplayed = 1;
        }
        if (input == '0') {
            printf(" \n ���ǽ��� �����ϴ�.\n");
            BossMobHP[2] = 250000;
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
    printf(" �׷� ����߾�~~~^^\n");
    tickets += 1;
    money += 2000000;
    printf("\n");
    printf("�������� ������ 10���� 200������ ȹ���߽��ϴ�!\n");
    printf("\n");
    printf(" ��� �Ϸ�!\n");
    Sleep(1000);
    return 0;
}
void Dungeon4() {
    BossMobHP[3] = 1000000;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    printf("\n");
    printf("\n �̿ ������ : �ʵ��л��� �ƴ°� �𸣴� ������......\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    printf(" \n                  [ HP : %d ]\n", BossMobHP[3]);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    int messageDisplayed = 0;
    int numberDisplayed = 1;
    while (BossMobHP[3] > 0) {
        char input = getchar();
        if (!numberDisplayed) {
            printf("\n �̿ ������ : �ʵ��л��� �ƴ°� �𸣴� ������......\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf(" \n                  [ HP : %d ]\n", BossMobHP[3]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            printf(" \n { ������ : 0 }\n");
            numberDisplayed = 1;
        }
        if (input == '0') {
            printf(" \n ���ǽ��� �����ϴ�.\n");
            BossMobHP[3] = 1000000;
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
    printf(" ������...�� ���� �ȳ� �� ��...\n");
    money += 10000000;
    tickets += 50;
    printf("\n");
    printf("�������� ������ 50���� 1000������ ȹ���߽��ϴ�!\n");
    printf("\n");
    printf(" ��� �Ϸ�!\n");
    Sleep(1000);
    return 0;
}
void Dungeon5() {
    BossMobHP[4] = 5000000;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    printf("\n");
    printf("\n �迵õ ������ : ���� ���ذ� �ȵ�... �� �̸� ��µ��� ���ϴ� �ž�...\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    printf(" \n                    [ HP : %d ]\n", BossMobHP[4]);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    int messageDisplayed = 0;
    int numberDisplayed = 1;
    while (BossMobHP[4] > 0) {
        char input = getchar();
        if (!numberDisplayed) {
            printf("\n �迵õ ������ : ���� ���ذ� �ȵ�... �� �̸� ��µ��� ���ϴ� �ž�...\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf(" \n                    [ HP : %d ]\n", BossMobHP[4]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            printf(" \n { ������ : 0 }\n");
            numberDisplayed = 1;
        }
        if (input == '0') {
            printf(" \n ���ǽ��� �����ϴ�.\n");
            BossMobHP[4] = 5000000;
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
    printf(" �׷�... �츮 �����... ��� ���Ҵ�.\n");
    Sleep(2000);
    printf(" ���� �Ϸ�!\n");
    Sleep(2000);
    printf("���� ������ �÷������ּż� �����մϴ�!");
    Sleep(2000);
    isGameOver = true;
    return 0;
}

int main(void)
{

    srand((unsigned int)time(NULL));  // ���� �õ尪 ����
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    printf("\n");
    printf("  #          ##       ###      ###    #    #\n");
    printf("  #         #  #     #   #      #     ##   #\n");
    printf("  #        #    #   #           #     # #  #\n");
    printf("  #        #    #   #  ###      #     #  # #\n");
    printf("  #        #    #   #    #      #     #   ##\n");
    printf("  #         #  #     #   #      #     #    #\n");
    printf("  ######     ##       ###      ###    #    #\n\n\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    printf("        [ ID ���� �й��� �Է����ּ��� ]  ");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                 ID : ");
    scanf_s("%d", &nickname_initial);
    while (!isGameOver)
    {
        system("@cls||clear");      // ȭ�� ����
        system("title ����ȣ �л� Ű���");
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
        printf(" �䱸 ������ �� : %d��", failureTicketCosts[level]);

        if (level == 0)
        {
            ZeroOneGangHwa++;
            printf("\n {%d�� -> %d�� %d�� �õ� ��...}\n", level, level + 1, ZeroOneGangHwa);

        }
        else if (level == 20)
        {
            printf("\n {�ְ� ��ȭ �ܰ� �޼�!!!}\n");
        }
        else
        {
            printf("\n {%d�� -> %d�� %d�� �õ� ��...}\n", level, level + 1, Attempt[level]);
        }

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
            float randNum = rand() % 100;
            Attempt[level]++;
            if (randNum < enhancementProbabilitiesStage1[level]) {
                money -= enhancementCosts[level];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                printf(" ***** SUCCESS *****\n");
                printf("                  \n");
                printf("    + %d  -> + %d \n", level, level + 1);
                printf("                  \n");
                printf(" ***** SUCCESS *****\n");
                attemptlevel = level;
                level++;// ��ȭ�� ���� ���� ��, ������ �ϳ� ���� ��Ŵ
                for (int i = 0; i < 20; i++) // ��ȭ ���� Ƚ�� ������ ����
                {
                    if (level == Levels[i])
                    {
                        Success[level] += 1;
                        break;
                    }
                }
                printf("\n [%d�� ��ȭ ���� Ƚ�� : %d]\n", level, Success[level]);
                attempt++;

            }
            else {
                if (level != 20) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    printf(" ***** FAILURE *****\n");
                    printf("                  \n");
                    printf("      %d  ->  % d    \n", level, level - 1);
                    printf("                  \n");
                    printf(" ***** FAILURE *****\n");
                    printf("\n ������.. �ڵ����� �ó�..�������� �����ȴ�...\n");
                    printf("\n [+%d ������ �Ҿ����ϴ�.]\n\n", level);
                    attemptlevel = level;
                    for (int i = 0; i < 20; i++) { // ��ȭ ���� Ƚ�� ������ ����
                        if (level == Levels[i]) {
                            Failure[level] += 1;
                            break;
                        }
                    }
                    printf("\n [%d�� ��ȭ ���� Ƚ�� : %d]\n", level, Failure[level]);

                    if (tickets > 0) {
                        choice = 0;
                        int ticketsToUse = failureTicketCosts[level]; // ���� �� �Ҹ�� �������� ��
                        money -= enhancementCosts[level];
                        printf("�н��� �����Ͽ����ϴ�. \n���� �н� ��ġ�� �����Ͻðڽ��ϱ�? \n�Ҹ�Ǵ� �������� %d�� �Դϴ�.\n{���� �н��� ���� : %d}\n(YES : 1/ NO : 2) : ", ticketsToUse, tickets);
                        while (true) {
                            choice = 0;
                            scanf_s("%d", &choice);
                            while (getchar() != '\n');  // �Է� ���� Ŭ����
                            if (ticketsToUse <= tickets && choice == 1) {
                                tickets -= ticketsToUse; // ���� �� �Ҹ�Ǵ� ������ ���� ����
                                printf("\n�������� ����մϴ�. (���� ������ ���� : %d)\n", tickets);
                                money += enhancementCosts[level];
                                break;  // ��ȿ�� �Է��� �޾����Ƿ� �ݺ��� ����
                            }
                            else if (choice == 2) {
                                printf("�н� ��ġ�� �ʱ�ȭ�մϴ�.\n");
                                level = 0; // ��ȭ ��ġ �ʱ�ȭ
                                break;  // ��ȿ�� �Է��� �޾����Ƿ� �ݺ��� ����
                            }
                            else {
                                printf("�߸��� �Է� �߰ų� �������� ���ڶ��ϴ� �ٽ� ���� �ϼ���! (YES : 1 / NO : 2) : ");
                            }
                        }
                    }
                    else {
                        printf("�������� ���� �н� ��ġ�� �ʱ�ȭ�մϴ�.\n");
                        level = 0;  // �������� �����Ƿ� ������ �ʱ�ȭ
                    }
                }
                else {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                    printf(" ***** MAX LEVEL *****\n");
                    printf(" �ְ� ��ȭ �ܰ��Դϴ�. \n");
                    printf(" ***** MAX LEVEL *****\n");
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
            printf("\n 1. �̻��� ������\n");
            printf(" 2. ���ҹ� ������\n");
            printf(" 3. ������ ������\n");
            printf(" 4. �̿ ������\n");
            printf(" 5. �迵õ ������\n\n");
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
            endDateTime = 1;
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
        Gopost();
    }
    return 0;
}
