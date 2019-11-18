program ADF4350;

uses
  Forms,
  ADF4350_main in 'ADF4350_main.pas' {Form1};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TForm1, Form1);
  Application.Run;
end.
