# POO-Reto
En este proyecto, tuvimos que desarrollar un código de c++ que incluyera los conocimientos vistos en la clase de Pensamiento computacional orientado a objetos.

El proyecto que hice se basa en Pokémon, este programa permite iniciar sesión o registrarse como un entrenador (usuario común) o un administrador, el entrenador tiene la posibilidad de jugar en un simulador de atrapar pokémons y también de comprar pokébolas (usadas para atrapar pokémons).

Por otro lado, el administrador puede registrar pokémons para el juego y eliminar entrenadores.

Un defecto del programa es que solo guarda datos mientras está en ejecución, por lo que un usuario registrado dejará de estarlo la siguiente vez que corra el programa, lo mismo aplica para los pokemons registrados por un Admin.

Este programa tiene 5 clases:

 - User
 - Trainer
 - Admin
 - Pokédex
 - Pokémon

El diagrama de clases está adjunto a este repos.

Las competencias a evaluar en estos archivos son:

 - Diseño clases sencillas completas (con todos los atributos y métodos requeridos).

Esta competencia se puede evaluar en cualquier clase, sin embargo, recomiendo la clase Pokemon y el archivo Pokemon.h debido a que es la clase más completa

 - Modelo un diagrama de clase útil para solucionar un problema utilizando UML.

Esto se evalúa con el UML adjunto

 - Utilizo el concepto de herencia en el diagrama de clases de manera adecuada.

Esto se evalúa con las clases Trainer, Admin y su clase madre User

 - Utilizo el concepto de composición (o agreagación) en el diagrama de clases.

Esto se evalúa con la clase Pokémon y su agregación a Pokédex y Trainer

 - Implemento las clases en c++ siguiendo el diseño del diagrama de clases en UML.

De nuevo esto pueder ser visto en las clases User, Trainer y Pokemon

 - Codifico métodos y atributos de clase correctamente. (constructores, getters, setters)

De nuevo, recomiendo la clase Pokemon debido a que es la clase más completa

 - Compruebo el acceso a los atributos y métodos de la clase (encapsulamiento correcto, mando a llamar los objetos de forma útil).

Para esto recomiendo observar la función pokeRegister del main.cpp, ubicada en la línea 130, al final de esta función llamo metodos de la clase Pokedex y Pokemon. Otro ejemplo claro es el uso de getters en PokeCatcher, estos se encuentran en las líneas 88, 92, 93, 94 y 95.

 - Implemento herencia de manera correcta y util

Podemos observar esto en los archivos Trainer.h, Admin.h y User.h, algunos ejemplos de su uso pueden ser vistos en la función isRegistered() ubicada en la línea 197 del main.cpp y en la función initliazeUsers del archivo PokeStarter.h, ubicada en la línea 27.

 - Implemento composición (o agregación) siguiendo mi diagrama de clases

El ejemplo de esto es visto en la clase Pokedex y su metodo addPokemon(), ubicado en la línea 16, donde se agregan objetos de tipo Pokemon al vector de pokemones de Pokedex

 - Implemento clases apegadas a requerimientos a partir de un modelo.

Mis clases son aprovechadas en su totalidad y se conectan las unas con otras.

 - Sigo estándares en todo mi código fuente: estilo, sangrías, comentarios, nombres, etc...

Esto puede ser visto en todo el código, incluyendo por ejemplo, el uso de identación en las clases a pesar de no ser obligatorio y también en el switch del main.cpp ubicado en la línea 277.

 - Cumplo con estándares en mi repositorio: tiene un readme claro que explica el proyecto (para que sirve, para que no sirve y como se usa), no tiene archivos basura o versiones pasadas.

En este repos se puede comprobar lo anterior.

 - Uso una herramienta para control de versiones (github).

Este repos lo demuestra-

 - Guardo correctamente los avances en commits durante la materia.

Debo admitir que no lleve un correcto control de los avances en gitHub y la mayor parte del avance está en un solo commit.
