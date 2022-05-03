// GameObject _gameObject;
// void setup() {
//     Serial.println(( "the setup..." ));
//     delay(( 1000 ));
//     // uint8_t  INPUT = 0;
//     pinMode( PLAYER_BUTTONS, INPUT );
//     pinMode( ROTARY, INPUT );
//     pinMode( UNDO, INPUT );
//     pinMode( RESET, INPUT );

//     // uint8_t  OUTPUT = 0;
//     pinMode( P1_POINTS_LED1, OUTPUT );
//     pinMode( P1_POINTS_LED2, OUTPUT );
//     pinMode( P1_POINTS_LED3, OUTPUT );
//     pinMode( P1_POINTS_LED4, OUTPUT );

//     pinMode( P2_POINTS_LED1, OUTPUT );
//     pinMode( P2_POINTS_LED2, OUTPUT );
//     pinMode( P2_POINTS_LED3, OUTPUT );
//     pinMode( P2_POINTS_LED4, OUTPUT );

//     pinMode( P1_SERVE, OUTPUT );
//     pinMode( P2_SERVE, OUTPUT );

//     pinMode( P1_GAMES_LED0, OUTPUT );
//     pinMode( P1_GAMES_LED1, OUTPUT );
//     pinMode( P1_GAMES_LED2, OUTPUT );
//     pinMode( P1_GAMES_LED3, OUTPUT );
//     pinMode( P1_GAMES_LED4, OUTPUT );
//     pinMode( P1_GAMES_LED5, OUTPUT );
//     pinMode( P1_GAMES_LED6, OUTPUT );
//     pinMode( P1_TIEBREAKER, OUTPUT );

//     pinMode( P2_GAMES_LED0, OUTPUT );
//     pinMode( P2_GAMES_LED1, OUTPUT );
//     pinMode( P2_GAMES_LED2, OUTPUT );
//     pinMode( P2_GAMES_LED3, OUTPUT );
//     pinMode( P2_GAMES_LED4, OUTPUT );
//     pinMode( P2_GAMES_LED5, OUTPUT );
//     pinMode( P2_GAMES_LED6, OUTPUT );
//     pinMode( P2_TIEBREAKER, OUTPUT );

//     pinMode( P1_SETS_LED1, OUTPUT );
//     pinMode( P1_SETS_LED2, OUTPUT );

//     pinMode( P2_SETS_LED1, OUTPUT );
//     pinMode( P2_SETS_LED2, OUTPUT );

//     Serial.begin( 9600 );
// }

// void loop() {
//     delay(( 1000 ));
//     Serial.println(( "starting loop..." ));
//     delay(( 1000 ));
//     int iteration = 0;
//     while ( iteration < 5 ) {
//         delay( 1000 );
//         Serial.println( "inside while...");
//         Serial.println( String( iteration ));
//         _gameObject.beginLoop();
//         iteration++;
//     }
// }
