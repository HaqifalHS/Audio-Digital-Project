# Audio-Digital-Project

This project is to make an audio recording which is then stored in the ATMEGA 2560 EEPROM and converted into a PWM signal then the audio output is output to the active speaker.

---
### Komponen
1. Arduino Mega2560
2. Push Button
---

### Desain
- Desan Mekanik 3D
  <img src="https://github.com/HaqifalHS/Audio-Digital-Project/issues/3#issuecomment-2095189850" width="300" height="200">
- Desain Schematic
  <img src="https://github.com/HaqifalHS/Audio-Digital-Project/issues/7#issuecomment-2106579813" width="300" height="200">
---

### Audio 
File audio dari mp3 akan dikonversi menjadi file hex dengan urutan file ```mp3``` > ```raw``` > ```hex```. Konversi file raw ke hex melalui terminal ubuntu dengan command berikut : <br>
```srec_cat file.raw -Binary -o new_file_name -C-Array```<br>
```xxd -i file.raw > new_file_name.h```

---

### Program
Program dibuat menggunakan platfromio.h dengan framework Arduino. Dimana program menggunakan bahasa cpp dengan berisikan kontrol PWM dan button, file ```hex``` dari audio dikonfigurasikan menjadi library

---
