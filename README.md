# Projekt na języki i metody programowania 2 
Repozytorium projektu automatu komórkowego realizowanego w ramach zajęć Języków i metod programowania 2 przez zespół nr 9


## Gra w życie 
Gra w życie Conwaya to przykład automatu komórkowego o prostych zasadach: każda komórka ma dwa stany, "żywa" i "martwa"; tworząc nową generację martwa komórka o dokładnie 3 żywych sąsiadach rodzi się, a żywa umiera przy innej liczbie sąsiadów niż 2 lub 3.

Układy żywych komórek względem siebie nazywamy strukturami. Możemy je podzielić na statyczne, oscylujące i statki - poruszające się.
Kilka przykładów [z Wikipedii](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life#Examples_of_patterns):

![przykladowe-struktury](https://media.giphy.com/media/4VVZTvTqzRR0BUwNIH/giphy.gif)

W naszej implementacji Gry w życie przyjęłyśmy następująco:
- rozważamy stały obszar planszy, wokół którego **nie ma** żadnych komórek;
- żywa komórka reprezentowana jest kolorem czarnym, a martwa białym.


## Moduły implementacji
Program podzieliłyśmy na moduły zawierające następujące funkcjonalności:
* obsługa plików `loadfile.c`:
  - czytanie do struktury przechowującej dane;
  - zapisywanie pliku wynikowego w tym samym formacie co plik wejściowy;
  - poprawne zarządzanie pamięcią w strukturze.
* tworzenie generacji na poziomie struktury `generacje.c`;
* generowanie unikalnych nazw plików .png `names.c`;
* otrzymywanie plików .png na podstawie struktury `write_png.c`.

Ponadto zamieściłyśmy kilka plików z przykładowymi poprawnymi danymi wejściowymi, odpowiadające plikom z kodem pliki nagłówkowe, plik `makefile` służący sprawnej kompilacji oraz `game_png` - gotowy, uruchamialny plik programu.

### Wymagany format plików wejściowych
Każdy plik musi zawierać **cztery** liczby całkowite, kolejno: 
1. żądaną liczbę generacji,
2. wymiar planszy wzdłuż osi OX układu kartezjańskiego (rozpatrując planszę jako tabelę - liczba jej kolumn), 
3. wymiar planszy wzdłuż osi OY (liczba rzędów tabeli),
4. liczbę **żywych** komórek

Po tych czterech wartościach musi wystąpić *n* par współrzędnych każdej żywej komórki w postaci dwóch liczb całkowitych nie wychodzących poza zakres planszy, gdzie n - liczba żywych komórek.

W pliku wejściowym każda wartość może być oddzielona dowolną kombinacją białych znaków. 
Tworząc plik wyjściowy stanu końcowego, zachowałyśmy konwencję umieszczania każdego nowego "obiektu" w nowej linii - mam zatem w pierwszej linii liczbę generacji, w drugiej oba wymiary planszy, w trzeciej liczbę żywych komórek, a następnie obie współrzędne każdej żywej komórki w oddzielnej linijce.

### Ograniczenia
Planszę w naszej implementacji reprezentujemy tablicą dwuwymiarową, stąd z powodów oczywistych wszystkie współrzędne oraz wymiary muszą być liczbami całkowitymi większymi lub równymi zero. Podobnie liczba istniejących żywych komórek z definicji nie może być ujemna.
Podczas wytwarzania plików .png oraz tworzenia kolejnych generacji wykorzystywana jest również dosyć pokaźna ilość pamięci, jednakże wszelakie błędne, w tym zbyt duże, wartości powodujące błędy przeywają program i wyświetlają stosowny komunikat.


## Uruchamianie programu
Aby uruchomić program generujący obrazki po każdej generacji, należy:
1. Wejść w katalog *src* po pobraniu
2. Upewnienić się, ze biblioteka `libpng` została zainstalowana na danym urządzeniu
3. Skompilować program za pomocą polecenia `make game_png`
4. Wywołać program poleceniem `./game_png [ścieżka_do_pliku_wejściowego]`

_Ad 4._ Podawanie ścieżki pliku wejśiowego jest opcjonalne - domyślnie program korzysta z pliku `glider_test.txt`, który pokazuje cały jeden cykl poruszania się struktury statku o nazwie *glider*

Program po uruchomieniu generuje pliki i zapisuje je odpowiednio: serię .png do katalogu `dane`, a jeden końcowy .txt do katalogu bieżącego, tj `src`.

### Inne przykłady załączone w kodzie źródłowym
`beehive_test.txt`: pokazuje przejście układu kilku żywych komórek w statyczną strukturę kryształu (ang. *beehive*)
`pattern_test.txt`: przejście z trzech oscylujących struktur świateł ulicznych (ang. *blinker*) w dwie takie struktury z ciekawymi efektami 
`sniper_test.txt`: cztery struktury oscylujących świateł ulicznych

