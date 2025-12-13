let set1 = ['asdf', 'qwer', 'wert', 'erty', 'rtyu', 'asdf']
let set2 = ['sdfg', 'dfgh', 'fghj', 'asdf']

function doesSet2ContainItemFromSet1(set1, set2) {
  for (let i of set1) {
    if (set2.includes(i)) {
      return true
    }
  }
  return false
}

function doesSet2ContainItemFromSet1Linear(set1, set2) {
  const lookupSet = new Set(set2)

  for (let i of set1) {
    if (lookupSet.has(i))
      return true
  }
  return false
}

console.time('function run time')
console.log(doesSet2ContainItemFromSet1(set1, set2))
console.timeEnd('function run time')

console.time('function run time')
console.log(doesSet2ContainItemFromSet1Linear(set1, set2))
console.timeEnd('function run time')
