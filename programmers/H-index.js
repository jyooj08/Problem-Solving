function solution(citations) {
    var answer = 0;
    citations.sort();
    // console.log(citations);
    let n = citations.length;

    for(let h=n;h>=0;h--){
        let cited = 0;
        let not_cited = 0;
        for(let i=0;i<n;i++){
            if(citations[i] >= h) cited++;
            if(citations[i] <= h) not_cited++;
        }
        // console.log(h, cited, not_cited);
        if(h <= cited) return h;
    }
    return answer;
}