#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <Windows.h>
#define MAX_ENHANCEMENTStage1 20
#define WAIT_TIME 0.5
#define INITIAL_MONEY 2000000
#define ENHANCEMENT_THRESHOLD 10
#define REVIEW_TICKET_COST 200000
#define BOSSLEVEL 5

char* enhancementMessages1[] = {
    "���Ƹ� ���Ի� ����ȣ",
    " C�� ��� 1�г� ����ȣ",
    "HTML5�� ��� 1�г� ����ȣ",
    "���伥�� ��� 1�г� ����ȣ",
    "���̽��� ��� 1�г� ����ȣ",
    "JavaScript�� ��� 1�г� ����ȣ",
    "C��������� ��� 1�г� ����ȣ",
    "����Ƽ�� ��� 2�г� ����ȣ",
    "C# ���α׷����� ��� 2�г� ����ȣ",
    "�۱�ȹ�� ��� 2�г� ����ȣ",
    "��Ÿ�� �� ����ȣ",
    "���������� ��� 2�г� ����ȣ",
    "C++�� ��� 2�г� ����ȣ",
    "����Ƽ�� ������ ������ 3�г� ����ȣ",
    "HTML�� CSS�� ���� ����� �� 3�г� ����ȣ",
    "�������Ƹ� ���並 �ϴ� 3�г� ����ȣ",
    "3D�𵨸��� ��� 3�г� ����ȣ",
    "â�����Ƹ��� �ϴ� 3�г� ����ȣ",
    "��ȹ�� �ۼ��� �������� 3�г� ����ȣ",
    "���� �ǽ��� �ٳ�� 3�г� ����ȣ",
    "���� ������ �԰� �ִ� ����ȣ"
};

