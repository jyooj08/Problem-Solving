function solution(s) {
    var answer = [];
    let arr = [];
    let num = '';
    let open = false;
    s = s.substring(1, s.length-1);    
    
    for(let i=0;i<s.length;i++){
        if(s[i]=='{') {arr.push(''); open = true;}
        else if(s[i]=='}') open =false;
        else if(open) arr[arr.length-1] += s[i];
    }
    
    arr = arr.map(item => item.split(',').map(item2 => Number(item2)));
    
    arr.sort(function(a, b){
        return a.length - b.length;
    })
    
    for(let i=0;i<arr.length;i++){
        for(let j=0;j<arr[i].length;j++){
            if(!answer.includes(arr[i][j])){
                answer.push(arr[i][j]);
                break;
            }
        }
    }
    
    return answer;
}