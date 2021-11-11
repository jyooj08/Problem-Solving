function isRight(str){
    let stack = [];
    for(let i=0;i<str.length;i++){
        if(str[i] == '(') stack.push('(');
        else if(str[i] == ')') stack.pop();
    }
    
    if(stack.length > 0) return false;
    return true;
}

function getResult(w){    
    //1
    if(w=='' || isRight(w)) return w;
    //2
    let u='', v='';
    let result = 0;
    let flag = true;
    for(let i=0;i<w.length;i++){
        if(w[i] == '(') result++;
        else if(w[i] == ')') result--;
        
        if(flag) u += w[i];
        else v += w[i];
        if(result==0) flag = false;
    }
    
    if(isRight(u)) return u + getResult(v);
    
    let a = '(' + getResult(v) + ')';
    let b = '';
    for(let i=1;i<u.length-1;i++){
        if(u[i]=='(') b += ')';
        else if(u[i]==')') b += '(';
    }
    
    return a + b;
}

function solution(w) {
    return getResult(w);
}