# TD4 - Toolbox

## MITM USB

Le projet [USBProxy](https://github.com/usb-tools/USBProxy-legacy) permet de lire les données échangées entre un appareil USB et la machine hôte. 

### Installation

```console
$ git clone https://github.com/usb-tools/USBProxy-legacy
$ cd USBProxy-legacy
$ sudo apt-get install libpcap-dev libusb-1.0
$ mkdir src/build
$ cd src/build
$ cmake ..
$ make
$ sudo make install
$ sudo ldconfig
```

### Utilisation

La commande suivante permet d'observer les paquets qui sont échangés entre l'hôte et le périphérique USB. Cependant, j'obtient une erreur que je ne parviens pas à résoudre :
```console
$ sudo usb-mitm -l
Loading plugins from /usr/local/lib/USBProxy/
vendorId=ffffffff
productId=ffffffff
cleaning up /tmp
removing 1
Made directory /tmp/gadget-PMLI42 for gadget
Error mounting gadgetfs from [/tmp/gadget-PMLI42].
Error code from mount is: [No such device]
Printing Config data
	Strings: 2
		DeviceProxy: DeviceProxy_LibUSB
		HostProxy: HostProxy_GadgetFS
	Vectors: 1
		Plugins:
			PacketFilter_StreamLog
Pointer: 1
		PacketFilter_StreamLog::file: 0x7ffb1c4d45c0
Device: 12 01 00 02 00 00 00 40 e8 04 60 68 00 04 01 02 03 01
  Manufacturer: SAMSUNG
  Product:      SAMSUNG_Android
  Serial:       R58M67ZQ21B
	*Config(1): 09 02 88 00 04 01 04 80 fa
	   Name: Conf 1
		Interface(0):
			*Alt(0): 09 04 00 00 03 06 01 01 05
			   Name: MTP
			Other(24): 08 24 80 0c 00 01 00 01
			Other(0b): 08 0b 01 02 02 02 01 08
				EP(81): 07 05 81 02 00 02 00
				EP(01): 07 05 01 02 00 02 01
				EP(82): 07 05 82 03 1c 00 06
		Interface(1):
			*Alt(0): 09 04 01 00 01 02 02 01 06
			   Name: CDC Abstract Control Model (ACM)
			Other(24): 05 24 00 10 01
			Other(24): 05 24 01 00 02
			Other(24): 04 24 02 02
			Other(24): 05 24 06 01 02
				EP(84): 07 05 84 03 0a 00 09
		Interface(2):
			*Alt(0): 09 04 02 00 02 0a 00 00 07
			   Name: CDC ACM Data
				EP(83): 07 05 83 02 00 02 00
				EP(02): 07 05 02 02 00 02 00
		Interface(3):
			*Alt(0): 09 04 03 00 02 ff 42 01 0a
			   Name: ADB Interface
				EP(03): 07 05 03 02 00 02 00
				EP(85): 07 05 85 02 00 02 00
HS Qualifier: 0a 06 00 02 00 00 00 40 01 00
	 Config(1): 09 07 80 00 04 01 04 80 fa
	   Name: Conf 1
		Interface(0):
			*Alt(0): 09 04 00 00 03 06 01 01 05
			   Name: MTP
			Other(0b): 08 0b 01 02 02 02 01 08
				EP(81): 07 05 81 02 40 00 00
				EP(01): 07 05 01 02 40 00 00
				EP(82): 07 05 82 03 1c 00 06
		Interface(1):
			*Alt(0): 09 04 01 00 01 02 02 01 06
			   Name: CDC Abstract Control Model (ACM)
			Other(24): 05 24 00 10 01
			Other(24): 05 24 01 00 02
			Other(24): 04 24 02 02
			Other(24): 05 24 06 01 02
				EP(84): 07 05 84 03 0a 00 20
		Interface(2):
			*Alt(0): 09 04 02 00 02 0a 00 00 07
			   Name: CDC ACM Data
				EP(83): 07 05 83 02 40 00 00
				EP(02): 07 05 02 02 40 00 00
		Interface(3):
			*Alt(0): 09 04 03 00 02 ff 42 01 0a
			   Name: ADB Interface
				EP(03): 07 05 03 02 40 00 00
				EP(85): 07 05 85 02 40 00 00
Error claiming interface 0: Resource busy
searching in [/tmp/gadget-PMLI42]
/tmp/gadget-PMLI42 device file not found.
Error, unable to find gadget file.
Fail on open 16 Device or resource busy
GadgetFS not connected.
done
```

## MITM Bluetooth

Le projet [Bluetooth_LE_MITM](https://github.com/PaulPauls/Bluetooth_LE_MITM) permet de se placer en Man in the Middle entre un périphérique Bluetooth Low Energy et une machine centrale.

Pour utiliser le projet on doit le cloner :

`git clone https://github.com/PaulPauls/Bluetooth_LE_MITM`

Puis intaller les dépendances :

`cd Bluetooth_LE_MITM/`

`pip install -r requirements.txt`

Les PC à notre disposition ne possèdent malheureusement pas d'antenne bluetooth :(.

## MITM Wifi

Le projet [mitm-router](https://github.com/brannondorsey/mitm-router) permet de transformer une machine en hotspot wifi et d'écouter tout le traffic http. 

### Installation

`$ git clone https://github.com/brannondorsey/mitm-router`
`$ cd mitm-router`

Il faut aussi [installer Docker](https://docs.docker.com/engine/install/).

### Utilisation

Le projet tournera dans un conteneur Docker, il faut donc dans un premier temps créer l'image docker :

`docker build . -t brannondorsey/mitm-router`

Puis il faut lancer un conteneur en prenant soin de mettre l'interface wifi pour la variable `AP_IFACE` et l'interface ethernet pour la variable `INTERNET_IFACE`. Mon ordinateur ne possède pas de carte wifi donc je ne peux pas non plus tester ce projet.

## Questions

1. Quel sont les critères qui rendent une vulnérabilité critique ?

La criticité d'une vulnérabilité dépend de plusieurs facteurs : 
- La facilité avec laquelle elle peut être exploitée.  Est-ce qu'elle requiert un accès physique à l'apareil ou est-ce qu'elle peut être exploitée à distance ?
- Les dégâts que peut engendrer l'exploitation de la vulnérabilité. Est-ce qu'elle permet d'avoir un accès complet sur le système ? Est-ce qu'elle permet juste de modifier un mot dans un affichage ?
- La probabilité qu'elle soit exploitée. Est-ce qu'elle demande des conditions très particulières ou des connaissances extrêmement pointues ? Est-ce qu'elle peut être exploitée lors d'un cas d'usage courant par un utilisateur lambda ?


2. Suivant ces critères quelle interface devrait être testée en premier? Pourquoi?

Les interfaces qui doivent être testées en premier sont les interfaces réseau, puisque les attaques les plus courantes proviennent du réseau ou de l'extérieur.

3. Quels avantages, inconvénients ont les outils que vous avez choisi ?

Je n'ai pas vraiment réussi à en faire fonctionner... Donc l'inconvénient serait qu'ils ne sont pas toujours fonctionnels ou maintenus. Cependant ils proposent, à priori, la possibilité d'écouter sur les différentes interfaces et pour certains, ils permettent même de forger des paquets.
Pour le wifi, seul le traffic http est interceptable, ce qui limite la portée de l'attaque étant donné que la majorité du traffic sur internet utilise le protocole https de nos jours.