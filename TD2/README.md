# TD2 - Binwalk

Binwalk est disponible [ici](https://github.com/ReFirmLabs/binwalk)

# Test

On teste l'image avec la commande :

`$ qemu-system-arm -M versatilepb -m 16 -kernel vmlinuz-qemu-arm-2.6.20 -append "clocksource=pit quiet rw"`

Puis dans le terminal qemu, on utilise la commande :

`$ run_demo`

Ceci nous donne une crise d'épilepsie : 

![](images/WAYTOODANK.png)

# Analyse du binaire

Grâce à [binwalk](https://github.com/ReFirmLabs/binwalk), on peut extraire le contenu du binaire :

`$ binwalk -C extracted_content -M -e vmlinuz-qemu-arm-2.6.20`

Grâce à la commande tree, on peut visualiser rapidement le contenu du résultat :

`$ tree extracted_content`

On peut voir que plusieurs images sont présentes ! Dont une qui s'appelle tux.png (notre cher petit Pingouin):
![](images/tux.png)

# Modification du contenu


Grâce à la commande `binwalk vmlinuz-qemu-arm-2.6.20`, on peut voir à partir de quel offset le système de fichier débute.

![](images/binwalk_firmware.png)

Ici, l'offset est de 12720 octets. Avec *dd* on récupère le fichier gzip de l'image qui se situe à l'offset. La commande à utiliser est donc :

`$ dd if=vmlinuz-qemu-arm-2.6.20 of=31B0.gz bs=1 skip=12720`

On peut ensuite décompresser le résultat avec *gzip* puis utiliser binwalk à nouveau.

![](images/binwalk_gzip_31B0.png)

On voit un autre fichier gzip à la position 59360, pour le récupérer, on refait appel à *dd* de la même manière que précédemment, cette fois-ci il faut préciser le nombre d'octets à récupérer puisque le fichier n'est pas en dernière position :

`$ dd if=31B0 of=E7E0.gz bs=1 skip=59360 count=2296597`

On peut à nouveau décompresser le résultat et rappeler binwalk :

![](images/binwalk_gzip_E7E0.png)

Dans le résultat de la commande on apperçoit notre fameux pingouin en position 0x2D89DC dans le fichier, grâce à un script python, on peut modifier un bit du fichier tux.png directement.

Il faut ensuite recompresser l'archive CPIO au format gzip, puis la repositionner dans le fichier 31B0. Puis il faut recompresser 31B0 au format gzip et enfin le repositionner dans l'image binaire : 

![](images/rebuild.png)

**ERREUR :** Lorsque je ne modifie pas l'archive CPIO, la reconstruction de l'image semble fonctionner, mais dès que j'y touche ça ne fonctionne plus... Je suppose que le problème vient du checksum CRC32 qu'il faudrait recalculé, mais comment ...? Je vois aussi que lorsque je recompresse mon E7E0, la taille du fichier est bien plus faible que l'originale, pourquoi ?

![](images/error.png)
