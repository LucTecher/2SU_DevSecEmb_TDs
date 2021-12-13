# TD4 - Toolbox

## MITM USB

Le projet [USBProxy](https://github.com/BenGardiner/USBProxy) permet de lire les données échangées entre un appareil USB et la machine hôte. Je n'arrive pas à le faire fonctionner cependant.

## MITM Bluetooth

Le projet [Bluetooth_LE_MITM](https://github.com/PaulPauls/Bluetooth_LE_MITM) permet de se placer en Man in the Middle entre un périphérique Bluetooth Low Energy et une machine centrale.

Pour utiliser le projet on doit le cloner :

`git clone https://github.com/PaulPauls/Bluetooth_LE_MITM`

Puis intaller les dépendances :

`cd Bluetooth_LE_MITM/`

`pip install -r requirements.txt`

Les PC à notre disposition ne possèdent malheureusement pas d'antenne bluetooth :( .

## MITM Wifi

[WifiMITM](https://github.com/mvondracek/wifimitm)