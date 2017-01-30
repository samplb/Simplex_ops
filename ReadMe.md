## Der Simplex-Algorithmus
 Ein einfaches C++ Programm



## Synopsis


Dieses Programm berechnet ein lineares Optimierunsproblem. Diesem einfachen Konsolenprogramm gibt man den Pfad zur Textdatei bekannt, wo die Koeffizienten gespeichert sind. Für Details siehe weiter unten unter Tests. 
Nachdem der Pfad bekanntgegeben wurde, gibt man noch bekannt ob Minimiert oder Maximiert wird und das Programm berechnet alle Variablen und gibt eine Einfache Sensibilitätsanalyse aus.
Im Menü findet man optional noch Beispiele.

## Code Example

Wir nutzen die Eigenbibliothek für die Matrixen.
main.cpp verwaltet das Programm, bietet die Ausgaben und erwartet und verwaltet die Eingaben.
Convertdouble.cpp konvertiert die Textdateien in ein double-array.
solve.cpp berechnet aus der erstellten Matrix die Lösungswerte.

## Motivation

Dieses Programm entstand im Zuge eines Programmierprojektes für PR OPS im WS2016 an der Universität Wien. 

## Installation
Download und installation von der Eigen-Bibliothek (siehe unter Librarys).
Compile: g++ -I /home/..../eigen -g -Wall main.cpp Solve.cpp Convertdouble.cpp -o simplex_ops

Textfiles mit den Parametern(siehe Tests).

## Librarys

