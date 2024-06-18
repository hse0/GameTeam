// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // 

function doPost(e) {
    try {
        // 데이터에서 각 필드 추출
        var postData = JSON.parse(e.postData.contents);
        var nickname_initial = postData.아이디;

        // 현재 날짜와 시간을 문자열로 변환
        var currentDateTime = new Date().toLocaleString(); 

        // 종료 시간을 받아오기
        var endDateTime = postData.종료시간; // 클라이언트에서 받은 종료 시간을 사용하거나 없을 경우 빈 문자열로 설정

        // 강화 단계
        var level = postData.강화단계 || 0;

        // 단계별 복습권 구매 갯수
        var tickets = postData.단계별복습권구매갯수|| 0;

        // 강화 시도 횟수
        var attempt = postData.강화시도횟수|| 0;

        // 판매 횟수
        var selling_count = postData.판매횟수|| 0;

        var storeCount = postData.스토어추가금액||0;
        // 현재 비용
        var money = postData.현재비용|| 0;

        // 시트에 현재 시간 데이터 입력
        var spreadsheetId = '1KTHch1UucHFaPQTr6Gfr_NAGCLW_V2ImnsHKxEn75n4';
        var sheetName = '시트1';
        var sheet = SpreadsheetApp.openById(spreadsheetId).getSheetByName(sheetName);

        // 시트의 마지막 행을 가져옴
        sheet.appendRow([nickname_initial,currentDateTime, endDateTime, level,tickets, attempt,selling_count,storeCount,money]);

        // 응답
        return ContentService.createTextOutput('Data saved successfully.');
    } catch (error) {
        // 오류 처리
        console.error('Error:', error);
        return ContentService.createTextOutput('Error: ' + error.message).setStatusCode(500);
    }
}