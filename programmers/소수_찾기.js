function isPrime(num){
    if(num <= 1) return 0;
    for(let i=2;i*i<=num;i++){
        if(num%i == 0) return 0;
    }
    return 1;
}

function solution(numbers) {
    var answer = 0;
    let num_list = [];
    
    function getNum(s, arr, len){
        if(s.length == len){
            num_list.push(s);
            return;
        }
        for(let i=0;i<arr.length;i++){
            getNum(s+arr[i], arr.slice(0,i) + arr.slice(i+1), len);
        }
    }
    for(let i=1;i<=numbers.length;i++){
        getNum('', numbers, i);
    }
    
    num_list = num_list.map(v => Number(v));
    num_list = [...new Set(num_list)];
    
    for(let i=0;i<num_list.length;i++){
        answer += isPrime(num_list[i]);
    }
    return answer;
}