function solution(n,a,b)
{
    let count = 1;
    
    if(a>b){
        let t = a;
        a = b;
        b = t;
    }
    
    while(1){
        if(b-a == 1 && b%2 == 0){
            break;
        }
        count++;
        a = Math.ceil(a/2);
        b = Math.ceil(b/2);
    }

    return count;
}