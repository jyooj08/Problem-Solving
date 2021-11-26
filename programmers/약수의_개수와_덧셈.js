function solution(left, right) {
    var answer = 0;
    for(let i=left;i<=right;i++){
        answer += i;
    }
    for(let i=1;i*i<=right;i++){
        if(i*i >= left) answer -= 2*i*i;
    }
    return answer;
}