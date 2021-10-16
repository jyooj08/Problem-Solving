function solution(record) {
    let answer = [];
    let enter = "님이 들어왔습니다.";
    let leave = "님이 나갔습니다.";
    let users = [];
    record = record.map((item) => item.split(' '));
    
    for(let i=0;i<record.length;i++){
        switch(record[i][0]){
            case 'Enter':
                users[record[i][1]] = record[i][2];
                answer.push([record[i][1], enter]);
                break;
            case 'Leave':
                answer.push([record[i][1], leave]);
                break;
            case 'Change':
                users[record[i][1]] = record[i][2];
                break;
            default:
                break;
        }
    }
    
    answer = answer.map(item => users[item[0]]+item[1]);
    return answer;
}