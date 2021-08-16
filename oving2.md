# Øving 2: Pekere og referanser

Svar til øving i faget *INFT2503: C++ For Programmerere*.

Skrevet av [Truls H. Jakobsen](https://github.com/trulshj)

## Oppgave 2

Hva vil skje om du skriver:

```c++
char *line = nullptr;   // eller char *line = 0;
strcpy(line, "Dette er en tekst");
```

**Svar:** Når du skriver det over vil kompilatoren bare sette av minne til pekeren `line` (altså 8 bytes på en 64-bit implemetasjon). Når du deretter forsøker å kopierer inn teksten til lokasjonen hvor `line` befinner seg kan det hende vi overskriver noen annen data eller ødelegger styringen til programmet. Det kan også hende at vi senere vil overskrive teksten siden minnet ikke blir reservert. Sannsynligvis vil du få en Segmentation Fault om du forsøker å kjøre dette.

## Oppgave 3

Finn ting som kan gå galt i følgende programbit:

```c++
char text[5];
char *pointer = text; 
char search_for = 'e'; 
cin >> text; // Feil 1
while (*pointer != search_for) { // Feil 2
  *pointer = search_for; // Feil 3
  pointer++;
}
```

**Feil 1:** Når vi skriver `char text[5]` så vil vi kunne ha en streng her med 4 bokstaver + `\0` som terminerer strengen. Når vi bruker extraction operatoren på `cin` så vil vi kunne legge inn en streng i `text` som er lenger enn 4 karakterer og vi vil overskrive annet minne.

**Feil 2:** I denne betingelsen for while-løkken tar vi ikke høyde for lengden på tekst. Dersom `text` ikke inneholder karakteren vi leter etter så vil vi her begynne å lete etter den utenfor minnet som `text` befinner seg på. Dette vil gi en segmentation fault.

**Feil 3:** Når vi skriver `*pointer = search_for;` så muterer vi teksten vi leter gjennom. Hvis vi for eksempel leter gjennom teksten "Kake" så vil den ende opp som "eeee" ettersom vi fant e helt til slutt. Hvis vi ser på "Telt" så ender vi opp med "eelt". Noe bedre hadde kanskje vært å sjekke ekvivalens inne i while-løkken også bryte ut om vi finner karakteren eller avslutte om vi overstiger lengden på teksten.

F.eks:

```c++
int i = 0;
while (i < 5) {
    if (*pointer == search_for) {
        cout << "Found " << search_for << " at text[" << i << "]" << endl;
        break;
    }
    pointer++;
    i++;
  }
```

*Merk:* Dette hjelper ikke for Feil 1
