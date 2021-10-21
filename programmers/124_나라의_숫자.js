function solution(n) {
    var answer = '';
    let num3 = n.toString(3);
    let num = num3.split('');
    for(let i=num.length-1;i>=0;i--){
        if(num[i]=='0'){
            //num = '4' + num;
            if(i > 0) num[i] = "4";
            for(let j=i-1;j>=0;j--){
                if(num[j]=='1') {
                    num[j] = '0'; break;
                }
                else if(num[j]=='2') {
                    num[j]='1'; break;
                } 
                else num[j] = '2'
            }
        } 
    }
    for(let i=0;i<num.length;i++) answer+=num[i];
    answer  = Number(answer).toString();
    return answer;
}