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

##Probleme:
Hat nach einer minimalen Änderung und darauffolgender Rückänderung angefangen am Almighty SementationFaults zu geben. Leider konnte der Grund nicht gefunden werden, da es bei jedem Projektmitglied problemlos gestartet ist. Da dies am Abgabetag aufgetreten ist, konnte kurzfristig auch keine Lösung gefunden werden. Das Programm hat vorher Problemlos kompiliert und daher wird das Problem laut eigener Erfahrung bei einer Almighty-Einstellun vermutet. Mehrere Studienkollegen berichteten schon öfter von ähnlichen Schwierigkeiten.
Zusätzlich war der Aufwand recht groß, da sich die restlichen Mitglieder nur an theoretischen Fragestellungen beteiligten.


