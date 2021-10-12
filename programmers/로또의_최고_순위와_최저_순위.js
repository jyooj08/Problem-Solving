function solution(lottos, win_nums) {
    var answer = [];
    lottos = lottos.filter(n => n > 0);
    
    let min = 0;
    for(let i=0;i<lottos.length;i++){
        if(win_nums.includes(lottos[i])) min++;
    }
    
    let max = min + 6 - lottos.length;

    let arr = [6,6,5,4,3,2,1];
    return [arr[max], arr[min]];
}