Zum kompilieren wird die Eigen Library (http://eigen.tuxfamily.org/index.php?title=Main_Page) benötigt um die Matrixen berechnen zu können. 
Dafür muss man dem Compiler den Pfad bekannt geben(http://eigen.tuxfamily.org/dox/GettingStarted.html). 

## Tests
Das Programm fordert beim Programmstart die Eingabe eines Pfades im Format: 
'C:/Users/xxx/Documents/.../testfile.txt' 
Dieses File soll mit den benötigten Werten gefüllt und mit Leerzeichen getrennt unter Einhaltung folgender Vorgabe erstellt werden:
n k
ZF-x1 ZF-x2 ZF-x3
NB-x1 NB-x2 NB-x3 NB-y1
NB-x1 NB-x2 NB-x3 NB-y2
NB-x1 NB-x2 NB-x3 NB-y

Erklärung:
n....Anzahl der Variablen
k....Anzahl der Nebenbedingungen
x_...die zu berechnenden Werten
y_...die Bedingungen der Nebenbedingungen.

Wenn Zielfunktion(ZF) maximiert, müssen alle Nebenbedingungen(NB) in der Form x1+x2 <= y sein,
wird die ZF minimiert, müssen alle Nebenbedingungen in der Form x1+x2 >= y sein.

## Contributors

1. Lakinger Sabrina-teammember
2. Stockinger Alwin-teammember
3. Hauser Florian-teammember
4. Sampl Bernhard(a1401504@unet.univie.ac.at)-developer

##Git
https://github.com/samplb/a1401504-unet.univie.ac.at.git
 
##Almighty

samplb94@almighty:~/ops$ ls
Algorithmus_TextuelleBeschreibung.txt  Convertdouble.h  ops        test
anmerkung.txt                          kompilieren.txt  Solve.cpp  test1
Convertdouble.cpp                      main.cpp         Solve.h    Textfile
samplb94@almighty:~/ops$ g++ -I /home/samplb94/Eigen/eigen -std=c++11 -g -Wall main.cpp Convertdouble.cpp Solve.cpp -o ops
main.cpp: In function ‘int main()’:
main.cpp:133:26: warning: ‘saved_stack.301’ may be used uninitialized in this function [-Wmaybe-uninitialized]
                     break;
                          ^
Solve.cpp: In member function ‘double* Solve::lpsolve(int, double*, int, double**, double*, bool)’:
Solve.cpp:173:1: warning: control reaches end of non-void function [-Wreturn-type]
 };
 ^
samplb94@almighty:~/ops$ ./ops


Welcome to our Program: Simplex-EasySolver

        Options:
        Please input the number of one of those options:
                 1 -path
                 2 -help
                 3 -maximising
                 4 -not implemented
                 5 -minimising
                 6 -close Program
3
3
Starte die Berechnung:

Textfile:
3 4
15 20 130
5 0 0 2
10 10 0 3
0 20 20 4
0 0 50 5
start solve.cpp

____________________________________________


Das Ausgangstableau:
 -15  -20 -130    0    0    0    0    0
   5    0    0    1    0    0    0    2
  10   10    0    0    1    0    0    3
   0   20   20    0    0    1    0    4
   0    0   50    0    0    0    1    5
____________________________________________


Schritt 1: 
 -15  -20    0    0    0    0  2.6   13
   5    0    0    1    0    0    0    2
  10   10    0    0    1    0    0    3
   0   20    0    0    0    1 -0.4    2
   0    0    1    0    0    0 0.02  0.1
Schritt 2: 
  -15     0     0     0     0     1   2.2    15
    5     0     0     1     0     0     0     2
   10     0     0     0     1  -0.5   0.2     2
    0     1     0     0     0  0.05 -0.02   0.1
    0     0     1     0     0     0  0.02   0.1
Schritt 3: 
    0     0     0     0   1.5  0.25   2.5    18
    0     0     0     1  -0.5  0.25  -0.1     1
    1     0     0     0   0.1 -0.05  0.02   0.2
    0     1     0     0     0  0.05 -0.02   0.1
    0     0     1     0     0     0  0.02   0.1

____________________________________________

End-Tableau: 
    0     0     0     0   1.5  0.25   2.5    18
    0     0     0     1  -0.5  0.25  -0.1     1
    1     0     0     0   0.1 -0.05  0.02   0.2
    0     1     0     0     0  0.05 -0.02   0.1
    0     0     1     0     0     0  0.02   0.1
____________________________________________


        |
        |Loesung:
        |       x1: 0.20
        |       x2: 0.10
        |       x3: 0.10
        |optimaler Wert: 18.00
        |
        |
        |Schlupfvariablen:
        |       y4: 1.00
        |       y5: 1.50
        |       y6: 0.25
        |       y7: 2.50


Sensibilitaetsanalyse: 
        Wenn Sie die Schlupfvariablen y4 um 1 erhöhen, sinkt auch
        bei der Bedingung 1 der Wert b: 2.00 auf 1.00.
        Der Optimalwert ändert sich dadurch auf 17.00(18.00-1.00).
Umgekehrt, wenn Sie b um 1 erhoehen, kann Z um den Wert 1.00 erhoeht werden

        Wenn Sie die Schlupfvariablen y5 um 1 erhöhen, sinkt auch
        bei der Bedingung 2 der Wert b: 3.00 auf 2.00.
        Der Optimalwert ändert sich dadurch auf 16.50(18.00-1.50).
Umgekehrt, wenn Sie b um 1 erhoehen, kann Z um den Wert 1.50 erhoeht werden

        Wenn Sie die Schlupfvariablen y6 um 1 erhöhen, sinkt auch
        bei der Bedingung 3 der Wert b: 4.00 auf 3.00.
        Der Optimalwert ändert sich dadurch auf 17.75(18.00-0.25).
Umgekehrt, wenn Sie b um 1 erhoehen, kann Z um den Wert 0.25 erhoeht werden

        Wenn Sie die Schlupfvariablen y7 um 1 erhöhen, sinkt auch
        bei der Bedingung 4 der Wert b: 5.00 auf 4.00.
        Der Optimalwert ändert sich dadurch auf 15.50(18.00-2.50).
Umgekehrt, wenn Sie b um 1 erhoehen, kann Z um den Wert 2.50 erhoeht werden


Hinweis:        Die genauen Aenderungen der einzelnen Variablen sind im Tableau abzulesen.
Press any key



##Probleme:
Hat nach einer minimalen Änderung und darauffolgender Rückänderung angefangen am Almighty bei der Berechnung einen SementationFaults zu geben(Abbruch nach Anfangs-Tableau). Leider konnte der Grund nicht gefunden werden, da es bei jedem Projektmitglied problemlos gestartet ist. Da dies am Abgabetag aufgetreten ist, konnte kurzfristig auch keine Lösung gefunden werden. Das Programm hat vorher kompiliert und funktioniert(siehe oben) und daher wird das Problem laut eigener Erfahrung bei einer Almighty-Einstellung vermutet. Mehrere Studienkollegen berichteten schon öfter von ähnlichen Schwierigkeiten.
Leider habe ich keinen grafischen Beweis der funktionierenden Version, Fehlerhafte ist als .jpg beigelegt.
Zusätzlich war der Aufwand recht groß, da sich die restlichen Mitglieder nur an theoretischen Fragestellungen beteiligten.


