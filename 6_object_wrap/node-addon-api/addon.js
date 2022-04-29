var addon = require('bindings')('addon');
console.log( "started..." );

let iterations = 0;
const PLAYER_BUTTONS = 202;
var cppInterface = new addon.CppInterface( 42 );
cppInterface.digitalWrite( 38,  1    );  // RESET
cppInterface.digitalWrite( 26,  1    );  // UNDO
cppInterface.digitalWrite( PLAYER_BUTTONS, 2000 );  // PLAYER_BUTTONS
let temp = cppInterface.getPinState();
console.table( temp );
while ( iterations < 10 ) {
    if ( cppInterface.digitalRead( PLAYER_BUTTONS ) < 2000 ) {
        console.log( "pin PLAYER_BUTTONS is low!" );
        exit( 0 ); }    
    cppInterface.gameLoop();
    console.log( "iteration: " + ++iterations );
    // postMessage( "iteration: " + iterations );
    temp = cppInterface.getPinState();
    console.table( temp );  
}  

