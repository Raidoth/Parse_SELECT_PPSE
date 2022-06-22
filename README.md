# Parse_SELECT_PPSE

Программа должна разобрать и распечатать уже полученный ответ карты на пакет SELECT PPSE.
А именно: выбрать из него все теги 61 (APPLICATION TEMPLATE), составить и отсортировать список приложений, существующих на карте, по алгоритму:
Из списка найденных на карте приложений сформировать список кандидатов, выбирая приложения, поддерживаемые совместно ридером и картой. Ридером поддерживается только одно приложение с RID =  {0xA0,0x00,0x00,0x06,0x58}. RID - это первые 5 байт тега 4F, PIX (суффикс приложения) - это оставшиеся байты тега  4F. Далее ридер сортирует полученный список кандидатов по приоритету (тег 87 - Application Priority Indicator). Если приоритет не задан (см. Таблица 1), то такие приложения помещаются в конец списка кандидатов в порядке, в котором они встретились в ответе карты.

После сортировки, вывести отсортированый список RID + PIX через printf();
Работать должно универсально, при любых ответах карты. Код должен быть чистым, без костылей, заплаток и хардкода

Сам терминал и карты для выполнения задания предоставлены не будут.
Для отладки можно использовать следующие варианты ответов карты:

6F39840E325041592E5359532E4444463031A527BF0C2461129F2A038106438701034F07A0000004320001610E8701024F09A000000658101033339000

6F29840E325041592E5359532E4444463031A517BF0C1461129F2A038106438701814F07A00000065810109000

6F10840E325041592E5359532E44444630319000

6F20840E325041592E5359532E4444463031A50EBF0C0B61099F2A038106438701019000

6F37840E325041592E5359532E4444463031A525BF0C2261129F2A038106438701034F07A0000004320001610C8701024F07A00000065810109000

## Project start
```
make
./main <answer SELECT PPSE>
```

##Test№1
```
./main 6F39840E325041592E5359532E4444463031A527BF0C2461129F2A038106438701034F07A0000004320001610E8701024F09A000000658101033339000
```
##Out
```
RID+PIX: A00000065810103333
```
##Test№2
```
./main 6F29840E325041592E5359532E4444463031A517BF0C1461129F2A038106438701814F07A00000065810109000
```
##Out
```
RID+PIX: A0000006581010
```
##Test№3
```
./main 6F10840E325041592E5359532E44444630319000
```
##Out
```
No application in answer
```
##Test№4
```
./main 6F20840E325041592E5359532E4444463031A50EBF0C0B61099F2A038106438701019000
```
##Out
```
No applications
No supported app
```
##Test№5
```
./main 6F37840E325041592E5359532E4444463031A525BF0C2261129F2A038106438701034F07A0000004320001610C8701024F07A00000065810109000
```
##Out
```
RID+PIX: A0000006581010
```
