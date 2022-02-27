function getAnswer(n) {
  let s = ("0" + n.toString(2)).split("");
  let len = s.length;
  if (s[len - 1] == "0") {
    s[len - 1] = "1";
    // console.log(s)
    return parseInt(s.join(""), 2);
  }

  for (let i = len - 2; i >= 0; i--) {
    if (s[i] == "0") {
      s[i] = "1";
      s[i + 1] = "0";
      // console.log(s)
      return parseInt(s.join(""), 2);
    }
  }
}

function solution(numbers) {
  var answer = [];
  for (let n of numbers) {
    answer.push(getAnswer(n));
  }
  return answer;
}
