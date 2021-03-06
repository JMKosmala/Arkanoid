//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TTimer *BTimer;
        TImage *Ball;
        TShape *Bg;
        TImage *Paddle;
        TTimer *PLeft;
        TTimer *PRight;
        TImage *Brick5;
        TImage *Brick1;
        TImage *Brick2;
        TImage *Brick3;
        TImage *Brick4;
        TImage *Brick6;
        TImage *Brick25;
        TImage *Brick7;
        TImage *Brick8;
        TImage *Brick9;
        TImage *Brick10;
        TImage *Brick11;
        TImage *Brick12;
        TImage *Brick13;
        TImage *Brick14;
        TImage *Brick15;
        TImage *Brick16;
        TImage *Brick17;
        TImage *Brick18;
        TImage *Brick19;
        TImage *Brick20;
        TImage *Brick21;
        TImage *Brick22;
        TImage *Brick23;
        TImage *Brick24;
        TLabel *Label1;
        TShape *Life1;
        TShape *Life2;
        TShape *Life3;
        TLabel *ScoreBoard;
        TLabel *Label3;
        TButton *AgainButton;
        TButton *CloseButton;
        TLabel *EndBox;
        void __fastcall BTimerTimer(TObject *Sender);
        void __fastcall PLeftTimer(TObject *Sender);
        void __fastcall PRightTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall CloseButtonClick(TObject *Sender);
        void __fastcall AgainButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
