char path[60]={};
int dryover=0;
int pindex=0;

void forward(int l=255,int r=255)
{
  //left
 digitalWrite(7,1); // pin 7 dir left
 digitalWrite(4,1); // pin 4 dir right
 analogWrite(6,l);  // pin 6 speed left 
 analogWrite(5,r);  //pin 5 speed right

}

// 90 degreee right turn
void rightTurn()
{
  
  while(digitalRead(A2)==0 && digitalRead(A3)==0 )
  {
     Serial.println("in loop of right turn ");
   
    digitalWrite(7,1);
    digitalWrite(4,0);
    analogWrite(6,250); //left
    analogWrite(5,0);  // right
  
}
 // stoping();
  //delay(100);


}

// 90 degreee Left turn
void leftTurn()
{
 
 while( digitalRead(A2)==0 && digitalRead(A3)==0)
  {
    Serial.println("in loop of left turn ");
    digitalWrite(7,0);
    digitalWrite(4,1);
    analogWrite(6,0); //left
    analogWrite(5,250);  // right

  }
 // stoping();
  //delay(100);  
 
}




void strtleft()
{
 while( digitalRead(A2)==1 && digitalRead(A3)==1)
  {
    Serial.println("in loop of left turn ");
  digitalWrite(7,0);
    digitalWrite(4,1);
    analogWrite(6,150); //left
    analogWrite(5,150);  // right
  }

  while( digitalRead(A2)==0 && digitalRead(A3)==0)
  {
    Serial.println("in loop of left turn ");
   digitalWrite(7,0);
    digitalWrite(4,1);
    analogWrite(6,150); //left
    analogWrite(5,150);  // right
  }
 // stoping();
  //delay(100);
 
}

void stoping()
{
  digitalWrite(7,0);
    digitalWrite(4,1);
    analogWrite(6,0); //left
    analogWrite(5,0);  // right
}


void UTurn(int l,int r)
{
 while( digitalRead(A2)==0 && digitalRead(A3)==0)
  {
    Serial.println("in loop of left turn ");
  digitalWrite(7,0);
    digitalWrite(4,1);
    analogWrite(6,150); //left
    analogWrite(5,150);  // right

  }
 // stoping();
  //delay(100);
 
}


    void sort()
    {
      int x = (pindex-2);

     while (x > 0)  
     {
      if (path[x]=='U')
      {
        if (path[x-1]=='L' && path[x+1]=='L')
          {
            path[x-1]='S';path[x]='O';path[x+1]='O';
          }
        else if (path[x-1]=='L' && path[x+1]=='S')
          {
            path[x-1]='R';path[x]='O';path[x+1]='O';
          }
        else if (path[x-1]=='R' && path[x+1]=='R')
          {
            path[x-1]='S';path[x]='O';path[x+1]='O';
          }
        else if (path[x-1]=='R' && path[x+1]=='S')
          {
            path[x-1]='L';path[x]='O';path[x+1]='O';
           }
        else if (path[x-1]=='S' && path[x+1]=='L')
          {
            path[x-1]='R';path[x]='O';path[x+1]='O';
           }
        else if (path[x-1]=='S' && path[x+1]=='R')
          {
            path[x-1]='L';path[x]='O';path[x+1]='O';
          }
        else if (path[x-1]=='L' && path[x+1]=='R')
          {
            path[x-1]='U';path[x]='O';path[x+1]='O';
          }
        else if (path[x-1]=='R' && path[x+1]=='L')
          {
            path[x-1]='U';path[x]='O';path[x+1]='O';
            }
        else if (path[x-1]=='S' && path[x+1]=='S')
          {
            path[x-1]='U';path[x]='O';path[x+1]='O';
            }
        //---------------------------------------
        x--;
        }
        else
           {x--;}
        }
      }
    

    int doneindex=0;
    void done()
    {
      sort();
     
    }

    void todo()
    {
       while(1)
       {
         if(path[doneindex]=='L')
          {
            strtleft();
            doneindex++;
            break;
        
          }
           if(path[doneindex]=='R')
          {
            rightTurn();
            doneindex++;
           break;
          }
          if(path[doneindex]=='S')
          {
           forward();
            doneindex++;
           break;
          }
         if(path[doneindex]=='O')
         {
            doneindex++;
         }
       }
    }


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    void dryRun()
    {
      
  if( digitalRead(A1)==0 && digitalRead(A2)==1  && digitalRead(A3)==1 && digitalRead(A4)==0 ){Serial.println("moving forward");                forward();}

   else if( digitalRead(A1)==1 && digitalRead(A2)==1  && digitalRead(A3)==1 && digitalRead(A4)==0){Serial.println("moving slightest left");forward(130,180);}

   else if( digitalRead(A1)==1 && digitalRead(A2)==1  && digitalRead(A3)==0 && digitalRead(A4)==0){Serial.println("0011");                  forward(150,200); }
   else if(digitalRead(A1)==1 && digitalRead(A2)==0  && digitalRead(A3)==0 && digitalRead(A4)==0){Serial.println("moving slight right0111");forward(0,200);}
   else if(digitalRead(A1)==0 && digitalRead(A2)==0  && digitalRead(A3)==1 && digitalRead(A4)==1){Serial.println("moving slightesgt right");forward(200,150);}
   else if( digitalRead(A1)==0 && digitalRead(A2)==0 && digitalRead(A3)==0 && digitalRead(A4)==1){Serial.println("moving slightesgt right");forward(200,0);}
   else if( digitalRead(A1)==0 && digitalRead(A2)==1  && digitalRead(A3)==1 && digitalRead(A4)==1){Serial.println("moving slightesgt right"); forward(180,130);}
   else if( digitalRead(A0)==1 && digitalRead(A1)==1 && digitalRead(A2)==1 && digitalRead(A3)==1  && digitalRead(A4)==1 && digitalRead(A5)==1 )
        {Serial.println("stoping");stoping(); dryover=1; done();}
 




                                                            // junction codes


    //code for for right turn 
    if(digitalRead(A0)==0 && digitalRead(A3)==1 && digitalRead(A4)==1   && digitalRead(A5)==1)
    {
            
         forward(100,100);
          delay(200);
      Serial.println(" found right turn ");
        Serial.println(" sea*rching for pure blacks");
        if(digitalRead(A1)==1 || digitalRead(A2)==1 || digitalRead(A3)==1 || digitalRead(A4)==1)   //right-straight
            {
    
               forward();
               path[pindex]='S';
               pindex++;
          
            }
        if(digitalRead(A0)==0 && digitalRead(A2)==0 && digitalRead(A3)==0 && digitalRead(A5)==0)    // only right
        {
     
          
          Serial.println("starting right turn");
          rightTurn();
      
        
        }
     
      
    }// left turn

    else if(digitalRead(A0)==1    && digitalRead(A2)==1 && digitalRead(A5)==0) 
    {
      Serial.println(" found left turn ");
      
          forward(100,100);
          delay(200);
        
          if(digitalRead(A1)==1 || digitalRead(A2)==1 || digitalRead(A3)==1 || digitalRead(A4)==1)//left-straight
            {
          
               strtleft();
               
              path[pindex]='L';
               pindex++;
            }
      
      
        else if(digitalRead(A0)==0 && digitalRead(A2)==0 && digitalRead(A3)==0 && digitalRead(A5)==0) //only left
        {
          
        
          Serial.println("starting left turn");
        leftTurn();
       
       }
      
    }



      // for T junction / crosss

       else if((digitalRead(A1)==1  && digitalRead(A2)==1  && digitalRead(A3)==1 && digitalRead(A4)==1) ||( digitalRead(A0)==1  && digitalRead(A5)==1) )
      {
        stoping();
        delay(300);
      Serial.println(" found left turn ");
      
          forward(100,100);
          delay(200);
        
          if(digitalRead(A2)==1 || digitalRead(A3)==1)          // only cross
           {
          
             strtleft();
             path[pindex]='L';
               pindex++;
           }
      
          Serial.println(" searching for pure black");
          if(digitalRead(A0)==0 && digitalRead(A3)==0 && digitalRead(A4)==0 && digitalRead(A5)==0)      //  only T
          {
          
        
          Serial.println("starting left turn");
           leftTurn();
           path[pindex]='L';
               pindex++;
       
         }
      
      }


    
    else if(digitalRead(A0)==0 && digitalRead(A2)==0 && digitalRead(A3)==0 && digitalRead(A5)==0)//u turrn
    {
      forward(100,100);
      delay(400);
        UTurn(100,100);  
        path[pindex]='U';
        pindex++;;
      
    }


    }
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void setup() {
   pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(6,OUTPUT);
 pinMode(7,OUTPUT);
 pinMode(2,INPUT_PULLUP);
 
 Serial.begin(9600);
 pinMode(A0,INPUT);
 pinMode(A1,INPUT);
 pinMode(A2,INPUT);
 pinMode(A3,INPUT);
 pinMode(A4,INPUT);
 pinMode(A5,INPUT);

}




