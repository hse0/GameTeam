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
    "병아리 신입생 이지호",
    " C언어를 배운 1학년 이지호",
    "HTML5를 배운 1학년 이지호",
    "포토샵을 배운 1학년 이지호",
    "파이썬을 배운 1학년 이지호",
    "JavaScript를 배운 1학년 이지호",
    "C언어응용을 배운 1학년 이지호",
    "유니티를 배운 2학년 이지호",
    "C# 프로그래밍을 배운 2학년 이지호",
    "앱기획을 배운 2학년 이지호",
    "현타가 온 이지호",
    "반응형웹을 배운 2학년 이지호",
    "C++을 배운 2학년 이지호",
    "유니티로 게임을 개발한 3학년 이지호",
    "HTML과 CSS로 웹을 만들어 본 3학년 이지호",
    "전공동아리 멘토를 하는 3학년 이지호",
    "3D모델링을 배운 3학년 이지호",
    "창업동아리를 하는 3학년 이지호",
    "기획서 작성을 마스터한 3학년 이지호",
    "현장 실습을 다녀온 3학년 이지호",
    "졸업 가운을 입고 있는 이지호"
};

char* enhancementMessages2[] = {
    "세상의 때가 묻지 않은 야생의 지호가 등장했다!",
    "김영천 교수님께 칭찬을 받은 귀여운 1학년이다.",
    "     이은임 교수님의 사랑을 받는 1학년이다.",
    "       노연석 교수님께서 매우 만족하신다.",
    "       이운석 교수님께 욕을 많이 먹었다.\n                                   슬슬 사람이 이상해진다.",
    "     이은임 교수님께선 큰 신뢰를 걸고 계신다.",
    "          김영천 교수님께 혼났다.\n                                   분명 C언어를 배웠는데...??",
    "         이상현 교수님께서 걱정하신다.\n                              원래 착했던 애가 이상해지고 있다...",
    "윤소미 교수님께서 좋아하신다. 다행히 아직 초반이라...",
    "      김영천 교수님께 맞기 직전까지 갔다.\n                                   한강물의 온도가 궁금하다...",
    "      교수님께 혼나고, 과제에 치이고... \n                               지호의 눈앞에 눈물이 글썽인다.",
    "         이운석 교수님께서 좋아하신다.\n                                 잠을 자지 않고 과제를 끝냈다.",
    "        이제 C계얼 언어를 다 배웠다.\n                            근데 포인터는 도저히 이해가 안된다...",
    "       코피를 흘려가며 게임을 만들었다.\n                       이상현 교수님께서 \"이게 게임이 맞나\"라고 하셨다.",
    "     이은임 교수님께 잔소리를 많이 들었다.\n                              그래도 내심 교수님께서 기특해하신다.",
    "           후배들의 존경을 받고 있다.\n                       이운석 교수님과 이상현 교수님도 그렇게 생각하실까?",
    "       노연석 교수님과 1대1 면담을 했다.\n                        아트도 괜찮은 것 같은데... 어디로 갈지 모르겠다.",
    "매일 밤 10시까지 후배, 동기들과 같이 작업을 한다.\n                                       이정도면 귀신이다.",
    "        본인은 정말 잘한다고 생각한다.\n                      이운석 교수님과 이상현 교수님도 그렇게 생각하실까?",
    "    회사에선 오랜만에 인재가 들어왔다고 한다.\n                                   하지만 본인은 회사가 별로다.",
    "            모든 능력을 탑재했다.\n                              이제 진짜 지옥을 향해 걸어간다."
};

int failure = 0;
int isTry = 0;                  // 강화 시도 여부 선택 변수
int choice;
bool isGameOver = false;        // 게임 종료 여부 변수
int tickets = 0;
int enhancement_cost = 0;
int dungeonSelect = 0;
int ZeroOneGangHwa = 0;

