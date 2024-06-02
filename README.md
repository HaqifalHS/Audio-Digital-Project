<img src="assets/WARM_GREETING_DEVICE.png">

# Warm Greeting Device
### Audio-Digital-Project

>This project is to make an audio recording which is then stored in the ATMEGA 2560 EEPROM and converted into a PWM signal then the audio output is output to the active speaker.

---
### Komponen
1. Arduino Mega2560
2. Push Button
3. Speaker Mono
--- 
### Block Diagram
<img src="https://github.com/HaqifalHS/Audio-Digital-Project/blob/f4499125f9e494aa4fdc2bc73da82e70bb7e9b9d/assets/blokDiagram.jpg">

---
### Desain
- [Desan Mekanik 3D](https://github.com/HaqifalHS/Audio-Digital-Project/blob/e685f46bf5777b190d26c859aad1c4a9765173e5/Mekanik/Readme.md)<br>
  <img src="https://github.com/HaqifalHS/Audio-Digital-Project/blob/e33110678c75640b1c9dc7cf8615ef37a85bc81d/assets/rancangan_sistem.png" width="300" height="200">
- Desain Schematic<br>
  <img src="https://github.com/HaqifalHS/Audio-Digital-Project/blob/e33110678c75640b1c9dc7cf8615ef37a85bc81d/assets/skematik.png" width="300" height="200">
---

### [Audio](https://github.com/HaqifalHS/Audio-Digital-Project/blob/2348ff62978557f05a66bd87971e037f53e90160/Audio/Readme.md)
File audio dari mp3 akan dikonversi menjadi file hex dengan urutan file ```mp3``` > ```raw``` > ```hex```.

Selanjutnya konversi file raw ke hex melalui terminal ubuntu dengan command berikut : <br>
```srec_cat file.raw -Binary -o new_file_name -C-Array```<br>
```xxd -i file.raw > new_file_name.h``` <br>

---
### Program
Program dibuat menggunakan platfromio.h dengan framework Arduino. Dimana program menggunakan bahasa cpp dengan berisikan kontrol PWM dan button, file ```hex``` dari audio dikonfigurasikan menjadi library

---
