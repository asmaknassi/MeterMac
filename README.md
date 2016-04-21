# MeterMac
Le projet consiste à développer un dispositif de mesure de l’audience TV pour MAC 
Sur MAC, il est possible d’accéder au son au format numérique en utilisant des API systèmes Cocoa; il est donc pertinent 
d’utiliser la même technologie de Watermarking que celle utilisée sur les audimètres TV. 
Cette technologie présente en effet l’avantage d’être déjà mise en place dans les régies et de pouvoir détecter
une chaîne de TV quel que soit son diffuseur (la chaîne elle-même ou un agrégateur comme un fournisseur d’accès Internet) 
et quel que soit l’application .
L’objectif est de développer un logiciel d’audimétrie (meter) sur MAC qui implémentera les fonctions suivantes :
-Le canal Audio sera récupéré au format numérique via l’API système et transmis à la librairie fournie par la société
Kantar Media. Les évènements d’audience détectés par la librairie seront stockés dans une base de données SQLlite sur 
le MAC à laquelle on accèdera via une librairie générique.
-Les évènements d’audience placés dans la base de données devront être transmis périodiquement au serveur de collecte 
en s’appuyant sur la librairie générique qui encapsule des Web services.
-Le meter sera activé automatiquement au démarrage du MAC.
-Par ailleurs, le meter devra gérer une interface de déclaration qui apparaitra au démarrage du MAC, à l’ouverture de 
session et sur reprise d’activité après plus de 30 minutes d’inactivité. Ce prompt présentera les prénoms des membres du 
foyer qu’il récupèrera sur un serveur de déclaration en Back-office via la lib générique. Les évènements de déclaration 
seront placés en base de données et transmis au serveur de collecte en même temps que les évènements de détection de contenu.
