# Hardware Hacking

## Synopsis

Le d�sir du consulat de r�unir les unvers-it�s vous laisse perplexe. Quelle id�e ridicule! Vous ne pourriez jamais faire la paix avec vos ennemis. Donc, comme tout hardware hacker militant ferait, vous vous occuperez de la situation!

Qu'est-ce que je propose?

C'est simple. On fait sauter le CS Paradise.
<img src="http://tpkblog.com/wp-content/uploads/2013/02/mgid-uma-content-mtv.jpg" width="48">

Cependant, personne ne peut savoir que vous �tes responsable de l'incident. Vos attaques devront �tre subtiles. Vous arrivez � vous faufiler dans le vaisseau et atteignez la salle de contr�les. C'est ici que votre mandat commence. Vous ne pouvez pas simplement implanter des objets externes. Ils se feraient remarquer imm�diatement. Vous devez donc utiliser les outils du consulat contre eux! Alt�rez discr�tement les m�thodes de contr�le, exploitez des hardware trojans, corrompez des noeuds de de calcul. Vos modifications doivent passer inaper�ues ou votre plan �chouera.

## La comp�tition

### Scores 

La comp�tition est divis�e en 6 hacks distribu�s sur 3 sections. Chaque hack vaut un certain nombre de points d�pendamment de sa difficult�. Vous pouvez faire les hacks dans l'ordre que vous voulez car il n'y a pas de d�pendances entre elles. 

Quand vous terminez un hack, signalez � un �valuateur. Il viendra v�rifier votre impl�mentation et vous accordera vos points si elle est correcte. Il n'y a pas de demi-notes. Vous avez compl�t� le hack � 100% ou c'est un �chec. L'�quipe avec le plus de points apr�s 3h gagne la comp�tition.

SVP garder vos circuits propres car les �valuateurs auront � les v�rifier. Le spaghetti sur breadboard ne sera pas accept� et vous devrez refaire le circuit. 
<img src="https://ih1.redbubble.net/image.528879934.4995/flat,550x550,075,f.u1.jpg" width="70">

### Outils disponibles 

Vos stations de travail incluent les outils suivants:

- Multim�tre
- Analyseur logique

Vos hardware kits contiennent les composantes suivantes:

- 2 x Teensy LC microcontr�leur 
- 1 x LM339
- Resistors
- Capacitors
- Wires
- 2-axis analog joysticks
- Tactile switches
- Micro-usb cable

Les logiciels suivants sont install�s sur votre machine virtuelle Windows 10 (tous �pingl�s sur la barre de t�che):

- Arduino 
- Teensy loader
- Saleae Logic 1.2.18
- joy.cpl
- Sublime text
- Git Bash

### Notes
**Les pins du microcontr�leur op�rent � 3.3V et ne supportent PAS un signal � 5V. Il sera grill� si connect� � un signal de 5V.**

Lors de la premi�re connexion du microcontr�leur et de l'analyseur logique, vous devrez manuellement connecter les dispositifs USB. VM->Removable Devices->Lakeview USB Device->Connect et VM->Removable Devices->Van Ooijen Technische Informatica->Connect. Si vous avez des probl�mes � flasher le microcontr�leur ou � le voir dans le logiciel de test, v�rifiez son statut de connexion � la VM.

Le mot de passe de la VM est "Passw0rd!".

Sur les sch�mas de configuration des sections, faites attention d'utiliser les �tiquettes textuelles des pins du microcontr�leur et non les num�ros de signaux sortant du bloc KiCad.

