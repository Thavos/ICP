[//]: # (xhruzs00)

# ICP Simulácia robotov
Simulátor robotov je softvérová aplikácia určená na simuláciu pohybu a interakcie robotov vo virtuálnom prostredí. Poskytuje používateľom grafické rozhranie na vytváranie máp, umiestňovanie prekážok a rozmiestňovanie robotov s rôznymi konfiguráciami.

## Funkcionalita
**Úprava mapy**: Vytváranie a úprava mapy pridávaním prekážok, robotov a definovaním rozmerov mapy.
**Ovládanie simulácie**: Spustenie, pozastavenie, klikom na robota sa aktivuje manuálne riadenie pomocou kláves W, A, S, D.
**Vstup/výstup súborov**: Ukladanie a načítanie máp do/z súborov na neskoršie použitie v textovom formáte.

## Závislosti

**Qt**: Projekt využíva rámec Qt pre grafické používateľské rozhranie.
**Štandardná knižnica C++17**

## Inštalácia a spustenie
Ak by Makefile z akéhokoľvek dôvodu nefungoval, napríklad kvôli inej verzii **Qt**, je súčasťou projektu súbor `robot-sim.pro` ktorý je možné preložiť príkazom `qmake robot-sim.pro`. Výstupom je **Makefile** pripravený na použitie.

Súčasťou projektu je **Makefile** s niekoľkými príkazmi:

- `make` 	        - preloží a vytvorí projekt v zložke `./build`
- `make run`        - spustí preložený program
- `make clean`      - vyčistí súbory 
- `make doxygen`    - vytvorí dokumentáciu v zložke`./doc`
- `make pack`       - vytvorí `.zip` súbor projektu

## Spustenie a používanie

Po spustení sa zobrazí hlavné menu so štyrmi možnosťami:

- Simulation	- spustí okno simulácie
- New Map		- spustí okno editovania mapy 
- Edit Map		- otvorí dialógové menu pre výber súboru na načítanie existujúcej mapy, následne okno editovania
- Quit			- ukončí aplikáciu


### Simulačné okno
Toto okno ponúka 5 funckií:

- Štart simulácie 
- Pauza simulácie
- Výber robota kliknutím - kliknutím na iné miesto/robota výber zruší/zmení
- Pohyb vpred a vzad klávesami W, S
- Otáčanie v smere a protismere ručičkových hodiniek

### Editovacie okno
V pravej časti vykresľuje stav mapy, v ľavej časti ponúka nástroje na editovanie. Pri výbere novej mapy sa zapne ihneď s prázdnou mapou. Ak je zvolená možnosť **Edit Map**, je na začiatku otvorený dialóg pre výber mapy.

- Mapa 
	- Šírka a výška mapy v rozmedzí <100; 1000>
- Mód
	- Add/Delete    - na určenie akcie ktorá sa vykoná na kliknutie myši
	- Robot         - stanoví objekt robota ako objekt ktorý chceme pridať/odobrať
	- Obstacle      - stanoví objekt prekážky ako objekt ktorý chceme pridať/odobrať
- Parametre robota
	- Angle                 - počiatočný uhol robota v stupňoch <0; 360>
	- Range                 - dĺžka lúču v akej robot detekuje prekážky v rozmedzí <0; 1000>
	- Rotation Angle        - uhol otáčania robota za 1 tik simulácie v rozmedzí <0; 360>
	- Rotation Direction    - určí smer otáčania robota v smere/protismere ručičkových hodiniek
		- Right - implicitne
		- Left
- Save - tlačidlo pre uloženie mapy

## Implementácia
Pri implementácii sme postupovali podľa návrhového vzoru MVC a dodržali návrh v pdf súbore `ICP_navrh.pdf`, ktorý je súčasťou projektu. Pre kolízie robotov sme využili techniku **raycasting** kde roboti vysielajú luč v smere svojho pohybu, následne iterovaním cez všetky prekážky zistíme či náš lúč pretína niektorú zo strán štrovrcovej prekážky. Samotné rohy a teda aj hrany sú pritom vynesené o niečo ďalej ako je grafika prekážok a to z dôvodu aby sme dorovnali rozdiel tela robota a zabezpečili, že žiadna jeho časť prekážkou neprejde.

Keďže sa jedná o 2D priestor a je často potrebné pracovať s pozíciami na **x** a **y** osi, implementovali sme vlastnú pomocnú triedu Vecotr2D.

## Známe obmedzenia

- Chýba validácia načítaných súborov.
- Roboti vedia zacúvať jemne za grafiku stien.
- Prekážky a roboti môžu byť umiestnený na úplný okraj mapy, v takom prípade sa budú roboti otáčať na mieste.
- Roboti môžu byť umiestnený v prekážke, opäť v takom prípade sa budú otáčať  na mieste.
- Mapa môže byť zmenšená po umiestnení objektov, objekty budú existovať za hranicami mapy, roboti sa budú otáčať na mieste.
- Zmena veľkosti mapy na menšiu za sebou zanechá voľný priestor.

## Autory

xhruzs00
xsnope04