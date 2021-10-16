function solution(s) {
    let loop = parseInt(s.length/2);
    let min = s.length;
    
    for(let len=1;len<=loop;len++){
        let stack = [];
        stack.push({str:s.substring(0,len), count: 1});
        for(let i=len;i<s.length;i+=len){
            let str = s.substring(i,i+len);
            if(stack[stack.length-1].str == str) stack[stack.length-1].count++;
            else stack.push({str: str, count: 1});
        }
        
        let size = 0;
        for(let i=0;i<stack.length;i++){
            size += (stack[i].count > 1 ? stack[i].str.length+stack[i].count.toString().length : stack[i].str.length);
        }
        if(size < min) min = size;
    }
    
    return min;
}