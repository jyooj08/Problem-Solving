function getTimeInterval(start, end) {
  start = start.split(":").map((x) => Number(x));
  end = end.split(":").map((x) => Number(x));
  let hour = end[1] >= start[1] ? end[0] - start[0] : end[0] - start[0] - 1;
  let min = end[1] >= start[1] ? end[1] - start[1] : 60 + end[1] - start[1];
  return hour * 60 + min;
}

function solution(fees, records) {
  let answer = [];
  let inout = {};
  let feesPerCar = [];

  for (let r of records) {
    let [time, number, type] = r.split(" ");
    if (inout[number]) inout[number].push(time);
    else inout[number] = [time];
  }

  for (const [key, val] of Object.entries(inout)) {
    if (val.length % 2 == 1) val.push("23:59");
    let totalTime = 0;
    for (let i = 0; i < val.length; i += 2) {
      totalTime += getTimeInterval(val[i], val[i + 1]);
    }

    // get fee
    let fee = 0;
    if (totalTime <= fees[0]) fee = fees[1];
    else fee = fees[1] + Math.ceil((totalTime - fees[0]) / fees[2]) * fees[3];

    feesPerCar.push([key, fee]);
  }

  feesPerCar.sort();
  for (let fee of feesPerCar) answer.push(fee[1]);

  return answer;
}
