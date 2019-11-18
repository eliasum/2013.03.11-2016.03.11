program StendOdnocvetnik;

uses
  Forms,
  StendOdnocvetnik_main in 'StendOdnocvetnik_main.pas' {MainForm};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TMainForm, MainForm);
  Application.Run;
end.
