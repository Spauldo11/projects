let brokenPassword = [];
function breakPassword(passcode) {
possibleCombinations = ["A", "a", "B", "b", "C", "c", "D", "d", "E", "e", "F", "f", "G", "g", "H", "h", "I", "i", "J", "j", "K", "k", "L", "l", "M", "m", "N", "n", "O", "o", "P", "p", "Q", "q", "R", "r", "S", "s", "T", "t", "U", "u", "V", "v", "W", "w", "X", "x", "Y", "y", "Z", "z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"];
for (let i = 0; i < passcode.length; i++) {
for (let j = 0; j < possibleCombinations.length; j++) {
    console.log(`${brokenPassword} ${possibleCombinations[j]}`);
if(possibleCombinations[j] == passcode[i]) {
    brokenPassword.push(possibleCombinations[j])
    break;
}
}
}
console.log(`Your password is ${brokenPassword}`);
}
breakPassword("spauldo102938");