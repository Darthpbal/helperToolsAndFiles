//This program is written for the AtTiny85


// multi button research
// https://www.edn.com/design/analog/4439796/Read-multiple-switches-using-ADC
// http://tronixstuff.com/2012/02/29/tutorial-analog-input-for-multiple-buttons-part-two/

#include <SoftwareSerial.h>
SoftwareSerial bt(0,1);//rx, tx

int xCeiling = 300,
    sqCeiling = 480,
    tCeiling = 730,
    cCeiling = 945,
    thumbCeiling = 80;

enum configuration {debug, live};
const configuration mode = debug;

bool jstat = false,
    jprevStat = false,
    tstat = false,
    tprevStat = false,
    cstat = false,
    cprevStat = false,
    sstat = false,
    sprevStat = false,
    xstat = false,
    xprevStat = false;

bool lstat = false,
    lprevStat = false,
    rstat = false,
    rprevStat = false,
    ustat = false,
    uprevStat = false,
    dstat = false,
    dprevStat = false;


void setup() {
  bt.begin(9600);
}



void loop() {
  // put your main code here, to run repeatedly:
  int ch0, ch1, ch2;
  ch0 = analogRead(1);
  ch1 = analogRead(2);
  ch2 = analogRead(3);


  //Raw input
  if(mode == debug){
      bt.print(ch0);
      bt.print('\t');

      bt.print(ch1);
      bt.print('\t');

      bt.print(ch2);
      bt.print('\t');
      bt.println();
  }



  //Gaming input
  if( ch0 < thumbCeiling){//thumb
    jstat = true;
  }
  else if( ch0 < xCeiling ){//X
    xstat = true;
  }
  else if( ch0 < sqCeiling ){//square
    sstat = true;
  }
  else if( ch0 < tCeiling ){//triangle
    tstat = true;
  }
  else if( ch0 < cCeiling ){//circle
    cstat = true;
  }
  else {//not pressed
    if(jstat) jstat = false;
    if(tstat) tstat = false;
    if(cstat) cstat = false;
    if(sstat) sstat = false;
    if(xstat) xstat = false;
  }


  //x axis
  if(ch1 < 470){
    lstat = true;
  }
  else if(ch1 > 600){
    rstat = true;
  }
  else {
    if(lstat) lstat = false;
    if(rstat) rstat = false;
  }


  //y axis
  if(ch2 > 540){
    dstat = true;
  }
  else if(ch2 < 450){
    ustat = true;
  }
  else {
    if(dstat) dstat = false;
    if(ustat) ustat = false;
  }


  if(mode == live){
      if(jstat && !jprevStat){
          bt.println("jprs");
      }
      else if(!jstat && jprevStat){
          bt.println("jrel");
      }


      if(tstat && !tprevStat){
          bt.println("tprs");
      }
      else if(!tstat && tprevStat){
          bt.println("trel");
      }


      if(cstat && !cprevStat){
          bt.println("cprs");
      }
      else if(!cstat && cprevStat){
          bt.println("crel");
      }


      if(sstat && !sprevStat){
          bt.println("sprs");
      }
      else if(!sstat && sprevStat){
          bt.println("srel");
      }


      if(xstat && !xprevStat){
          bt.println("xprs");
      }
      else if(!xstat && xprevStat){
          bt.println("xrel");
      }


      if(lstat && !lprevStat){
          bt.println("lprs");
      }
      else if(!lstat && lprevStat){
          bt.println("lrel");
      }


      if(rstat && !rprevStat){
          bt.println("rprs");
      }
      else if(!rstat && rprevStat){
          bt.println("rrel");
      }


      if(ustat && !uprevStat){
          bt.println("uprs");
      }
      else if(!ustat && uprevStat){
          bt.println("urel");
      }


      if(dstat && !dprevStat){
          bt.println("dprs");
      }
      else if(!dstat && dprevStat){
          bt.println("drel");
      }
  }




  jprevStat = jstat;
  tprevStat = tstat;
  cprevStat = cstat;
  sprevStat = sstat;
  xprevStat = xstat;
  lprevStat = lstat;
  rprevStat = rstat;
  uprevStat = ustat;
  dprevStat = dstat;

   delay(70);
}