Le dossier */firmwares/* contient les firmware pr�compil�s pour chaque section.

Le dossier */Datasheets/* contient des documents techniques et des instructions sur comment programmer le microcontr�leur. 

Des fichiers *.ino* de base sont fournis pour les hacks qui requi�rent de la programmation. Ils contiennent des fonctions utiles.

Les joysticks fournis ont un intervalle anormal. Leur intervalle �lectrique se termine � environs 50% de leur intervalle physique. Quand on parle de bouger d'un certain pourcentage le long d'une axe du joystick, on parle de son intervalle �lectrique et non physique.  

Certains hacks demandent des entr�es de boutons tactiles. Vous n'avez pas besoin de faire un anti-rebond (debounce).

Les rails d'alimentation sur le breadboard sont discontinus au centre. Connectez les deux moiti�s pour avoir un rail continu.

Si vous avez des probl�mes lors du set-up d'une section, demandez de l'aide. Ne perdez pas votre temps sur la configuration SVP.

## Section 1

La premi�re composante que vous examinez est le syst�me de contr�le principal. Il est compos� d'un joystick 2 axes et d'une croix directionnelle de 4 boutons. Le joystick contr�le les moteurs du vaisseau et la croix permet de s�lectionner un univers parall�le � naviguer. Une id�e vous vient � l'esprit: vous pourriez inverser leurs fonctions. Le vaisseau est vou� � s'�craser si le capitaine essaie de le contr�ler dans cet �tat alt�r�.

N.B. : Cette section contient 4 hacks car il y a plusieurs fa�ons d'impl�menter ses composantes. Les contr�le de la croix directionnelle avec le joystick se fait dans les hacks 1 et 2. Le contr�le du joystick avec la croix directionnelle se fait dans les hacks 3 et 4.

### Configuration

Dans cette section, un microcontr�leur agit en tant que module principal du syst�me de contr�le. Il est connect� au PC par USB et transf�re ses donn�es en tant que manette de jeu USB.

Impl�mentez le circuit suivant (INCLUANT LA DISPOSITION DES BOUTONS). Le VCC du joystick est bien 3.3V, ignorez le fait que la pin est �tiquet�e 5V:
![Gamepad](img/gamepad.png)

Branchez le microcontr�leur dans le port usb de votre PC et flashez le avec le firmware *section1.hex*. Pour tester le syst�me, vous utiliserez l'application *joy.cpl*. Cherchez ce fichier dans la barre de recherche Windows et double cliquez sur le dispositif USB pour ouvrir la page de test. Les 4 boutons de la croix directionnelle devraient d�clencher le "hat" dans leurs directions respectives. Le joystick devrait d�placer les axes analogues dans les deux directions.

### Hack 1 (5 points)

Contr�lez les entr�es de la croix directionnelle avec un joystick. Les directions de la croix devraient �tre d�clench�es lorsque le joystick d�passe la moiti� du seuil d'activation maximal dans une direction donn�e. Vous ne pouvez pas alt�rer le firmware du syst�me principal; votre solution doit �tre une addition de composantes externes.

Composantes que vous devez utiliser (vous n'avez pas le droit d'ajouter autre chose):  
    - Joystick  
    - Un deuxi�me microcontr�leur  
    - Fils  


### Hack 2 (10 points)

Contr�lez les entr�es de la croix directionnelle avec un joystick. Les directions de la croix devraient �tre d�clench�es lorsque le joystick d�passe la moiti� du seuil d'activation maximal dans une direction donn�e. Vous ne pouvez pas alt�rer le firmware du syst�me principal; votre solution doit �tre une addition de composantes externes.

Composantes que vous devez utiliser (vous n'avez pas le droit d'ajouter autre chose):  
    - Comparateur analogue LM339 (datasheet: /Datasheets/lm339.pdf)  
    - R�sistances  
    - Fils  

### Hack 3 (5 points)

Contr�lez les entr�es du joystick avec une croix directionnelle. Les 4 boutons tactiles doivent imiter le comportement du joystick lorsqu'il se trouve � 50% de son seuil d'activation maximal (ex: le bouton UP d�clenche un mouvement de 50% en direction NORD dans le logiciel de test). Votre impl�mentation doit permettre la combinaison de direction verticales et horizontales (ex: UP et DROITE en m�me temps d�clenchent un mouvement de 50% direction NORD-EST). Vous ne pouvez pas alt�rer le firmware du syst�me principal; votre solution doit �tre une addition de composantes externes.

Composantes que vous devez utiliser (vous n'avez pas le droit d'ajouter autre chose):  
    - 4 interrupteurs tactiles  
    - R�sistances  
    - Fils  

N.B:  
- Lorsque les pins d'entr�e des axes X et Y sont flottantes, le gamepad affiche une position neutre. 

### Hack 4 (10 points)

Contr�lez les entr�es du joystick avec une croix directionnelle. Les 4 boutons tactiles doivent imiter le comportement du joystick lorsqu'il se trouve � 50% de son seuil d'activation maximal (ex: le bouton UP d�clenche un mouvement de 50% en direction NORD dans le logiciel de test). Votre impl�mentation doit permettre la combinaison de direction verticales et horizontales (ex: UP et DROITE en m�me temps d�clenchent un mouvement de 50% direction NORD-EST). Vous ne pouvez pas alt�rer le firmware du syst�me principal; votre solution doit �tre une addition de composantes externes.

Composantes que vous devez utiliser (vous n'avez pas le droit d'ajouter autre chose):  
    - Un autre microcontr�leur  
    - R�sistances  
    - Condensateurs  
    - Fils  

N.B:  
- Lorsque les pins d'entr�e des axes X et Y sont flottantes, le gamepad affiche une position neutre. 

## Section 2

Une fois le syst�me de contr�le alt�r�, vous d�cidez d'examiner les syst�me d'armes. Vous notez 8 boutons �tiquet�s: UP, RIGHT, DOWN, LEFT, TORPEDO, CANON, SHIELD, SELFDESTRUCT. C'est une opportunit� parfaite. Vous pourriez associer le bouton SHIELD � la fonction SELFDESTRUCT... le consulat aura une petite surprise la prochaine fois que le capitaine essaie d'armer ses boucliers. :hear_no_evil: :bomb: :skull: :smiling_imp: 

Vous n'avez pas acc�s aux fils des boutons poussoirs. Cependant, vous �tes capables d'exposer une partie des circuits. Vous observez que les boutons sont entr�s dans un microcontr�leur et que celui-ci est connect� au syst�me principal avec trois lignes de donn�es non-identifi�es. Vous remarquez que vous avez �galement acc�s au port usb du microcontr�leur g�rant les boutons et que le bootloader USB a �t� laiss� intact (quel design horrible). Cela laisse le syst�me ouvert pour une attaque classique de corruption de noeud!

### Configuration

Dans cette section, il y a deux microcontr�leurs. Un est le gestionnaire d'entr�es et l'autre est le syst�me principal. Le gestionnaire d'entr�e lit les boutons et les transmet au syst�me principal via un protocole inconnu. 

Impl�mentez le circuit suivant (INCLUANT LA DISPOSITION DES BOUTONS):
![Hack5](img/hack5.png)

Branchez le gestionnaire d'entr�es dans votre PC et flashez le avec le firmware *section2_input_controller.hex*. D�branchez le gestionnaire d'entr�es, connectez le syst�me principal et flashez le avec le firmware *section2_main_system.hex*. Ouvrez le testeur de gamepad. Les 4 boutons de la croix directionnelle devraient d�clencher le "hat" et les 4 boutons devraient avoir les correspondances suivantes:

- TORPEDO: button 0
- CANON: button 1
- SHIELD: button 2
- SELF DESTRUCT: button 3

### Hack 5 (20 points)


Vous devez alt�rer le fonctionnement du gestionnaire d'entr�es pour que les fonction SHIELD et SElFDESTRUCT soient invers�es. Le comportement des autres boutons reste inchang�. Comme mentionn� pr�c�demment, vous ne pouvez pas alt�rer les circuits �lectriques. La seule fa�on de l'impl�menter est de changer le firmware du gestionnaire d'entr�es. Vous n'avez pas acc�s � son code source donc vous devez �tudier le protocole de communication et le r�impl�menter. 

Voici un exemple de signaux que vous devriez observer avec l'analyseur logique:
![Hack5 Capture](img/hack5_capture.png)

## Section 3

Dans les deux sections pr�c�dentes, vous avez hack� le dashboard et les contr�les d'armes. En th�orie, votre travail est termin�. Cependant, en sortant du vaisseau, vous passez par la chambre du capitaine. En entrant, vous remarquez qu'il poss�de un syst�me de jeu branch� dans une TV. La console roule *Animal Crossing*... :cow: :pig: :dog: 

Cette console ne semble pas standard. La seule entr�e de la manette est un joystick; il n'y a pas de boutons. La manette est connect�e � la console avec un seul fil de donn�es.

Une id�e brillante vous vient � l'esprit. Vous savez ce qui rendrait le capitaine furieux? Briser sa manette :joy_cat: . Vous d�cidez donc d'introduire des dysfonctionnalit�s en hackant sa manette.

### Configuration

Dans cette section, il y a deux microcontr�leurs. Une agit comme la manette et l'autre comme la console. La manette lit les entr�es du joystick et les transmet � la console via un protocole inconnu. 

Impl�mentez le circuit suivant. Le VCC du joystick est bien 3.3V, ignorez le fait que la pin est �tiquet�e 5V:
![Hack6](img/hack6.png)

Branchez le microcontr�leur de la console dans le port usb du PC et flashez le avec le firmware *section3_console.hex*. Connectez le microcontr�leur de la console et flashez le avec le firmware *section3_controller.hex*. Reconnectez le microcontr�leur de la console et ouvrez le testeur de gamepad sur votre PC. Le joystick devrait d�placer les axes analogues dans les deux directions.

### Hack 6 (40 points)

Comme mentionn� pr�c�demment, vous ne pouvez pas alt�rer les circuits �lectriques. La seule fa�on de l'impl�menter est de changer le firmware de la manette. Vous n'avez pas acc�s � son code source donc vous devez �tudier le protocole de communication et le r�impl�menter. 

Voici les 3 dysfonctionnalit�s � impl�menter:

- Pendant 2 secondes, la manette agit normalement.
- Pendant 2 secondes, les axes X et Y sont invers�s (X per�u comme y et vice-versa). 
- Pendant 2 secondes, la manette n'envoit que des positions de joystick neutres.

It�rez � travers ces 3 modes infiniment dans des cycles de 6 secondes. 

Voici un exemple de signaux que vous devriez observer avec l'analyseur logique:
![Hack6 Capture](img/hack6_capture.png)

N.B. : Ceci est une impl�mentation logicielle d'un protocole de communication mat�riel rapide. Donc des erreurs de timing peuvent arriver facilement. En contre-mesure, un watchdog a �t� impl�ment� dans le firmware de la console. Le dispositif se r�initialise s'il y a blocage lors des communications. C'est �galement un bon indicateur de l'exactitude temporelle de votre impl�mentation du protocole. 


