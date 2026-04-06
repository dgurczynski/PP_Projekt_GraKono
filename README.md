# PP_Projekt_GraKono

Konsolowa implementacja strategicznej gry planszowej **Kono** (rozmiar 4x4), stworzona w języku C++. Projekt umożliwia rozgrywkę gracza z botem w trybie tekstowym.

### Główne Funkcje
* **Rozgrywka z AI:** Bot wykonujący ruchy losowe oraz strategiczne skoki (bicia).
* **System Ruchów:** Obsługa współrzędnych w formacie `A4-A3` z pełną walidacją poprawności.
* **Interfejs ASCII:** Renderowanie tablicy wyników i planszy przy użyciu rozszerzonych znaków graficznych.
* **Zasady Kono:** Implementacja przesuwania pionków o jedno pole oraz bić poprzez przeskakiwanie nad własnymi jednostkami.
* **Warunki Zwycięstwa:** Automatyczne wykrywanie zbicia wszystkich pionków przeciwnika lub ich całkowitego zablokowania.

### Obsługa Programu
1. Skompiluj i uruchom program.
2. Podaj nazwy graczy.
3. Wykonuj ruchy, wpisując pozycję startową i docelową (np. `A1-A2`).
