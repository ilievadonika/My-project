Задание:

Един любител на кодирането измислил своя система за кодиране. 

Той съпоставил на всяка една от първите k (0<k<10) на брой малки букви от латинската азбука 
по един низ с дължина най-много N знака (0<N<10), като низът бил съставен от някои от цифрите 0, 1, 2, ..., 9.
a - 101
b - 1111
c - 2056644
d - 01
e - 0
f - 010
g - 0001
h - 1100

i - 11
j - 1


След това, той взел един важен низ от М букви (0<М<20), съставен само от използваните от него малки латински
букви и заместил всяка буква със съответната й последователност от цифри, за да кодира важния низ.

За нещастие, след известно време било установено, че измислената от любнтеля система за кодиране е такава, че 
изобщо казано, не е възможно да се нaправи еднозначно декодиране.


Напишете npoгрaмa СОDЕ.ЕХЕ, която намира един или няколко възможни начина за декодиране на важния низ, 
или съобщава, че този низ не е получен като резултат от прилarане на системата на любителя за кодиране.

Входните данни се четат от текстовия файл СОDЕ.INP.
В първия ред на файла е даден важния низ в кодиран вид, записан като последователност от цифри, 
без разделящи ги шпации.
В следващия ред на файла е записано числото k.
Следват k реда, във осеки от които е записана на първа позиция k-тата малка буква от латинската 
азбука и след нея, с разделител от една шпация, е записан низът, с който любителят прави кодирането на тази 
буква, във вид на последователност от цифри, без разделящи ги шпации.

Изходните данни трябва да бъдат записани в текстов файл с име СОDЕ.OUT.
В първия му ред трябва да е записан броят на възможните начини за декодиране на кодираната последователност, 
или да е изписано числото 0, ако тази последователност не е възможно да бъде декодирана.
Следват толкова реда във файла, колкото начини за декодиране са намерени, като във всеки от тези редове трябва 
да е записана последователността от малки латински букви (без разделящи шпации), получена като резултат на 
декодирането.
Ако вашата npoгpaмa намери повече от 10 начина за декодиране, тя трябва да изведе само 10 от тях и тогава в 
първия ред на изходния файл трябва да бъде записан знакът +.
Пример
CODE.INP
110001
4
а 110
b 11
с 0
d 001
CODE.OUT
2
ad
bcd

