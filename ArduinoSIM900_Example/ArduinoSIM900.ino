/*
											***SatixCommunity***
										http://www.satixcommunity.de
Autor:     Felix
Beschreibung:	Wir wollen mit einem SIM900 Shield SMS verschicken und anrufe tätigen.
				

Bei Fragen, Anregungen, oder Verbesserungsvorschlaegen schreibt einfach bei uns ins Forum,
oder meldet euch bei mir unter: felix@satixcommunity.de
*/

// Die SoftwareSerial library erlaubt es uns nicht nur Pin 0 und 1
// zur Seriellenkommunikation zu benutzen. Wenn ihr die selbe SIM900
// library benutzt wie wir hier, dann lest mal die Instructions im doc Ordner.
// Wir benutzen Pin 2 als TX und Pin 3 als RX. Wobei TX der Sender und RX
// der Empfänger ist.
// Wenn ihr mehr ueber die SoftwareSerial library lesen wollt,
// schaut einfach hier: https://www.arduino.cc/en/Reference/SoftwareSerial vorbei.
#include "SoftwareSerial.h"
// Die SIM900, sms und call Headerdateien sind alle in der Library die
// wir vorgestellt haben.
#include "SIM900.h"
#include "sms.h"
#include "call.h"

// Wir erstellen hier ein call und ein sms Objekt.
SMSGSM sms;
CallGSM call;

char number[] = "+4915754116967"; // Hier kommt eure Nummer rein. (Beispiel: "+49123456789")

void setup() 
{
	Serial.begin(9600);

	// Wenn das Shield bereit ist, soll es eine Status Meldung ausgeben.
	// Möglicherweise werden euch im Seriellen Monitor 'kryptische' Worte
	// angezeigt und erst nach einer Weile der Status.
	// Das liegt an der library.
	if (gsm.begin(9600))
	{
		Serial.println("Status: Okay");
	}
	else
	{
		Serial.println("Status: Failure");
	}

	// Mit diesem Code könnt ihr eine SMS verschicken.
	
	sms.SendSMS(number, "Überwachungssystem ist jetzt aktiv.");
	

	// Mit diesem Code könnt ihr jemanden anrufen.
	/*
	call.Call(number);
	*/
}


void loop() 
{

}
