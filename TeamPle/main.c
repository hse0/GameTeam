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
    "병아리 신입생(세상의 때가 묻지 않은 귀여운 신입생이 등장했다!)",
    "C언어를 배운 1학년(김영철 교수님께 칭찬을 받은 귀여운 1학년이다.)",
    "HTML5를 배운 1학년(이윤임 교수님의 사랑을 받는 1학년이다.)",
    "포토샵을 배운 1학년(노은석 교수님께서 매우 만족하신다.)",
    "파이썬을 배운 1학년(이은석 교수님께 욕을 많이 먹었다. 슬슬 사람이 이상해진다.)",
    "JavaScript를 배운 1학년(이윤임 교수님께선 큰 신뢰를 걸고 계신다.)",
    "C언어응용을 배운 1학년(김영철 교수님께 혼났다. 분명 C언어를 배웠는데...??)",
    "유니티를 배운 2학년(이성현 교수님께서 걱정하신다. 원래 착했던 애가 이상해지고 있다...)",
    "C# 프로그래밍을 배운 2학년(윤수미 교수님께서 좋아하신다. 다행히 아직 초반이라...)",
    "앱기획을 배운 2학년(김영철 교수님께 맞기 직전까지 갔다. 한강물의 온도가 궁금하다...)",
    "현타가 온 대학생(교수님께 혼나고, 과제에 치이고... 학생의 눈앞에 눈물이 글썽인다.)",
    "반응형웹을 배운 2학년(이은석 교수님께서 좋아하신다. 잠을 자지 않고 과제를 끝냈다.)",
    "C++을 배운 2학년(이제 C계얼 언어를 다 배웠다. 근데 포인터는 도저히 이해가 안된다...)",
    "유니티로 게임을 개발한 3학년(코피를 흘려가며 게임을 만들었다. 이성현 교수님께서 \"이게 게임이 맞나\"라고 하셨다.)",
    "HTML과 CSS로 웹을 만들어 본 3학년(이윤임 교수님께 잔소리를 많이 들었다. 그래도 내심 교수님께서 기특해하신다.)",
    "전공동아리 멘토를 하는 3학년(후배들의 존경을 받고 있다. 이은석 교수님과 이성현 교수님도 그렇게 생각하실까?)",
    "3D모델링을 배운 3학년(노은석 교수님과 1대1 면담을 했다. 아트도 괜찮은 것 같은데... 어디로 갈지 모르겠다.)",
    "창업동아리를 하는 3학년(매일 학교에 21시까지 후배, 동기들과 같이 작업을 한다. 이정도면 귀신이다.)",
    "기획서 작성을 마스터한 3학년(본인은 정말 잘한다고 생각한다. 이은석 교수님과 이성현 교수님도 그렇게 생각하실까?)",
    "현장 실습을 다녀온 3학년(회사에선 오랜만에 인재가 들어왔다고 한다. 하지만 본인은 회사가 별로다.)",
    "졸업 가운을 입고 있는 대학생(모든 능력을 탑재했다. 이제 진짜 지옥을 향해 걸어간다.)"
};

int isTry = 0;                  // 강화 시도 여부 선택 변수
int level = 0;                  // 현재 무기의 강화 수치
int money = INITIAL_MONEY;      // 현재 소지금 
int choice;
bool isGameOver = false;        // 게임 종료 여부 변수
int store;
int tickets = 0;

// 강화 성공 확률 배열
float enhancementProbabilities[MAX_ENHANCEMENT + 1] = {
    100.0f,95.0f,90.0f,85.0f,80.0f,
    75.0f,70.0f,60.0f,55.0f,50.0f,
    25.0f,25.0f,25.0f,25.0f,25.0f,
    25.0f, 20.0f, 15.0f, 10.0f, 5.0f, 0.0f
};

// 강화 시도 비용 배열
int enhancementCosts[MAX_ENHANCEMENT + 1] = {
    10000, 15000, 20000, 25000, 30000,
    35000, 40000, 45000, 50000, 55000,
    60000, 65000, 70000, 75000, 80000,
    85000, 90000, 95000, 100000, 105000,
};

// 학생 급여 배열
int studentSalaries[MAX_ENHANCEMENT + 1] = {
    0, 50000, 60000, 65000, 70000,
    75000, 80000, 85000, 90000, 95000,
    100000, 105000, 110000, 115000, 120000,
    125000, 130000, 135000, 140000,145000,
    150000
};

