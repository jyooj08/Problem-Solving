function solution(answers) {
    let answer = [0,0,0];
    let s1 = [1,2,3,4,5]; // 5
    let s2 = [2,1,2,3,2,4,2,5]; // 8
    let s3 = [3,3,1,1,2,2,4,4,5,5]; // 10
    
    for(let i=0;i<answers.length;i++){
        if(answers[i] == s1[i%5]) answer[0]++;
        if(answers[i] == s2[i%8]) answer[1]++;
        if(answers[i] == s3[i%10]) answer[2]++;
    }
    
    let max = Math.max(answer[0], answer[1], answer[2]);
    
    let answer2 = [];
    for(let i=0;i<3;i++){
        if(answer[i] === max) answer2.push(i+1);
    }
    return answer2;
}