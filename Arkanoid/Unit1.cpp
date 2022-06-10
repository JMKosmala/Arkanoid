//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int  x=-6, y=-6;
//movement of ball
int points=0, round=1, level=25, lives=3 ;
//result
bool hit(TImage * b, TImage * brick)
{
        if((b->Left >= brick->Left - b->Width) &&
           (b->Left <= brick->Left + brick->Width) &&
           (b->Top  <= brick->Top + brick->Height) &&
           (b->Top +b->Height  >= brick->Top))
        return true;
        else
        return false;
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BTimerTimer(TObject *Sender)
{
        //ball movement
        Ball->Left += x;
        Ball->Top += y;

        //bounce from left wall
        if(Ball->Left <=Bg->Left)
        x=-x;

        //bounce from right wall
        if(Ball->Left >= Bg->Width-Ball->Width)
        x=-x;

        //bounce from top wall
        if(Ball->Top <=Bg->Top)
        y=-y;

        //fault
        if(Ball->Top>=Bg->Height-Ball->Height)
        {
        BTimer->Enabled=false;
        Ball->Visible=false;
        lives --;
        if (lives==2) Life3->Visible=false;
        else if (lives==1) Life2->Visible= false;
        else if (lives<=0) Life1->Visible= false;
        //continue
        if (lives >0)
        Ball->Left=50; Ball->Top=50;
        Ball->Visible=true;
        BTimer->Enabled=true;





        }
        //paddle hit
        else if((Ball->Top + Ball->Height > Paddle->Top) &&
           (Ball->Left >Paddle->Left-Ball->Width/2) &&
           (Ball->Left <Paddle->Left + Paddle->Width))
        {
             if (y>0)   y=-y;
        }
        //b1   (on bricks hit)
        if (hit(Ball,Brick1) && Brick1->Visible == true)
        {x=-x;  y=-y; Brick1->Visible=false; points++; level--;}
        //b2
        if (hit(Ball,Brick2) && Brick2->Visible == true)
        {x=-x;  y=-y; Brick2->Visible=false; points++; level--;}
        //b3
        if (hit(Ball,Brick3) && Brick3->Visible == true)
        {x=-x;  y=-y; Brick3->Visible=false; points++; level--;}
        //b4
        if (hit(Ball,Brick4) && Brick4->Visible == true)
        {x=-x;  y=-y; Brick4->Visible=false; points++; level--;}
        //b5
        if (hit(Ball,Brick5) && Brick5->Visible == true)
        {x=-x;  y=-y; Brick5->Visible=false; points++; level--;}
        //b6
        if (hit(Ball,Brick6) && Brick6->Visible == true)
        {x=-x;  y=-y; Brick6->Visible=false; points++; level--;}
        //b7
        if (hit(Ball,Brick7) && Brick7->Visible == true)
        {x=-x;  y=-y; Brick7->Visible=false; points++; level--;}
        //b8
        if (hit(Ball,Brick8) && Brick8->Visible == true)
        {x=-x;  y=-y; Brick8->Visible=false; points++; level--;}
        //b9
        if (hit(Ball,Brick9) && Brick9->Visible == true)
        {x=-x;  y=-y; Brick9->Visible=false; points++; level--;}
        //b10
        if (hit(Ball,Brick10) && Brick10->Visible == true)
        {x=-x;  y=-y; Brick10->Visible=false; points++; level--;}
        //b11
        if (hit(Ball,Brick11) && Brick11->Visible == true)
        {x=-x;  y=-y; Brick11->Visible=false; points++; level--;}
        //b12
        if (hit(Ball,Brick12) && Brick12->Visible == true)
        {x=-x;  y=-y; Brick12->Visible=false; points++; level--;}
        //b13
        if (hit(Ball,Brick13) && Brick13->Visible == true)
        {x=-x;  y=-y; Brick13->Visible=false; points++; level--;}
        //b14
        if (hit(Ball,Brick14) && Brick14->Visible == true)
        {x=-x;  y=-y; Brick14->Visible=false; points++; level--;}
        //b15
        if (hit(Ball,Brick15) && Brick15->Visible == true)
        {x=-x;  y=-y; Brick15->Visible=false; points++; level--;}
        //b16
        if (hit(Ball,Brick16) && Brick16->Visible == true)
        {x=-x;  y=-y; Brick16->Visible=false; points++; level--;}
        //b17
        if (hit(Ball,Brick17) && Brick17->Visible == true)
        {x=-x;  y=-y; Brick17->Visible=false; points++; level--;}
        //b18
        if (hit(Ball,Brick18) && Brick18->Visible == true)
        {x=-x;  y=-y; Brick18->Visible=false; points++; level--;}
        //b19
        if (hit(Ball,Brick19) && Brick19->Visible == true)
        {x=-x;  y=-y; Brick19->Visible=false; points++; level--;}
        //b20
        if (hit(Ball,Brick20) && Brick20->Visible == true)
        {x=-x;  y=-y; Brick20->Visible=false; points++; level--;}
         //b21
        if (hit(Ball,Brick21) && Brick21->Visible == true)
        {x=-x;  y=-y; Brick21->Visible=false; points++; level--;}
        //b22
        if (hit(Ball,Brick22) && Brick22->Visible == true)
        {x=-x;  y=-y; Brick22->Visible=false; points++; level--;}
        //b23
        if (hit(Ball,Brick23) && Brick23->Visible == true)
        {x=-x;  y=-y; Brick23->Visible=false; points++; level--;}
        //b24
        if (hit(Ball,Brick24) && Brick24->Visible == true)
        {x=-x;  y=-y; Brick24->Visible=false; points++; level--;}
        //b25
        if (hit(Ball,Brick25) && Brick25->Visible == true)
        {x=-x;  y=-y; Brick25->Visible=false; points++; level--;}

        //scoreboard
        Scoreboard->Caption = points;

        //next round
        if (level<=0)
        {
        BTimer->Enabled=false;
        Application->MessageBox("Prepare for next round","Next Round",MB_OK);
        BTimer->Enabled=true;
        BTimer->Interval--;
        Ball->Top=330; Ball->Left=250;
        Brick1->Visible=true;   Brick2->Visible=true;    Brick3->Visible=true;
        Brick4->Visible=true;   Brick5->Visible=true;    Brick6->Visible=true;
        Brick7->Visible=true;   Brick8->Visible=true;    Brick9->Visible=true;
        Brick10->Visible=true;  Brick11->Visible=true;   Brick12->Visible=true;
        Brick13->Visible=true;  Brick14->Visible=true;   Brick15->Visible=true;
        Brick16->Visible=true;  Brick17->Visible=true;   Brick18->Visible=true;
        Brick19->Visible=true;  Brick20->Visible=true;   Brick21->Visible=true;
        Brick22->Visible=true;  Brick23->Visible=true;   Brick24->Visible=true;
        Brick25->Visible=true;
        level=25;
        }
        //losing
        if (lives<=0)
        {
                AnsiString p;
                p= IntToStr(points);
                BTimer->Enabled=false;
                Ball->Visible=false;
                Label3->Caption= "You lose. Your score is "+ p +" points" ;
                Label3->Visible=true;
                AgainButton->Visible=true;
                CloseButton->Visible=true;
        }



}
//---------------------------------------------------------------------------
void __fastcall TForm1::PLeftTimer(TObject *Sender)
{
        if(Paddle->Left > Bg->Left+5)
        Paddle->Left -=20;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PRightTimer(TObject *Sender)
{
        if(Paddle->Left+Paddle->Width < Bg->Width-10)
        Paddle->Left +=20;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == VK_LEFT) PLeft->Enabled = true;
        if(Key == VK_RIGHT) PRight->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == VK_LEFT) PLeft->Enabled = false;
        if(Key == VK_RIGHT) PRight->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CloseButtonClick(TObject *Sender)
{
        Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AgainButtonClick(TObject *Sender)
{
        points=0; round=1; level=25; lives=3 ;
        BTimer->Interval=15;
        BTimer->Enabled=true;
        Ball->Top=330; Ball->Left=250;
        Ball->Visible=true;
        x=-5; y=-5;

        Label3->Visible=false;
        AgainButton->Visible=false;
        CloseButton->Visible=false;

        Brick1->Visible=true;   Brick2->Visible=true;    Brick3->Visible=true;
        Brick4->Visible=true;   Brick5->Visible=true;    Brick6->Visible=true;
        Brick7->Visible=true;   Brick8->Visible=true;    Brick9->Visible=true;
        Brick10->Visible=true;  Brick11->Visible=true;   Brick12->Visible=true;
        Brick13->Visible=true;  Brick14->Visible=true;   Brick15->Visible=true;
        Brick16->Visible=true;  Brick17->Visible=true;   Brick18->Visible=true;
        Brick19->Visible=true;  Brick20->Visible=true;   Brick21->Visible=true;
        Brick22->Visible=true;  Brick23->Visible=true;   Brick24->Visible=true;
        Brick25->Visible=true;

        Life1->Visible=true;    Life2->Visible=true;     Life3->Visible=true;

}
//---------------------------------------------------------------------------