//축적 데이터를 쌓기 위한 강화 단계 설정 배열
int Levels[MAX_ENHANCEMENTStage1] = {
    1,2,3,4,5,
    6,7,8,9,10,
    11,12,13,14,15,
    16,17,18,19,20
};
// 강화 단계별 총 강화 시도 횟수
int Attempt[MAX_ENHANCEMENTStage1] = {
    1,1,1,1,1,
    1,1,1,1,1,
    1,1,1,1,1,
    1,1,1,1,1
};
// 강화 단계별 성공 횟수
int Success[MAX_ENHANCEMENTStage1] = {
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0
};
// 강화 단계별 실패 횟수
int Failure[MAX_ENHANCEMENTStage1] = {
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0
};
// 강화 단계별 복습권 구매 갯수
int TicketBuyLevels[MAX_ENHANCEMENTStage1] =
{
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0
};

int nickname_initial; // 닉네임
int currentDateTime; // 방문 시간
int endDateTime = 2; // 종료 시간
int level = 0; // 강화 단계
int attemptlevel = 0;
int TicketBuyLevels[MAX_ENHANCEMENTStage1]; // 단계별 구매 횟수
int attempt = 0; // 강화시도 횟수
int success = 0;  // 성공 횟수
int selling_count = 0; // 판매횟수 
int money = INITIAL_MONEY; // 현재 비용 
int numTickets = 0;
int realMoneyStore = 0; // 현질 상점

void Gopost()
{
    char command[2048];
    sprintf_s(command, sizeof(command),
        "curl -d \"{\\\"아이디\\\":\\\"%d\\\",\\\"접속시간\\\":\\\"%d\\\",\\\"종료시간\\\":\\\"%d\\\",\\\"강화단계\\\":\\\"%d\\\",\\\"단계별복습권구매갯수\\\":\\\"%d\\\",\\\"강화시도횟수\\\":\\\"%d\\\",\\\"판매횟수\\\":\\\"%d\\\",\\\"현재비용\\\":\\\"%d\\\"}\" https://script.google.com/macros/s/AKfycby2CBSun8_hCI4xYBzVQaLUKwMX5fUfFXL8sh6bS5CwxF8oyWIqyEl6jC31opBweO9m/exec",
        nickname_initial, currentDateTime, endDateTime, attemptlevel, tickets, attempt, selling_count, money);
    system(command);
    srand((unsigned int)time(NULL));         // 랜덤 시드값 설정 
}
// 강화 성공 확률 배열
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

// 강화 시도 비용 배열
int enhancementCosts[MAX_ENHANCEMENTStage1 + 1] = {
    20000, 30000, 40000, 50000, 60000,
    70000, 80000, 110000, 130000, 150000,
    200000, 250000, 350000, 500000, 600000,
    700000, 800000, 850000, 900000, 1000000,
};
// 각 강화 수치별로 실패 시 소모되는 복습권 갯수 배열
int failureTicketCosts[MAX_ENHANCEMENTStage1 + 1] = {
    0, 0, 1, 1, 1,
    1, 1, 1, 1, 2,
    2, 3, 4, 5, 7,
    10, 13, 17, 33, 50,
};
// 학생 급여 배열
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

// 학생 판매 함수
void sellStudent(int* level, int* money) {
    if (*level == 0) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("\n 아직 이지호 학생을 강화하지 않았습니다.\n");
    }
    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        printf("이지호 학생을 취업 시켰습니다. 이지호 학생이 큰 절을 하며 떠나갑니다.\n");
        *money += studentSalaries[*level];
        printf("현재 소지금에 %d원이 추가되었습니다.\n", studentSalaries[*level]);
        *level = 0; // 학생을 판매하면 레벨 초기화
    }
}

