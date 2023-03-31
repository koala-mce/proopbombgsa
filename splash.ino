
void explodeSplash(){
  digitalWrite (TESTEPIN, LOW); //#teste
  digitalWrite(REDLED, LOW);  
  digitalWrite(GREENLED, LOW); 
  cls();
  delay(100);
  endGame = false;
  lcd.setCursor(1,0);
  lcd.print("BOMBA EXPLODIU");
  lcd.setCursor(2,1);
  lcd.print("FIM DE JOGO");
  for(int i = 200; i>0; i--)// this is the ultra hi definition explosion sound xD
  {
    tone(tonepin,i);
    delay(20);
  }
  noTone(tonepin);
  if(relayEnable){
    activateRelay(); 
  }
  delay(50);
  if(testeEnable);
    activateTeste();
  cls();

  //end code
  lcd.print("JOGAR DE NOVO?");
  lcd.setCursor(0,1);
  lcd.print("A : SIM B : NAO");
  while(1)
  {
    var = keypad.waitForKey();
    if(var == 'a' ){
      tone(tonepin,2400,30);
      //We have two options, search & destroy and sabotaje play again options so!
      if(sdStatus){
        startGameCount();
        search();
      }
      if(saStatus){
        saStatus=true;
        startGameCount();
        start=true; //to set iTime to actual millis() :D
        sabotage();
      }
    }  
    if(var == 'b' ){
      tone(tonepin,2400,30);
      menuPrincipal();

      break;
    }  
  } 
}
void failSplash(){
  digitalWrite (TESTEPIN, LOW); //#teste
  digitalWrite(REDLED, LOW);  
  digitalWrite(GREENLED, LOW); 
  cls();
  delay(100);
  endGame = false;
  lcd.setCursor(1,0);
  lcd.print("TEMPO EXCEDIDO");
  lcd.setCursor(4,1);
  lcd.print("FIM DE JOGO");
  for(int i = 200; i>0; i--)// this is the ultra hi definition explosion sound xD
  {
    tone(tonepin,i);
    delay(20);
  }
  noTone(tonepin);
  if(relayEnable){
    activateRelay(); 
  }
  delay(5000);
  cls();

  //end code
  lcd.print("JOGAR DE NOVO?");
  lcd.setCursor(0,1);
  lcd.print("A : SIM B : NAO");
  while(1)
  {
    var = keypad.waitForKey();
    if(var == 'a' ){
      tone(tonepin,2400,30);
      //We have two options, search & destroy and sabotaje play again options so!
      if(sdStatus){
        startGameCount();
        search();
      }
      if(saStatus){
        saStatus=true;
        startGameCount();
        start=true; //to set iTime to actual millis() :D
        sabotage();
      }
      if(cwStatus){
        cwStatus=true;
        startGameCount();
        start=true;
        cutWire();
      }
    }  
    if(var == 'b' ){
      tone(tonepin,2400,30);
      menuPrincipal();
    
      break;
    }  
  } 
}
void disarmedSplash(){
  endGame = false;
  digitalWrite (TESTEPIN, LOW); //#teste
  digitalWrite(REDLED, LOW); 
  digitalWrite(GREENLED, LOW);
  if(sdStatus || saStatus){
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("BOMBA DEFUSADA");
    lcd.setCursor(1,1); //PRIMEIRO NUMERO ALINHAMENTO . SEGUNDO NUMERO 0 LINHA DE CIMA, 1 LINHA DE BAIXO
    lcd.print("VITORIA DEFESA");
    digitalWrite(TESTEPIN, HIGH);
    digitalWrite(GREENLED, HIGH);  
    delay(5000);
    digitalWrite(GREENLED, LOW); 
  }
  //end code
  lcd.clear();
  lcd.print("JOGAR DE NOVO?");
  lcd.setCursor(0,1);
  lcd.print("A : SIM B : NAO");
  digitalWrite(TESTEPIN, LOW); //desligar sirene ao acabar o jogo #teste
  digitalWrite(REDLED, LOW);  
  digitalWrite(GREENLED, LOW); 
  while(1)
  {
    var = keypad.waitForKey();
    if(var == 'a' ){
      tone(tonepin,2400,30);
      //We have two options, search & destroy and sabotaje play again options so!
      if(sdStatus){
        startGameCount();
        search();
      }
      if(saStatus){
        saStatus=true;
        startGameCount();
        start=true; //to set iTime to actual millis() :D
        sabotage();
      }
    }  
    if(var == 'b' ){
      tone(tonepin,2400,30);
      menuPrincipal();
      break;
    }  
  } 
}
