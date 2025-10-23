/*
console.log(`Hello`);
console.log(`This is my first JavaScript!`);
window.alert(`This is an alert!`);
window.alert(`I love JavaScript!`);
*/

let fullName = "Bill Gates";
let age = 21;
let isStudent = true;
let price = 14.99;

document.getElementById("p1").textContent = `Your name is ${fullName}.`;
document.getElementById("p2").textContent = `You are ${age} years old.`;
document.getElementById("p3").textContent = `Are you a student? ${isStudent}`;
document.getElementById("p4").textContent = `The price of this item is RM${price}`;

console.log(typeof price);
console.log(`Your name is ${fullName}.`);
console.log(`You are ${age} years old.`);
console.log(`Are you a student: ${isStudent}`);
console.log(`The price of this item is RM${price}`);