void GoStore() {
    printf("\n   상점으로 가고 있습니다.\n\n");
    Sleep(500);
    while (1) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
        printf(" * 학습 재화를 사용하여 아이템을 구매할 수 있습니다 *\n\n");
        printf(" * 1. 학생 판매 (학생 가치 : %d원)\n", studentSalaries[level]);
        printf(" * 2. 복습권 구매 (개당 20만)\n");
        printf(" * 3. 재단 지원받기\n");
        printf(" * 4. 메인화면 이동\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

        printf("\n * 아이템을 선택하세요 : ");
        int shopChoice;
        if (scanf_s("%d", &shopChoice) != 1) {
            printf("숫자를 입력하세요.\n");
            while (getchar() != '\n'); // 입력 버퍼 비우기
            continue; // 다시 입력 받기
        }
        while (getchar() != '\n'); // 입력 버퍼 비우기
        switch (shopChoice) {
        case 1:
            if (level > 0) {
                if (money < 0) {
                    money = 0;
                }
                printf("\n 강화한 레벨: + %d\n", level);
                printf("\n 판매 금액: %d원\n\n", studentSalaries[level]);
                money += studentSalaries[level];
                enhancementCosts; //현재 강화 비용
                selling_count++;
                level = 0;
                money;
            }
            else {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                printf(" \n 학생 레벨이 0이므로 학생 판매 옵션을 사용할 수 없습니다.\n\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            }
            break;
        case 2:
            printf(" \n 복습권을 몇 개 구매하시겠습니까? : ");
            int numTickets;
            if (scanf_s("%d", &numTickets) != 1 || numTickets <= 0) {
                printf("잘못된 입력입니다.\n");
                break;
            }
            while (getchar() != '\n'); // 입력 버퍼 비우기

            if (money < REVIEW_TICKET_COST * numTickets) {
                printf(" \n 재화가 부족하여 복습권을 구매할 수 없습니다.\n\n");
                break;
            }
            else {
                money -= REVIEW_TICKET_COST * numTickets;
                tickets += numTickets;
                printf(" \n 복습권을 %d개 구매하였습니다.\n", numTickets);
                printf("\n 보유 복습권 갯수 : %d개\n", tickets);
                printf(" \n 현재 소지금: %d원\n\n", money);
                TicketBuyLevels[level] += numTickets;
                printf("[%d강 단계에서 복습권 %d개 구입함!]\n\n", level, TicketBuyLevels[level]);
                break;
            }
        case 3:
            while (realMoneyStore != 5)
            {
                realMoneyStore = 0;
                printf("\n [재단에서 지원을 받아 소지금을 추가할 수 있습니다.]\n\n");
                printf(" * 1. 500만원 - 2,900원\n\n");
                printf(" * 5. 상점 나가기\n\n");
                printf(" 해당 선택지의 번호를 입력하세요. : ");
                scanf_s("%d", &realMoneyStore);
                if (realMoneyStore == 1)
                {
                    money += 5000000;
                    printf("\n\n 500만원을 충전했습니다!\n");
                }
                else if (realMoneyStore == 5) {
                    printf("\n\n 재단의 지원을 거절합니다...");
                }
                else
                {
                    printf("\n\n 잘못된 입력입니다.\n");
                    while (getchar() != '\n');
                }
            }
            break;
        case 4:
            isTry = 0;
            printf("\n 2초뒤에 상점에서 나갑니다....");
            return;// 상점 메뉴에서 빠져나감
        default:
            printf(" 잘못된 입력입니다.\n");
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
            printf("               < 줌의 달인 이상현 교수님 >");
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
            printf("\n    아트는 무슨 아트야... 개발도 못하는 것들이..\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf(" \n                  [ HP : %d ]\n", BossMobHP[0]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            printf(" \n { 나가기 : 0 }\n");
            printf("\n 교수님께 드리고 싶은 말씀을 입력하세요. \n\n=> ");
            PictureOn = 1;
        }
        attack = getchar();
        if (attack == '0') {
            printf(" \n 강의실을 나갑니다.\n");
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
    printf(" 됐어... 이제 너랑 얘기 안할꺼야...\n");
    tickets += 1;
    printf("\n");
    printf(" 보상으로 복습권 1개를 획득했습니다!\n");
    printf("\n");
    Sleep(1000);
    printf(" 면담 완료!\n");
    Sleep(1000);
    printf("\n 2초뒤에 던전에서 나갑니다....");
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
            printf("                 < 윤소미 교수님 >\n");
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
            printf("\n               하... 잠시만요...\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf(" \n                  [ HP : %d ]\n", BossMobHP[1]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            printf(" \n { 나가기 : 0 }\n");
            printf("\n 교수님께 드리고 싶은 말씀을 입력하세요.\n => ");
            PictureOn = 1;
        }
        attack = getchar();
        if (attack == '0') {
            printf(" \n 강의실을 나갑니다.\n");
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
    printf(" 다행히 수업이 어렵진 않았나 보네요 ^^\n");
    tickets += 3;
    printf("\n");
    printf(" 보상으로 복습권 3개를 획득했습니다!\n");
    printf("\n");
    Sleep(1000);
    printf(" 면담 완료!\n");
    Sleep(1000);
    printf("\n 2초뒤에 던전에서 나갑니다....");
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
            printf("             < 자소서 킬러 이은임 교수님 >       \n");
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
            printf("\n           괜찮아 다시 천천히 해와^^\n                (자기소개서를 반으로 찢으며)\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf(" \n                [ HP : %d ]\n", BossMobHP[2]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            printf(" \n { 나가기 : 0 }\n");
            printf("\n 교수님께 드리고 싶은 말씀을 입력하세요.\n => ");
            PictureOn = 1;
        }
        attack = getchar();
        if (attack == '0') {
            printf(" \n 강의실을 나갑니다.\n");
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
    printf(" 그래 고생했어~~~^^\n");
    tickets += 1;
    money += 2000000;
    printf("\n");
    printf("보상으로 복습권 10개와 200만원을 획득했습니다!\n");
    printf("\n");
    Sleep(1000);
    printf(" 면담 완료!\n");
    Sleep(1000);
    printf("\n 2초뒤에 던전에서 나갑니다....");
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
            printf("        < 좌표 충돌의 대가 이운석 교수님 >\n\n");
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
            printf("\n      초등학생도 아는걸 모르는 주제에......\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf(" \n                  [ HP : %d ]\n", BossMobHP[3]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            printf(" \n { 나가기 : 0 }\n");
            printf("\n 교수님께 드리고 싶은 말씀을 입력하세요.\n => ");
            PictureOn = 1;
        }
        attack = getchar();
        if (attack == '0') {
            printf(" \n 강의실을 나갑니다.\n");
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
    printf(" 으어어얽...난 이제 안녕 못 해...\n");
    money += 10000000;
    tickets += 50;
    printf("\n");
    printf("보상으로 복습권 50개와 1000만원을 획득했습니다!\n");
    Sleep(1000);
    printf("\n");
    printf(" 면담 완료!\n");
    Sleep(1000);
    printf("\n 2초뒤에 던전에서 나갑니다....");
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
            printf("                   < 기적의 코드 김영천 교수님 >\n");
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
            printf("\n     나는 이해가 안돼... 왜 이리 노력들을 안하는 거야...\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf(" \n                        [ HP : %d ]\n", BossMobHP[4]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            printf(" \n { 나가기 : 0 }\n");
            printf("\n 교수님께 드리고 싶은 말씀을 입력하세요.\n => ");
            PictureOn = 1;
        }
        attack = getchar();
        if (attack == '0') {
            printf(" \n 강의실을 나갑니다.\n");
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
    printf(" 그래... 우리 모범생... 고생 많았다.\n\n");
    Sleep(2000);
    printf(" 게임 완료!\n\n");
    Sleep(2000);
    printf(" 저희 게임을 플레이해주셔서 감사합니다!\n\n");
    Sleep(2000);
    printf(" *********** 게임 클리어 ***********\n");
    printf(" 게임을 끝까지 클리어하셨다면 cmd창을\n 컴퓨터의 현재 시간, 날짜와 같이 나오게 캡쳐해서 보내주시면\n 음료수 기프티콘을 보내드립니다!\n [(010-9580-1369)로 연락주세요!]\n");
    printf(" *********** 게임 클리어 ***********\n\n");
    Sleep(120000);
    printf("고생하셨습니다!");
    isGameOver = true;
    return 0;
}
int main(void)
{
    system("@cls||clear");
    system("mode con cols=122 | title 이지호 키우기");
    // 콘솔 창 크기 조절
    srand((unsigned int)time(NULL));  // 랜덤 시드값 설정
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    printf("\n");
    printf("   ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("   ┃                                                                                                                 ┃\n");
    printf("   ┃                               과연...! 이지호 학생은 무사히 졸업 할 수 있을 것 인가...                          ┃\n");
    printf("   ┃                                                                                                                 ┃\n");
    printf("   ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n");
    printf("   ┃                                                                                                                 ┃\n");
    printf("   ┃                                                                                                                 ┃\n");
    printf("   ┃                                                                                                                 ┃\n");
    printf("   ┃                                                                                                                 ┃\n");
    printf("   ┃                                                                                                                 ┃\n");
    printf("   ┃                                                                                                                 ┃\n");
    printf("   ┃                                                                                                                 ┃\n");
    printf("   ┃                                                                                                                 ┃\n");
    printf("   ┃                                                                                                                 ┃\n");
    printf("   ┃                  ______         _       _                 _                     ___  _  _                       ┃\n");
    printf("   ┃                  | ___ \\       (_)     (_)               | |                   |_  |(_)| |                      ┃\n");
    printf("   ┃                  | |_/ /  __ _  _  ___  _  _ __    __ _  | |      ___   ___      | | _ | |__    ___             ┃\n");
    printf("   ┃                  |    /  / _` || |/ __|| || '_ \\  / _` | | |     / _ \\ / _ \\     | || || '_ \\  / _ \\            ┃\n");
    printf("   ┃                  | |\\ \\ | (_| || |\\__ \\| || | | || (_| | | |____|  __/|  __/ /\\__/ /| || | | || (_) |           ┃\n");
    printf("   ┃                  \\_| \\_| \\__,_||_||___/|_||_| |_| \\__, | \\_____/ \\___| \\___| \\____/ |_||_| |_| \\___/            ┃\n");
    printf("   ┃                                                    __/ |                                                        ┃\n");
    printf("   ┃                                                   |___/                                                         ┃\n");
    printf("   ┃                                                                                                                 ┃\n");
    printf("   ┃                                                                                                                 ┃\n");
    printf("   ┃                                                                                                                 ┃\n");
    printf("   ┃                                                                                                                 ┃\n");
    printf("   ┃                                                                                                                 ┃\n");
    printf("   ┃                                                                                                                 ┃\n");
    printf("   ┃                                                                                                                 ┃\n");
    printf("   ┃                                                                                                                 ┃\n");
    printf("   ┃                                                                                                        Ver 1.0  ┃\n");
    printf("   ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf("                                                                                                                      \n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    printf("                                           ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("                                           ┃    학번으로 로그인 해 주세요!!   ┃\n");
    printf("                                           ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n");
    printf("                                                     ID : ");
    scanf_s("%d", &nickname_initial);
    while (!isGameOver)
    {
        system("@cls||clear");      // 화면 정리
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        system("@cls||clear");      // 화면 정리
        printf("\n");
        printf("  ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
        printf("  ┃                                                                                    ┃                             ┃\n");
        printf("  ┃                                                                                    ┃         information         ┃\n");
        printf("  ┃                                                                                    ┃                             ┃\n");
        printf("  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
        printf("                                                                                       ┃ 학습 성공률 : %.2f%%\n", enhancementProbabilitiesStage1[level]);
        printf("                                                                                       ┃  학습 비용  : %d원\n", enhancementCosts[level]);
        printf("                                                                                       ┃ 요구 복습권 : %d개\n", tickets);
        printf("                                                                                       ┃ 보유 복습권 : %d개\n", failureTicketCosts[level]);
        printf("                                                                                       ┃ 현재 소지금 : %d원\n", money);
        printf("                                                                                       ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("                        %s\n", enhancementMessages2[level]);
        printf("\n");
        printf("                                +% d % s\n\n                                     + 학습 파워 :% d\n", level, enhancementMessages1[level], JihoPower[level]);
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("   ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
        printf("   ┃                                < 선 택 해 라 >                                    ┃          회원 정보          ┃\n");
        printf("   ┃                                                                                   ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
        printf("   ┃        1. 학습 하기      2. 상점 가기      3. 면담 신청      4. 자퇴 하기                    %d         \n", nickname_initial);
        printf("   ┃                                                                                   ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
        printf("   ┃                                                                                   ┃     Homework is my Life     ┃\n");
        printf("   ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
        printf("                                                                                         %d강 -> %d강 %d차 시도 중...\n", level, level + 1, Attempt[level]);
        isTry = 0;
        printf("    당신의 선택은? : ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        scanf_s("%d", &isTry);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        switch (isTry)
        {
        case 1:     // 강화에 도전 할 경우
            // 돈이 부족하면 메시지 출력 후 break
            if (money < enhancementCosts[level]) {
                printf("돈이 부족하여 공부 할 수 없습니다.\n");
                break;
            }
            printf("\n  *** 학습중 *** \n\n");
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
                level++;// 강화에 성공 했을 시, 레벨을 하나 증가 시킴
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
                    printf("\n 어익후.. 핸드폰을 봤네..교수님이 봐버렸다...\n");
                    printf("\n [+%d 지식을 잃었습니다.]\n\n", level);
                    attemptlevel = level;
                    for (int i = 0; i < 20; i++) { // 강화 실패 횟수 데이터 수집
                        if (level == Levels[i]) {
                            attempt++;
                            break;
                        }
                    }
                    printf("\n [%d강 강화 실패 횟수 : %d]\n", level, Failure[level]);

                    if (tickets > 0) {
                        int ticketsToUse = failureTicketCosts[level]; // 실패 시 소모될 복습권의 수
                        money -= enhancementCosts[level];
                        printf("학습에 실패하였습니다. \n현재 학습 수치를 유지하시겠습니까? \n소모되는 복습권은 %d개 입니다.\n{보유 학습권 갯수 : %d}\n(YES : 1/ NO : 2) : ", ticketsToUse, tickets);
                        while (true) {
                            choice = 0;
                            scanf_s("%d", &choice);
                            while (getchar() != '\n');  // 입력 버퍼 클리어
                            if (ticketsToUse <= tickets && choice == 1) {
                                tickets -= ticketsToUse; // 실패 시 소모되는 복습권 갯수 적용
                                printf("\n복습권을 사용합니다. (보유 복습권 갯수 : %d)\n", tickets);
                                money += enhancementCosts[level];


                                break;  // 유효한 입력을 받았으므로 반복문 종료
                            }
                            else if (choice == 2) {
                                printf("학습 수치를 초기화합니다.\n");
                                level = 0; // 강화 수치 초기화
                                TicketBuyLevels[level] = 0;
                                attempt + 1;
                                break;  // 유효한 입력을 받았으므로 반복문 종료
                            }
                            else {
                                printf("잘못된 입력 했거나 복습권이 모자랍니다 다시 선택 하세요! (YES : 1 / NO : 2) : ");
                            }
                        }
                    }
                    else {
                        printf("복습권이 없어 학습 수치를 초기화합니다.\n");
                        level = 0;  // 복습권이 없으므로 레벨을 초기화
                    }
                }
                else {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                    printf(" ***** MAX LEVEL *****\n");
                    printf(" 최고 강화 단계입니다. \n");
                    printf(" ***** MAX LEVEL *****\n");
                }
            }
            // 강화 비용 차감
            break;
        case 2:
            GoStore();
            break;
        case 3:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            printf("   ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
            printf("   ┃  이곳은 교수님과 함께하는 면담실 입니다 면담을 완료하면 다양한 보상이 주어집니다! ┃        < 추천 면담 >        ┃\n");
            printf("   ┃                                                                                   ┃                             ┃\n");
            printf("   ┃         1. 이상현 교수님과 면담                    2. 윤소미 교수님과 면담        ┃1강  ~ 11강 => 이상현 교수님 ┃\n");
            printf("   ┃                                                                                   ┃12강 ~ 14강 => 윤소미 교수님 ┃\n");
            printf("   ┃         3. 이은임 교수님과 면담                    4. 이운석 교수님과 면담        ┃15강 ~ 17강 => 이은임 교수님 ┃\n");
            printf("   ┃                                                                                   ┃18강 ~ 19강 => 이운석 교수님 ┃\n");
            printf("   ┃                              5.  김영천 교수님과 면담                             ┃    20강    => 김영천 교수님 ┃\n");
            printf("   ┃                                                                                   ┃                             ┃\n");
            printf("   ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
            printf("   메인화면으로 나가기 - [ 1~5를 제외한 모든 입력키 ]\n\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            printf("   면담하고 싶은 교수님의 번호를 입력하세요 : ");
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
                printf("잘못된 입력입니. 다시 선택하세요.\n");
                break;
            }
            break;
        case 4:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf("\n 이런! 이지호 학생이 자퇴 했습니다 이제 어쩌죠...?\n");
            endDateTime = 1;
            isGameOver = true; // 게임 종료
            break;
        default:
            printf("잘못된 입력입니다. 다시 선택하세요.\n"); // 엔터 눌러야지 나가기.
            while (getchar() != '\n'); // 입력 버퍼 비우기
            break;
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        Gopost();
    }
    return 0;
}