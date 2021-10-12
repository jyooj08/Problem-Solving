function solution(new_id) {
    // 1
    new_id = new_id.toLowerCase();
    console.log('a' < 'b');
    // 2
    let x = '-_.'; let new_id2 = '';
    for(let i=0;i<new_id.length;i++){
        if(new_id[i] < 'a' || new_id[i] > 'z') continue; //console.log(new_id[i],1);
        if(new_id[i] < '0' || new_id[i] > '9') continue; //console.log(new_id[i],2);
        if(!x.includes(new_id[i])) continue;//console.log(new_id[i],3);
        new_id2 = new_id2 + new_id[i]; 
    }
    console.log('result: ',new_id2);
    return '';
}