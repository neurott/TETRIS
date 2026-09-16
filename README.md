# Tetris

Un clon de Tetris hecho en C++ usando [raylib](https://www.raylib.com/) como motor gráfico, creado simplemente para aprender C++ y algo de desarrollo de videojuegos, anteriormente probé con GODOT, pero de mañoso, preferí algo que no tuviera interfaz y tener el control completo de la aplicación. Este mini-proyecto lo armé aplicando programación orientada a objetos, buscando practicar el diseño de clases y la separación de responsabilidades más allá de simplemente hacer que el juego funcione.

---

Lo siguiente esta escrito con IA, ya que es todo lo que se necesita para ejecutar el juego desde el Visual

## Características

- Sistema de piezas (bloques) con rotación
- Detección y limpieza de líneas completas
- Efectos de sonido (movimiento, rotación, hard drop, game over) y música de fondo
- Fuente personalizada (Monogram)

## Estructura del proyecto

```
src/        Código fuente (game, grid, block, position, colors, main)
Font/       Fuente utilizada en el juego
Sounds/     Efectos de sonido y música
lib/        Librerías dinámicas necesarias en Windows (libgcc, libstdc++)
Makefile    Build basado en el Makefile de ejemplos de raylib
```

## Requisitos

- [raylib](https://www.raylib.com/) instalado (probado con la versión 5.0.0)
- Un compilador compatible con C++ (MinGW / w64devkit en Windows)

## Compilar

```bash
make
```

Esto genera el ejecutable del juego (`game.exe` en Windows).

## Ejecutar

```bash
./game.exe
```

## Controles

- Flechas izquierda/derecha: mover la pieza
- Flecha abajo: bajar más rápido
- Flecha arriba: rotar
- Barra espaciadora: hard drop

---

> COSAS QUE FALTAN:

- [ ] Agregar un menú de opciones: música on/off, efectos de sonido on/off, volúmenes, temas visuales (varios), temas de interfaz y velocidad (fácil/media/difícil)
- [ ] Puntaje más alto (high score)
- [ ] Poder pausar el juego, con su menú de pausa (probablemente lo más difícil)
- [ ] Aumentar la dificultad a partir de cierto puntaje
---
