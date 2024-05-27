# Audio-Digital-Project

This project is to make an audio recording which is then stored in the ATMEGA 2560 EEPROM and converted into a PWM signal then the audio output is output to the active speaker.

---
### Komponen
1. Arduino Mega2560
2. Push Button
3. Speaker Mono
---

### Desain
- Desan Mekanik 3D<br>
  <img src="assets/photo1.png" width="300" height="200">
- Desain Schematic<br>
  <img src="assets/photo4.png" width="300" height="200">
---

### Audio 
#File audio dari mp3 akan dikonversi menjadi file hex dengan urutan file ```mp3``` > ```raw``` > ```hex```. Konversi file raw ke hex melalui terminal ubuntu dengan command berikut : <br>
```srec_cat file.raw -Binary -o new_file_name -C-Array```<br>
```xxd -i file.raw > new_file_name.h``` <br>
Rekaman Audio <br>
<img src="assets/photo2.jpg" width="300" height="200">
---

### Program
Program dibuat menggunakan platfromio.h dengan framework Arduino. Dimana program menggunakan bahasa cpp dengan berisikan kontrol PWM dan button, file ```hex``` dari audio dikonfigurasikan menjadi library

---