// 강화 유지 비용 배열
//int maintainCosts[MAX_ENHANCEMENT + 1] = {
//    0, 0, 0, 0, 0,
//    0, 0, 0, 0, 0,
//    5000, 6000, 7000, 8000, 9000,
//    10000, 11000, 12000, 13000, 14000,
//    15000
//};

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
    Sleep(2000);
    while (1) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
        printf(" * 학습 재화를 사용하여 아이템을 구매할 수 있습니다 *\n\n");
        printf(" * 1. 학생 판매 (학생 가치 : %d원)\n", studentSalaries[level]);
        printf(" * 2. 복습권 구매\n");
        printf(" * 3. 메인화면 이동\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

        printf("\n * 아이템을 선택하세요 : ");
        int shopChoice;
        scanf_s("\n%d", &shopChoice);



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

                level = 0;
            }
            else {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                printf(" \n 학생 레벨이 0이므로 학생 판매 옵션을 사용할 수 없습니다.\n\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            }
            break;
        case 2:
            if (money < REVIEW_TICKET_COST) {
                printf(" \n 재화가 부족하여 복습권을 구매할 수 없습니다.\n\n");
                break;
            }
            else {
                money -= REVIEW_TICKET_COST;
                tickets++;
                printf(" \n 복습권을 구매하였습니다.\n");
                printf("\n 보유 복습권 갯수 : %d개\n", tickets);
                printf(" \n 현재 소지금: %d원\n\n", money);
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


int main(void)
{
    system("mode con cols=120 lines=30 | title 이지호 학생 키우기");


    srand((unsigned int)time(NULL));         // 랜덤 시드값 설정

    while (!isGameOver)
    {
        system("@cls||clear");      // 화면 정리

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        printf(" ** 이지호 학생 키우기 **  \n\n");

        // 상태 출력
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        printf(" 학생 레벨 : + %d %s\n", level, enhancementMessages[level]);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        printf(" \n 현재 소지금 : %d원\n", money);
        printf(" 학습 비용 : %d원\n", enhancementCosts[level]);
        printf(" 학습 성공률 : %.2f%%\n", enhancementProbabilities[level]);
        printf(" \n 보유 복습권 갯수 : %d\n", tickets);
        printf(" \n 메뉴:\n\n");
        printf(" * 1. 학생 강화하기\n", level);
        printf(" * 2. 상점가기\n", store);
        printf(" * 3. 포기하기\n\n", isGameOver);
        
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
                // 강화에 성공 했을 시, 레벨을 하나 증가 시킴
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
                printf("\n 어익후.. 핸드폰을 봤네..교수님이 봐버렸다...\n");
                printf("\n [+%d 지식을 잃었습니다.]\n\n", level);

                if (1 <= level <= 20)
                {
                    if (tickets != 0)
                    {
                        money -= enhancementCosts[level];
                        printf("학습에 실패하였습니다. \n현재 학습 수치를 유지하시겠습니까? \n{보유 학습권 갯수 : %d}\n(YES : 1/ NO : 2) : ", tickets);
                        scanf_s("%d", &choice);
                        if (choice == 1) {
                            tickets--;
                            printf("\n복습권을 사용합니다. (보유 복습권 갯수 : %d)\n", tickets);
                            money += enhancementCosts[level];
                        }
                        else if (choice == 2) {
                            printf("학습 수치를 초기화합니다.\n");
                            level = 0; // 강화 수치 초기화
                        }
                        else {
                            printf("잘못된 입력입니다. 다시 선택하세요.\n");
                            continue;
                        }
                    }
                    else
                    {
                        level = 0;
                    }
                }
            }
            // 강화 비용 차감

            break;
        case 2:
            GoStore();
            break;
        case 3:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf("\n 이런! 이지호 학생이 자퇴 했습니다 이제 어쩌죠...?\n");
            isGameOver = true; // 게임 종료
            break;
        default:
            printf("잘못된 입력입니다. 다시 선택하세요.\n");
            break;
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        printf("\n 계속하려면 아무 키나 누르세요! \n");
        getchar(); // 개행 문자 처리를 위해 getchar 사용

        // 사용자 입력 대기
        while (getchar() != '\n'); // 버퍼 비우기
    }

    return 0;
}
