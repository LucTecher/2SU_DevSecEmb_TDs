# Travaux dirigés du cours de Sécurité et Systèmes embarqués

## Cours
Le cours est disponible [ici](https://github.com/xkt/2SU_DevSecEmb) !

## Question générale en texte libre

- Décrivez votre processus et raisonnement pour évaluer la sécurité d'un système embarqué au niveau matériel et logiciel.

Premièrement, il faut établir la surface d'attaque en commençant par la surface d'attaque physique du matériel. Chaque moyen d'intéragir avec l'appareil élargit la surface d'attaque (port USB, port ethernet, NFC ...). Il faut donc s'assurer qu'ils sont tous bien essentiels et qu'il n'y en a pas qui sont là juste parce que la board en possédait par défaut.
Il faut aussi prendre en compte la manière avec laquelle sera utilisé l'appareil. Est-ce qu'il sera dans une boîte perché en haut d'une antenne de 30m ou est ce qu'il sera chez l'utilisateur ? Ce dernier cas implique que les accès physiques sont tout aussi sensibles et probables que les accès à distance. Il faut aussi s'assurer qu'il n'y ait pas de vulnérabilité sur le matériel tel qu'une puce sur laquelle on peut facilement lire des données (JTAG par exemple).

Il faut ensuite essayer d'établir la surface d'attaque logicielle afin de la limiter. Est-ce que le système est à jour ? Si non, est-ce qu'il y a des failles critiques connues qui pourraient être facilement exploitables ? Il faut aussi faire un tour des différents services qui sont utilisés par l'appareil et vérifier qu'ils sont tous bien essentiels afin de limiter la surface d'attaque. Tout comme pour le système, il faut vérifier qu'il n'existe pas de failles critiques sur les différents services et il faut aussi s'assurer qu'ils sont bien à jour.

On peut ensuite établir des scénarii d'attaques et essayer de les mettre en place. Ces différentes hypothèses d'attaques doivent être classées en fonction de leur probabilité et des risques qu'elles impliquent si elles venaient à se réaliser. En fonction des résultats de ces tests, on peut suggérer des solutions ou simplement les communiquer aux équipes qui s'occupent du matériel ou du logiciel selon ce qui est concerné afin qu'ils puissent établir des solutions.