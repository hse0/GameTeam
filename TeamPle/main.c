#define _CRT_SECURE_NO_WARNINGS
#define MAX_DATETIME_LENGTH 20
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>
#include <windows.h>
#define MAX_ENHANCEMENTStage1 20
#define WAIT_TIME 0.5
#define INITIAL_MONEY 200000000
#define ENHANCEMENT_THRESHOLD 10
#define REVIEW_TICKET_COST 200000
#define BOSSLEVEL 5

char* enhancementMessages1[] = {
    "병아리 신입생 이지호(세상의 때가 묻지 않은 야생의 지호가 등장했다!)",
    "C언어를 배운 1학년 이지호(김영천 교수님께 칭찬을 받은 귀여운 1학년이다.)",
    "HTML5를 배운 1학년 이지호(이은임 교수님의 사랑을 받는 1학년이다.)",
    "포토샵을 배운 1학년 이지호(노연석 교수님께서 매우 만족하신다.)",
    "파이썬을 배운 1학년 이지호(이운석 교수님께 욕을 많이 먹었다. 슬슬 사람이 이상해진다.)",
    "JavaScript를 배운 1학년 이지호(이은임 교수님께선 큰 신뢰를 걸고 계신다.)",
    "C언어응용을 배운 1학년 이지호(김영천 교수님께 혼났다. 분명 C언어를 배웠는데...??)",
    "유니티를 배운 2학년 이지호(이상현 교수님께서 걱정하신다. 원래 착했던 애가 이상해지고 있다...)",
    "C# 프로그래밍을 배운 2학년 이지호(윤소미 교수님께서 좋아하신다. 다행히 아직 초반이라...)",
    "앱기획을 배운 2학년 이지호(김영천 교수님께 맞기 직전까지 갔다. 한강물의 온도가 궁금하다...)",
    "현타가 온 이지호(교수님께 혼나고, 과제에 치이고... 지호의 눈앞에 눈물이 글썽인다.)",
    "반응형웹을 배운 2학년 이지호(이운석 교수님께서 좋아하신다. 잠을 자지 않고 과제를 끝냈다.)",
    "C++을 배운 2학년 이지호(이제 C계얼 언어를 다 배웠다. 근데 포인터는 도저히 이해가 안된다...)",
    "유니티로 게임을 개발한 3학년 이지호(코피를 흘려가며 게임을 만들었다. 이상현 교수님께서 \"이게 게임이 맞나\"라고 하셨다.)",
    "HTML과 CSS로 웹을 만들어 본 3학년 이지호(이은임 교수님께 잔소리를 많이 들었다. 그래도 내심 교수님께서 기특해하신다.)",
    "전공동아리 멘토를 하는 3학년 이지호(후배들의 존경을 받고 있다. 이운석 교수님과 이상현 교수님도 그렇게 생각하실까?)",
    "3D모델링을 배운 3학년 이지호(노연석 교수님과 1대1 면담을 했다. 아트도 괜찮은 것 같은데... 어디로 갈지 모르겠다.)",
    "창업동아리를 하는 3학년 이지호(매일 학교에 밤 10시까지 후배, 동기들과 같이 작업을 한다. 이정도면 귀신이다.)",
    "기획서 작성을 마스터한 3학년 이지호(본인은 정말 잘한다고 생각한다. 이운석 교수님과 이상현 교수님도 그렇게 생각하실까?)",
    "현장 실습을 다녀온 3학년 이지호(회사에선 오랜만에 인재가 들어왔다고 한다. 하지만 본인은 회사가 별로다.)",
    "졸업 가운을 입고 있는 이지호(모든 능력을 탑재했다. 이제 진짜 지옥을 향해 걸어간다.)"
};

int  failure = 0;
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
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0
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

// 강화시도
char nickname_initial; // 닉네임
char currentDateTime[MAX_DATETIME_LENGTH]; // 방문 시간
char endDateTime[MAX_DATETIME_LENGTH]; // 종료 시간
int level = 0; // 강화 단계
int TicketBuyLevels[MAX_ENHANCEMENTStage1]; // 단계별 구매 횟수
int attempt = 0; // 강화시도 횟수
int success = 0;  // 성공 횟수
int selling_count = 0; // 판매횟수 
int money = INITIAL_MONEY; // 현재 비용 
int numTickets = 0;


