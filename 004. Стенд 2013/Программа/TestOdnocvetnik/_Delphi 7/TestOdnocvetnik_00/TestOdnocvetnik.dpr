program TestOdnocvetnik;

uses
  Forms,
  TestOdnocvetnik_main in 'TestOdnocvetnik_main.pas' {MainForm},
  AboutBox in 'AboutBox.pas' {F_AboutBox};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TMainForm, MainForm);
  Application.CreateForm(TF_AboutBox, F_AboutBox);
  Application.Run;
end.