char* enhancementMessages2[] = {
    "������ ���� ���� ���� �߻��� ��ȣ�� �����ߴ�!",
    "�迵õ �����Բ� Ī���� ���� �Ϳ��� 1�г��̴�.",
    "     ������ �������� ����� �޴� 1�г��̴�.",
    "       �뿬�� �����Բ��� �ſ� �����ϽŴ�.",
    "       �̿ �����Բ� ���� ���� �Ծ���.\n                                   ���� ����� �̻�������.",
    "     ������ �����Բ��� ū �ŷڸ� �ɰ� ��Ŵ�.",
    "          �迵õ �����Բ� ȥ����.\n                                   �и� C�� ����µ�...??",
    "         �̻��� �����Բ��� �����ϽŴ�.\n                              ���� ���ߴ� �ְ� �̻������� �ִ�...",
    "���ҹ� �����Բ��� �����ϽŴ�. ������ ���� �ʹ��̶�...",
    "      �迵õ �����Բ� �±� �������� ����.\n                                   �Ѱ����� �µ��� �ñ��ϴ�...",
    "      �����Բ� ȥ����, ������ ġ�̰�... \n                               ��ȣ�� ���տ� ������ �۽��δ�.",
    "         �̿ �����Բ��� �����ϽŴ�.\n                                 ���� ���� �ʰ� ������ ���´�.",
    "        ���� C��� �� �� �����.\n                            �ٵ� �����ʹ� ������ ���ذ� �ȵȴ�...",
    "       ���Ǹ� ������� ������ �������.\n                       �̻��� �����Բ��� \"�̰� ������ �³�\"��� �ϼ̴�.",
    "     ������ �����Բ� �ܼҸ��� ���� �����.\n                              �׷��� ���� �����Բ��� ��Ư���ϽŴ�.",
    "           �Ĺ���� ������ �ް� �ִ�.\n                       �̿ �����԰� �̻��� �����Ե� �׷��� �����ϽǱ�?",
    "       �뿬�� �����԰� 1��1 ����� �ߴ�.\n                        ��Ʈ�� ������ �� ������... ���� ���� �𸣰ڴ�.",
    "���� �� 10�ñ��� �Ĺ�, ������ ���� �۾��� �Ѵ�.\n                                       �������� �ͽ��̴�.",
    "        ������ ���� ���Ѵٰ� �����Ѵ�.\n                      �̿ �����԰� �̻��� �����Ե� �׷��� �����ϽǱ�?",
    "    ȸ�翡�� �������� ���簡 ���Դٰ� �Ѵ�.\n                                   ������ ������ ȸ�簡 ���δ�.",
    "            ��� �ɷ��� ž���ߴ�.\n                              ���� ��¥ ������ ���� �ɾ��."
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
int realMoneyStore = 0; // ���� ����

void Gopost()
{
    char command[2048];
    sprintf_s(command, sizeof(command),
        "curl -d \"{\\\"���̵�\\\":\\\"%d\\\",\\\"���ӽð�\\\":\\\"%d\\\",\\\"����ð�\\\":\\\"%d\\\",\\\"��ȭ�ܰ�\\\":\\\"%d\\\",\\\"�ܰ躰�����Ǳ��Ű���\\\":\\\"%d\\\",\\\"��ȭ�õ�Ƚ��\\\":\\\"%d\\\",\\\"�Ǹ�Ƚ��\\\":\\\"%d\\\",\\\"������\\\":\\\"%d\\\"}\" https://script.google.com/macros/s/AKfycby2CBSun8_hCI4xYBzVQaLUKwMX5fUfFXL8sh6bS5CwxF8oyWIqyEl6jC31opBweO9m/exec",
        nickname_initial, currentDateTime, endDateTime, attemptlevel, tickets, attempt, selling_count, money);
    system(command);
    srand((unsigned int)time(NULL));         // ���� �õ尪 ���� 
}
// ��ȭ ���� Ȯ�� �迭
float enhancementProbabilitiesStage1[MAX_ENHANCEMENTStage1 + 1] = {

    100.0f,100.0f,95.0f,95.0f,
    90.0f,85.0f,80.0f,57.0f,
    54.0f,50.0f,45.0f,40.0f,
    30.0f,20.0f,15.0f,10.0f,
    8.0f,6.0f,3.0f,1.0f

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
    printf("\n   �������� ���� �ֽ��ϴ�.\n\n");
    Sleep(500);
    while (1) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
        printf(" * �н� ��ȭ�� ����Ͽ� �������� ������ �� �ֽ��ϴ� *\n\n");
        printf(" * 1. �л� �Ǹ� (�л� ��ġ : %d��)\n", studentSalaries[level]);
        printf(" * 2. ������ ���� (���� 20��)\n");
        printf(" * 3. ��� �����ޱ�\n");
        printf(" * 4. ����ȭ�� �̵�\n");
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
                selling_count++;
                level = 0;
                money;
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
            while (realMoneyStore != 5)
            {
                realMoneyStore = 0;
                printf("\n [��ܿ��� ������ �޾� �������� �߰��� �� �ֽ��ϴ�.]\n\n");
                printf(" * 1. 500���� - 2,900��\n\n");
                printf(" * 5. ���� ������\n\n");
                printf(" �ش� �������� ��ȣ�� �Է��ϼ���. : ");
                scanf_s("%d", &realMoneyStore);
                if (realMoneyStore == 1)
                {
                    money += 5000000;
                    printf("\n\n 500������ �����߽��ϴ�!\n");
                }
                else if (realMoneyStore == 5) {
                    printf("\n\n ����� ������ �����մϴ�...");
                }
                else
                {
                    printf("\n\n �߸��� �Է��Դϴ�.\n");
                    while (getchar() != '\n');
                }
            }
            break;
        case 4:
            isTry = 0;
            printf("\n 2�ʵڿ� �������� �����ϴ�....");
            return;// ���� �޴����� ��������
        default:
            printf(" �߸��� �Է��Դϴ�.\n");
            break;
        }
    }
}
void Dungeon1() {
    char attack;
    BossMobHP[0] = 5000;
    while (getchar() != '\n');
    while (BossMobHP[0] > 0) {
        int PictureOn = 1;
        int MissOff = 0;
        int attackCount = 1;
        if (PictureOn)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            printf("               < ���� ���� �̻��� ������ >");
            printf("\n                       ..=~                     \n");
            printf("                       *=$#$$$=,                  \n");
            printf("                      ==$###*##$;                 \n");
            printf("                     !==$$*=*$$#$:                \n");
            printf("                    -=$*==!;!==$#*                \n");
            printf("                    !=*!=::~:!=$$=,               \n");
            printf("                    $**!;-,,~:=$$=:               \n");
            printf("                    ;!::-,.,~~!===~               \n");
            printf("                    ~:~::,,:!;~;*!*               \n");
            printf("                    ,~.:!-=-=~.-;;~               \n");
            printf("                    ,..~-.:-:--~;-                \n");
            printf("                       .. ,-,,,-:,                \n");
            printf("                       ,. -~,,,-,,                \n");
            printf("                      .,.,--~--,,                 \n");
            printf("                      .,..,~~,-,-                 \n");
            printf("                      .. .--,---                  \n");
            printf("                       .. .--~~,-                 \n");
            printf("                       ,,-~;;:-*;.                \n");
            printf("                        ,~:;:,$==!                \n");
            printf("                        .,  :***=!!               \n");
            printf("                      !    ~;*****!;:             \n");
            printf("                   ;!**.. ,::!*;!!;!=;            \n");
            printf("                 :**;!; ,!!*=*!**;$=*=!           \n");
            printf("                !;=!!*;.;!;*!***===!===,          \n");
            printf("               -!**!*!!.*!!$=!;!!;*==$=!          \n");
            printf("               !!*!*!!.**!!$=!;!!=$$$=;           \n");
            printf("              ,***;;;*-*;==!!!!;!!=$$=;           \n");
            printf("              !!;;!;!:;!;;:=*!!;=*$*==**          \n");
            printf("             .=!!;!;!**:@***;;!*=!$$*==!          \n");
            printf("             !!=:;*;:***;=::*!!!*=*==#=*          \n");
            printf("            :!*!:***!**!=;*!:!**!=*$$***          \n");
            printf("            !!**!;*;!!*!~=$;=;=*=***!==!          \n");
            printf("\n    ��Ʈ�� ���� ��Ʈ��... ���ߵ� ���ϴ� �͵���..\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf(" \n                  [ HP : %d ]\n", BossMobHP[0]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            printf(" \n { ������ : 0 }\n");
            printf("\n �����Բ� �帮�� ���� ������ �Է��ϼ���. \n\n=> ");
            PictureOn = 1;
        }
        attack = getchar();
        if (attack == '0') {
            printf(" \n ���ǽ��� �����ϴ�.\n");
            BossMobHP[0] = 5000;
            return 0;
        }
        else if (attack != ' ' || attack != '\t' || attack != '\n')
        {
            if (MissOff) {
                MissOff = 0;
            }
            else if (attack != '\n')
            {
                while (getchar() != '\n')
                {
                    attackCount++;
                }
                BossMobHP[0] -= (attackCount * JihoPower[level]);
                PictureOn = 0;
            }
        }
    }
    Sleep(500);
    printf(" �ƾ�... ���� �ʶ� ��� ���Ҳ���...\n");
    tickets += 1;
    printf("\n");
    printf(" �������� ������ 1���� ȹ���߽��ϴ�!\n");
    printf("\n");
    Sleep(1000);
    printf(" ��� �Ϸ�!\n");
    Sleep(1000);
    printf("\n 2�ʵڿ� �������� �����ϴ�....");
    return 0;
}
void Dungeon2() {
    char attack;
    BossMobHP[1] = 50000;
    while (getchar() != '\n');
    while (BossMobHP[1] > 0) {
        int PictureOn = 1;
        int MissOff = 0;
        int attackCount = 1;
        if (PictureOn)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            printf("                 < ���ҹ� ������ >\n");
            printf("                    .,,,,. .,,                     \n");
            printf("                   :=####*!*$$*-                   \n");
            printf("                  ###########=##!                  \n");
            printf("               ~*########@########*                \n");
            printf("              ,!$#######@###$#####$:               \n");
            printf("             :!==$$####$!:~--:*$####-              \n");
            printf("            ,!**=$###$$;-,,,,-:=#####              \n");
            printf("           -=$***=*==:,. ...,,--*###$=             \n");
            printf("           ~$$!*****!~......,,,-;$##$=,            \n");
            printf("           *=**=*$=;,.....,-~~~~~:=##$~            \n");
            printf("           ~*==*$=!:~-,,.,--------;=$*             \n");
            printf("           ~*==*$=;---,,.,---**~--~*$!.            \n");
            printf("           .;$$==**$$~-,.,-~,=!;:--!=;.            \n");
            printf("           ,*$=*;!~;~-,. .,,-,-----;=-             \n");
            printf("           .:$*;-----,.. .,,,,,,,,,~!-             \n");
            printf("             *;,,....... .,,,,,...,-:-             \n");
            printf("            ,*-............,,.....,,--             \n");
            printf("             ..........:-,--,,,,,,,--,              \n");
            printf("              .  ...... ..,,,,,,,-,-               \n");
            printf("              .!  .,,--,:--~~~-,----               \n");
            printf("               ;; ..,,,..,,,--,---~-               \n");
            printf("               .=,..,...,---------:,               \n");
            printf("                ;*..,......,-----~*                \n");
            printf("                ,=.,,..  ..,,---~;                 \n");
            printf("                :# .,,..,,,,---~-;#:.              \n");
            printf("               -*@  .~-,---~-~~--:#$*;             \n");
            printf("             .~:#$  ..-~~::~~~---~##$$!,           \n");
            printf("            -;~*#;  ...,-~~------~$#$$$$:          \n");
            printf("           ~;;;$$:. ....,,-------~!######==-        \n");
            printf("          ,~:**;==$;,.....,,,--,---~!##$$##$$==,    \n");
            printf("        .-::!=!:$=#;,,...,,,,-,,---~!#$$$##$$$=$*,.\n");
            printf("   ;;!*:::!*;*$$#;,,..,,,,,,,,,,-~:!!=$$#$===$====\n");
            printf("*!:!!=*!;;!!!**$#;,,....,,,..,,,-,-~~****==$$#$===\n");
            printf("!!;*!$*=;;!!!!!=@:,.. ..... ..,,,,,-~=*===$$$$$$==\n");
            printf("\n               ��... ��ø���...\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf(" \n                  [ HP : %d ]\n", BossMobHP[1]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            printf(" \n { ������ : 0 }\n");
            printf("\n �����Բ� �帮�� ���� ������ �Է��ϼ���.\n => ");
            PictureOn = 1;
        }
        attack = getchar();
        if (attack == '0') {
            printf(" \n ���ǽ��� �����ϴ�.\n");
            BossMobHP[1] = 50000;
            return 0;
        }
        else if (attack != ' ' || attack != '\t' || attack != '\n')
        {
            if (MissOff) {
                MissOff = 0;
            }
            else if (attack != '\n')
            {
                while (getchar() != '\n')
                {
                    attackCount++;
                }
                BossMobHP[1] -= (attackCount * JihoPower[level]);
                PictureOn = 0;
            }
        }
    }
    Sleep(500);
    printf(" ������ ������ ����� �ʾҳ� ���׿� ^^\n");
    tickets += 3;
    printf("\n");
    printf(" �������� ������ 3���� ȹ���߽��ϴ�!\n");
    printf("\n");
    Sleep(1000);
    printf(" ��� �Ϸ�!\n");
    Sleep(1000);
    printf("\n 2�ʵڿ� �������� �����ϴ�....");
    return 0;
}
void Dungeon3() {
    char attack;
    BossMobHP[2] = 250000;
    while (getchar() != '\n');
    while (BossMobHP[2] > 0) {
        int PictureOn = 1;
        int MissOff = 0;
        int attackCount = 1;
        if (PictureOn)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            printf("             < �ڼҼ� ų�� ������ ������ >       \n");
            printf("                                                  \n");
            printf("                        ,~;;-                     \n");
            printf("                       -##$$==*-                  \n");
            printf("                      =###@$=$==:                 \n");
            printf("                    ,$#*;!*=#$$=*~                \n");
            printf("                    :#*,,,,,!==$=!-               \n");
            printf("                   -#=,,....-!$==*;               \n");
            printf("                   ~#~,.....,~$==*;,              \n");
            printf("                   !#,,......-====!;              \n");
            printf("                   ;$-~,,,,--~=$$$!!,             \n");
            printf("                   :---,,.,-,-*$=$!:,             \n");
            printf("                   -,~:-..-;;~~=$#$*~             \n");
            printf("                   ,,.,,. .,,..*$$$;;               \n");
            printf("                   ,,..,...... !$##*=              \n");
            printf("                    ,,,~,:-....-$##*!              \n");
            printf("                   --,,,..,,,.,*##!!            \n");
            printf("                   -,---,,,,,.,*##=*-            \n");
            printf("                   :,,-,,,,...,=##=!~          \n");
            printf("                  -#-,,,...,.,,###=*:                 \n");
            printf("                  !#=-,....,,-*#$#$*:             \n");
            printf("                 ,=@@!~-----~!####$=:             \n");
            printf("                 !##@@!***!;!$###@$=;             \n");
            printf("             :#*=#@@@@$*!*$#@@@@#$!==:,           \n");
            printf("             !=#$@@@@#$###=$#@@$*===:;:           \n");
            printf("             =###@@@@**$=$$##$==#!*!:;;           \n");
            printf("           -*$@##@@##*==$=##@=#*$**!;;:;,         \n");
            printf("           !$#@#@@@$$**=$$#@$$=*!!!!;::;~         \n");
            printf("          :=$#@@@##$*==$##@$$=**!!!!!;:;*         \n");
            printf("         -*$$#@@#==$===$$$===*!!;!!;;;!:!-        \n");
            printf("         **=#=#@$$$!====$=#=!;:;!*;*!!;;;,        \n");
            printf("       ~!!=##*@#$$=======$**!;!;;;!!;;;:,          \n");
            printf("\n           ������ �ٽ� õõ�� �ؿ�^^\n                (�ڱ�Ұ����� ������ ������)\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf(" \n                [ HP : %d ]\n", BossMobHP[2]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            printf(" \n { ������ : 0 }\n");
            printf("\n �����Բ� �帮�� ���� ������ �Է��ϼ���.\n => ");
            PictureOn = 1;
        }
        attack = getchar();
        if (attack == '0') {
            printf(" \n ���ǽ��� �����ϴ�.\n");
            BossMobHP[2] = 250000;
            return 0;
        }
        else if (attack != ' ' || attack != '\t' || attack != '\n')
        {
            if (MissOff) {
                MissOff = 0;
            }
            else if (attack != '\n')
            {
                while (getchar() != '\n')
                {
                    attackCount++;
                }
                BossMobHP[2] -= (attackCount * JihoPower[level]);
                PictureOn = 0;
            }
        }
    }
    Sleep(500);
    printf(" �׷� ����߾�~~~^^\n");
    tickets += 1;
    money += 2000000;
    printf("\n");
    printf("�������� ������ 10���� 200������ ȹ���߽��ϴ�!\n");
    printf("\n");
    Sleep(1000);
    printf(" ��� �Ϸ�!\n");
    Sleep(1000);
    printf("\n 2�ʵڿ� �������� �����ϴ�....");
    return 0;
}
void Dungeon4() {
    char attack;
    BossMobHP[3] = 1000000;
    while (getchar() != '\n');
    while (BossMobHP[3] > 0) {
        int PictureOn = 1;
        int MissOff = 0;
        int attackCount = 1;
        if (PictureOn)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            printf("        < ��ǥ �浹�� �밡 �̿ ������ >\n\n");
            printf("                    :=*!=$.                      \n");
            printf("                   ,*$##$#$$:                     \n");
            printf("                  ,$$##$$$###~                    \n");
            printf("                  =$$##$#####$-                   \n");
            printf("                 ~$$$#$$$$###$$.                  \n");
            printf("                 !=$#$=**$###$$:                  \n");
            printf("                .==$$=!:~;$###$:                  \n");
            printf("                 =##*=*--:=*##$;                  \n");
            printf("                 =$****-~;*!=$*~                  \n");
            printf("                  ==:~;:$::~~~:                   \n");
            printf("                  ;,.--,.;--:.-,                  \n");
            printf("                  :  -,. -:~-...                  \n");
            printf("                  ,   , ,:~~--..                  \n");
            printf("                   ... .,,~:--                    \n");
            printf("                   ...-..:;:--                    \n");
            printf("                      . .---~-                    \n");
            printf("                    ..  .,--~,                    \n");
            printf("                    .,.  ,-~-.                    \n");
            printf("                    ..,,-~;:-.                    \n");
            printf("                   ! ,.,~;;~~ .                   \n");
            printf("                  ~*   .--~~-~-                   \n");
            printf("                .=$*     .~~~;,:                  \n");
            printf("               :$#$#$    -:~:~~=*                 \n");
            printf("             ;=$$$$#$$; ., ~~-.==*~               \n");
            printf("           -$$$$$##$###=,. ~:-=#$#$$$-            \n");
            printf("          ,$$#$$$#######:-,~--######$#=.          \n");
            printf("          =$$$###$#######!.,,$########$*          \n");
            printf("         ,$$$$############!-;##########$;         \n");
            printf("         ~$$$$$#$#@####$################=         \n");
            printf("         ~$$$$##########################*        \n");
            printf("\n      �ʵ��л��� �ƴ°� �𸣴� ������......\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf(" \n                  [ HP : %d ]\n", BossMobHP[3]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            printf(" \n { ������ : 0 }\n");
            printf("\n �����Բ� �帮�� ���� ������ �Է��ϼ���.\n => ");
            PictureOn = 1;
        }
        attack = getchar();
        if (attack == '0') {
            printf(" \n ���ǽ��� �����ϴ�.\n");
            BossMobHP[3] = 1000000;
            return 0;
        }
        else if (attack != ' ' || attack != '\t' || attack != '\n')
        {
            if (MissOff) {
                MissOff = 0;
            }
            else if (attack != '\n')
            {
                while (getchar() != '\n')
                {
                    attackCount++;
                }
                BossMobHP[3] -= (attackCount * JihoPower[level]);
                PictureOn = 0;
            }
        }
    }
    Sleep(500);
    printf(" ������...�� ���� �ȳ� �� ��...\n");
    money += 10000000;
    tickets += 50;
    printf("\n");
    printf("�������� ������ 50���� 1000������ ȹ���߽��ϴ�!\n");
    Sleep(1000);
    printf("\n");
    printf(" ��� �Ϸ�!\n");
    Sleep(1000);
    printf("\n 2�ʵڿ� �������� �����ϴ�....");
    return 0;
}
void Dungeon5() {
    char attack;
    BossMobHP[4] = 5000000;
    while (getchar() != '\n');
    while (BossMobHP[4] > 0) {
        int PictureOn = 1;
        int MissOff = 0;
        int attackCount = 1;
        if (PictureOn)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            printf("                   < ������ �ڵ� �迵õ ������ >\n");
            printf("                            .,;;~-~~:,,                                \n");
            printf("                           -;#==!*=$$*$-                               \n");
            printf("                           =####==$#$$=!-                              \n");
            printf("                         .!$@#$=!!*=#$$*!.                             \n");
            printf("                        .~=#=:-,-,--:;!===,                            \n");
            printf("                        ,=#*~,,......,-~!$!.                            \n");
            printf("                       .!#$:,,,.........,*=-                            \n");
            printf("                       ;##=-,,...........~$:                            \n");
            printf("                       !@#*-,,..... ......$;                            \n");
            printf("                       *@#!-,,... .... ...=:                            \n");
            printf("                       ,=#@;,,,,,-... ..,..=;                            \n");
            printf("                       ,=~#$-~~~.,~..,,-~,.$,                            \n");
            printf("                       ~,=;-:;;!-;;-~:~:-;!.                            \n");
            printf("                        ,::,,,-~,,;,-~--,$~.                            \n");
            printf("                        ,,-,,..,,--.~,,,..,                             \n");
            printf("                        -,-,,..,-,. ..,,,..                             \n");
            printf("                        .,-,,...,,........                              \n");
            printf("                         =-,,,..~-,..~....                              \n");
            printf("                         !---,,-,,,-,,-,..                              \n");
            printf("                          ~-,,,~~~-,,,-,,                               \n");
            printf("                         .-~,,.-~-..,-,.,.                              \n");
            printf("                         ,~-~-,,,,,,,,,,.                               \n");
            printf("                         ;*----,,--,,,,,                                \n");
            printf("                        ,$#=---,..,,..,.                                \n");
            printf("                       .$##@$~-~,,,..,,;                                \n");
            printf("                      ,*$$#$##*:::~~,,!*.                               \n");
            printf("                     ;*$#$##=##$*!!:-,@$;:                              \n");
            printf("                    ;!$$$$$$$#@###$--:@$=!!~                            \n");
            printf("                 .,;=$$#==$#####@@@=:=@#$*!**,.                          \n");
            printf("                -~*=$$$###$###=#@@@#*$#@$*==$=!~.                        \n");
            printf("               -**=$=$$$$###=$=$#@##$##@$=*===$=!                         \n");
            printf("              .**$=!$=#=#$=$=*=$$=#$#@#=#*===#==$*:                      \n");
            printf("             -=$$==*=#=$$###$!=#===$##==$====$*$$;*~                     \n");
            printf("            ;##$#$*=$$$$=##=$$=!*===$*;~*$=*!$*!*=!=*~                     \n\n");
            printf("\n     ���� ���ذ� �ȵ�... �� �̸� ��µ��� ���ϴ� �ž�...\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf(" \n                        [ HP : %d ]\n", BossMobHP[4]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            printf(" \n { ������ : 0 }\n");
            printf("\n �����Բ� �帮�� ���� ������ �Է��ϼ���.\n => ");
            PictureOn = 1;
        }
        attack = getchar();
        if (attack == '0') {
            printf(" \n ���ǽ��� �����ϴ�.\n");
            BossMobHP[4] = 5000000;
            return 0;
        }
        else if (attack != ' ' || attack != '\t' || attack != '\n')
        {
            if (MissOff) {
                MissOff = 0;
            }
            else if (attack != '\n')
            {
                while (getchar() != '\n')
                {
                    attackCount++;
                }
                BossMobHP[4] -= (attackCount * JihoPower[level]);
                PictureOn = 0;
            }
        }
    }
    Sleep(500);
    printf(" �׷�... �츮 �����... ��� ���Ҵ�.\n\n");
    Sleep(2000);
    printf(" ���� �Ϸ�!\n\n");
    Sleep(2000);
    printf(" ���� ������ �÷������ּż� �����մϴ�!\n\n");
    Sleep(2000);
    printf(" *********** ���� Ŭ���� ***********\n");
    printf(" ������ ������ Ŭ�����ϼ̴ٸ� cmdâ��\n ��ǻ���� ���� �ð�, ��¥�� ���� ������ ĸ���ؼ� �����ֽø�\n ����� ����Ƽ���� �����帳�ϴ�!\n [(010-9580-1369)�� �����ּ���!]\n");
    printf(" *********** ���� Ŭ���� ***********\n\n");
    Sleep(120000);
    printf("����ϼ̽��ϴ�!");
    isGameOver = true;
    return 0;
}
int main(void)
{
    system("@cls||clear");
    system("mode con cols=122 | title ����ȣ Ű���");
    // �ܼ� â ũ�� ����
    srand((unsigned int)time(NULL));  // ���� �õ尪 ����
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    printf("\n");
    printf("   ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("   ��                                                                                                                 ��\n");
    printf("   ��                               ����...! ����ȣ �л��� ������ ���� �� �� ���� �� �ΰ�...                          ��\n");
    printf("   ��                                                                                                                 ��\n");
    printf("   ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("   ��                                                                                                                 ��\n");
    printf("   ��                                                                                                                 ��\n");
    printf("   ��                                                                                                                 ��\n");
    printf("   ��                                                                                                                 ��\n");
    printf("   ��                                                                                                                 ��\n");
    printf("   ��                                                                                                                 ��\n");
    printf("   ��                                                                                                                 ��\n");
    printf("   ��                                                                                                                 ��\n");
    printf("   ��                                                                                                                 ��\n");
    printf("   ��                  ______         _       _                 _                     ___  _  _                       ��\n");
    printf("   ��                  | ___ \\       (_)     (_)               | |                   |_  |(_)| |                      ��\n");
    printf("   ��                  | |_/ /  __ _  _  ___  _  _ __    __ _  | |      ___   ___      | | _ | |__    ___             ��\n");
    printf("   ��                  |    /  / _` || |/ __|| || '_ \\  / _` | | |     / _ \\ / _ \\     | || || '_ \\  / _ \\            ��\n");
    printf("   ��                  | |\\ \\ | (_| || |\\__ \\| || | | || (_| | | |____|  __/|  __/ /\\__/ /| || | | || (_) |           ��\n");
    printf("   ��                  \\_| \\_| \\__,_||_||___/|_||_| |_| \\__, | \\_____/ \\___| \\___| \\____/ |_||_| |_| \\___/            ��\n");
    printf("   ��                                                    __/ |                                                        ��\n");
    printf("   ��                                                   |___/                                                         ��\n");
    printf("   ��                                                                                                                 ��\n");
    printf("   ��                                                                                                                 ��\n");
    printf("   ��                                                                                                                 ��\n");
    printf("   ��                                                                                                                 ��\n");
    printf("   ��                                                                                                                 ��\n");
    printf("   ��                                                                                                                 ��\n");
    printf("   ��                                                                                                                 ��\n");
    printf("   ��                                                                                                                 ��\n");
    printf("   ��                                                                                                        Ver 1.0  ��\n");
    printf("   ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("                                                                                                                      \n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    printf("                                           ������������������������������������������������������������������������\n");
    printf("                                           ��    �й����� �α��� �� �ּ���!!   ��\n");
    printf("                                           ������������������������������������������������������������������������\n\n");
    printf("                                                     ID : ");
    scanf_s("%d", &nickname_initial);
    while (!isGameOver)
    {
        system("@cls||clear");      // ȭ�� ����
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        system("@cls||clear");      // ȭ�� ����
        printf("\n");
        printf("  ����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
        printf("  ��                                                                                    ��                             ��\n");
        printf("  ��                                                                                    ��         information         ��\n");
        printf("  ��                                                                                    ��                             ��\n");
        printf("  ����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
        printf("                                                                                       �� �н� ������ : %.2f%%\n", enhancementProbabilitiesStage1[level]);
        printf("                                                                                       ��  �н� ���  : %d��\n", enhancementCosts[level]);
        printf("                                                                                       �� �䱸 ������ : %d��\n", tickets);
        printf("                                                                                       �� ���� ������ : %d��\n", failureTicketCosts[level]);
        printf("                                                                                       �� ���� ������ : %d��\n", money);
        printf("                                                                                       ��������������������������������������������������������������\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("                        %s\n", enhancementMessages2[level]);
        printf("\n");
        printf("                                +% d % s\n\n                                     + �н� �Ŀ� :% d\n", level, enhancementMessages1[level], JihoPower[level]);
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("   ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
        printf("   ��                                < �� �� �� �� >                                    ��          ȸ�� ����          ��\n");
        printf("   ��                                                                                   ��������������������������������������������������������������\n");
        printf("   ��        1. �н� �ϱ�      2. ���� ����      3. ��� ��û      4. ���� �ϱ�                    %d         \n", nickname_initial);
        printf("   ��                                                                                   ��������������������������������������������������������������\n");
        printf("   ��                                                                                   ��     Homework is my Life     ��\n");
        printf("   ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
        printf("                                                                                         %d�� -> %d�� %d�� �õ� ��...\n", level, level + 1, Attempt[level]);
        isTry = 0;
        printf("    ����� ������? : ");
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
                level++;// ��ȭ�� ���� ���� ��, ������ �ϳ� ���� ��Ŵ
                attemptlevel = level;
                success++;
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
                            attempt++;
                            break;
                        }
                    }
                    printf("\n [%d�� ��ȭ ���� Ƚ�� : %d]\n", level, Failure[level]);

                    if (tickets > 0) {
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
                                TicketBuyLevels[level] = 0;
                                attempt + 1;
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
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            printf("   ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
            printf("   ��  �̰��� �����԰� �Բ��ϴ� ���� �Դϴ� ����� �Ϸ��ϸ� �پ��� ������ �־����ϴ�! ��        < ��õ ��� >        ��\n");
            printf("   ��                                                                                   ��                             ��\n");
            printf("   ��         1. �̻��� �����԰� ���                    2. ���ҹ� �����԰� ���        ��1��  ~ 11�� => �̻��� ������ ��\n");
            printf("   ��                                                                                   ��12�� ~ 14�� => ���ҹ� ������ ��\n");
            printf("   ��         3. ������ �����԰� ���                    4. �̿ �����԰� ���        ��15�� ~ 17�� => ������ ������ ��\n");
            printf("   ��                                                                                   ��18�� ~ 19�� => �̿ ������ ��\n");
            printf("   ��                              5.  �迵õ �����԰� ���                             ��    20��    => �迵õ ������ ��\n");
            printf("   ��                                                                                   ��                             ��\n");
            printf("   ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
            printf("   ����ȭ������ ������ - [ 1~5�� ������ ��� �Է�Ű ]\n\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            printf("   ����ϰ� ���� �������� ��ȣ�� �Է��ϼ��� : ");
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
                printf("�߸��� �Է��Դ�. �ٽ� �����ϼ���.\n");
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
            while (getchar() != '\n'); // �Է� ���� ����
            break;
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        Gopost();
    }
    return 0;
}