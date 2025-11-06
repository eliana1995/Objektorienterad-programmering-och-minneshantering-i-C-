# Objektorienterad programmering och minneshantering i C++

Ett arbete skrivet i C++ av Eliana, Hafsa, Fredrik och Madeleine

[Uppgiftsbeskrivning](https://gist.github.com/davidsvson/1cacf23963d0fb7672abe7ddb2f6c2bf)

---

**_Syfte: Denna uppgift syftar till att testa vår förståelse för objektorienterad programmering i C++, inklusive användning av klasser, arv, polymorfi och minneshantering på både stacken och heapen._**

Vi har skapat ett enkelt inventariesystem för ett rollspel.  
Genom att implementera arv så kan subklasserna Armor, Potion och Weapon ärva de virtuella funktionerna från Item. Detta gör att funktionsanrop kan göras utan att behöva veta vilken specifik typ av objekt som funktionen ska anropas på.

Spelarklassen Player har en vector av pekare som pekar till de objekt som spelaren valt att lägga till sitt inventory. Objekten klonas från fördefinerad lista av Item-objekt från vilken spelaren kan välja att lägga till sitt inventory.

### Minneshantering

-   Player-objektet skapas på stack-minnet.
-   Item-objekt skapas på heap-minnet med nyckelordet new.
-   När programmet avslutas så tas Player-objektet bort.
-   Player-destruktorn tar bort de items som lagts till inventoryt vilket säkerställer att minnet som allokerats på heapen frigörs.
-   De Item-objekt som finns i den fördefinerade listan tas bort vilket säkerställer att minnet som allokerats på heapen frigörs.
