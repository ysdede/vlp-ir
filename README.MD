http://hackaday.com/2010/10/25/avr-programming-02-the-hardware/


avrdude -c usbasp -p m328p -P usb -U flash:w:kumanda.hex -U lfuse:w:0x52:m hfuse:w:0xD9:m -U efuse:w:0x07:m

efuse hatası: http://www.avrfreaks.net/forum/avrdude-failing-verify-fuses sadece son üç bit kullanılıyor 0xFF = 0x07

avrdude -c usbasp -p m328p -P usb -U flash:w:kumanda8Mhz.hex -U lfuse:w:0xff:m hfuse:w:0xDe:m -U efuse:w:0x07:m

Pro Mini çalışan:
avrdude -c usbasp -p m328p -P usb -Uflash:w:C:\DOCUME~1\DEVELO~1\LOCALS~1\Temp\builda705828a14443041b10aea666c5c7a4b.tmp/kumanda.ino.hex:i -U lfuse:w:0xE2:m hfuse:w:0xD9:m -U efuse:w:0x07:m
avrdude -c usbasp -p m328p -P usb -Uflash:w:C:\Documents and Settings\developer\Desktop\projeler\HeraSafe\kumandaInt8MhzBODdisabled.hex:i -U lfuse:w:0xE2:m hfuse:w:0xD9:m -U efuse:w:0x07:m
C:\DOCUME~1\DEVELO~1\LOCALS~1\Temp\builda705828a14443041b10aea666c5c7a4b.tmp/kumanda.ino.hex