void loop() {

 if(digitalRead(2)==1 && dryover != 1)
 {
  dryRun();
  Serial.println("-----------------------------------                in dry run                      ---------------------------------------------");
 }

else{

  Serial.println("-----------------------------------                in actual run                      ---------------------------------------------");
   if( digitalRead(A1)==0 && digitalRead(A2)==1  && digitalRead(A3)==1 && digitalRead(A4)==0 ){Serial.println("moving forward");                forward();}

   else if( digitalRead(A1)==1 && digitalRead(A2)==1  && digitalRead(A3)==1 && digitalRead(A4)==0){Serial.println("moving slightest left");forward(130,180);}

   else if( digitalRead(A1)==1 && digitalRead(A2)==1  && digitalRead(A3)==0 && digitalRead(A4)==0){Serial.println("0011");                  forward(150,200); }
   else if(digitalRead(A1)==1 && digitalRead(A2)==0  && digitalRead(A3)==0 && digitalRead(A4)==0){Serial.println("moving slight right0111");forward(0,200);}
   else if(digitalRead(A1)==0 && digitalRead(A2)==0  && digitalRead(A3)==1 && digitalRead(A4)==1){Serial.println("moving slightesgt right");forward(200,150);}
   else if( digitalRead(A1)==0 && digitalRead(A2)==0 && digitalRead(A3)==0 && digitalRead(A4)==1){Serial.println("moving slightesgt right");forward(200,0);}
   else if( digitalRead(A1)==0 && digitalRead(A2)==1  && digitalRead(A3)==1 && digitalRead(A4)==1){Serial.println("moving slightesgt right"); forward(180,130);}
   else if(digitalRead(A0)==1 && digitalRead(A1)==1 && digitalRead(A2)==1 && digitalRead(A3)==1  && digitalRead(A4)==1 && digitalRead(A5)==1 ){Serial.println("stoping");stoping();}
  
   if(digitalRead(A0)==1 || digitalRead(A5)==1)
   {
    todo();
   }
  

}



   
}
