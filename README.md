# KohiJaniArduino
**2025/26 1. félév – Robotika alapjai GY**

## A projekt lényege és koncepciója
A projekt célja egy **távolságmérő radar rendszer** megvalósítása Arduino segítségével. A rendszer folyamatosan pásztázza a környezetét egy **szervo motorral mozgatott ultrahangos távolságérzékelő** segítségével, és az érzékelt távolságot **LCD kijelzőn** jeleníti meg.  

A projekt lényege, hogy **vizuálisan és elektronikus úton is jelezze a tárgyak közelségét**.

---

## A rendszer fő elemei

### Pásztázás szervo motorral
A szervo motor 0–180° között mozgatja az ultrahangos érzékelőt, így a környezet egy részét folyamatosan vizsgálja.

### Távolságmérés
Az ultrahangos szenzor a visszaverődő jelek alapján méri a tárgyaktól való távolságot, majd ezt az értéket **centiméterben** számolja ki.

### Adatmegjelenítés LCD-n
Az aktuális szöget és a mért távolságot az LCD kijelzőn jelenítjük meg, ami azonnali vizuális visszajelzést ad.

### LED jelzés
Az öt LED a teljes 180°-os pásztázási tartomány öt egyenlő szegmensét jelzi, és azt mutatja meg, hogy az érzékelt objektum éppen melyik szegmensben található.

### Beállítható maximális mérési távolság
Egy potméterrel szabályozható a maximális érzékelési távolság, így a rendszer **rugalmasan alkalmazkodik a környezethez**.

### Közelség visszajelzés
Ha valami 10 cm-en belül helyezkedik el, akkor a buzzer konstans sípolásba kezd addig, amíg el nem távolodik az objektum.

---

## Szükséges elemek listája

- Ultrahangos távolságérzékelő (HC-SR04)  
- Szervo motor (SG-90)  
- LCD kijelző (16x2)  
- 5 db LED  
- 6 db ellenállás
- Buzzer
- Potenciométer  
- Jumper kábelek  
- Breadboard