// 복습권 사용 갯수 변수 설정해주기




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
    printf("\n *** 상점으로 이동 ***\n\n");
    Sleep(500);
    while (1) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
        printf(" * 학습 재화를 사용하여 아이템을 구매할 수 있습니다 *\n\n");
        printf(" * 1. 학생 판매 (학생 가치 : %d원)\n", studentSalaries[level]);
        printf(" * 2. 복습권 구매 (개당 20만)\n");
        printf(" * 3. 메인화면 이동\n");
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
                attempt = 0;
                failure = 0;
                success = 0;
                enhancementCosts; //현재 강화 비용
                selling_count++;
                level = 0;
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
            isTry = 0;
            return;// 상점 메뉴에서 빠져나감
        default:
            printf(" 잘못된 입력입니다.\n");
            break;
        }
    }
}
void Dungeon1() {
    BossMobHP[0] = 5000;
    int enterPressed = 0;
    printf("                         ..=~                     \n");
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
    printf("\n 이상현 교수님 : 아트는 무슨 아트야... 개발도 못하는 것들이..\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    printf(" \n                  [ HP : %d ]\n", BossMobHP[0]);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    printf(" \n { 나가기 : 0 }\n");
    while (1) {
        SHORT keyState = GetAsyncKeyState(VK_RETURN);
        int pressed = keyState & 0x8000;             
        if (enterPressed && !pressed)
        {
            BossMobHP[0] -= JihoPower[level];
            printf("                         ..=~                     \n");
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
            printf("\n 이상현 교수님 : 아트는 무슨 아트야... 개발도 못하는 것들이..\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf(" \n                  [ HP : %d ]\n", BossMobHP[0]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            printf(" \n { 나가기 : 0 }\n");                            
        }
        enterPressed = pressed;
        if (GetAsyncKeyState('0') & 0x8000) {
            printf(" \n 강의실을 나갑니다.\n");
            BossMobHP[0] = 5000;
            return 0;
        }
        if (BossMobHP[0] <= 0)
        {
            break;
        }
        Sleep(10);
    }
    printf(" 됐어... 이제 너랑 얘기 안할꺼야...\n");
    tickets += 1;
    printf("\n");
    printf("보상으로 복습권 1개를 획득했습니다!\n");
    printf("\n");
    printf(" 면담 완료!\n");
    Sleep(1000);
    return 0;
}
void Dungeon2() {
    BossMobHP[1] = 50000;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    printf("\n");
    printf("                    .,,,,. .,,                     \n");
    printf("                   :=####*!*$$*-                   \n");
    printf("                  ###########=##!                  \n");
    printf("                -=#####@@@@##$###;                 \n");
    printf("               ~*########@########*                \n");
    printf("              ,!$#######@###$#####$:               \n");
    printf("             :!==$$####$!:~--:*$####-              \n");
    printf("            ,!**=$###$$;-,,,,-:=#####              \n");
    printf("            :*=*==$$$$!-....,,~!$####-             \n");
    printf("           .!==**====*-.....,,-:=####=             \n");
    printf("           -=$***=*==:,. ...,,--*###$=             \n");
    printf("           ~$$!*****!~......,,,-;$##$=,            \n");
    printf("           !$**!=*=!~.......,,,-~*###$~            \n");
    printf("           !=***=**;,.......,,,--;$##$-            \n");
    printf("           *=**=*$=;,.....,-~~~~~:=##$~            \n");
    printf("           ~*==*$=!:~-,,.,--------;=$*             \n");
    printf("           ~*==*$=;---,,.,---**~--~*$!.            \n");
    printf("           .;$$==**$$~-,.,-~,=!;:--!=;.            \n");
    printf("           ,*$=*;!~;~-,. .,,-,-----;=-             \n");
    printf("           .:$*;-----,.. .,,,,,,,,,~!-             \n");
    printf("             *;,,....... .,,,,,...,-:-             \n");
    printf("            ,*-............,,.....,,--,             \n");
    printf("             ........,. .,,--,,.,,,,-              \n");
    printf("             ..........:-,--,,,,,,,-               \n");
    printf("              .  ...... ..,,,,,,,-,-               \n");
    printf("              .. ...... ...,------,-               \n");
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
    printf("    ::!:~:!=!;*$$#;,,..,,,,,,,,,--~;=$=$$#$===$=$*:\n");
    printf("   ;;!*:::!*;*$$#;,,..,,,,,,,,,,-~:!!=$$#$===$====\n");
    printf("~!;;!!*!:;**!!=$#:,,...,,,,,,,,,---::**=$$=$$$$===\n");
    printf("*!:!!=*!;;!!!**$#;,,....,,,..,,,-,-~~****==$$#$===\n");
    printf("!!;*!$*=;;!!!!!=@:,.. ..... ..,,,,,-~=*===$$$$$$==\n");
    printf("\n 윤소미 교수님 : 하... 잠시만요...\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    printf(" \n                  [ HP : %d ]\n", BossMobHP[1]);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    int messageDisplayed = 0;
    int numberDisplayed = 1;
    while (BossMobHP[1] > 0) {
        char input = getchar();
        if (!numberDisplayed) {
            printf("                    .,,,,. .,,                     \n");
            printf("                   :=####*!*$$*-                   \n");
            printf("                  ###########=##!                  \n");
            printf("                -=#####@@@@##$###;                 \n");
            printf("               ~*########@########*                \n");
            printf("              ,!$#######@###$#####$:               \n");
            printf("             :!==$$####$!:~--:*$####-              \n");
            printf("            ,!**=$###$$;-,,,,-:=#####              \n");
            printf("            :*=*==$$$$!-....,,~!$####-             \n");
            printf("           .!==**====*-.....,,-:=####=             \n");
            printf("           -=$***=*==:,. ...,,--*###$=             \n");
            printf("           ~$$!*****!~......,,,-;$##$=,            \n");
            printf("           !$**!=*=!~.......,,,-~*###$~            \n");
            printf("           !=***=**;,.......,,,--;$##$-            \n");
            printf("           *=**=*$=;,.....,-~~~~~:=##$~            \n");
            printf("           ~*==*$=!:~-,,.,--------;=$*             \n");
            printf("           ~*==*$=;---,,.,---**~--~*$!.            \n");
            printf("           .;$$==**$$~-,.,-~,=!;:--!=;.            \n");
            printf("           ,*$=*;!~;~-,. .,,-,-----;=-             \n");
            printf("           .:$*;-----,.. .,,,,,,,,,~!-             \n");
            printf("             *;,,....... .,,,,,...,-:-             \n");
            printf("            ,*-............,,.....,,--,             \n");
            printf("             ........,. .,,--,,.,,,,-              \n");
            printf("             ..........:-,--,,,,,,,-               \n");
            printf("              .  ...... ..,,,,,,,-,-               \n");
            printf("              .. ...... ...,------,-               \n");
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
            printf("    ::!:~:!=!;*$$#;,,..,,,,,,,,,--~;=$=$$#$===$=$*:\n");
            printf("   ;;!*:::!*;*$$#;,,..,,,,,,,,,,-~:!!=$$#$===$====\n");
            printf("~!;;!!*!:;**!!=$#:,,...,,,,,,,,,---::**=$$=$$$$===\n");
            printf("*!:!!=*!;;!!!**$#;,,....,,,..,,,-,-~~****==$$#$===\n");
            printf("!!;*!$*=;;!!!!!=@:,.. ..... ..,,,,,-~=*===$$$$$$==\n");
            printf("\n 윤소미 교수님 : 하... 잠시만요...\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf(" \n                  [ HP : %d ]\n ", BossMobHP[1]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            printf(" \n { 나가기 : 0 }\n"); // 나가기 스페이스바 누르면 한번더 실행 고치기. 모든 Dungeon
            numberDisplayed = 1;
        }
        if (input == '0') {
            printf(" \n 강의실을 나갑니다.\n");
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
                printf("\n 다시 입력해주세요.\n");
                printf(" {나가기 : 0 }\n");
                messageDisplayed = 1;
            }
        }
    }
    printf(" 다행히 수업이 어렵진 않았나 보네요 ^^\n");
    tickets += 3;
    printf("\n");
    printf("보상으로 복습권 3개를 획득했습니다!\n");
    printf("\n");
    printf(" 면담 완료!\n");
    Sleep(1000);
    return 0;
}
void Dungeon3() {
    BossMobHP[2] = 250000;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    printf("\n");
    printf("                                                  \n");
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
    printf("\n 이은임 교수님 : 괜찮아 다시 천천히 해와^^ (자기소개서를 반으로 찟으시면서)\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    printf(" \n                [ HP : %d ]\n", BossMobHP[2]);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    int messageDisplayed = 0;
    int numberDisplayed = 1;
    while (BossMobHP[2] > 0) {
        char input = getchar();
        if (!numberDisplayed) {
            printf("                                                  \n");
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
            printf("\n 이은임 교수님 : 괜찮아 다시 천천히 해와^^ (자기소개서를 반으로 찟으시면서)\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf(" \n                [ HP : %d ]\n", BossMobHP[2]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            printf(" \n { 나가기 : 0 }\n");
            numberDisplayed = 1;
        }
        if (input == '0') {
            printf(" \n 강의실을 나갑니다.\n");
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
                printf(" 다시 입력해주세요.\n");
                printf(" { 나가기 : 0 }\n");
                messageDisplayed = 1;
            }
        }
    }
    printf(" 그래 고생했어~~~^^\n");
    tickets += 1;
    money += 2000000;
    printf("\n");
    printf("보상으로 복습권 10개와 200만원을 획득했습니다!\n");
    printf("\n");
    printf(" 면담 완료!\n");
    Sleep(1000);
    return 0;
}
void Dungeon4() {
    BossMobHP[3] = 1000000;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    printf("\n");
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
    printf("\n 이운석 교수님 : 초등학생도 아는걸 모르는 주제에......\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    printf(" \n                  [ HP : %d ]\n", BossMobHP[3]);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    int messageDisplayed = 0;
    int numberDisplayed = 1;
    while (BossMobHP[3] > 0) {
        char input = getchar();
        if (!numberDisplayed) {
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
            printf("\n 이운석 교수님 : 초등학생도 아는걸 모르는 주제에......\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf(" \n                  [ HP : %d ]\n", BossMobHP[3]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            printf(" \n { 나가기 : 0 }\n");
            numberDisplayed = 1;
        }
        if (input == '0') {
            printf(" \n 강의실을 나갑니다.\n");
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
                printf(" 다시 입력해주세요.\n");
                printf(" { 나가기 : 0 }\n");
                messageDisplayed = 1;
            }
        }
    }
    printf(" 으어어얽...난 이제 안녕 못 해...\n");
    money += 10000000;
    tickets += 50;
    printf("\n");
    printf("보상으로 복습권 50개와 1000만원을 획득했습니다!\n");
    printf("\n");
    printf(" 면담 완료!\n");
    Sleep(1000);
    return 0;
}
void Dungeon5() {
    BossMobHP[4] = 5000000;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    printf("\n");
    printf("                               .. .,                                  \n");
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
    printf("            ~$$##$$*$###$$##**$$=====#!*$===!$=#$;!*                      \n");
    printf("            !#####*==$$##$$**=$===$*!!#*$*==*$=$$=*!                       \n");
    printf("            ;$###=$$##$=@!$==$$===!=!;:!*$=;*$$=$$$=~                      \n");
    printf("            !#$$#=$$$$=$$$$===##*$$==!:;!==!*#$=$==*!                      \n");
    printf("            ;##$#$*=$$$$=##=$$=!*===$*;~*$=*!$*!*=!=*~                     \n");
    printf("\n 김영천 교수님 : 나는 이해가 안돼... 왜 이리 노력들을 안하는 거야...\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    printf(" \n                    [ HP : %d ]\n", BossMobHP[4]);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    int messageDisplayed = 0;
    int numberDisplayed = 1;
    while (BossMobHP[4] > 0) {
        char input = getchar();
        if (!numberDisplayed) {
            printf("                               .. .,                                  \n");
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
            printf("            ~$$##$$*$###$$##**$$=====#!*$===!$=#$;!*                      \n");
            printf("            !#####*==$$##$$**=$===$*!!#*$*==*$=$$=*!                       \n");
            printf("            ;$###=$$##$=@!$==$$===!=!;:!*$=;*$$=$$$=~                      \n");
            printf("            !#$$#=$$$$=$$$$===##*$$==!:;!==!*#$=$==*!                      \n");
            printf("            ;##$#$*=$$$$=##=$$=!*===$*;~*$=*!$*!*=!=*~                     \n");
            printf("\n 김영천 교수님 : 나는 이해가 안돼... 왜 이리 노력들을 안하는 거야...\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf(" \n                    [ HP : %d ]\n", BossMobHP[4]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            printf(" \n { 나가기 : 0 }\n");
            numberDisplayed = 1;
        }
        if (input == '0') {
            printf(" \n 강의실을 나갑니다.\n");
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
                printf(" 다시 입력해주세요.\n");
                printf(" { 나가기 : 0 }\n");
                messageDisplayed = 1;
            }
        }
    }
    printf(" 그래... 우리 모범생... 고생 많았다.\n");
    Sleep(2000);
    printf(" 게임 완료!\n");
    Sleep(2000);
    printf("저희 게임을 플레이해주셔서 감사합니다!");
    Sleep(2000);
    isGameOver = true;
    return 0;
}

int main(void)
{

    srand((unsigned int)time(NULL));  // 랜덤 시드값 설정
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    char nickname_initial[100];  // 닉네임을 저장할 배열

    printf("\n");
    printf("  #          ##       ###      ###    #    #\n");
    printf("  #         #  #     #   #      #     ##   #\n");
    printf("  #        #    #   #           #     # #  #\n");
    printf("  #        #    #   #  ###      #     #  # #\n");
    printf("  #        #    #   #    #      #     #   ##\n");
    printf("  #         #  #     #   #      #     #    #\n");
    printf("  ######     ##       ###      ###    #    #\n\n\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    printf("        [ ID 란에 학번을 입력해주세요 ]  ");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                 ID : ");
    fgets(nickname_initial, sizeof(nickname_initial), stdin);  // 사용자로부터 닉네임 입력 받기
    nickname_initial[strcspn(nickname_initial, "\n")] = 0;  // fgets는 개행 문자까지 읽기 때문에 문자열 끝에서 개행 문자 제거       

    while (!isGameOver)
    {
        system("@cls||clear");      // 화면 정리
        system("title 이지호 학생 키우기");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        printf(" ** 이지호 학생 키우기 **  \n\n");
        // 상태 출력
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        printf(" 학생 레벨 : + %d %s (파워 : %d)\n", level, enhancementMessages1[level], JihoPower[level]);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        printf(" \n 현재 소지금 : %d원\n", money);
        printf(" 학습 비용 : %d원\n", enhancementCosts[level]);
        printf(" 학습 성공률 : %.2f%%\n", enhancementProbabilitiesStage1[level]);
        printf(" \n 보유 복습권 갯수 : %d\n", tickets);
        printf(" 요구 복습권 수 : %d개", failureTicketCosts[level]);

        if (level == 0)
        {
            ZeroOneGangHwa++;
            printf("\n {%d강 -> %d강 %d차 시도 중...}\n", level, level + 1, ZeroOneGangHwa);

        }
        else if (level == 20)
        {
            printf("\n {최고 강화 단계 달성!!!}\n");
        }
        else
        {
            printf("\n {%d강 -> %d강 %d차 시도 중...}\n", level, level + 1, Attempt[level]);
        }

        printf(" \n 메뉴:\n\n");
        printf(" * 1. 학생 강화하기\n");
        printf(" * 2. 상점가기\n");
        printf(" * 3. 강의실가기\n");
        printf(" * 4. 포기하기\n\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        printf("\n * 메뉴를 선택하세요 : ");
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
            float randNum = rand() % 101;
            if (randNum < enhancementProbabilitiesStage1[level]) {
                money -= enhancementCosts[level];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                printf(" ***** SUCCESS *****\n");
                printf("                  \n");
                printf("    + %d  -> + %d \n", level, level + 1);
                printf("                  \n");
                printf(" ***** SUCCESS *****\n");
                level++;// 강화에 성공 했을 시, 레벨을 하나 증가 시킴
                for (int i = 0; i < 20; i++) // 강화 성공 횟수 데이터 수집
                {
                    if (level == Levels[i])
                    {
                        Success[level] += 1;
                        break;
                    }
                }
                printf("\n [%d강 강화 성공 횟수 : %d]\n", level, Success[level]);
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
                    for (int i = 0; i < 20; i++) { // 강화 실패 횟수 데이터 수집
                        if (level == Levels[i]) {
                            Failure[level] += 1;
                            break;
                        }
                    }
                    printf("\n [%d강 강화 실패 횟수 : %d]\n", level, Failure[level]);

                    if (tickets > 0) {
                        choice = 0;
                        int ticketsToUse = failureTicketCosts[level]; // 실패 시 소모될 복습권의 수
                        money -= enhancementCosts[level];
                        printf(" 학습에 실패하였습니다. \n\n 현재 학습 수치를 유지하시겠습니까? \n 소모되는 복습권은 %d개 입니다.\n {보유 학습권 갯수 : %d}\n\n (YES : 1/ NO : 2) : ", ticketsToUse, tickets);
                        while (true) {
                            scanf_s("%d", &choice);
                            while (getchar() != '\n');  // 입력 버퍼 클리어
                            if (ticketsToUse <= tickets && choice == 1)
                            {
                                tickets -= ticketsToUse; // 실패 시 소모되는 복습권 갯수 적용
                                printf("\n 복습권을 사용합니다. (보유 복습권 갯수 : %d)\n", tickets);
                                money += enhancementCosts[level];
                                break;  // 유효한 입력을 받았으므로 반복문 종료
                            }
                            else if (choice == 2) {
                                printf(" 학습 수치를 초기화합니다.\n");
                                level = 0; // 강화 수치 초기화
                                break;  // 유효한 입력을 받았으므로 반복문 종료
                            }
                            else {
                                printf("\n\n 잘못된 입력을 했거나 복습권이 모자랍니다 다시 선택 하세요!\n (YES : 1 / NO : 2) : ");
                            }
                        }
                    }
                    if (tickets <= 0)
                    {
                        printf(" 복습권이 없어 학습 수치를 초기화합니다.\n");
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
            printf("\n 계속하려면 아무 키나 누르세요! \n");
            // 강화 비용 차감
            break;
        case 2:
            GoStore();
            break;
        case 3:
            printf("\n *** 강의실로 이동 ***\n\n");
            // Sleep(2000);
            printf("\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            printf(" 이곳은 강의실입니다. 교수님들과 면담을 할 수 있습니다.\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            printf("\n 1. 이상현 교수님\n");
            printf(" 2. 윤소미 교수님\n");
            printf(" 3. 이은임 교수님\n");
            printf(" 4. 이운석 교수님\n");
            printf(" 5. 김영천 교수님\n\n");
            printf(" 메인화면으로 나가기 - [ 1~5를 제외한 모든 입력키 ]\n\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            printf(" 면담하고 싶은 교수님의 번호를 입력하세요 : ");
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
                printf("잘못된 입력입니다. 다시 선택하세요.\n");
                break;
            }
            break;
        case 4:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf("\n 이런! 이지호 학생이 자퇴 했습니다 이제 어쩌죠...?\n");

            isGameOver = true; // 게임 종료
            break;
        default:
            printf("잘못된 입력입니다. 다시 선택하세요.\n"); // 엔터 눌러야지 나가기.
            break;
        }
        /*Sleep(1000);*/
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

        // 사용자 입력 대기
        while (getchar() != '\n'); // 버퍼 비우기

        char command[2048];

        void sendToGoogleSheet(const char* nickname_initial, const char* currentDateTime, const char* endDateTime, int level, int TicketBuyLevels[], int attempt, int success, int selling_count, int money); {
            // TicketBuyLevels 배열을 문자열로 변환
            char TicketBuyLevelsStr[512] = "";
            for (int i = 0; i < sizeof(TicketBuyLevels) / sizeof(TicketBuyLevels[0]); i++) {
                char temp[32];
                sprintf(temp, "%d", TicketBuyLevels[i]);
                strcat(TicketBuyLevelsStr, temp);
                if (i < sizeof(TicketBuyLevels) / sizeof(TicketBuyLevels[0]) - 1) {
                    strcat(TicketBuyLevelsStr, ",");
                }
            }

            // curl 명령어 생성
            sprintf_s(command, sizeof(command),
                "curl -d \"{\\\"아이디\\\":\\\"%s\\\",\\\"접속시간\\\":\\\"%s\\\",\\\"종료시간\\\":\\\"%s\\\",\\\"강화 단계\\\":\\\"%d\\\",\\\"단계별 복습권 구매갯수\\\":\\\"%s\\\",\\\"강화시도횟수\\\":\\\"%d\\\",\\\"성공 횟수\\\":\\\"%d\\\",\\\"판매 횟수\\\":\\\"%d\\\",\\\"현재 비용\\\":\\\"%d\\\"}\" https://script.google.com/macros/s/AKfycbxg6gLqurtAF9Izw3c34JwhPGiau-MElKPU27mUe3Dh15P6_fJdRLHRyPv9A17cXQAt/\\exec",
                nickname_initial, currentDateTime, endDateTime, level, TicketBuyLevelsStr, attempt, success, selling_count, money);

            // curl 명령어 실행
            system(command);

            // 랜덤 시드값 설정 
            srand((unsigned int)time(NULL));
        }

    }
    return 0;
}