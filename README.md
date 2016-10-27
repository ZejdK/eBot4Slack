# eBot4Slack


Kratki opis:
    Bot koji mjenja eBota, napravljen za Slack


ToDo:
-   std::String sa podrskom za UNICODE
-   odrediti znak koji predstavlja komandu (!, ., nesto...), jer ne mora se svaki string "indeksirati"/"parsirati"/kako god
-   skontati kako dobiti pravi token
-   skontati kako skloniti [bot] kad god bot posalje poruku




Neke ideje (za kasnije):
u prvom planu:
-   zastita od spamanja (u slucaju beskonacne petlje koja sadrzi ispis) (mozda?)
-   nekako sprjeciti da slackbot i ovaj bot odgovaraju jedan drugom na poruke, tj da se ne zaglave u petlji
-   chat logger
    *   treba onda iskljuciti edit, da se ne bi desili problemi sa "sinhronizacijom", tj da na jednom pise jedno, a na drugom nesto drugo
-   procesor/parser komandi (vrijeme/prognoza, izvjestaji, ping, seen, ...)
-   odgovor na nadjene rijeci iz poruka (ili mozda ostaviti ovo slackbotu)
-   youtube linkovi
    *   http://stackoverflow.com/questions/14379459/fetch-all-youtube-videos-using-curl

ostalo:
-    pracenje broja (ukupan i trenutno aktivnih) korisnika
-    rss
-    kviz, reakcije kucanja, mini igre


