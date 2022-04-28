var addon = require('bindings')('addon');

var cppInterface = new addon.CppInterface(10);

$( '.app' ).html( cppInterface.value() );
console.log( cppInterface.plusOne() ); // 11
console.log( cppInterface.plusOne() ); // 12
console.log( cppInterface.plusOne() ); // 13

console.log( cppInterface.multiply().value() ); // 13
console.log( cppInterface.multiply(10).value() ); // 130

var newobj = cppInterface.multiply(-1);
console.log( newobj.value() ); // -13
console.log( cppInterface === newobj ); // false

export default addon;
