## Der Simplex-Algorithmus
 Ein einfaches C++ Programm



## Synopsis


Dieses Programm berechnet ein lineares Optimierunsproblem in der Form von ZF->max. Diesem einfachen Konsolenprogramm gibt man den Pfad zur Textdatei bekannt, wo die Koeffizienten gespeichert sind. Siehe weiter unten unter Tests. 

## Code Example

We use the Library of Eigen, because there are more options fo calculate the values.
Main.cpp oranizes everything and awaits the parameters
Convertdouble.cpp converts the Textfile in a double-array
solve.cpp takes the Eigen Matrix and returns an array with the resolution. 

## Motivation

Dieses Programm entstand im Zuge eines Programmierprojektes für PR OPS im WS2016 an der Universität Wien. 

## Installation

Compile: g++ -I /home/..../eigen -g -Wall main.cpp Solve.cpp Convertdouble.cpp -o simplex_ops

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
...

## Contributors

1. Lakinger Sabrina-teammember
2. Stockinger Alwin-teammember
3. Hauser Florian-teammember
4. Sampl Bernhard-developer

##Git
https://github.com/samplb/a1401504-unet.univie.ac.at.git

##Probleme:
Hat nach einer minimalen Änderung und darauffolgender Rückänderung angefangen am Almighty SementationFaults zu geben. Leider konnte der Grund nicht gefunden werden, da es bei jedem Projektmitglied problemlos gestartet ist. Da dies am Abgabetag aufgetreten ist, konnte kurzfristig auch keine Lösung gefunden werden. Das Programm hat vorher Problemlos kompiliert und daher wird das Problem laut eigener Erfahrung bei einer Almighty-Einstellun vermutet. Mehrere Studienkollegen berichteten schon öfter von ähnlichen Schwierigkeiten.
Zusätzlich war der Aufwand recht groß, da sich die restlichen Mitglieder nur an theoretischen Fragestellungen beteiligten.


