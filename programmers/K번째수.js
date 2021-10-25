function solution(array, commands) {
    var answer = [];
    for(let i=0;i<commands.length;i++){
        console.log('commands', commands[i])
        let arr = array.slice().splice(commands[i][0]-1, commands[i][1] - commands[i][0] + 1);
        arr.sort(function(a,b){
            return a > b;
        });
        answer.push(arr[commands[i][2]-1]);
    }
    return answer;
}