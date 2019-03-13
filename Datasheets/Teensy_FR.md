# Utiliser le microcontr�leur Teensy LC


## T�l�verser un firmware pr�-compil�

1. Ouvrir l'appication Teensy loader (�pingl� � la barre de t�ches ou *C:\Program Files (x86)\Arduino\hardware\tools\teensy.exe*)
2. Cliquez: *File -> Open HEX File*
3. S�lectionnez le fichier qu vous voulez flasher.
4. Appuyez sur le bouton du bootloader du microcontr�leur:

![Button](button.png)

5. Attendez un message "reboot ok" sur l'interface:

![Reboot Ok](reboot_ok.png)

## Compiler et t�l�verser un firmware

1. Lancer arduino:
![Arduino](arduino.png)

2. Ouvrir le fichier *.ino* de votre projet (*file->open*).

3. Assurez-vous d'avoir les param�tres suivants (en s�lectionnant le bon port s�riel):  
![Config](config.png)

4. Ouvrir l'appication Teensy loader (�pingl� � la barre de t�ches ou *C:\Program Files (x86)\Arduino\hardware\tools\teensy.exe*)

5. *Ctrl+U* ou cliquez sur le bouton "upload":  
![Upload](upload.png)  

6. Arduino va automatiquement transf�rer le fichier hex g�n�r� vers le Teensy loader. 

7. Appuyez sur le bouton du bootloader du microcontr�leur:

![Button](button.png)

8. Attendez un message "reboot ok" sur l'interface:

![Reboot Ok](reboot_ok.png)

## Documentation

Le fichier */Datasheets/TeensyLC.pdf* contient le brochage (pinout) du microcontr�leur.

Utilisez la documentation Arduino de PJRC pour les fonctionnalit�s suivantes:

- I/O Digital (utilisez digitalWriteFast and digitalReadFast): https://www.pjrc.com/teensy/td_digital.html
- PWM: https://www.pjrc.com/teensy/td_pulse.html 
- Timing Functions: https://www.pjrc.com/teensy/td_timing.html
- USB Serial: https://www.pjrc.com/teensy/td_serial.html

Pour les autres fonctions, r�f�rez-vous � la documentation Arduino oroginale:  
https://www.arduino.cc/reference/en/

